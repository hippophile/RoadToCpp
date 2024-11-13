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
#include <map>

using namespace std;

class School;
class Department;
class Student;

class University_Branch {
private:
    string name;
    string address;
    vector<School> schools;
    int num_schools;
    int num_departments;
    int num_students;

public:

    University_Branch(string n, string ad)
        : name(n), address(ad), num_schools(0), num_departments(0), num_students(0) {}

    void add_school(const class School& school) {
        schools.push_back(school);
        num_schools++;
    }

    void print() const {
        cout << "University Branch: " << name << ", Address: " << address << endl;
        cout << "Number of Schools: " << num_schools << endl;
        cout << "Number of Departments: " << num_departments << endl;
        cout << "Number of Students: " << num_students << endl;
    }

};

class School {
private:
    string name;
    vector<Department> departments;
    int num_departments;
    int num_students;

public:
    School(string n) : name(n), num_departments(0), num_students(0){}

    void add_department(const Department& department) {
        departments.push_back(department);
        num_departments++;
    }

    void print() const {
        cout << "School: " << name << endl;
        cout << "Number of Departments: " << num_departments << endl;
        cout << "Number of Students: " << num_students << endl;
    }
};

class Department {
private:
    string name;
    int DN; // department name
    int num_students;

public:
    Department(string n, int dn) : name(n), DN(dn), num_students(0) {}

    void print() const {
        cout << "Department: " << name << " (ID: " << DN << ")" << endl;
        cout << "Number of Students: " << num_students << endl;
    }
};

class Student {
    string full_name;
    unsigned long AM;

    Student(string n, unsigned long am) : full_name(n), AM(am) {}

    void print() const {
        cout << "Student: " << full_name << ", AM: " << AM << endl;
    }
};

int main() {

    University_Branch ekpa_cyprus("EKPA", "Cyprus");

    School informatics("School of Informatics");
    School medicine("School of Medicine");

    Department cs("Computer Science", 1115);
    Department med("Medical Science", 2110);

    informatics.add_department(cs);
    medicine.add_department(med);

    ekpa_cyprus.add_school(informatics);
    ekpa_cyprus.add_school(medicine);

    ekpa_cyprus.print();
    informatics.print();
    medicine.print();
    cs.print();
    med.print();

    return 0;
}