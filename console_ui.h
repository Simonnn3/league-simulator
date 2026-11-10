#pragma once

#include "Team.h"
#include "campionato.h"
#include <vector>

void stampasquadra(const std::vector<Team>& squadre);
void stampacalendario(const std::vector<Team>& squadre, const std::vector<Partita>& Calendario);
void stampaclassifica(const std::vector<Team>& classifica);