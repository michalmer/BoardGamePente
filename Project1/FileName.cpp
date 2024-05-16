#include "rysowaniefunkcji.h"
#include "gracze.h"
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

int main()
{
    gracz* gracz1;
    gracz* gracz2;
    char nick[20];
    char znak;
    int wybor1;
    char wybor2;
    int wiersz;
    char kolumna;
    char board[19][19];
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
         cout << "                                       |---------------------------------------------------|"<<endl;
    printf("                                       |Chcesz grac z komputerem(1) czy innym graczem(2) ? |\n");
    cout << "                                       |---------------------------------------------------|"<<endl<<endl;
    cout << "                                                               ......." << endl;
    setCursorPosition(66, 12);
    scanf("%d", &wybor1);
    if (wybor1 == 2)
    {
        gracz1 = new real();
        gracz2 = new real();

        cout << "                                       |---------------------------------------------------|" << endl;
        printf("                                       |Podaj nick Gracza 1(max 19 znakow)                 |\n");
        cout << "                                       |---------------------------------------------------|" << endl<<endl;

        cout << "                                                               ......." << endl;
        setCursorPosition(63, 17);
        scanf("%s", nick);
        gracz1->ustawnick(nick);
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
        scanf("%s", nick);
        gracz2->ustawnick(nick);
        cout << "                                       |---------------------------------------------------|" << endl;
        printf("                                       |Podaj jakiego znaku chcesz uzywac:                 |\n");
        cout << "                                       |---------------------------------------------------|" << endl << endl;
        cout << "                                                               ......." << endl;
        setCursorPosition(66, 32);
        scanf(" %c", &znak);
        gracz2->ustawznak(znak);
        cout << "                              |---------------------------------------------------------------------|" << endl;
        printf("                              |Jesli chcesz zaczac gre wpisz (T) jesli chcesz zakonczyc gre wpisz(K)|\n");
        cout << "                              |---------------------------------------------------------------------|" << endl << endl;
        cout << "                                                               ......." << endl;
        setCursorPosition(66, 37);
        scanf(" %c", &wybor2);
        system("cls");
        if (wybor2 == 'T')
        {
            do {
                system("cls");
                drawBoard(board);
                gracz1->wykonajRuch(board);
                gracz1->sprawdzCzyBicie(board);
                system("cls");
                drawBoard(board);
                gracz2->wykonajRuch(board);
                gracz1->sprawdzCzyBicie(board);
                system("cls");
                drawBoard(board);






                printf("Chcesz zrobic kolejny ruch(T) czy zakonczyc gre? (K)");
                scanf(" %c", &wybor2);

            } while (wybor2 != 'K' && gracz1->stan_wygranej == 0 && gracz2->stan_wygranej == 0);

        }
    }
    else if (wybor1 == 1)
    {
        gracz1 = new real();
        gracz2 = new komputer();
        gracz2->ustawnick("komputer");
        printf("Podaj swoj nick: (max 19 znakow)");
        scanf("%s", nick);
        gracz1->ustawnick(nick);
        printf("Podaj jakiego znaku chcesz uzywac: ");
        scanf(" %c", &znak);
        gracz1->ustawznak(znak);
        printf("Podaj jakiego znaku ma uzywac komputer: ");
        scanf(" %c", &znak);
        gracz2->ustawznak(znak);
        printf("Jesli chcesz zaczac gre wpisz (T) jesli chcesz zakonczyc gre wpisz(K)");
        scanf(" %c", &wybor2);
        system("cls");
        if (wybor2 == 'T')
        {
            do {
                system("cls");
                drawBoard(board);
                gracz1->wykonajRuch(board);
                system("cls");
                drawBoard(board);
                gracz2->wykonajRuch(board);
                system("cls");
                drawBoard(board);






                printf("Chcesz zrobic kolejny ruch(T) czy zakonczyc gre? (K)");
                scanf(" %c", &wybor2);

            } while (wybor2 != 'K' && gracz1->stan_wygranej == 0 && gracz2->stan_wygranej == 0);

        }
    }

    return 0;
}