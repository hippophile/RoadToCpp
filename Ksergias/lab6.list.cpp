/*Άσκηση 1 – Κλάσεις - const member functions – mutators – accessors
1.1. Ορίστε μία “class” που θα αναπαριστά την έννοια του σημείου στο δισδιάστατο χώρο και μία
“class” για την έννοια του τριγώνου (μπορείτε να χρησιμοποιήσετε ένα ή περισσότερα
αρχεία).
Σε μια ενδεικτική main δημιουργήστε μερικά αντικείμενα των παραπάνω τύπων.
1.2. Προσθέστε μία μέθοδο “set” που θα δίνει τιμές στα αντικείμενα. Για το σημείο θα δέχεται 2
συντεταγμένες, ενώ τα υπόλοιπα σημεία που αναπαριστούν το τρίγωνο θα δέχονται 3
αντίστοιχα.
Κάντε αντίστοιχα δοκιμές στην main.
1.3. Προσθέστε μία μέθοδο “print“ που θα εκτυπώνει τα δεδομένα κάθε αντικειμένου. Για το σημείο
ειδικότερα, χρησιμοποιήστε επιπλέον μια μέθοδο “printInfo” που θα οριστεί σαν private (η
“print” να χρησιμοποιεί την “printInfo”).
1.4. Προσθέστε μία συνάρτηση μέλος “get” στο τρίγωνο, που δεδομένου ενός αριθμού index θα
επιστρέφει το αντίστοιχο σημείο του τριγώνου. Τι διαφορές προκύπτουν αν η συνάρτηση μέλος
επιστρέφει αναφορά ή όχι; Αν το σημείο που επιστρέφεται είναι const ή όχι;
1.5. Προσθέστε μία συνάρτηση μέλος “dist” στο σημείο, που δεδομένου ενός άλλου σημείου
υπολογίζει την σχετική τους απόσταση. Επίσης, προσθέστε μία συνάρτηση μέλος “area” στο
τρίγωνο που θα υπολογίζει το εμβαδόν (έστω για πειραματισμό πάντα η τιμή 1).
1.6. Προσθέστε μία συνάρτηση μέλος “equal” που υπολογίζει αν δύο σημεία ή τρίγωνα είναι ίσα
αντίστοιχα. Στα τρίγωνα αυτό γίνεται συγκρίνοντας τα εμβαδά τους. Επίσης Προσθέστε μία
συνάρτηση μέλος “isTheSame” στο τρίγωνο που υπολογίζει αν δύο τρίγωνα είναι τα ίδια (και
όχι απλά να έχουν ίσο εμβαδόν)*/

#include <iostream>
#include <memory> //  std::shared_ptr και std::unique_ptr

namespace std {

    // 1.1 & 1.2
    struct Point {
        double x; 
        double y; 

        Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {
            cout << "Constructor called: Point(" << x << ", " << y << ") created.\n";
        }

        ~Point() {
            cout << "Destructor called: Point(" << x << ", " << y << ") destroyed.\n";
        }

        double getX() const { return x; }
        double getY() const { return y; }
        void setX(double newX) { x = newX; }
        void setY(double newY) { y = newY; }

        void print() const {
            cout << "Point(" << x << ", " << y << ")\n";
        }
    };

    // Άσκηση 2:
    struct Node {
        Point data;
        shared_ptr<Node> next;      // shared_ptr >> new

        
        Node(const Point &point, shared_ptr<Node> nextNode = nullptr)
            : data(point), next(nextNode) {
            cout << "Node created with Point(" << data.x << ", " << data.y << ").\n";
        }
    };

    // Άσκηση 3:
    class List {
    private:
        struct Node {
            Point data;
            Node *next;

            // Constructor
            Node(const Point &point, Node *nextNode = nullptr)
                : data(point), next(nextNode) {
                cout << "Node created with Point(" << data.x << ", " << data.y << ").\n";
            }
        };

        Node *head;
        size_t count;

    public:
        
        List() : head(nullptr), count(0) {
            cout << "List created.\n";
        }

        ~List() {
            while (head) {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            cout << "List destroyed and memory released.\n";
        }

        size_t size() const { return count; }

        void pushFront(const Point &point) {
            head = new Node(point, head);
            ++count;
        }

        void pop(size_t position) {
            if (position >= count) {
                cout << "Invalid position.\n";
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
            cout << "Node at position " << position << " removed.\n";
        }

        void print() const {
            Node *current = head;
            size_t index = 0;

            if (!current) {
                cout << "List is empty.\n";
                return;
            }

            while (current) {
                cout << "Node " << index << ": ";
                current->data.print();
                current = current->next;
                ++index;
            }
        }
    };
}

int main() {
    using namespace std;

    List list;

    list.pushFront(Point(1.0, 2.0));
    list.pushFront(Point(3.0, 4.0));
    list.pushFront(Point(5.0, 6.0));


    list.print();

    list.pop(1);
    list.print();

    cout << "List size: " << list.size() << "\n";

    return 0;
}
