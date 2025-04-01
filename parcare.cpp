#include <iostream>
#include <string>

using namespace std;

int TARIF_ORAR = 5;

class LocParcare {
public:
    int numarLoc;
    string numarMasina;
    int ora, minut;


    void parcareMasina(string nr, int h, int m) {
        if (numarMasina == "") {
            numarMasina = nr;
            ora = h;
            minut = m;
            cout << "Masina " << nr << " parcata la locul " << numarLoc << " la ora " << h << ":" << m << endl;
        }
        else {
            cout << "Locul " << numarLoc << " este deja ocupat!" << endl;
        }
    }

    void eliberareLoc(int h, int m) {
        if (numarMasina != "") {
            int durata = (h - ora) * 60 + (m - minut);
            if (durata < 0) {
                durata += 24 * 60;
            }


            int cost = (durata / 60) * TARIF_ORAR;
            if (durata % 60 != 0) {
                cost += TARIF_ORAR;
            }
            cout << "Eliberare loc " << numarLoc << " ocupat de masina " << numarMasina;
            cout << " parcata la ora " << ora << ":" << minut << ". Tariful este " << cost << " lei." << endl;
            numarMasina = "";
        }
        else {
            cout << "Locul " << numarLoc << " este deja liber!" << endl;
        }
    }


    void init(int numar) {
        numarLoc = numar;
        numarMasina = "";
        ora = 0;
        minut = 0;
    }
};

int main() {
    LocParcare locuri[100];


    for (int i = 0; i < 100; i++) {
        locuri[i].init(i + 1);
    }

    int loc, ora, minut;
    string numar;


    cout << "Introdu numarul masinii: ";
    cin >> numar;
    cout << "Introdu numarul locului de parcare: ";
    cin >> loc;
    cout << "Introdu ora parcarii: ";
    cin >> ora;
    cout << "Introdu minutul parcarii: ";
    cin >> minut;


    locuri[loc - 1].parcareMasina(numar, ora, minut);


    cout << "Introdu numarul locului de parcare de eliberat: ";
    cin >> loc;
    cout << "Introdu ora eliberarii: ";
    cin >> ora;
    cout << "Introdu minutul eliberarii: ";
    cin >> minut;

    locuri[loc - 1].eliberareLoc(ora, minut);

    return 0;

}
