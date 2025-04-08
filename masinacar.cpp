#include <iostream>
#include <string>

using namespace std;

// definirea clasei Car
class Car {
private:
    string brand; // brandul mașinii

public:
    // Constructor
    Car(string b) : brand(b) {
        cout << "Car " << brand << " created;
    }

    // destructor
    ~Car() {
        cout << "Car " << brand << " destroyed;
    }

    // declarația clasei prietene
    friend class FriendClass;
};

// definirea clasei prietene
class FriendClass {
public:
    // metodă care accesează membrii privați ai clasei Car
    void showCarBrand(const Car& car) {
        cout << "Accessing private member: The brand is " << car.brand << ;
    }
};

int main() {
    Car myCar("Toyota"); //crearea unui obiect de tip Car
    FriendClass friendObj; // crearea unui obiect de tip FriendClass

    // accesarea membrului privat al clasei Car folosind clasa prietenă
    friendObj.showCarBrand(myCar);

    return 0;
}
