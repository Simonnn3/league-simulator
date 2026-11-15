#include "Database.h"

sqlite3* db = nullptr;

bool apridatabase() {

    int risultato = sqlite3_open("data/campionati.db", &db);

    if (risultato != SQLITE_OK) {
        return false;
    }
    sqlite3_exec(db, "PRAGMA foreign_keys = ON;", nullptr, nullptr, nullptr);

    return true;
}

void chiudidatabase() {
    if (db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool creaschema() {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS Squadre (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL UNIQUE,
            attacco INTEGER,
            difesa INTEGER
        );

        CREATE TABLE IF NOT EXISTS Stagioni (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL UNIQUE,
            data_inizio TEXT NOT NULL
        );

        CREATE TABLE IF NOT EXISTS StagioneSquadre (
            stagione_id INTEGER NOT NULL,
            squadra_id INTEGER NOT NULL,
        
            PRIMARY KEY (stagione_id, squadra_id),
        
            FOREIGN KEY (stagione_id) REFERENCES Stagioni(id),
            FOREIGN KEY (squadra_id) REFERENCES Squadre(id)
        );
    )";

    int risultato = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);

    return risultato == SQLITE_OK;
}

bool salvasquadre(std::vector<Team>& squadre) {

    const char* sql = "INSERT OR IGNORE INTO Squadre (nome, attacco, difesa) VALUES (?, ?, ?)";

    sqlite3_stmt* stmt = nullptr;

    int risultato = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (risultato != SQLITE_OK) {
        return false;
    }

    const char* sql_id = "SELECT id FROM Squadre WHERE nome = ?";

    sqlite3_stmt* stmt_id = nullptr;

    risultato = sqlite3_prepare_v2(db, sql_id, -1, &stmt_id, nullptr);

    if (risultato != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return false;
    }

    for (Team& squadra : squadre) {

        sqlite3_bind_text(stmt, 1, squadra.nome.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 2, squadra.attacco);
        sqlite3_bind_int(stmt, 3, squadra.difesa);

        risultato = sqlite3_step(stmt);

        if (risultato != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            sqlite3_finalize(stmt_id);
            return false;
        }

        if (sqlite3_changes(db) > 0) {
            squadra.id = sqlite3_last_insert_rowid(db);
        }

        else {
            sqlite3_bind_text(stmt_id, 1, squadra.nome.c_str(), -1, SQLITE_TRANSIENT);

            risultato = sqlite3_step(stmt_id);

            if (risultato == SQLITE_ROW) {
               squadra.id = sqlite3_column_int(stmt_id, 0);
            }

            else {
                sqlite3_finalize(stmt);
                sqlite3_finalize(stmt_id);
                return false;
            }

        sqlite3_reset(stmt_id);
        sqlite3_clear_bindings(stmt_id);
        }

        sqlite3_reset(stmt);
        sqlite3_clear_bindings(stmt);
    }

    sqlite3_finalize(stmt);
    sqlite3_finalize(stmt_id);

    return true;
}

bool caricasquadre(std::vector<Team>& squadre) {

    const char* sql = "SELECT id, nome, attacco, difesa FROM Squadre";

    sqlite3_stmt* stmt = nullptr;

    int risultato = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (risultato != SQLITE_OK) {
        return false;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        Team squadra;

        squadra.id = sqlite3_column_int(stmt, 0);
        squadra.nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        squadra.attacco = sqlite3_column_int(stmt, 2);
        squadra.difesa = sqlite3_column_int(stmt, 3);

        squadre.push_back(squadra);
    }

    sqlite3_finalize(stmt);

    return true;
}