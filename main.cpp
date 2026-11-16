#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Team.h"
#include "campionato.h"
#include "console_ui.h"
#include "application/CampionatoService.h"
#include "infrastructure/Database.h"
using namespace std;

string ottienistagione(int& anno_inizio) {

    time_t ora = time(nullptr);
    tm* data = localtime(&ora);

    anno_inizio = data->tm_year + 1900;

    if (data->tm_mon < 8) {
        anno_inizio--;
    }

    return to_string(anno_inizio) + "/" + to_string(anno_inizio + 1);
}

int main(){
    srand(time(nullptr));

    if (!apridatabase()) {
        cout << "Errore nell'apertura del database!" << endl;
        return 1;
    }

    if (!creaschema()) {
        cout << "Errore nella creazione delle tabelle!" << endl;
        chiudidatabase();
        return 1;
    }

    cout << "Database collegato correttamente!" << endl;

    int anno_inizio;

    string nome_stagione = ottienistagione(anno_inizio);

    string data_inizio = to_string(anno_inizio) + "-09-01";

    int id_stagione = 0;

    if (!creastagione(nome_stagione, data_inizio, id_stagione)) {
        cout << "Errore nella creazione della stagione!" << endl;
        chiudidatabase();
        return 1;
    }

    cout << "Stagione attiva: " << nome_stagione << endl;

    vector<string> nomi = {
        "AN Brescia",
        "RN Savona",
        "Pro Recco",
        "Trieste PN",
        "CN Posillipo",
        "CC Napoli",
        "CC Ortigia",
        "SS Lazio",
        "Chiavari Nuoto",
        "Olympic Roma",
        "Roma Vis Nova",
        "SC Quinto",
        "Telimar Palermo",
        "De Akker Bologna"
    };

    vector<Team> squadre;
    vector<Partita> calendario;

    if (!caricasquadre(squadre)) {
        cout << "Errore nel caricamento delle squadre!" << endl;
        chiudidatabase();
        return 1;
    }

    if (squadre.empty()) {
        cout << "Nessuna squadra trovata. Generazione nuove squadre..." << endl;
        generasquadra(nomi, squadre);
    }


    else {
        cout << "Squadre caricate dal database!" << endl;
    }

    inizializzacampionato(squadre, calendario);

    if (!salvasquadre(squadre)) {
        cout << "Errore nel salvataggio delle squadre!" << endl;
        chiudidatabase();
        return 1;
    }

    if (!salvastagionesquadre(squadre, id_stagione)) {
        cout << "Errore nel collegamento delle squadre alla stagione!" << endl;
        chiudidatabase();
        return 1;
    }


    stampasquadra(squadre);
 
    stampacalendario(squadre, calendario);

    eseguisimulazione(squadre, calendario);

   stampacalendario(squadre, calendario);

    vector<Team> classifica = ottieniclassifica(squadre);
    stampaclassifica(classifica);

    chiudidatabase();

    return 0;
}