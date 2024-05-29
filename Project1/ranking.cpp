#define _CRT_SECURE_NO_WARNINGS
#include "ranking.h"
#include "gracze.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//funkcja sortuje tablice wynikow malejaco
void Sort(real players[], int num_players) {
    for (int i = 1; i < num_players; ++i) 
    {
        real temp = players[i];
        int j = i - 1;

        while (j >= 0 && players[j].pokazwygrana() < temp.pokazwygrana()) {
            players[j + 1] = players[j];
            j = j - 1;
        }
        players[j + 1] = temp;
    }
}


//funkcja aktualizuje tabele wynikow poprzez dodanie nowych graczy lub zmiane wyniku istniejacym
void update_score(real players[], int& num_players, const char* name)
{
    int found = 0;
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].nick, name) == 0) {
            // Zwiêkszenie liczby wygranych gracza
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
    int max = INT_MAX;
    for (int i = 0; i < num_players; i++)
    {
        if (players[i].pokazwygrana() > max)
        {

        }
    }
    Sort(players, num_players);
}
//funkcja zapisuje tabele wynikow do pliku tekstowego
void save_scoreboard(real players[], int num_players) {
    ofstream file("ranking.txt");
    if (!file.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_players; i++) {
        file << players[i].nick << ":" << players[i].pokazwygrana() << endl;
    }
    file.close();
}

