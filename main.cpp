#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <locale.h>

using namespace std;

string generuj_haslo(int dlugosc, bool duze_litery, bool znaki_specjalne, bool numery) {
    string haslo = "";
    string litery_male = "abcdefghijklmnopqrstuvwxyz";
    string litery_duze = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string znaki = "!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/";
    string cyfry = "0123456789";
    string dostepne_znaki = "";

    if (duze_litery)
        dostepne_znaki += litery_duze;
    else
        dostepne_znaki += litery_male;

    if (znaki_specjalne)
        dostepne_znaki += znaki;

    if (numery)
        dostepne_znaki += cyfry;

    srand(time(NULL));

    for (int i = 0; i < dlugosc; i++) {
        int losowy_indeks = rand() % dostepne_znaki.length();
        haslo += dostepne_znaki[losowy_indeks];
    }

    return haslo;
}

int main() {
    setlocale(LC_CTYPE, "Polish");

    cout << "Twórca: Mariusz Mann 2AP" << endl;

    string imie, nazwisko, stanowisko;
    bool duze_litery = false, znaki_specjalne = false, numery = false, dlugosc_hasla = false;
    int dlugosc = 0;

    cout << "Podaj imię: ";
    cin >> imie;

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;

    cout << "Podaj stanowisko: ";
    cin >> stanowisko;

    char wybor;

    cout << "Czy chcesz dodaæ opcję Duże Litery? (Y/N): ";
    cin >> wybor;

    if (wybor == 'Y' || wybor == 'y')
        duze_litery = true;

    cout << "Czy chcesz dodać opcję Znaki Specjalne? (Y/N): ";
    cin >> wybor;

    if (wybor == 'Y' || wybor == 'y')
        znaki_specjalne = true;

    cout << "Czy chcesz dodać opcję Numery? (Y/N): ";
    cin >> wybor;

    if (wybor == 'Y' || wybor == 'y')
        numery = true;


    dlugosc_hasla = true;
    cout << "Podaj długość hasła (maks. 120): ";
    cin >> dlugosc;
    dlugosc = min(dlugosc, 120);


    string haslo = generuj_haslo(dlugosc, duze_litery, znaki_specjalne, numery);

    string zatGenStop;
    while(zatGenStop != "Stop"){
        cout << "Zatwierdz | Generuj | Stop" << endl;
        cin >> zatGenStop;
        if(zatGenStop == "Zatwierdz"){
            system("cls");
            cout << "Imię: " << imie << endl;
            cout << "Nazwisko: " << nazwisko << endl;
            cout << "Stanowisko: " << stanowisko << endl;
            cout << "Wygenerowane hasło: " << haslo << endl;
        }
        else if(zatGenStop == "Generuj"){
            system("cls");
            cout << "Wygenerowane hasło: " << haslo << endl;
        }
        else{
            system("cls");
            cout << "Do Zobaczenia";
        }
    }

}
