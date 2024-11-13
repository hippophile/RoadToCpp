/*Άσκηση 1
1.1. Ορίστε μια “class” “University_Branch”, που αναπαριστά το παράρτημα ενός Πανεπιστημίου
και η οποία θα περιέχει ένα όνομα, μία διεύθυνση, έναν αριθμό από Σχολές, το πλήθος των
Σχολών, το πλήθος των Τμημάτων των Σχολών και των φοιτητών τους (σε κατάλληλες
μεταβλητές). Κατασκευάστε κατάλληλες συναρτήσεις μέλη (constructors/destructors, getter,
setter και print).
1.2. Ορίστε μία δεύτερη “class” “School”, που με την σειρά της θα έχει ένα όνομα και έναν αριθμό
από Τμήματα, το πλήθος των Τμημάτων και των φοιτητών τους. Κατασκευάστε κατάλληλες
συναρτήσεις μέλη (constructors/destructors, getter, setter και print).
1.3. Ορίστε μία τρίτη “class” “Department”, που με την σειρά της θα έχει ένα όνομα, έναν μοναδικό
χαρακτηριστικό φυσικό αριθμό (πχ 1115) και έναν αριθμό από φοιτητές. Κατασκευάστε
κατάλληλες συναρτήσεις μέλη (constructors/ destructors, getter, setter και print).
1.4. Ορίστε μία τέταρτη “class” “Student”, που θα έχει μοναδικό Ονοματεπώνυμο, και έναν
μοναδικό φυσικό πενταψήφιο αριθμό που τον χαρακτηρίζει. Ο αριθμός του Τμήματος μαζί με
το έτος εισαγωγής και ο πενταψήφιος αποτελούν τον Αριθμό Μητρώου του κάθε φοιτητή (ΑΜ).
1.5. Σε μία ενδεικτική “main” δημιουργήστε ένα Παράρτημα του ΕΚΠΑ στην Κύπρο, μερικές σχολές
αντίστοιχες με τις σχολές του ΕΚΠΑ, καθώς και Τμήματα για την κάθε Σχολή, αντίστοιχα με τα
Τμήματα των Σχολών του ΕΚΠΑ. Επίσης δημιουργήστε μερικούς φοιτητές για το Τμήμα
Πληροφορικής του Παραρτήματος του ΕΚΠΑ στην Κύπρο, καθώς και μερικούς για το Τμήμα
της Ιατρικής της αντίστοιχης Σχολής. Με τις αντίστοιχες συναρτήσεις μέλη των κλάσεων
εκτυπώστε τον αριθμό των Σχολών, των Τμημάτων και των φοιτητών του Παραρτήματος του
ΕΚΠΑ. Λαμβάνοντας από τρεις global μεταβλητές τον αντίστοιχο αριθμό των Σχολών, των
Τμημάτων και το σύνολο των φοιτητών του μητρικού ΕΚΠΑ, εκτυπώστε τον συνολικό αριθμό
Σχολών και Τμημάτων του ΕΚΠΑ και του Παραρτήματος μαζί. Εκτυπώστε επίσης τον αριθμό των Τμημάτων για κάθε Σχολή του Παραρτήματος καθώς και τον αριθμό των φοιτητών του
κάθε Τμήματος.
1.6. Αν δεν υπήρχε περίπτωση να ιδρυθεί άλλο Παράρτημα από άλλο Πανεπιστήμιο, πως θα
μπορούσατε να υλοποιήσετε την κλάση του Παραρτήματος; Κάντε τις κατάλληλες αλλαγές και
στην “main” για να το δοκιμάσετε.
1.7. Αποθηκεύστε τους φοιτητές που δημιουργήσατε χρησιμοποιώντας την κλάση map της STD.
Στην “main” κάντε δοκιμές*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class School;

class University_Branch {
private:
    string name;
    string address;
    vector<School> schools;
    int num_schools;
    int num_departments;
    int num_students;

public:

    University_Branch(string n, string ad) : name(n), address(ad), num_schools(0),  {
        
    }

    void add_school(School school) {
        schools.push_back(school);
        num_schools++;
    }

    void print() const {
        cout << "University Branch: " << name << ", Address: " << address << endl;
        cout << "Number of Schools: " << num_schools << endl;
    }

    ~University_Branch() {};
};

class School {
private:
    string name;
    int num_departments;
    int num_students;

private:
    School(string n) : name(n) {
        
    };



    ~School() {};
};

class Department {
private:
    string name;
    int DN; // department name
    int num_students;

public:
    Department(string n) : name(n) {};

    ~Department() {};
};

class Student {
    string big_name;
    unsigned long AM;

    Student(string n) : big_name(n) {};

    ~Student() {};

};

int main() {



    return 0;
}