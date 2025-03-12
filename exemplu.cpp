#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string nume;
    int varsta;
    float medie;

public:
    // Constructor cu parametri
    Student(string nume_student, int varsta_student, float medie_student) {
        nume = nume_student;
        varsta = varsta_student;
        medie = medie_student;
        cout << "Constructorul a fost apelat pentru: " << nume << endl;
    }

    ~Student() {
        // Destructor pentru a elibera memoria când obiectul este distrusr
        cout << "Destructorul a fost apelat pentru: " << nume << endl;
    }

    void afisare_informatii() {
        // Afișează informațiile despre student
        cout << "Nume: " << nume << ", Varsta: " << varsta << ", Medie: " << medie << endl;
    }

    float getMedie() const {
        // Returnează media studentului
        return medie;
    }
};

int main() {
    int n;
    cout << "Introduceti nr de studenti: ";
    cin >> n;

    // Crearea unui array dinamic pentru studenți
    Student** studenti = new Student * [n];

    for (int i = 0; i < n; i++) {
        string nume;
        int varsta;
        float medie;

        // Citirea informațiilor despre fiecare student
        cout << "Introduceti numele studentului " << i + 1 << ": ";
        cin >> nume;
        cout << "Introduceti varsta studentului " << i + 1 << ": ";
        cin >> varsta;
        cout << "Introduceti media studentului " << i + 1 << ": ";
        cin >> medie;

        // Crearea unui nou obiect Student și stocarea acestuia în array
        studenti[i] = new Student(nume, varsta, medie);
    }

    // Afișarea tuturor studenților
    cout << "\nLista studentilor:\n";
    for (int i = 0; i < n; i++) {
        studenti[i]->afisare_informatii();
    }

    // Găsirea studentului cu cea mai mare medie
    Student* maxMedieStudent = studenti[0];
    for (int i = 1; i < n; i++) {
        if (studenti[i]->getMedie() > maxMedieStudent->getMedie()) {
            maxMedieStudent = studenti[i];
        }
    }
    cout << "\nStudentul cu cea mai mare medie este:\n";
    maxMedieStudent->afisare_informatii();

    // Sortarea studenților după medie (de la cea mai mare la cea mai mică) folosind metoda bulelor
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Schimbare condiție pentru sortare descrescătoare
            if (studenti[j]->getMedie() < studenti[j + 1]->getMedie()) {
                swap(studenti[j], studenti[j + 1]);
            }
        }
    }

    // Afișarea studenților sortați
    cout << "\nStudentii sortati dupa medie (de la cel mai mare la cel mai mic):\n";
    for (int i = 0; i < n; i++) {
        studenti[i]->afisare_informatii();
    }

    // Eliberarea memoriei alocate dinamic
    for (int i = 0; i < n; i++) {
        delete studenti[i];
    }
    delete[] studenti;

    return 0;
}

				
				

//salut ce faci?
	






	


















			
