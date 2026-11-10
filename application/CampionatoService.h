#pragma once

#include "../Team.h"
#include "../campionato.h"
#include <vector>

void inizializzacampionato(
    const std::vector<std::string>& nomi,
    std::vector<Team>& squadre,
    std::vector<Partita>& calendario
);