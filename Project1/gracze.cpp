#define _CRT_SECURE_NO_WARNINGS
#include "gracze.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void gracz::dodajbicie() {
    ile_bic++;
}
int gracz::pokazbicia()
{
    return ile_bic;
}
gracz::gracz() : ilosc_wygranych(0), ile_bic(0), stan_wygranej(0),nick("default"),znak('X') {}

void gracz::wygrana() {
    ilosc_wygranych++;
    stan_wygranej = 1;
    std::cout << " __          ____     _______ _____            _      ______  _____ \n";
    std::cout << " \\ \\        / /\\ \\   / / ____|  __ \\     /\\   | |    |  ____|/ ____|\n";
    std::cout << "  \\ \\  /\\  / /  \\ \\_/ / |  __| |__) |   /  \\  | |    | |__  | (___  \n";
    std::cout << "   \\ \\/  \\/ /    \\   /| | |_ |  _  /   / /\\ \\ | |    |  __|  \\___ \\ \n";
    std::cout << "    \\  /\\  /      | | | |__| | | \\ \\  / ____ \\| |____| |____ ____) |\n";
    std::cout << "     \\/  \\/       |_|  \\_____|_|  \\_\\/_/    \\_\\______|______|_____/ \n";
    std::cout << "                                                                     \n";
    std::cout << "                                                                   \n";
    printf("GRATULACJE %s\n\n", nick);
}
void gracz::ustawznak(char z)
{
    znak = z;
}
void gracz::ustawnick(const char* nazwa)
{
    strncpy(nick, nazwa, 19);
    nick[19] = '\0';
}
int gracz::zmianakolumna(char kolumna) 
{
    int i = 0;
    char temp = 'A';
    while (temp != kolumna) {
        temp++;
        i++;
        if (temp == kolumna) {
            return i;
        }
    }
    return i;
}
void gracz::sprawdzCzyBicie(char board[19][19])
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (board[i][j] == znak)
            {
                //PIONOWO
                if ((i + 3 < 18) && board[i+3][j] == znak && (board[i+1][j] != ' ' && board[i + 1][j] != znak) && (board[i+2][j] != ' ' && board[i + 2][j] != znak))
                {
                    ile_bic++;
                    board[i + 1][j] = ' ';
                    board[i + 2][j] = ' ';
                }
                if ((i - 3 > 0) && board[i - 3][j] == znak && (board[i - 1][j] != ' ' && board[i - 1][j] != znak) && (board[i - 2][j] != ' ' && board[i - 2][j] != znak))
                {
                    ile_bic++;
                    board[i - 1][j] = ' ';
                    board[i - 2][j] = ' ';

                }
                //POZIOMO
                if ((j + 3 < 18) && board[i][j+3] == znak && (board[i][j+1] != ' ' && board[i][j + 1] != znak) && (board[i][j+2] != ' ' && board[i][j + 2] != znak))
                {
                    ile_bic++;
                    board[i][j + 1] = ' ';
                    board[i][j + 2] = ' ';
                }
                if ((j - 3 > 0) && board[i][j-3] == znak && (board[i][j-1] != ' ' && board[i][j - 1] != znak) && (board[i][j - 2] != ' ' && board[i][j - 2] != znak))
                {
                    ile_bic++;
                    board[i][j - 1] = ' ';
                    board[i][j - 2] = ' ';
                }
                //NA SKOS
                if ((i + 3 < 18 && j + 3 < 18) && board[i + 3][j + 3] == znak && (board[i + 1][j + 1] != ' ' && board[i + 1][j + 1] != znak) && (board[i + 2][j + 2] != ' ' && board[i + 2][j + 2] != znak))
                {
                    ile_bic++;
                    board[i + 1][j + 1] = ' ';
                    board[i + 2][j + 2] = ' ';
                }
                if ((i - 3 < 18 && j - 3 < 18) && board[i - 3][j - 3] == znak && (board[i - 1][j - 1] != ' ' && board[i - 1][j - 1] != znak) && (board[i - 2][j - 2] != ' ' && board[i - 2][j - 2] != znak))
                {
                    ile_bic++;
                    board[i - 1][j - 1] = ' ';
                    board[i - 2][j - 2] = ' ';
                }
                if ((i + 3 < 18 && j - 3 < 18) && board[i + 3][j - 3] == znak && (board[i + 1][j - 1] != ' ' && board[i + 1][j - 1] != znak) && (board[i + 2][j - 2] != ' ' && board[i + 2][j - 2] != znak))
                {
                    ile_bic++;
                    board[i + 1][j - 1] = ' ';
                    board[i + 2][j - 2] = ' ';
                }
                if ((i - 3 < 18 && j + 3 < 18) && board[i - 3][j + 3] == znak && (board[i + 1][j - 1] != ' ' && board[i + 1][j - 1] != znak) && (board[i - 2][j + 2] != ' ' && board[i - 2][j + 2] != znak))
                {
                    ile_bic++;
                    board[i - 1][j + 1] = ' ';
                    board[i - 2][j + 2] = ' ';
                }

            }
        }
    }
}
int gracz::sprawdzczywygrana(char board[19][19])
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            //PIONOWO
            if (board[i][j] == znak && board[i - 1][j] == znak && board[i - 2][j] == znak && board[i - 3][j] == znak && board[i - 4][j] == znak)
            {
                return 1;
            }
            //POZIOMO
            if (board[i][j] == znak && board[i][j+1] == znak && board[i][j+2] == znak && board[i][j+3] == znak && board[i][j+4] == znak)
            {
                return 1;
            }
            //NA SKOS
            if (board[i][j] == znak && board[i - 1][j+1] == znak && board[i - 2][j+2] == znak && board[i - 3][j+3] == znak && board[i - 4][j+4] == znak)
            {
                return 1;
            }
            if (board[i][j] == znak && board[i + 1][j + 1] == znak && board[i + 2][j + 2] == znak && board[i + 3][j + 3] == znak && board[i + 4][j + 4] == znak)
            {
                return 1;
            }
        }
    }
}
void gracz::zapiszwynik()
{
    FILE* A = fopen("ranking.txt", "r+");
    fprintf(A, "Nick gracza: %s, Wygrane rundy: %d", nick, ilosc_wygranych);
    fclose(A);
}
void gracz::dodajwygrana()
{
    ilosc_wygranych++;
}
int gracz:: pokazwygrana()
{
    return ilosc_wygranych;
}
void gracz::ustawwygrane(int wygrane)
{
    ilosc_wygranych = wygrane;
}
void real::wykonajRuch(char board[19][19])
{
    int wiersz;
    char kolumna;
    printf("Podaj wiersz i kolumne: ");
    scanf("%d", &wiersz);
    scanf(" %c", &kolumna);
    if (wiersz < 0 || (kolumna < 'A' || kolumna > 'S'))
    {
        
        do{
            while (getchar() != '\n') {
                continue;
            }
            printf("Ta pozycja nie istnieje! Podaj nowa pozycje!");
            printf("Podaj wiersz i kolumne: ");
            scanf("%d", &wiersz);
            scanf(" %c", &kolumna);
        } while (wiersz < 0 || (kolumna < 'A' || kolumna > 'S'));
    }
    if (board[wiersz - 1][zmianakolumna(kolumna)] != ' ')
    {
        while (board[wiersz - 1][zmianakolumna(kolumna)] != ' ')
        {
            printf("Ta pozycja jest zajeta! Podaj nowa pozycje!");
            printf("Podaj wiersz i kolumne: ");
            scanf("%d", &wiersz);
            scanf(" %c", &kolumna);
        }
        board[wiersz - 1][zmianakolumna(kolumna)] = znak;
    }
    else
    {
        board[wiersz - 1][zmianakolumna(kolumna)] = znak;

    }
}
real :: real() : gracz() {}
void komputer::wykonajRuch(char board[19][19])
{
    int wiersz = rand() % 19 + 1;
    char kolumna = 'A' + (rand() % 19);
    board[wiersz - 1][zmianakolumna(kolumna)] = znak;
}
komputer :: komputer() : gracz() {}