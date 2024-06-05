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
//ustawia pozycje kursora 
void setCursorPosition(int x, int y) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };
    SetConsoleCursorPosition(hStdout, position);
}
//wyswietla wyniki z rankingu
void wyswietlwyniki()
{
    char line[256];
    FILE* B = fopen("ranking.txt", "r");
    if (B == NULL) {
        perror("Blad otwarcia pliku");
    }
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
    int indeks;
    char nick1[20];
    char nick2[20];
    int valid;
    char ch;
    char znak1;
    char znak2;
    int ktory;
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
        indeks = 12;
        do {
            valid = scanf("%d", &wybor1);
            while ((ch = getchar()) != '\n');
            if (valid != 1 || (wybor1 != 1 && wybor1 != 2)) {
                printf("Zly numer! Podaj jeszcze raz (1 lub 2)\n");
                indeks += 2;
            }
        } while (valid != 1 || (wybor1 != 1 && wybor1 != 2));
        if (wybor1 == 2)
        {
            gracz1 = new real();
            gracz2 = new real();
            gracz1->ustawbicia(0);
            gracz2->ustawbicia(0);
            bicia1 = 0;
            bicia2 = 0;
            cout << "                                   |----------------------------------------------------------|" << endl;
            printf("                                   |Podaj nick Gracza 1,ktory zaczyna rozgrywke(max 19 znakow)|\n");
            cout << "                                   |----------------------------------------------------------|" << endl << endl;

            cout << "                                                               ......." << endl;
            indeks += 5;
            setCursorPosition(63, indeks);
            scanf("%s", nick1);
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj jakiego znaku chcesz uzywac:                 |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            indeks += 5;
            setCursorPosition(66, indeks);
            scanf(" %c", &znak1);
            while ((ch = getchar()) != '\n' && ch != EOF);

            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj nick Gracza 2(max 19 znakow)                 |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            indeks += 5;
            setCursorPosition(63, indeks);
            scanf("%s", nick2);
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj jakiego znaku chcesz uzywac:                 |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            indeks += 5;
            setCursorPosition(66, indeks);
            scanf(" %c", &znak2);
            while ((ch = getchar()) != '\n' && ch != EOF);
         
            gracz1->ustawnick(nick1);
            gracz1->ustawznak(znak1);
            gracz2->ustawnick(nick2);
            gracz2->ustawznak(znak2);
            cout << "                        |--------------------------------------------------------------------------------|" << endl;
            printf("                        |Jesli chcesz rozpoczac gre wpisz (T) jesli chcesz zakonczyc gre wpisz inny znak |\n");
            cout << "                        |--------------------------------------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            indeks += 5;
            setCursorPosition(66, indeks);
            do {
                valid = scanf(" %c", &wybor2);
                while ((ch = getchar()) != '\n');
                if (valid != 1 || (wybor2 != 'T' && wybor2 != 'K')) {
                    printf("Zla litera! Podaj jeszcze raz (T lub K)\n");
                    indeks += 2;
                }
            } while (valid != 1 || (wybor2 != 'T' && wybor2 != 'K'));
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
                    Sleep(1000);
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
                    Sleep(1000);
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


                } while (gracz1->stan_wygranej == 0 && gracz2->stan_wygranej == 0);

            }
        }
        else if (wybor1 == 1)
        {
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj poziom trudnosci HARD (H) lub EASY(E)        |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;

            cout << "                                                               ......." << endl;
            indeks += 5;
            setCursorPosition(66, indeks);
            do {
                valid = scanf(" %c", &wybor4);
                while ((ch = getchar()) != '\n');
                if (valid != 1 || (wybor4 != 'H' && wybor4 != 'E')) {
                    printf("Zla litera! Podaj jeszcze raz (H lub E)\n");
                    indeks += 2;
                }
            } while (valid != 1 || (wybor4 != 'H' && wybor4 != 'E'));
            
            cout << "                                       |------------------------------------------------------|" << endl;
            printf("                                       |Podaj kto ma zaczynac pierwszy,ty(1) czy komputer(2): |\n");
            cout << "                                       |------------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            indeks += 5;
            setCursorPosition(66, indeks);
            do {
                valid = scanf("%d", &ktory);
                while ((ch = getchar()) != '\n');
                if (valid != 1 || (ktory != 1 && ktory != 2)) {
                    printf("Zly numer gracza! Podaj jeszcze raz (1 lub 2)\n");
                    indeks += 2;
                }
            } while (valid != 1 || (ktory != 1 && ktory != 2));
            if (ktory == 1)
            {
                gracz1 = new real();
                if (wybor4 == 'H')
                {
                    gracz2 = new komputerHARD();
                }
                else
                {
                    gracz2 = new komputerEASY();
                }
            }
            else if (ktory == 2)
            {
                gracz2 = new real();
                if (wybor4 == 'H')
                {
                    gracz1 = new komputerHARD();
                }
                else
                {
                    gracz1 = new komputerEASY();
                }
            }
            else
            {
                gracz1 = new real();
                gracz2 = new komputerEASY();
            }
            gracz1->ustawbicia(0);
            gracz2->ustawbicia(0);
            bicia1 = 0;
            bicia2 = 0;
            strncpy(nick2, "komputer", 20);
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj swoj nick (max 19 znakow)                    |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;

            cout << "                                                               ......." << endl;
            indeks += 5;
            setCursorPosition(63, indeks);
            scanf("%s", nick1);
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj jakiego znaku chcesz uzywac:                 |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            indeks += 5;
            setCursorPosition(66, indeks);
            scanf(" %c", &znak1);
            while ((ch = getchar()) != '\n' && ch != EOF);
            cout << "                                       |---------------------------------------------------|" << endl;
            printf("                                       |Podaj jakiego znaku ma uzywac komputer:            |\n");
            cout << "                                       |---------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            indeks += 5;
            setCursorPosition(66, indeks);
            scanf(" %c", &znak2);
            while ((ch = getchar()) != '\n' && ch != EOF);
            if (ktory == 1)
            {
                gracz1->ustawnick(nick1);
                gracz1->ustawznak(znak1);
                gracz2->ustawnick("komputer");
                gracz2->ustawznak(znak2);
            }
            else if (ktory == 2)
            {
                gracz1->ustawnick("komputer");
                gracz1->ustawznak(znak2);
                gracz2->ustawnick(nick1);
                gracz2->ustawznak(znak1);
            }
            cout << "                        |--------------------------------------------------------------------------------|" << endl;
            printf("                        |Jesli chcesz rozpoczac gre wpisz (T) jesli chcesz zakonczyc gre wpisz inny znak |\n");
            cout << "                        |--------------------------------------------------------------------------------|" << endl << endl;
            cout << "                                                               ......." << endl;
            indeks += 5;
            setCursorPosition(66, indeks);
            scanf(" %c", &wybor2);
            while ((ch = getchar()) != '\n' && ch != EOF);
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
                    Sleep(1000);
                    gracz1->wykonajRuch(board);
                    if (gracz1->sprawdzczywygrana(board) == 1)
                    {
                        if (ktory == 1)
                        {
                            gracz1->wygrana();
                            continue;
                        }
                        gracz1->przegrana();
                        continue;
                    }
                    gracz1->sprawdzCzyBicie(board);
                    gracz2->sprawdzCzyBicie(board);
                    bicia1 = gracz1->pokazbicia();
                    bicia2 = gracz2->pokazbicia();
                    if (bicia1 == 5)
                    {
                        if (ktory == 1)
                        {
                            gracz1->wygrana();
                            continue;
                        }
                        gracz1->wygrana();
                        continue;
                    }
                    if (bicia2 == 5)
                    {
                        if (ktory == 1)
                        {
                            gracz1->przegrana();
                            continue;
                        }
                        gracz1->wygrana();
                        continue;
                    }
                    system("cls");
                    drawBoard(board);
                    printf("\n%s: ", gracz1->nick);
                    for (int i = 0; i < bicia1; i++)
                    {
                        printf("%c ", 219);
                    }
                    printf("      ");
                    printf("%s: ", gracz2->nick);
                    for (int i = 0; i < bicia2; i++)
                    {
                        printf("%c ", 219);
                    }
                    printf("\n");
                    printf("RUCH GRACZA: %s\n", gracz2->nick);
                    Sleep(1000);
                    gracz2->wykonajRuch(board);
                    if (gracz2->sprawdzczywygrana(board) == 1)
                    {
                        if (ktory == 2)
                        {
                            gracz2->wygrana();
                            continue;
                        }
                        gracz2->przegrana();
                        continue;
                    }
                    gracz1->sprawdzCzyBicie(board);
                    gracz2->sprawdzCzyBicie(board);
                    bicia1 = gracz1->pokazbicia();
                    bicia2 = gracz2->pokazbicia();
                    if (bicia1 == 5)
                    {
                        if (ktory == 1)
                        {
                            gracz1->wygrana();
                            continue;
                        }
                        gracz1->wygrana();
                        continue;
                    }
                    if (bicia2 == 5)
                    {
                        if (ktory == 1)
                        {
                            gracz1->przegrana();
                            continue;
                        }
                        gracz1->wygrana();
                        continue;
                    }
                    system("cls");
                    drawBoard(board);

                    system("cls");
                } while (gracz1->stan_wygranej == 0 && gracz2->stan_wygranej == 0);

            }
        }
        printf("Chcesz zagrac jeszcze raz (T) czy chcesz zakonczyc gre? (inny znak z klawiatury)");
        scanf(" %c", &wybor3);
    }while (wybor3 == 'T');
    return 0;
}