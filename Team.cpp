#include "Team.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void generasquadra(const vector<string>&nomi, vector<Team>& squadre){
    for (string nome : nomi){
        Team nuovaSquadra;
        nuovaSquadra.nome = nome;
        nuovaSquadra.attacco = rand() % 51 + 50;
        nuovaSquadra.difesa = rand() % 51 + 50;
        squadre.push_back(nuovaSquadra);
    }
}

void stampasquadra(const vector<Team>& squadre){
    for (auto Team : squadre){
        cout << Team.nome << endl;
        cout << "Attacco: " << Team.attacco << endl;
        cout << "Difesa: " << Team.difesa << endl << endl;
    }
}