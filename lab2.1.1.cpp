/*Άσκηση 1.1
Κατασκευάστε το πρόγραμμα primes.cpp το οποίο θα δέχεται ως είσοδο έναν ακέραιο και
i. θα βρίσκει όλους τους πρώτους αριθμούς μέχρι τον συγκεκριμένο ακέραιο και θα τους γράφει
σε έναν μονοδιάστατο πίνακα.
ii. θα γράφει σε έναν δεύτερο μονοδιάστατο πίνακα τους περιττούς πρώτους αριθμούς που έχει
βρεί και
iii. θα γράφει σε έναν τρίτο μονοδιάστατο πίνακα τους άρτιους πρώτους αριθμούς.
iv. θα εκτυπώνει τους πίνακες με τα στοιχεία του κάθε πίνακα χωρισμένα με στηλογνώμονα
(tab).*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


void sieve_of_Erato(int n, vector<int>& primes, vector<int>& odd_primes, vector<int>& even_primes){
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime

    // all of i -> root(n) = prime
    // and all of multiplicates of i starin from i*i are not prime
    for(int i = 2; i * i <= n; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            primes.push_back(i);
            if(i == 2){
                even_primes.push_back(i);
            }
            else {
                odd_primes.push_back(i);
            }
        }
    }
}

int main(){

    int n;

    cout << "What is your favorite integer number?\n";
    cin >> n;

    vector<int> primes, odd_primes, even_primes;
    sieve_of_Erato(n, primes, odd_primes, even_primes);

    cout << "The Prime Numbers:\n";
    for(int prime : primes){
        cout << prime << "\t";
    }
    cout << endl;

    cout << "Odd Prime Numbers:\n";
    for (int odd_prime : odd_primes) {
        cout << odd_prime << "\t";
    }
    cout << endl;

    cout << "Even Prime Numbers:\n";
    for (int even_prime : even_primes) {
        cout << even_prime << "\t";
    }
    cout << endl;

    return 0;
}