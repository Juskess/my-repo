#include <iostream>
#include <string>
using namespace std;

// Clasa de bază
class animal {
protected:
    string nume;
    int varsta;
    string mancare;
    float kg;
    string culoare;

public:
    animal(string nume, int varsta, string mancare, float kg, string culoare)
        : nume(nume), varsta(varsta), mancare(mancare), kg(kg), culoare(culoare) {
    }

    virtual ~animal() {} // Destructor virtual

    virtual void afisare_informatii() {
        cout << "Animal: " << nume << endl
            << "Varsta: " << varsta << " ani" << endl
            << "Mancare: " << mancare << endl
            << "Kilograme: " << kg << endl
            << "Culoare: " << culoare << endl;
    }
};

// Clasa derivată pentru mamifere
class mamifer : public animal {
protected:
    string tip_alimentar;

public:
    mamifer(string nume, int varsta, string mancare, float kg, string culoare, string tip_alimentar)
        : animal(nume, varsta, mancare, kg, culoare), tip_alimentar(tip_alimentar) {
    }

    void afisare_informatii() override {
        animal::afisare_informatii();
        cout << "Tip alimentar: " << tip_alimentar << endl;
    }
};

// Clasa derivată pentru fauna marină
class fauna_marina : public animal {
protected:
    string tip_animal;

public:
    fauna_marina(string nume, int varsta, string mancare, float kg, string culoare, string tip_animal)
        : animal(nume, varsta, mancare, kg, culoare), tip_animal(tip_animal) {
    }

    void afisare_informatii() override {
        animal::afisare_informatii();
        cout << "Tip de animal marin: " << tip_animal << endl;
    }
};

// Clasa derivată pentru păsări
class pasare : public animal {
protected:
    float lungime_aripi;

public:
    pasare(string nume, int varsta, string mancare, float kg, string culoare, float lungime_aripi)
        : animal(nume, varsta, mancare, kg, culoare), lungime_aripi(lungime_aripi) {
    }

    void afisare_informatii() override {
        animal::afisare_informatii();
        cout << "Lungime aripi: " << lungime_aripi << " metri" << endl;
    }
};

// Funcție pentru afișarea instrucțiunilor
void instructiuni() {
    cout << "Alege tipul de animal:\n";
    cout << "1. Mamifer\n";
    cout << "2. Fauna marina\n";
    cout << "3. Pasare\n";
    cout << "Introdu optiunea: ";
}

// Funcția principală
int main() {
    // Exemple de animale predefinite
    mamifer leu("Leu", 8, "Carne", 190.0, "Auriu", "Carnivor");
    mamifer elefant("Elefant", 15, "Iarba", 5000.0, "Gri", "Ierbivor");

    fauna_marina delfin("Delfin", 10, "Peste", 150.0, "Gri", "Mamifer marin");
    fauna_marina rechin("Rechin", 12, "Peste", 900.0, "Gri-albastru", "Cartilaginos");

    pasare vultur("Vultur", 5, "Carne", 6.0, "Maro", 2.4);
    pasare flamingo("Flamingo", 7, "Alge", 3.5, "Roz", 1.5);

    cout << "Exemple predefinite de animale:\n\n";
    leu.afisare_informatii();
    cout << endl;
    elefant.afisare_informatii();
    cout << endl;

    delfin.afisare_informatii();
    cout << endl;
    rechin.afisare_informatii();
    cout << endl;

    vultur.afisare_informatii();
    cout << endl;
    flamingo.afisare_informatii();
    cout << endl;

    // Afișarea meniului pentru animale suplimentare
    instructiuni();

    int optiune;
    cin >> optiune;

    if (optiune < 1 || optiune > 3) {
        cout << "Optiune invalida. Program terminat." << endl;
        return 0;
    }

    int n;
    cout << "Introdu numarul de animale noi: ";
    cin >> n;

    if (n <= 0) {
        cout << "Numar invalid. Program terminat." << endl;
        return 0;
    }

    animal** animale = new animal * [n];

    for (int i = 0; i < n; i++) {
        string nume, mancare, culoare;
        int varsta;
        float kg;

        cout << "Animal " << i + 1 << ":\n";
        cout << "Nume: ";
        cin >> nume;
        cout << "Varsta: ";
        cin >> varsta;
        cout << "Mancare: ";
        cin >> mancare;
        cout << "Kilograme: ";
        cin >> kg;
        cout << "Culoare: ";
        cin >> culoare;

        if (optiune == 1) {
            string tip_alimentar;
            cout << "Tip alimentar: ";
            cin >> tip_alimentar;
            animale[i] = new mamifer(nume, varsta, mancare, kg, culoare, tip_alimentar);
        }
        else if (optiune == 2) {
            string tip_animal;
            cout << "Tip de animal marin: ";
            cin >> tip_animal;
            animale[i] = new fauna_marina(nume, varsta, mancare, kg, culoare, tip_animal);
        }
        else if (optiune == 3) {
            float lungime_aripi;
            cout << "Lungime aripi (in metri): ";
            cin >> lungime_aripi;
            animale[i] = new pasare(nume, varsta, mancare, kg, culoare, lungime_aripi);
        }
        cout << endl;
    }

    cout << "Animalele introduse:\n";
    for (int i = 0; i < n; i++) {
        animale[i]->afisare_informatii();
        cout << endl;
    }

    // Eliberarea memoriei alocate
    for (int i = 0; i < n; i++) {
        delete animale[i];
    }
    delete[] animale;

    return 0;
}
