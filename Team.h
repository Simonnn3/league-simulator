#pragma once

#include <string>
#include <vector>

struct Team {
    std::string nome;
    int attacco = 0;
    int difesa = 0;
    int partitegiocate = 0;
    int partitevinte = 0;
    int partitepareggiate = 0;
    int partiteperse = 0;
    int puntifatti = 0;
    int golfatti = 0;
    int golsubiti = 0;
};

void generasquadra(const std::vector<std::string>& nomi, std::vector<Team>& squadre);
void stampasquadra(const std::vector<Team>& squadre);