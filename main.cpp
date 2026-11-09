#include <iostream>
#include <string>
#include <vector>
#include "Team.h"
#include "campionato.h"
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

    generasquadra(nomi, squadre);
    stampasquadra(squadre); 
    creacalendario(squadre, calendario);
    stampacalendario(squadre, calendario);
    simulacampionato(squadre, calendario);
    stampacalendario(squadre, calendario);
    vector<Team> classifica = calcolaclassifica(squadre);
    stampaclassifica(classifica);

    return 0;
}