/*Άσκηση 2.1 - Pointers
I. Γράψτε μια συνάρτηση που ανταλλάσσει δύο ακέραιες τιμές χρησιμοποιώντας
call-by-reference.
II. Ξαναγράψτε τη συνάρτησή σας και χρησιμοποιήσετε δείκτες αντί για αναφορές.
ΑΝΤΙΚΕΙΜΕΝΟΣΤΡΑΦΗΣ ΠΡΟΓΡΑΜΜΑΤΙΣΜΟΣ
Εργαστήριο 2: Oop – new/delete
III. Γράψτε μια συνάρτηση παρόμοια με αυτή του μέρους ΙΙ, αλλά αντί να ανταλλάσσει δύο
τιμές, ανταλλάσσει δύο δείκτες που δείχνουν ο ένας στις τιμές του άλλου. Η συνάρτησή
σας θα πρέπει να λειτουργεί σωστά για το ακόλουθο παράδειγμα κλήσης:
int x = 5, y = 6;
int * ptr1 = &x, * ptr2 = & y;
swap (& ptr1 , & ptr2 ) ;
cout << * ptr1 << ’ ’ << * ptr2 ; // Prints "6 5"*/

#include <iostream>
using namespace std;

void SwapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void SwapByPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SwapPointers(int** ptr1, int** ptr2) {
    int* temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "Original values: x = " << x << ", y = " << y << endl;

    SwapByReference(x, y);
    cout << "After SwapByReference: x = " << x << ", y = " << y << endl;

    SwapByReference(x, y);

    SwapByPointer(&x, &y);
    cout << "After SwapByPointer: x = " << x << ", y = " << y << endl;

    int a = 5, b = 6;
    int* ptr1 = &a;
    int* ptr2 = &b;
    cout << "Original pointers: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;

    SwapPointers(&ptr1, &ptr2);
    cout << "After SwapPointers: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;

    return 0;
}
