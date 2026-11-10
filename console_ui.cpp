#include "console_ui.h"
#include <iostream>

using namespace std;

void stampasquadra(const vector<Team>& squadre){
      for (const Team& squadra : squadre){
        cout << squadra.nome << endl;
        cout << "Attacco: " << squadra.attacco << endl;
        cout << "Difesa: " << squadra.difesa << endl << endl;
    }
}

void stampacalendario (const vector<Team>& squadre, const vector<Partita>& Calendario){
    int numeroGiornate = 0;

    for (const Partita& partita : Calendario) {
        if (partita.giornata > numeroGiornate) {
            numeroGiornate = partita.giornata;
        }
    }

    for (int giornata = 1; giornata <= numeroGiornate; giornata++) {
        cout << endl << "GIORNATA " << giornata << ":" << endl;

        for (const Partita& partita : Calendario) {
            if (partita.giornata == giornata) {
                cout << squadre[partita.squadraCasa].nome << " - " << squadre[partita.squadraTrasferta].nome;

                if (partita.partitaGiocata) {
                    cout << ": " << partita.golCasa << " - " << partita.golTrasferta;
                }

                cout << endl;
            }
        }
    }
}

void stampaclassifica(const vector<Team>& classifica){
    
    cout << "CLASSIFICA FINALE" <<endl;

     for (int i = 0; i < classifica.size(); i++) {
        cout << i + 1 << ". " << classifica[i].nome << " - " << classifica[i].puntifatti << " punti" << endl;
    }
}