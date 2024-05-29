#include "rysowaniefunkcji.h"
#include "gracze.h"
#include "ranking.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream> 
#include <cstring> 
#include <windows.h>
#include <stdlib.h>
using namespace std;
void setCursorPosition(int x, int y) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };
    SetConsoleCursorPosition(hStdout, position);
}
void wyswietlwyniki()
{
    char line[256];
    FILE* B = fopen("ranking.txt", "r");
    while (fgets(line, sizeof(line), B))
    {
        printf("%s", line);
    }
    fclose(B);

}
int main()
{
    gracz* gracz1;
    gracz* gracz2;
    char nick1[20];
    char nick2[20];
    char znak;
    int wybor1;
    char wybor2;
    char wybor3;
    char wybor4;
    int wiersz;
    char kolumna;
    int bicia1 = 0;
    int bicia2 = 0;
    char board[19][19];
    ifstream file("ranking.txt");
    if (!file.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku" << endl;
        return 1;
    }
    real players[20];
    int num_players = 0;
    char name[20];
    do
    {
        system("cls");
        //wczytywanie danych o graczach znajdujacych sie w rankingu
        while (file.getline(name, 20, ':')) {
            int ilosc = players[num_players].pokazwygrana();
            file >> ilosc;
            players[num_players].ustawwygrane(ilosc);
            file.ignore();
            players[num_players].ustawnick(name);
            num_players++;
        }
        file.close();

        for (int i = 0; i < 19; ++i) {
            for (int j = 0; j < 19; ++j) {
                board[i][j] = ' ';
            }
        }
        cout << "                                                _____  ______ _   _ _______ ______ \n"
            "                                               |  __ \\|  ____| \\ | |__   __|  ____|\n"
            "                                               | |__) | |__  |  \\| |  | |  | |__   \n"
            "                                               |  ___/|  __| | . ` |  | |  |  __|  \n"
            "                                               | |    | |____| |\\  |  | |  | |____ \n"
            "                                               |_|    |______|_| \\_|  |_|  |______|\n\n\n";
        cout << "                                       |---------------------------------------------------|" << endl;
        printf("                                       |Chcesz grac z komputerem(1) czy innym graczem(2) ? |\n");
        cout << "                                       |---------------------------------------------------|" << endl << endl;
        cout << "                                                               ......." << endl;
        setCursorPosition(66, 12);
        scanf("%d", &wybor1);
        if (wybor1 == 2)
        {
            gracz1 = new real();
            gracz2 = new real();
            gracz1->ustawbicia(0);
            gracz2->ustawbicia(0);
            bicia1 = 0;
            bicia2 = 0;

            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj nick Gracza 1(max 19 znakow)                 |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;

            cout << "                                                               ......." << endl;
            setCursorPosition(63, 17);
            scanf("%s", nick1);
            gracz1->ustawnick(nick1);
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj jakiego znaku chcesz uzywac:                 |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            setCursorPosition(66, 22);
            scanf(" %c", &znak);
            gracz1->ustawznak(znak);
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj nick Gracza 2(max 19 znakow)                 |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            setCursorPosition(63, 27);
            scanf("%s", nick2);
            gracz2->ustawnick(nick2);
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj jakiego znaku chcesz uzywac:                 |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            setCursorPosition(66, 32);
            scanf(" %c", &znak);
            gracz2->ustawznak(znak);
            cout << "                              |-------------------------------------------------------------------------|" << endl;
            printf("                              |Jesli chcesz rozpoczac gre wpisz (T) jesli chcesz zakonczyc gre wpisz(K) |\n");
            cout << "                              |-------------------------------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            setCursorPosition(66, 37);
            scanf(" %c", &wybor2);
            system("cls");
            if (wybor2 == 'T')
            {
                do {
                    system("cls");
                    drawBoard(board);
                    printf("\n%s: ", gracz1->nick);
                    for (int i = 0; i < bicia1; i++)
                    {
                        printf("%c ", 219);
                    }
                    printf("             ");
                    printf("%s: ", gracz2->nick);
                    for (int i = 0; i < bicia2; i++)
                    {
                        printf("%c ", 219);
                    }
                    printf("\n");
                    printf("RUCH GRACZA: %s\n", gracz1->nick);
                    gracz1->wykonajRuch(board);
                    if (gracz1->sprawdzczywygrana(board) == 1)
                    {
                        gracz1->wygrana();
                        update_score(players, num_players, nick1);
                        save_scoreboard(players, num_players);
                        wyswietlwyniki();
                        continue;
                    }
                    gracz1->sprawdzCzyBicie(board);
                    gracz2->sprawdzCzyBicie(board);
                    bicia1 = gracz1->pokazbicia();
                    bicia2 = gracz2->pokazbicia();
                    if (bicia1 == 5)
                    {
                        gracz1->wygrana();
                        update_score(players, num_players, nick1);
                        save_scoreboard(players, num_players);
                        wyswietlwyniki();
                        continue;
                    }
                    if (bicia2 == 5)
                    {
                        gracz2->wygrana();
                        update_score(players, num_players, nick2);
                        save_scoreboard(players, num_players);
                        wyswietlwyniki();
                        continue;
                    }
                    system("cls");
                    drawBoard(board);
                    printf("\n%s: ", gracz1->nick);
                    for (int i = 0; i < bicia1; i++)
                    {
                        printf("%c ", 219);
                    }
                    printf("             ");
                    printf("%s: ", gracz2->nick);
                    for (int i = 0; i < bicia2; i++)
                    {
                        printf("%c ", 219);
                    }
                    printf("\n");
                    printf("RUCH GRACZA: %s\n", gracz2->nick);
                    gracz2->wykonajRuch(board);
                    if (gracz2->sprawdzczywygrana(board) == 1)
                    {
                        gracz2->wygrana();
                        update_score(players, num_players, nick2);
                        save_scoreboard(players, num_players);
                        wyswietlwyniki();
                        continue;
                    }
                    gracz2->sprawdzCzyBicie(board);
                    gracz1->sprawdzCzyBicie(board);
                    bicia1 = gracz1->pokazbicia();
                    bicia2 = gracz2->pokazbicia();
                    if (bicia2 == 5)
                    {
                        gracz2->wygrana();
                        update_score(players, num_players, nick2);
                        save_scoreboard(players, num_players);
                        wyswietlwyniki();
                        continue;
                    }
                    if (bicia1 == 5)
                    {
                        gracz1->wygrana();
                        update_score(players, num_players, nick1);
                        save_scoreboard(players, num_players);
                        wyswietlwyniki();
                        continue;
                    }
                    system("cls");
                    drawBoard(board);






                    printf("Chcesz zrobic kolejny ruch(T) czy zakonczyc gre? (K)");
                    scanf(" %c", &wybor2);

                } while (wybor2 != 'K' && gracz1->stan_wygranej == 0 && gracz2->stan_wygranej == 0);

            }
        }
        else if (wybor1 == 1)
        {
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj poziom trudnosci HARD (H) lub EASY(E)        |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;

            cout << "                                                               ......." << endl;
            setCursorPosition(66, 17);
            scanf(" %c", &wybor4);
            if (wybor4 == 'H')
            {
                gracz2 = new komputerHARD();
            }
            else
            {
                gracz2 = new komputerEASY();
            }
            gracz1 = new real();
            gracz1->ustawbicia(0);
            gracz2->ustawbicia(0);
            bicia1 = 0;
            bicia2 = 0;
            strncpy(nick2, "komputer", 20);
            gracz2->ustawnick("komputer");
            
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj swoj nick (max 19 znakow)                    |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;

            cout << "                                                               ......." << endl;
            setCursorPosition(63, 22);
            scanf("%s", nick1);
            gracz1->ustawnick(nick1);
           
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj jakiego znaku chcesz uzywac:                 |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            setCursorPosition(66, 27);
            scanf(" %c", &znak);
            gracz1->ustawznak(znak);

            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj jakiego znaku ma uzywac komputer:            |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            setCursorPosition(66, 32);
            scanf(" %c", &znak);
            gracz2->ustawznak(znak);
           
            cout << "                              |-------------------------------------------------------------------------|" << endl;
            printf("                              |Jesli chcesz rozpoczac gre wpisz (T) jesli chcesz zakonczyc gre wpisz(K) |\n");
            cout << "                              |-------------------------------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            setCursorPosition(66, 37);
            scanf(" %c", &wybor2);
            system("cls");
            if (wybor2 == 'T')
            {
                do {
                    system("cls");
                    drawBoard(board);
                    printf("\n%s: ", gracz1->nick);
                    for (int i = 0; i < bicia1; i++)
                    {
                        printf("%c", 219);
                    }
                    printf("      ");
                    printf("%s: ", gracz2->nick);
                    for (int i = 0; i < bicia2; i++)
                    {
                        printf("\n%c", 219);
                    }
                    printf("\n");
                    gracz1->wykonajRuch(board);
                    if (gracz1->sprawdzczywygrana(board) == 1)
                    {
                        gracz1->wygrana();
                        update_score(players, num_players, nick1);
                        save_scoreboard(players, num_players);
                        wyswietlwyniki();
                        continue;
                    }
                    gracz1->sprawdzCzyBicie(board);
                    gracz2->sprawdzCzyBicie(board);
                    bicia1 = gracz1->pokazbicia();
                    if (bicia1 == 5)
                    {
                        gracz1->wygrana();
                        update_score(players, num_players, nick1);
                        save_scoreboard(players, num_players);
                        wyswietlwyniki();

                        continue;
                    }
                    system("cls");
                    drawBoard(board);
                    printf("\n%s: ", gracz1->nick);
                    for (int i = 0; i < bicia1; i++)
                    {
                        printf("%c", 219);
                    }
                    printf("      ");
                    printf("\n%s: ", gracz2->nick);
                    for (int i = 0; i < bicia2; i++)
                    {
                        printf("%c", 219);
                    }
                    gracz2->wykonajRuch(board);
                    if (gracz2->sprawdzczywygrana(board) == 1)
                    {
                        gracz1->przegrana();
                        continue;
                    }
                    gracz1->sprawdzCzyBicie(board);
                    gracz2->sprawdzCzyBicie(board);
                    bicia2 = gracz2->pokazbicia();
                    if (bicia2 == 5)
                    {
                        gracz1->przegrana();
                        continue;
                    }
                    system("cls");
                    drawBoard(board);

                    printf("Chcesz zrobic kolejny ruch(T) czy zakonczyc gre? (K)");
                    scanf(" %c", &wybor2);
                    system("cls");
                } while (wybor2 != 'K' && gracz1->stan_wygranej == 0 && gracz2->stan_wygranej == 0);

            }
        }
        printf("Chcesz zagrac jeszcze raz (T) czy chcesz zakonczyc gre? (K)");
        scanf(" %c", &wybor3);
    }while (wybor3 == 'T');
    return 0;
}