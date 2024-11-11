/*Άσκηση 3 - constructors – initializer lists
3.1
Ορίστε μία κλάση “String” που θα παρέχει μερικώς παρόμοια λειτουργικότητα με την κλάση string
της STL. Θα πρέπει να αποθηκεύει εσωτερικά:
● την συμβολοσειρά που αναπαριστά,
● το μέγεθός της, καθώς και
● την μέγιστη χωρητικότητα που έχει κάθε δεδομένη στιγμή.
3.2
Ορίστε έναν constructor που θα δέχεται:
● την συμβολοσειρά με την οποία θα αρχικοποιηθεί το “String” (ως απλό πίνακα χαρακτήρων)
και έναν που θα δέχεται:
● την αρχική χωρητικότητα του “String”,
● την συμβολοσειρά με την οποία θα αρχικοποιηθεί το “String” (ως απλό πίνακα
χαρακτήρων).
Τέλος ορίστε τον αντίστοιχο destructor, ενώ σε μία “main” δημιουργήστε αντικείμενα με τους δύο
παραπάνω τρόπους.
3.3
Ορίστε συναρτήσεις μέλη που
● θα επιστρέφουν το μέγεθος (”size”),
● την χωρητικότητα (”capacity”),
● τον χαρακτήρα στην θέση “index” της συμβολοσειράς (“at”). Αν δεν υπάρχει η θέση “index”
τότε θα επιστρέφεται ο χαρακτήρας ‘\0’.
3.4
Ορίστε μία συνάρτηση μέλος “find” που θα δέχεται ένα “String” και μία αρχική θέση (default 0) και
θα ψάχνει αν υπάρχει το “String” που δόθηκε σαν όρισμα σε κάποιο σημείο του αρχικού “String”,
μετά την αρχική θέση. Αν υπάρχει, θα επιστρέφει την θέση στην οποία ξεκινάει. Διαφορετικά θα
επιστρέφει -1. Αν το “String” υπάρχει πολλές φορές, θα επιστρέφει τη*/

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class String {
private:
    int size;
    int capacity;
    char *p;

public:
    String(const char* str) : size(strlen(str)), capacity(size) {
        p = new char[size + 1];
        strcpy(p, str);
    }

    String(const char* str, int capacity) : capacity(capacity), size(strlen(str)) {
        p = new char[capacity + 1];
        strcpy(p, str);
    }

    ~String(){
        delete[] p;
    }

    int size_() const {
        return size;
    }

    int capacity_() const {
        return capacity;
    }

    char at(int index) const { 
        if (index >= 0 && index < size) {
            return p[index];
        }
        return '\0';
    }

    int find(const String& str, int start = 0) const {
        for (int i = start; i <= size - str.size_(); i++) {
            bool match = true;
            for (int j = 0; j < str.size_(); j++) {
                if (p[i + j] != str.p[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }
        return -1;
    }

};

int main() {
    // Δημιουργία αντικειμένων String
    String str1("Hello, world!");  // Δημιουργία με τον πρώτο constructor
    String str2("world");          // Δημιουργία ενός άλλου αντικειμένου με τον πρώτο constructor

    // Έλεγχος της μεθόδου find
    int position = str1.find(str2);  // Ψάχνουμε για το str2 μέσα στο str1
    if (position != -1) {
        cout << "Το 'world' βρέθηκε στη θέση: " << position << endl;
    } else {
        cout << "Η λέξη 'world' δεν βρέθηκε." << endl;
    }

    // Δοκιμή της μεθόδου at
    char ch = str1.at(7);  // Προσπέλαση του χαρακτήρα στη θέση 7
    if (ch != '\0') {
        cout << "Ο χαρακτήρας στη θέση 7 είναι: " << ch << endl;
    } else {
        cout << "Η θέση είναι εκτός ορίων." << endl;
    }

    // Δοκιμή των μεθόδων size και capacity
    cout << "Μέγεθος του str1: " << str1.size_() << endl;
    cout << "Χωρητικότητα του str1: " << str1.capacity_() << endl;

    return 0;
}