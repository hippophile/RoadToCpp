/*Άσκηση 1
Έχουμε μηχανικά αντικείμενα (Machinery) που χαρακτηρίζονται από ένα όνομα και ένα βάρος.
Επίσης έχουμε οχήματα (Vehicle) και υπολογιστές (Computer) που είναι και μηχανικά αντικείμενα.
1. Ορίστε τις κατάλληλες κλάσεις που μοντελοποιούν την παραπάνω ιεραρχία. Η Machinery θα
έχει και συναρτήσεις getter για το όνομα και το βάρος. H Machinery έχει και μία συνάρτηση
operate που δέχεται έναν ακέραιο (ο οποίος θα έχει και κάποια default τιμή) και θα εκτυπώνει
ότι το αντικείμενο δούλεψε για τόσες ώρες. Δοκιμάστε τα παραπάνω στη main.
2. Επαναορίστε την operate (override) σε κάθε υποκλάση της Machinery. Για την Computer, ας
γίνεται χρήση και της αρχικής operate (αυτή της Machinery).
3. Ορίστε την operate της Machinery σαν pure virtual. Επίσης ορίστε τον destructor της
Machinery σαν virtual. Δοκιμάστε τις αλλαγές που προκαλούνται στη main (με και χωρίς το
virtual).*/

/*Άσκηση 2
Ορίστε μία κλάση Person και μία Technician (που κληρονομεί από την Person). Ορίστε στη Person
μία συνάρτηση workOn που δέχεται σαν όρισμα ένα δείκτη σε Machinery και εφαρμόζει πάνω σε
αυτό την operate. Ορίστε επίσης μία workOn που δέχεται σαν όρισμα ένα δείκτη σε Vehicle.
Αντίστοιχα ορίστε στη Technician μία workOn που δέχεται σαν όρισμα ένα δείκτη σε Machinery και
μία που δέχεται σαν όρισμα ένα δείκτη σε Computer. Δοκιμάστε τα παραπάνω στη main.*/

#include <iostream>
#include <string>
using namespace std;

class Machinery {
private:
    string name;
    double weight;

public:
    Machinery(const string& name, double w) : name(name), weight(w) {}

    virtual ~Machinery(){}

    string get_name () const {
        return name;
    }   

    double get_weight () const {
        return weight;
    }

    virtual void operate (int hours = 1 ) const {
        cout << "Machinery worked for " << hours << " hours" << endl;
    }

};

class Vehicle : public Machinery {
public:
    Vehicle(const string& name, double w) : Machinery(name, w) {};

    void operate(int hours = 1) const override {
        cout << "Vehicle worked for " << hours << " hours" << endl;
    }

};

class Computer : public Machinery {
public:
    Computer(const string& name, double w) : Machinery(name, w) {};

    void operate(int hours = 1) const override {
        // Machinery::operate(hours);
        cout << "Computer was in use for " << hours << " hours" << endl;
    }


};

class Person {
private:
    string name;

public:
    Person(const string& name) : name(name) {}

    ~Person() {}

    // work_on for machinery
    virtual void work_on(Machinery* machine){
        cout << "Person is working on a machinery.\n";
        machine->operate();
    }

    // work_on for vehicle
    void work_on(Vehicle* vehicle) {
    cout << "Person is working on a vehicle.\n";
    vehicle->operate();
    }

};

class Technician : public Person {
public:
    Technician(const string& name) : Person(name) {}
    
        // work_on for machinery
    void work_on(Machinery* machine) override {
        cout << "Person is working on a machinery.\n";
        machine->operate();
    }

    // work_on for computer
    void work_on(Computer* computer) {
    cout << "Person is working on a computer.\n";
    computer->operate();
    }

};


int main() {
    // Δημιουργία αντικειμένων Vehicle και Computer
    Vehicle v("Car", 1200.0);
    Computer c("Laptop", 2.5);

    // Δημιουργία αντικειμένου Person
    Person p("John");

    // Δοκιμή της Person
    cout << "\n--- Testing Person ---\n";
    p.work_on(&v);  // Δοκιμή με Vehicle
    p.work_on(&c);  // Δοκιμή με Computer (πρέπει να εκτυπώσει μήνυμα για Machinery)

    // Δημιουργία αντικειμένου Technician
    Technician t("Alice");

    // Δοκιμή της Technician
    cout << "\n--- Testing Technician ---\n";
    t.work_on(&v);  // Δοκιμή με Vehicle
    t.work_on(&c);  // Δοκιμή με Computer

    return 0;
}




