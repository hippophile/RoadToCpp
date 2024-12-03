/*ΑΝΤΙΚΕΙΜΕΝΟΣΤΡΑΦΗΣ ΠΡΟΓΡΑΜΜΑΤΙΣΜΟΣ
Εργαστήριο 6: Oop – Υλοποίηση δομής δεδομένων (Λίστα)
ΕΡΓΑΣΤΗΡΙΟ 6:
Αντικειμενοστραφής προγραμματισμός – Υλοποίηση δομής δεδομένων (Λίστα)
Σκοπός της ενότητας αυτής είναι να υλοποιήσετε μια δομή δεδομένων (λίστα) κάνοντας τις
κατάλληλες σχεδιαστικές επιλογές που απαιτεί ο αντικειμενοστραφής προγραμματισμός.
Άσκηση 1
1.1. Ορίστε μια “struct” που θα αναπαριστά την έννοια του σημείου στο δισδιάστατο χώρο. Ορίστε
τους κατάλληλους constructor/destructor καθώς και τους accessors που χρειάζονται. Ο
constructor και ο destructor να εκτυπώνουν κάποιο μήνυμα.
1.2. Ορίστε μια μέθοδο print που θα εκτυπώνει το σημείο.
Άσκηση 2
Ορίστε μια “struct” “Node” που θα αναπαριστά την έννοια του κόμβου της λίστας. Θα χρειαστεί
τουλάχιστον να αναπαριστάτε την πληφορορία του κόμβου (ένα σημείο) καθώς και τον επόμενο
κόμβο. Ορίστε τον κατάλληλο constructor. Πώς θα δέχεται ο constructor του Node το σημείο που
κρατάει; Τι διαφορές παρατηρείτε αν αυτό γίνει με δείκτη ή αναφορά ή αν γίνει απλά με σημείο; Σε
μια ενδεικτική main δημιουργήστε ένα κόμβο για να παρατηρήσετε διαφορές.
Άσκηση 3
3.1. Ορίστε μια “class” “List” που θα αναπαριστά την δομή της λίστας στο σύνολο της. Τι πεδία
χρειάζεται να υπάρχουν; Ορίστε τον κατάλληλο constructor.
3.2. Προσθέστε μια μέθοδο “size” που θα επιστρέφει το πλήθος των κόμβων που βρίσκονται μέσα
στη λίστα. Η συνάρτηση πρέπει να έχει σταθερό χρόνο εκτέλεσης (δεν πρέπει να διατρέχει την
λίστα).
3.3. Προσθέστε μια μέθοδο “pushFront” που θα εισάγει ένα σημείο στην αρχή της λίστας.
3.4. Προσθέστε μια μέθοδο “pop” που θα δέχεται έναν αριθμό (μια θέση μέσα στη λίστα) και θα
διαγράφει τον κόμβο αυτό από την λίστα.
3.5. Προσθέστε μια μέθοδο “print” που θα εκτυπώνει τα στοιχεία της λίστας.
3.6. Προσθέστε τον destructor της λίστας. Ο destructor θα πρέπει να επιβάλει ότι μετά την
καταστροφή της λίστας, έχει αποδεσμευτεί όλος ο χώρος της μνήμης που είχε δεσμευτεί για
λειτουργίες της λίστας.
3.7. Σε μια ενδεικτική main δοκιμάστε τις παραπάνω λειτουργίες.
3.8. Ορίστε την “struct” “Node” εσωτερικά της λίστας. Σε ποιό σημείο πρέπει να μπει ο ορισμός
(public/private); Τι μας προσφέρει ο ορισμός του κόμβου “εσωτερικά” της λίστας;
Σελ. 1 / 1*/

#include <iostream>
#include <memory>

namespace mynamespace {

    // Άσκηση 1.1 & 1.2: Ορισμός struct Point
    struct Point {
        double x; // Συντεταγμένη x
        double y; // Συντεταγμένη y

        // Constructor
        Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {
            std::cout << "Constructor called: Point(" << x << ", " << y << ") created.\n";
        }

        // Destructor
        ~Point() {
            std::cout << "Destructor called: Point(" << x << ", " << y << ") destroyed.\n";
        }

        // Accessors
        double getX() const { return x; }
        double getY() const { return y; }
        void setX(double newX) { x = newX; }
        void setY(double newY) { y = newY; }

        // Μέθοδος print για την εκτύπωση του σημείου
        void print() const {
            std::cout << "Point(" << x << ", " << y << ")\n";
        }
    };

    // Άσκηση 2: Ορισμός struct Node
    struct Node {
        Point data;
        std::shared_ptr<Node> next;

        // Constructor
        Node(const Point &point, std::shared_ptr<Node> nextNode = nullptr)
            : data(point), next(nextNode) {
            std::cout << "Node created with Point(" << data.x << ", " << data.y << ").\n";
        }
    };

    // Άσκηση 3: Ορισμός της κλάσης List
    class List {
    private:
        struct Node {
            Point data;
            Node *next;

            // Constructor
            Node(const Point &point, Node *nextNode = nullptr)
                : data(point), next(nextNode) {
                std::cout << "Node created with Point(" << data.x << ", " << data.y << ").\n";
            }
        };

        Node *head;
        size_t count; // Μέτρηση κόμβων για σταθερό χρόνο

    public:
        // Constructor
        List() : head(nullptr), count(0) {
            std::cout << "List created.\n";
        }

        // Destructor
        ~List() {
            while (head) {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            std::cout << "List destroyed and memory released.\n";
        }

        // Μέθοδος size
        size_t size() const { return count; }

        // Μέθοδος pushFront
        void pushFront(const Point &point) {
            head = new Node(point, head);
            ++count;
        }

        // Μέθοδος pop
        void pop(size_t position) {
            if (position >= count) {
                std::cout << "Invalid position.\n";
                return;
            }

            Node *temp = head;
            if (position == 0) {
                head = head->next;
                delete temp;
            } else {
                for (size_t i = 0; i < position - 1; ++i) {
                    temp = temp->next;
                }
                Node *toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;
            }
            --count;
            std::cout << "Node at position " << position << " removed.\n";
        }

        // Μέθοδος print
        void print() const {
            Node *current = head;
            size_t index = 0;

            if (!current) {
                std::cout << "List is empty.\n";
                return;
            }

            while (current) {
                std::cout << "Node " << index << ": ";
                current->data.print();
                current = current->next;
                ++index;
            }
        }
    };
}

int main() {
    using namespace mynamespace;

    // Άσκηση 3.7: Δοκιμή λειτουργιών
    List list;

    // Προσθήκη κόμβων
    list.pushFront(Point(1.0, 2.0));
    list.pushFront(Point(3.0, 4.0));
    list.pushFront(Point(5.0, 6.0));

    // Εκτύπωση λίστας
    list.print();

    // Διαγραφή κόμβου
    list.pop(1);
    list.print();

    // Έλεγχος μεγέθους
    std::cout << "List size: " << list.size() << "\n";

    return 0;
}
