#include <iostream>
#include <unistd.h> // Για την usleep() στο Linux

using namespace std;

void printWithDelay(const string &message, int delayMicroseconds) {
    for (char c : message) {
        cout << c << flush; // Χρησιμοποιούμε flush για άμεση εκτύπωση κάθε χαρακτήρα
        usleep(delayMicroseconds); // Καθυστέρηση σε μικροδευτερόλεπτα
    }
    cout << endl; // Τέλος γραμμής
}

void blinkText(const string &message, int repeat, int delayMicroseconds) {
    for (int i = 0; i < repeat; ++i) {
        cout << "\r" << message << flush;
        usleep(delayMicroseconds);
        cout << "\r" << string(message.size(), ' ') << flush;
        usleep(delayMicroseconds);
    }
    cout << "\r" << message << endl; // Επανεμφάνιση του μηνύματος στο τέλος
}

void matrixEffect(int width, int height) {
    while (true) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << (rand() % 2); // Τυχαίος χαρακτήρας 0 ή 1
            }
            cout << endl;
        }
        usleep(100000); // Καθυστέρηση 0,1 δευτερόλεπτα
        system("clear");
    }
}

void loadingBar(int length, int delayMicroseconds) {
    cout << "[";
    for (int i = 0; i < length; ++i) {
        cout << "=" << flush;
        usleep(delayMicroseconds);
    }
    cout << "] Ολοκληρώθηκε!" << endl;
}

void loadingRoller(int repeat, int delayMicroseconds) {
    const char symbols[] = {'|', '/', '-', '\\'};
    for (int i = 0; i < repeat; ++i) {
        cout << "\r" << symbols[i % 4] << flush;
        usleep(delayMicroseconds);
    }
    cout << "\r" << "Ολοκληρώθηκε!" << endl;
}



int main() {
    string message = "I want my money bitch!...";
    int delayMicroseconds = 100000; // 100000 μικροδευτερόλεπτα = 0.1 δευτερόλεπτο

     printWithDelay(message, delayMicroseconds);
    // blinkText("Προσοχή!", 5, 500000); // Αναβοσβήνει 5 φορές, καθυστέρηση 0,5 δευτερόλεπτα
    // matrixEffect(40, 20); // Πλάτος 40, ύψος 20
    // loadingBar(20, 200000); // 20 θέσεις, καθυστέρηση 0,2 δευτερόλεπτα ανά θέση
    // loadingRoller(20, 200000); // Κυκλικά για 20 επαναλήψεις
    


    return 0;
}
