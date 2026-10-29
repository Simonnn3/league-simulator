#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;
random_device rd;
mt19937 generatore(rd());

struct Team {
    string nome;
    int attacco;
    int difesa;
    int partitegiocate = 0;
    int partitevinte = 0;
    int partitepareggiate = 0;
    int partiteperse = 0;
    int puntifatti = 0;
    int golfatti = 0;
    int golsubiti = 0;
};

struct Partita {
    int squadraCasa;
    int squadraTrasferta;
    bool partitaGiocata = false;
};

void giocapartita(Team& squadra1, Team& squadra2);

void generasquadra(const vector<string>&nomi, vector<Team>& squadre){
    for (string nome : nomi){
        Team nuovaSquadra;
        nuovaSquadra.nome = nome;
        nuovaSquadra.attacco = rand() % 51 + 50;
        nuovaSquadra.difesa = rand() % 51 + 50;
        squadre.push_back(nuovaSquadra);
    }
};

void stampasquadra(vector<Team> &squadre){
    for (auto Team : squadre){
        cout << Team.nome << endl;
        cout << "Attacco: " << Team.attacco << endl;
        cout << "Difesa: " << Team.difesa << endl << endl;
    }
}

void creacalendario(const vector<Team>& squadre, vector<Partita>& Calendario){
    for (int i = 0; i < squadre.size(); i++) {
        for (int j = i + 1; j < squadre.size(); j++){
            Partita nuovaPartita;
            nuovaPartita.squadraCasa = i;
            nuovaPartita.squadraTrasferta = j;
            Calendario.push_back(nuovaPartita);
        }
    }
}

void simulacampionato(vector<Team>& squadre, vector<Partita>& Calendario){
    for(Partita& partita : Calendario ){
        giocapartita(
            squadre[partita.squadraCasa],
            squadre[partita.squadraTrasferta]
        );
        partita.partitaGiocata = true;
    }
}

void giocapartita(Team& squadra1, Team& squadra2){
    int bonussquadra1 = (squadra1.attacco - squadra2.difesa)/10;
    int golsquadra1 = (rand() % 21) + bonussquadra1;
    int bonussquadra2 = (squadra2.attacco - squadra1.difesa)/10;
    int golsquadra2 = (rand() % 21) + bonussquadra2;

    if (golsquadra1 < 0) {
        golsquadra1 = 0;
    }

    if (golsquadra2 < 0) {
        golsquadra2 = 0;
    }

    squadra1.partitegiocate++;
    squadra2.partitegiocate++;

    squadra1.golfatti += golsquadra1;
    squadra2.golfatti += golsquadra2;

    squadra1.golsubiti += golsquadra2;
    squadra2.golsubiti += golsquadra1;

    if (golsquadra1 > golsquadra2){
        squadra1.partitevinte++;
        squadra1.puntifatti += 3;
        squadra2.partiteperse++;
        cout << squadra1.nome << " Ha vinto " << squadra1.golfatti << "- " << squadra2.golfatti <<endl;
    }
    else if (golsquadra1 < golsquadra2){
        squadra2.partitevinte++;
        squadra2.puntifatti += 3;
        squadra1.partiteperse++;
        cout << squadra2.nome << " Ha vinto " << squadra2.golfatti << "- " << squadra1.golfatti <<endl;
    }
    else{
        squadra1.partitepareggiate++;
        squadra1.puntifatti += 1;
        squadra2.partitepareggiate++;
        squadra2.puntifatti += 1;
        cout << squadra1.nome << " E " << squadra2.nome << "Hanno pareggiato " << squadra1.golfatti << "- " << squadra2.golfatti <<endl;
    };


}


int main(){
    srand(time(nullptr));

    vector<string> nomi = {
        "AN Brescia",
        "Pro Recco",
        "De Akker Bologna",
        "Trieste"
    };
    vector<Team> squadre = {
        
    };

    vector<Partita> calendario = {
        
    };

    generasquadra(nomi, squadre);
    stampasquadra(squadre);
    creacalendario(squadre, calendario);
    simulacampionato(squadre, calendario);

    return 0;
}