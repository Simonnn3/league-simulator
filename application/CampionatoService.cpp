#include "CampionatoService.h"

void inizializzacampionato(const std::vector<std::string>& nomi, std::vector<Team>& squadre, std::vector<Partita>& calendario) {
    generasquadra(nomi, squadre);
    creacalendario(squadre, calendario);
}

void eseguisimulazione(std::vector<Team>& squadre, std::vector<Partita>& calendario) {
    simulacampionato(squadre, calendario);
}

std::vector<Team> ottieniclassifica(const std::vector<Team>& squadre) {
    return calcolaclassifica(squadre);
}