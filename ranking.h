#ifndef ranking_hpp
#define ranking_hpp
#include "gracze.h"

void update_score(real players[], int& num_players, const char* name);
void save_scoreboard(real players[], int num_players);
void Sort(real players[], int num_players);

#endif
