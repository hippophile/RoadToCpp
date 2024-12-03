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

int main() {
    Vehicle v("Car", 1200.0);         // Δημιουργία αντικειμένου Vehicle
    Computer c("Laptop", 2.5);       // Δημιουργία αντικειμένου Computer

    v.operate(4);                    // Vehicle worked for 4 hours
    c.operate(2);                    // Computer was in use for 2 hours

    return 0;
}


