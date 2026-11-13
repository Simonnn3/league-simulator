#include "Database.h"

sqlite3* db = nullptr;

bool apridatabase() {

    int risultato = sqlite3_open("data/campionati.db", &db);

    if (risultato != SQLITE_OK) {
        return false;
    }

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
    )";

    int risultato = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);

    return risultato == SQLITE_OK;
}

bool salvasquadre(const std::vector<Team>& squadre) {

    const char* sql = "INSERT OR IGNORE INTO Squadre (nome, attacco, difesa) VALUES (?, ?, ?)";

    sqlite3_stmt* stmt = nullptr;

    int risultato = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (risultato != SQLITE_OK) {
        return false;
    }

    for (const Team& squadra : squadre) {

        sqlite3_bind_text(stmt, 1, squadra.nome.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 2, squadra.attacco);
        sqlite3_bind_int(stmt, 3, squadra.difesa);

        risultato = sqlite3_step(stmt);

        if (risultato != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            return false;
        }

        sqlite3_reset(stmt);
        sqlite3_clear_bindings(stmt);
    }

    sqlite3_finalize(stmt);

    return true;
}

bool caricasquadre(std::vector<Team>& squadre) {

    const char* sql = "SELECT nome, attacco, difesa FROM Squadre";

    sqlite3_stmt* stmt = nullptr;

    int risultato = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (risultato != SQLITE_OK) {
        return false;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        Team squadra;

        squadra.nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        squadra.attacco = sqlite3_column_int(stmt, 1);
        squadra.difesa = sqlite3_column_int(stmt, 2);

        squadre.push_back(squadra);
    }

    sqlite3_finalize(stmt);

    return true;
}