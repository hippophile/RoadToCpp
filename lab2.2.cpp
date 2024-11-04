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

int main() {
    int x = 5, y = 10;

    cout << "Original values: x = " << x << ", y = " << y << endl;

    SwapByReference(x, y);
    cout << "After SwapByReference: x = " << x << ", y = " << y << endl;

    SwapByReference(x, y);

    SwapByPointer(&x, &y);
    cout << "After SwapByPointer: x = " << x << ", y = " << y << endl;

    return 0;
}
