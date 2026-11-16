#pragma once

#include <sqlite3.h>
#include "../Team.h"

bool apridatabase();
void chiudidatabase();
bool creaschema();

bool salvasquadre(std::vector<Team>& squadre);
bool caricasquadre(std::vector<Team>& squadre);

bool creastagione(const std::string& nome, const std::string& data_inizio, int& id_stagione);
bool salvastagionesquadre(const std::vector<Team>& squadre, int id_stagione);