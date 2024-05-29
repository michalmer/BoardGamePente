#ifndef gracze_hpp
#define gracze_hpp

class gracz 
{
    int ilosc_wygranych;
    int ile_bic;

public:
    int stan_wygranej;
    char nick[20];
    char znak;
    void dodajbicie();
    void wygrana();
    void przegrana();
    virtual void wykonajRuch(char board[19][19]) = 0;
    int zmianakolumna(char kolumna);
    void ustawznak(char z);
    void ustawnick(const char* nazwa);
    gracz();
    void sprawdzCzyBicie(char board[19][19]);
    int pokazbicia();
    int sprawdzczywygrana(char board[19][19]);
    void zapiszwynik();
    void dodajwygrana();
    int pokazwygrana();
    void ustawwygrane(int wygrane);
    void ustawbicia(int bicia);
};

class real : public gracz 
{
public:
    real();
    void wykonajRuch(char board[19][19]);
};

class komputerHARD : public gracz 
{
public:
    komputerHARD();
    void wykonajRuch(char board[19][19]);
};
bool blokuj_przeciwnika(char plansza[19][19], char znak);
bool sprawdz_ciag(char plansza[19][19], int x, int y, int dx, int dy, char znak);
bool ustaw_znak(char plansza[19][19], int x, int y, char znak);
void losowy_ruch(char plansza[19][19], int& x, int& y, char znak);


class komputerEASY : public gracz
{
public:
    komputerEASY();
    void wykonajRuch(char board[19][19]);
};

#endif
