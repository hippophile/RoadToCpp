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
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;

    void print_info() const {
        cout << '(' << x << ',' << y << ')' << endl;
    }

public:
    Point(double cordx = 0.0, double cordy = 0.0) : x(cordx), y(cordy) {}

    void set(double cordx, double cordy) {
        x = cordx;
        y = cordy;
    }

    void print() const {
        print_info();
    }

    double dist(const Point& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    bool equal(const Point& another) const {
        return ((x == another.x) && (y == another.y));
    }

    friend class Triangle;  // Allow Triangle to access private members
};

class Triangle {
private:
    Point p1, p2, p3;

public:
    Triangle(const Point& point1 = Point(), const Point& point2 = Point(), const Point& point3 = Point())
        : p1(point1), p2(point2), p3(point3) {}

    void set(const Point& point1, const Point& point2, const Point& point3) {
        p1 = point1;
        p2 = point2;
        p3 = point3;
    }

    void print() const {
        cout << "P1 = "; p1.print();
        cout << "P2 = "; p2.print();
        cout << "P3 = "; p3.print();
    }

    const Point& get(int index) const {
        if (index == 0) return p1;
        else if (index == 1) return p2;
        else if (index == 2) return p3;
        throw out_of_range("Index out of bounds");
    }

    double area() const {
        return 0.5 * std::abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
    }

    bool equal(const Triangle& other) const {
        return this->area() == other.area();
    }

    bool is_the_same(const Triangle& another) const {
        return p1.equal(another.p1) && p2.equal(another.p2) && p3.equal(another.p3);
    }
};

int main() {
    Point p1(1.0, 1.0), p2(2.0, 2.0), p3(3.0, 3.0);
    Triangle triangle1(p1, p2, p3);

    // Set and print Point
    p1.set(5.0, 5.0);
    p1.print();

    // Print Triangle details
    triangle1.print();
    cout << "Area of triangle: " << triangle1.area() << endl;

    // Testing equality and same triangles
    Triangle triangle2(p1, p2, p3);
    cout << "Triangles are equal: " << (triangle1.equal(triangle2) ? "Yes" : "No") << endl;
    cout << "Triangles are the same: " << (triangle1.is_the_same(triangle2) ? "Yes" : "No") << endl;

    return 0;
}
