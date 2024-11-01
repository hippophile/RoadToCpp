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