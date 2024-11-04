#include <iostream>
using namespace std;

void ReadArray(char* array, int size) {
    cout << "Input " << size << " characters: ";

    int length = 0;
    while (length < size) {
        char ch;
        cin.get(ch);

        if (ch == '\n') break;

        array[length] = ch;
        length++;
    }
    array[length] = '\0';
}

void PrintArray(char* array, int size) {
    cout << "Your array with size " << size << " is: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i];
    }
    cout << endl;
}

int DeleteRepeats(char array[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[i] == array[j]) {
                
                for (int k = j; k < size - 1; ++k) {
                    array[k] = array[k + 1];
                }
                size--;  
                j--;     
                PrintArray(array, size); 
            }
        }
    }
    return size;
}

int main() {
    int size;
    cout << "Input the size of your array: ";
    cin >> size;

    cin.ignore();

    char* array = new char[size + 1];

    ReadArray(array, size);
    PrintArray(array, size);

    size = DeleteRepeats(array, size);
    PrintArray(array, size);
    delete[] array;

    return 0;
}
