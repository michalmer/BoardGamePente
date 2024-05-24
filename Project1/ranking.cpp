#define _CRT_SECURE_NO_WARNINGS
#include "ranking.h"
#include "gracze.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void update_score(real players[], int& num_players, const char* name)
{
    int found = 0;
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].nick, name) == 0) {
            // Zwi�kszenie liczby wygranych gracza
            players[i].dodajwygrana();
            found = 1;
            break;
        }
    }
    if (!found) {
        // Dodanie nowego gracza do tablicy
        players[num_players].ustawnick(name);
        players[num_players].ustawwygrane(1);
        num_players++;
    }
}

void save_scoreboard(real players[], int num_players) {
    ofstream file("ranking.txt");
    if (!file.is_open()) {
        cerr << "Nie mo�na otworzy� pliku" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_players; i++) {
        file << players[i].nick << ":" << players[i].pokazwygrana() << endl;
    }
    file.close();
}