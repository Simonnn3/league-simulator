#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Team.h"
#include "campionato.h"
#include "console_ui.h"
#include "application/CampionatoService.h"
using namespace std;

int main(){
    srand(time(nullptr));

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

    inizializzacampionato(nomi, squadre, calendario);

    stampasquadra(squadre); 
    stampacalendario(squadre, calendario);

    eseguisimulazione(squadre, calendario);

    stampacalendario(squadre, calendario);

    vector<Team> classifica = calcolaclassifica(squadre);
    stampaclassifica(classifica);

    return 0;
}