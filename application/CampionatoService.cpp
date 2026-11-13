#include "CampionatoService.h"

void inizializzacampionato(std::vector<Team>& squadre, std::vector<Partita>& calendario) {
    creacalendario(squadre, calendario);
}

void eseguisimulazione(std::vector<Team>& squadre, std::vector<Partita>& calendario) {
    simulacampionato(squadre, calendario);
}

std::vector<Team> ottieniclassifica(const std::vector<Team>& squadre) {
    return calcolaclassifica(squadre);
}