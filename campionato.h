#pragma once

#include "Team.h"
#include <vector>

struct Partita {
    int squadraCasa;
    int squadraTrasferta;
    int giornata;
    bool partitaGiocata = false;
};

void creacalendario(const std::vector<Team>& squadre, std::vector<Partita>& Calendario);
void stampacalendario(const std::vector<Team>& squadre, const std::vector<Partita>& Calendario);
void giocapartita(Team& squadra1, Team& squadra2);
void simulacampionato(std::vector<Team>& squadre, std::vector<Partita>& Calendario);
void stampaclassifica(const std::vector<Team>& squadre);