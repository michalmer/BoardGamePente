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
};

class real : public gracz 
{
public:
    real();
    void wykonajRuch(char board[19][19]);
};

class komputer : public gracz 
{
public:
    komputer();
    void wykonajRuch(char board[19][19]);
};




#endif
