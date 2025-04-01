#include <iostream>
#include <string>
#include <limits> // Pentru a curăța buffer-ul de input
#include <ctime>  // Pentru a manipula ora

using namespace std;

// Clasa Masina
class Masina {
private:
    string nr_inmatriculare; // Numarul de inmatriculare al masinii
    int ora_intrare, minut_intrare; // Ora si minutul cand a intrat masina
    int ora_iesire, minut_iesire; // Ora si minutul cand a iesit masina
    double tarif_pe_ora; // Tariful pe ora de parcare
    bool este_parcata; // Starea masinii (parcata sau nu)

public:
    // Constructor pentru clasa Masina
    Masina(string nr, int ora_intrare, int minut_intrare, double tarif) {
        nr_inmatriculare = nr;
        this->ora_intrare = ora_intrare;
        this->minut_intrare = minut_intrare;
        tarif_pe_ora = tarif;
        este_parcata = true; // Initial, masina este parcata
    }

    // Metode pentru a accesa si modifica datele private

    // Seteaza ora si minutul iesirii
    void setIesire(int ora, int minut) {
        ora_iesire = ora;
        minut_iesire = minut;
    }

    // Returneaza numarul de inmatriculare
    string getNrInmatriculare() {
        return nr_inmatriculare;
    }

    // Calculeaza tariful pe baza timpului petrecut in parcare
    double calculeazaTarif() {
        int durata_minute = (ora_iesire - ora_intrare) * 60 + (minut_iesire - minut_intrare);
        return durata_minute / 60.0 * tarif_pe_ora;
    }

    // Verifica daca masina este parcata
    bool esteParcata() {
        return este_parcata;
    }

    // Elibereaza locul de parcare
    void elibereazaParcare() {
        este_parcata = false;
    }
};

// Clasa Parcare
class Parcare {
protected:
    int locuri_disponibile; // Locuri disponibile de parcare

public:
    Parcare(int locuri) {
        locuri_disponibile = locuri;
    }

    // Verifica daca sunt locuri disponibile
    bool suntLocuriDisponibile() {
        return locuri_disponibile > 0;
    }

    // Ocupa un loc de parcare
    void ocupaLoc() {
        if (locuri_disponibile > 0) {
            locuri_disponibile--;
        }
    }

    // Elibereaza un loc de parcare
    void elibereazaLoc() {
        locuri_disponibile++;
    }

    // Afiseaza numarul de locuri disponibile
    void afiseazaLocuriDisponibile() {
        cout << "Locuri disponibile: " << locuri_disponibile << endl;
    }
};

// Clasa derivata GestionareParcare care mosteneste Parcare
class GestionareParcare : public Parcare {
private:
    Masina* masini[100]; // Punctul de stocare al masinilor
    int numar_masini;

public:
    GestionareParcare(int locuri) : Parcare(locuri) {
        numar_masini = 0;
    }

    // Adauga o masina
    void adaugaMasina(string nr, int ora_intrare, int minut_intrare, double tarif) {
        if (suntLocuriDisponibile()) {
            masini[numar_masini] = new Masina(nr, ora_intrare, minut_intrare, tarif);
            ocupaLoc();
            numar_masini++;
            cout << "Masina cu numarul " << nr << " a fost parcata!" << endl;
        }
        else {
            cout << "Nu mai sunt locuri disponibile!" << endl;
        }
    }

    // Elibereaza un loc de parcare
    void elibereazaMasina(string nr) {
        for (int i = 0; i < numar_masini; i++) {
            if (masini[i]->getNrInmatriculare() == nr && masini[i]->esteParcata()) {
                int ora_iesire, minut_iesire;
                cout << "Introdu ora iesirii: ";
                cin >> ora_iesire;
                cout << "Introdu minutul iesirii: ";
                cin >> minut_iesire;

                masini[i]->setIesire(ora_iesire, minut_iesire);
                double tarif = masini[i]->calculeazaTarif();
                cout << "Masina cu numarul " << nr << " a parasit parcarea. Tariful este: " << tarif << " lei." << endl;

                masini[i]->elibereazaParcare();
                elibereazaLoc();
                return;
            }
        }
        cout << "Masina nu a fost gasita!" << endl;
    }

    // Afiseaza locurile disponibile
    void afiseazaLocuri() {
        afiseazaLocuriDisponibile();
    }
};

int main() {
    int optiune;
    GestionareParcare parcare(5); // Creaza o parcare cu 5 locuri disponibile

    do {
        cout << "\n1. Adauga masina\n2. Elibereaza masina\n3. Afiseaza locuri\n4. Iesire\nOptiune: ";
        if (!(cin >> optiune)) {
            cin.clear();  // Resetează starea lui cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Curăță buffer-ul
            continue;  // Reia bucla pentru o nouă citire validă
        }

        switch (optiune) {
        case 1: {
            string nr;
            int ora, minut;
            double tarif;

            cout << "Introdu numarul de inmatriculare: ";
            cin >> nr;
            cout << "Introdu ora intrarii (0-23): ";
            cin >> ora;
            cout << "Introdu minutul intrarii (0-59): ";
            cin >> minut;
            cout << "Introdu tariful pe ora: ";
            cin >> tarif;

            parcare.adaugaMasina(nr, ora, minut, tarif);
            break;
        }
        case 2: {
            string nr;
            cout << "Introdu numarul de inmatriculare al masinii care paraseste parcarea: ";
            cin >> nr;
            parcare.elibereazaMasina(nr);
            break;
        }
        case 3:
            parcare.afiseazaLocuri();
            break;
        case 4:
            cout << "La revedere!" << endl;
            break;
        default:
            cout << "Optiune invalida!" << endl;
            break;
        }
    } while (optiune != 4);

    return 0;
}
