/*Άσκηση 3 - Δυναμική δέσμευση μνήμης
Γράψτε ένα πρόγραμμα που μπορεί να χρησιμοποιηθεί για τη συλλογή δεδομένων σχετικά με
τον αριθμό των αγώνων τένις που παίζουν οι φοιτητές σε ένα έτος. Το πρόγραμμα θα πρέπει να
εκτελεί τα εξής βήματα:
α) Στη συνάρτηση "main", να ρωτήσετε τον χρήστη πόσοι φοιτητές συμμετείχαν στην
έρευνα.
Ένας πίνακας τύπου 'string' και ένας πίνακας τύπου 'int' θα πρέπει να είναι δυναμικά
και ο ένας θα αποθηκεύει το όνομα κάθε μαθητή και ο άλλος θα αποθηκεύει τον αριθμό
των αγώνων τένις που έπαιξε κάθε μαθητής κατά τη διάρκεια του έτους.
β) Η συνάρτηση "input" θα πρέπει να κληθεί για να γεμίσει τους δύο πίνακες.
Μην δέχεστε αρνητικούς αριθμούς κατά την εισαγωγή του αριθμού των αγώνων τένις.
Εάν εισαχθεί ένας αρνητικός αριθμός, τότε θα πρέπει να ζητηθεί ο χρήστης να εισάγει εκ
νέου τον σωστό αριθμό.
γ) Η συνάρτηση 'displayMostMatches' θα πρέπει να κληθεί για να υπολογίσει τον
μαθητή που έπαιξε τους περισσότερους αγώνες. Πρέπει να εμφανίζει το όνομα του
μαθητή και τον αριθμό των αγώνων που έπαιξε.
δ) Η συνάρτηση 'mean' θα πρέπει να κληθεί για να υπολογιστεί ο μέσος αριθμός των
αγώνων που διεξήχθησαν.
ε) Η συνάρτηση 'sortStudents' θα πρέπει να κληθεί για να ταξινομήσει τον πίνακα των
μαθητών ενώ ο πίνακας που αποθηκεύει τον αριθμό των αγώνων που έπαιξε κάθε
μαθητής θα πρέπει να ενημερωθεί αναλόγως. Μετά την εκτέλεση της συνάρτησης, οι
ενημερωμένοι πίνακες θα πρέπει να εμφανιστούν στην έξοδο.
Λειτουργικές απαιτήσεις:
void input(string names[], int matches[], int size)
Επιτρέπει στο χρήστη να εισάγει το όνομα κάθε μαθητή και τον αριθμό των αγώνων τένις που
έπαιξε ο εν λόγω μαθητής και να αποθηκεύει τις πληροφορίες αυτές σε τους δύο πίνακες.
void display(const string names[], const int matches[], int size)
Εμφανίζει τα ονόματα των μαθητών και τον αριθμό των αγώνων που ο καθένας έχει παίξει.
void displayMostMatches(const string names[], const int matches[], int size)
ΑΝΤΙΚΕΙΜΕΝΟΣΤΡΑΦΗΣ ΠΡΟΓΡΑΜΜΑΤΙΣΜΟΣ
Εργαστήριο 2: Oop – new/delete
Εμφάνιση του ονόματος του μαθητή που έπαιξε τους περισσότερους αγώνες τένις κατά τη
διάρκεια του έτους, καθώς και τον αριθμό των αγώνων που έπαιξε.
double mean(const int matches[], int num)
Τα ορίσματα αυτής της συνάρτησης είναι ένας πίνακας ακεραίων αριθμών και ο αριθμός των
στοιχείων του πίνακα. Η συνάρτηση θα πρέπει να προσδιορίζει τον μέσο όρο του πίνακα και να
επιστρέφει την τιμή αυτή ως τύπο double.*/
#include <iostream>
#include <string>
using namespace std;

void input(string names[], int matches[], int size){

    for(int i = 0; i < size; i++){
        cout << "enter one name: ";
        cin >> names[i];
        cout << "enter how many games he played: ";
        cin >> matches[i];
        while(matches[i] < 0){
            cout << "You are dumb, try again";
            cout << "enter how many games he played: ";
            cin >> matches[i];
        }
    }
}

void display(const string names[], const int matches[], int size){
    for(int i = 0; i < size; i++){
        cout << endl << names[i];
        cout << matches[i] << endl;
    }
}

void displayMostMatches(const string names[], const int matches[], int size){
    int max = 0;

    for(int i = 1; i < size; i++){
        if(matches[max] < matches[i]){
            max = i;
        }
    }
    cout << endl << names[max];
    cout << matches[max] << endl;

}
   
double mean(const int matches[], int num){
    if(num <= 0) return 0;
    double x = 0;

    for(int i = 0; i < num; i++){
        x += matches[i];
    }
    double average = x / num;
    cout << "The average of the games that have been played is: " << average << endl;
    return average;
}

int main(){
    int size;
    
    cout << "How many students did the survey: " << endl;
    cin >> size;

    int *matches = new int[size];

    if(matches == NULL){
        cout << "You are dumb, try again";
    }

    string *names = new string[size];
    
    

    if(names == NULL){
        cout << "You are dumb, try again";
    }

    input(names, matches, size);
    displayMostMatches(names, matches, size);
    mean(matches, size);

    delete[] names;
    delete[] matches;

    return 0;
}