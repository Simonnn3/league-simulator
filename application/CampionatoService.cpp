#include "CampionatoService.h"

void inizializzacampionato(
    const std::vector<std::string>& nomi,
    std::vector<Team>& squadre,
    std::vector<Partita>& calendario
) {
    generasquadra(nomi, squadre);
    creacalendario(squadre, calendario);
}