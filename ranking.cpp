#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void update_score(gracz players[], int& num_players, const char* name)
{
    int found = 0;
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].nick, name) == 0) {
            // Zwiêkszenie liczby wygranych gracza
            players[i].ilosc_wygranych++;
            found = 1;
            break;
        }
    }
    if (!found) {
        // Dodanie nowego gracza do tablicy
        players[num_players].ustawnick(name);
        players[num_players].ilosc_wygranych = 1;
        num_players++;
    }
}

void save_scoreboard(gracz players[], int num_players) {
    ofstream file("ranking.txt");
    if (!file.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_players; i++) {
        file << players[i].nick << ":" << players[i].ilosc_wygranych << endl;
    }
    file.close();
}