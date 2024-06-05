#define _CRT_SECURE_NO_WARNINGS
#include "gracze.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//metoda do dodawania bicia
void gracz::dodajbicie() 
{
    ile_bic++;
}
//metoda do zwracania ilosci bic
int gracz::pokazbicia()
{
    return ile_bic;
}
//metoda do ustawiania ilosci bic
void gracz :: ustawbicia(int bicia)
{
    ile_bic = bicia;
}
//konstruktor domyslny dla gracz
gracz::gracz() : ilosc_wygranych(0), ile_bic(0), stan_wygranej(0),nick("default"),znak('X') {}

//Metoda wypisuje na ekranie napis WYGRALES korzystajac ze znakow ASCII
void gracz::wygrana() 
{
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
//Metoda wypisuje na ekranie napis PRZEGRALES korzystajac ze znakow ASCII
void gracz::przegrana()
{
    ilosc_wygranych++;
    stan_wygranej = 1;
    std::cout << "  _____                              _           \n";
    std::cout << " |  __ \\                            | |          \n";
    std::cout << " | |__) | __ _______  __ _ _ __ __ _| | ___  ___ \n";
    std::cout << " |  ___/ '__|_  / _ \\/ _` | '__/ _` | |/ _ \\/ __|\n";
    std::cout << " | |   | |   / /  __/ (_| | | | (_| | |  __/\\__ \\\n";
    std::cout << " |_|   |_|  /___\\___|\\__, |_|  \\__,_|_|\\___||___/\n";
    std::cout << "                      __/ |                      \n";
    std::cout << "                     |___/                       \n";


}
//metoda ustawia znak gracza
void gracz::ustawznak(char z)
{
    znak = z;
}
//metoda ustawia nick gracza
void gracz::ustawnick(const char* nazwa)
{
    strncpy(nick, nazwa, 19);
    nick[19] = '\0';
}
//Metoda zmienia kolumne zapisana jako litere alfabetu na cyfre
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
//Metoda sprawdza czy istnieje bicie pionow wroga poprzez otoczenie go z dwoch stron
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
//Metoda sprawdza czy istnieje 5 pionkow gracza ustawionych pionowo,poziomo lub na skos, co zapewnia natychmiastowa wygrana
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
//metoda dodaje wygrana 
void gracz::dodajwygrana()
{
    ilosc_wygranych++;
}
//metoda zwraca ilosc wygranych
int gracz:: pokazwygrana()
{
    return ilosc_wygranych;
}
//metoda ustawia ilosc wygranych
void gracz::ustawwygrane(int wygrane)
{
    ilosc_wygranych = wygrane;
}
//funkcja czysci bufor
void WyczyscBufor() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//funkcja sprawdza czy wiersz jest poprawny
int czyPoprawnyWiersz(int wiersz) 
{
    return wiersz >= 1 && wiersz <= 19;
}
// Funkcja sprawdzaj¹ca poprawnoœæ kolumny
int czyPoprawnaKolumna(char kolumna) 
{
    return kolumna >= 'A' && kolumna <= 'S';
}
//Metoda stawia znak klasy gracz na danym polu planszy, jesli to pole jest puste i istnieje
void real::wykonajRuch(char board[19][19])
{
    char input[100];
    int wiersz;
    char kolumna;
    int c;
   /* if (input[strlen(input) - 1] != '\n')
    {
        WyczyscBufor();
    }*/
    while (1)
    {
        printf("Podaj wiersz i kolumne: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            WyczyscBufor();
            continue;
        }

        // Usuniêcie nowej linii z koñca wejœcia, jeœli istnieje
        char* nowalinia = strchr(input, '\n');
        if (nowalinia) {
            *nowalinia = '\0';
        }
        else 
        {
            WyczyscBufor();
        }

        if (sscanf(input, "%d%c", &wiersz, &kolumna) != 2 || !czyPoprawnyWiersz(wiersz) || !czyPoprawnaKolumna(kolumna)) {
            printf("Pole niepoprawne: %s\n", input);
            continue;
        }
        if ((board[wiersz - 1][zmianakolumna(kolumna)] != ' '))
        {
            printf("Ta pozycja jest zajeta!");
            continue;
        }
        board[wiersz - 1][zmianakolumna(kolumna)] = znak;
        break;
    }
}
//konstruktor domyslny tworzacy obiekt real
real :: real() : gracz() {}
//Funkcja sprawdza czy da sie zablokowac przeciwnika poprzez zablokowanie mu mozliwosci postawienia piatego pionka(natychmiastowa wygrana)
bool blokuj_przeciwnika(char plansza[19][19], char znak) 
{
    const int rozmiar = 19;

    for (int i = 0; i < rozmiar; ++i) 
    {
        for (int j = 0; j < rozmiar; ++j) 
        {
            //POZIOMO
            if (j <= rozmiar - 5 && sprawdz_ciag(plansza, i, j, 0, 1, znak)) 
            {
                if (ustaw_znak(plansza, i, j - 1, znak) || ustaw_znak(plansza, i, j + 3, znak))
                {
                    return true;
                }
            }
            //PIONOWO
            if (i <= rozmiar - 5 && sprawdz_ciag(plansza, i, j, 1, 0,znak)) 
            {
                if (ustaw_znak(plansza, i - 1, j, znak) || ustaw_znak(plansza, i + 3, j, znak))
                {
                    return true;
                }
            }
            //UKOS DOL
            if (i <= rozmiar - 5 && j <= rozmiar - 5 && sprawdz_ciag(plansza, i, j, 1, 1, znak)) 
            {
                if (ustaw_znak(plansza, i - 1, j - 1, znak) || ustaw_znak(plansza, i + 3, j + 3, znak))
                {
                    return true;
                }
            }
            //UKOS GORA
            if (i >= 4 && j <= rozmiar - 5 && sprawdz_ciag(plansza, i, j, -1, 1, znak)) 
            {
                if (ustaw_znak(plansza, i + 1, j - 1, znak) || ustaw_znak(plansza, i - 3, j + 3, znak))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
//Funkcja sprawdza czy istnieje 5 elementowy ciag znakow w zadanym kierunku na planszy
bool sprawdz_ciag(char plansza[19][19], int x, int y, int dx, int dy, char znak) 
{
    for (int k = 0; k < 3; ++k) {
        if (plansza[x + k * dx][y + k * dy] == ' ' || plansza[x + k * dx][y + k * dy] == znak)
        {
            return false;
        }
    }
    return true;
}
//funkcja ustawia znak na planszy jesli miejsce jest puste
bool ustaw_znak(char plansza[19][19], int x, int y, char znak) {
    const int rozmiar = 19;
    if (x >= 0 && x < rozmiar && y >= 0 && y < rozmiar && plansza[x][y] == ' ') 
    {
        plansza[x][y] = znak;
        return true;
    }
    return false;
}
//funkcja ustawia losowy ruch, jesli nie zachodzi potrzeba zablokowania drugiego gracza
void losowy_ruch(char plansza[19][19], int& x, int& y, char znak) 
{
    const int rozmiar = 19;
    do 
    {
        x = rand() % rozmiar;
        y = rand() % rozmiar;
    } while (plansza[x][y] != ' ');
}

//Metoda umieszcza na polu planszy znak klasy gracza korzystajac z funkcji pomocniczych,wariant z uzyciem strategii
void komputerHARD :: wykonajRuch(char plansza[19][19]) 
{
    const int rozmiar = 19;
    int k,l;
    if (blokuj_przeciwnika(plansza,znak)) 
    {
        return;
    }
    else
    {
        for (int i = 0; i < 19; i++)
        {
            for (int j = 0; j < 19; j++)
            {
                k = i;
                l = j;
                if (plansza[i][j] == znak)
                {

                    while (plansza[k + 1][j] != ' ' && k < 19)
                    {
                        k++;
                    }
                    if (k < 19)
                    {
                        if ((plansza[k][j] != ' ' && plansza[k][j] != znak) && (plansza[k + 3][j] != ' ' && plansza[k + 3][j] != znak))
                        {
                            int x, y;
                            losowy_ruch(plansza, x, y, znak);
                            plansza[x][y] = znak;
                            return;
                        }
                        if (k + 1 < 19)
                        {
                            plansza[k + 1][j] = znak;
                            return;
                        }
                    }
                    while (plansza[i][l + 1] != ' ' && l < 19)
                    {
                        l++;
                    }
                    if (l < 19)
                    {
                        if ((plansza[i][l] != ' ' && plansza[i][l] != znak) && (plansza[i][l + 3] != ' ' && plansza[i][l + 3] != znak))
                        {
                            int x, y;
                            losowy_ruch(plansza, x, y, znak);
                            plansza[x][y] = znak;
                            return;
                        }
                        if (l + 1 < 19)
                        {
                            plansza[i][l + 1] = znak;
                            return;
                        }
                    }
                }

            }
        }
    }
    int x, y;
    losowy_ruch(plansza, x, y,znak);
    plansza[x][y] = znak;
}

//konstruktor domyslny tworzacy obiekt komputerHARD
komputerHARD :: komputerHARD() : gracz() {}
//konstruktor domyslny tworzacy obiekt komputerEASY
komputerEASY :: komputerEASY() : gracz() {}

//Metoda umieszcza na polu planszy znak klasy gracza,wariant wykorzystujacy wylacznie liczby pseudolosowe
void komputerEASY ::wykonajRuch(char board[19][19])
{
    srand(time(NULL));
    int wiersz = rand() % 19 + 1;
    char kolumna = 'A' + (rand() % 19);
    board[wiersz - 1][zmianakolumna(kolumna)] = znak;
}