#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;
random_device rd;
mt19937 generatore(rd());

struct Team {

    string nome;
    int attacco;
    int difesa;
};

void generasquadra(const vector<string>&nomi, vector<Team>& squadre){
    for (string nome : nomi){
        Team nuovaSquadra;
        nuovaSquadra.nome = nome;
        nuovaSquadra.attacco = rand() % 51 + 50;
        nuovaSquadra.difesa = rand() % 51 + 50;
        squadre.push_back(nuovaSquadra);
    }
};


int main(){
    vector<string> nomi = {
        "AN Brescia",
        "Pro Recco",
        "De Akker Bologna",
        "Trieste"
    };
    vector<Team> squadre = {

    };

    generasquadra(nomi, squadre);

    return 0;
}