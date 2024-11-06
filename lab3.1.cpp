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
#include <string>
#include <cmath>
using namespace std;

class Point{
    private:
        double x, y;

        void print_info(){
            cout << '(' << x << ',' << y << ')' << endl;
        }
    
    public:
        Point(double cordx = 0.0, double cordy = 0.0) : x(cordx), y(cordy) {}

        ~Point(){}
    
    void set(double cordx, double cordy){
        x = cordx;
        y = cordy;
    }

    void print(){
        print_info();
    }

    double dist(const Point& other){
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    bool equal(const Point& another){
        return ((x == another.x) && (y == another.y));
    }

};

class Triangle{
    private:
        Point p1, p2, p3;

    private: 
        Triangle(const Point& point1 = Point(), const Point& point2 = Point(), const Point& point3 = Point())
            : p1(point1), p2(point2), p3(point3){}

        ~Triangle(){}

    void set(Point point1, Point point2, Point point3){
        p1 = point1;
        p2 = point2;
        p3 = point3;
    }

    void print(){
        cout << "P1 = "; p1.print();
        cout << "P2 = "; p2.print();
        cout << "P3 = "; p3.print();
    }

    const Point& get(int index){
        if (index == 0) return p1;
        if (index == 1) return p2;
        if (index == 2) return p3;
        return NULL;
    }

    double area(const Point& a, const Point& b, const Point& c){
        return 0.5 * std::abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    }

    bool equal(const Triangle& other){
        return area() == other.area();
    }

    bool is_the_same(const Triangle& another){
        return p1.equal(another.p1) && p2.equal(another.p2) && p3.equal(another.p3);
    }

};