#pragma once

#include "../Team.h"
#include "../campionato.h"
#include <vector>

void inizializzacampionato(std::vector<Team>& squadre, std::vector<Partita>& calendario);

void eseguisimulazione(std::vector<Team>& squadre, std::vector<Partita>& calendario);

std::vector<Team> ottieniclassifica(const std::vector<Team>& squadre);