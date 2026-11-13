#pragma once

#include <sqlite3.h>
#include "../Team.h"

bool apridatabase();
void chiudidatabase();
bool creaschema();

bool salvasquadre(const std::vector<Team>& squadre);
bool caricasquadre(std::vector<Team>& squadre);