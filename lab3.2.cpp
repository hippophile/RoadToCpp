/*Ορίστε μία class “Pet” και μία “Person”. Η κλάση “Pet” έχει έναν δείκτη σε κάποιο αντικείμενο
“Person” (private), καθώς και μία μέθοδο (“setOwner” - public) που δέχεται ως όρισμα έναν δείκτη
σε “Person” και αρχικοποιεί το αντίστοιχο μέλος δεδομένο (data member - mutator method).
Αντίστοιχα η κλάση “Person” έχει έναν δείκτη σε κάποιο “Pet” του οποίου είναι ο ιδιοκτήτης του
(“owner”), καθώς και μία μέθοδο “getPet” η οποία δημιουργεί ένα αντικείμενο “Pet” και καλεί
κατάλληλα την μέθοδο “setOwner” του, ώστε να οριστεί η ίδια ιδιοκτήτης του (“owner”).
Κατασκευάστε ένα αρχείο με τον απαραίτητο κώδικα για τα παραπάνω, ενώ στο ίδιο αρχείο και σε
μία “main” δημιουργήστε ένα αντικείμενο “Person” και αποδώστε του ένα αντικείμενο “Pet”*/

#include <iostream>
#include <string>
using namespace std;

class Person;

class Pet {
    private:  
        Person* ptr_person;

    public:
        void setOwner(Person* owner){
            ptr_person = owner;
        }
};

class Person {
    private:
        Pet* ptr_pet;
    public:
        void get_pet(){
            ptr_pet = new Pet;
            ptr_pet -> setOwner(this);
        }
        bool has_pet() const{
            return ptr_pet != nullptr;
        }
};

int main(){

    Person Filip;
    Filip.get_pet();

     if (Filip.has_pet()) {
        cout << "You DO have a pet :)" << endl;
    } else {
        cout << "You do NOT have a pet :(" << endl;
    }
 
    return 0;
}