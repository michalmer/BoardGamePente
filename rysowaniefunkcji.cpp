#include "rysowaniefunkcji.h"
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

 //Funkcja do rysowania planszy w konsoli
void drawBoard(char board[19][19]) 
{
    HANDLE hOut;
    cout << " _____  ______ _   _ _______ ______ \n"
        "|  __ \\|  ____| \\ | |__   __|  ____|\n"
        "| |__) | |__  |  \\| |  | |  | |__   \n"
        "|  ___/|  __| | . ` |  | |  |  __|  \n"
        "| |    | |____| |\\  |  | |  | |____ \n"
        "|_|    |______|_| \\_|  |_|  |______|\n\n\n";
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_INTENSITY);
    cout << "  ";
    for (int i = 0; i < 19 * 4 + 41; ++i)
        cout << "=";
    cout << "  ";
    cout << "\n";
    
    
    
    cout << "   ";
    for (int i = 0; i < 19; ++i) 
    {
        char znak = 65 + i;
        cout << "   ";
        cout << znak << "  ";
    }
    cout << "    ";
    cout << "\n";
    for (int i = 0; i < 19 * 4 + 45; ++i)
    {
        SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
        if (i < 3 || i > (19 * 4 + 43) - 2)
        {
            SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_INTENSITY);
        }
        cout << "-";
    }
    cout << "\n";
    for (int i = 0; i < 19; ++i) 
    {
        SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_INTENSITY);
        if (i < 9)
            cout << " ";
        cout << i + 1 << " ";
        SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
        cout << "| ";
        for (int j = 0; j < 19; ++j) 
        {
            if (j == 19 - 1)
            {
                cout << " ";
                cout << board[i][j] << flush;
                cout << "  |";
                continue;
            }
            cout << " ";
            cout << board[i][j] << flush;
            cout << " ";
            cout << " | ";
        }
        SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_INTENSITY);
        cout << " ";
        if (i < 9)
            cout << " ";
        cout << i + 1;
        SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
        cout << "\n";
        int temp = 15;
        for (int k = 0; k < 19 * 4 + 45; ++k)
        {
            SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
            if (i == (19 - 1))
            {
                if (k < 3 || k >(19 * 4 + 45) - 4)
                {
                    SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_INTENSITY);
                }
                cout << "-";
                continue;
            }
            if (k < 3 || k >(19 * 4 + 45) - 4)
            {
                SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_INTENSITY);
            }
            if (k == 3 || k== 9)
            {
                cout << "|";
                continue;
            }
            if (k == temp)
            {
                cout << "|";
                temp += 6;
                continue;
            }
            cout << "-";
        }
        cout << "\n";
    }
    SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_INTENSITY);
    cout << "   ";
    for (int i = 0; i < 19; ++i)
    {
        char znak = 65 + i;
        cout << "   ";
        cout << znak << "  ";
    }
    cout << "    ";
    cout << "\n";


    cout << "  ";
    for (int i = 0; i < 19 * 4 + 41; ++i)
    {
        cout << "=";
    }
    printf("  ");
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << "\n\n";
}