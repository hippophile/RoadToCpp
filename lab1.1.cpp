#include <iostream>
using namespace std;

// Oops
// Fly like an aeroplane
class Customer {       // The class
  public:             // Access specifier
    int num_account ;        // Attribute (int variable)
   // int pass;
    int premium_channels;  
    int num_con;                // Attribute (string variable)
};

// int stef_filip(Customer.num_account,  Customer.premium_channels, x,  Customer.num_con){

// };

int main(){
    Customer normal;
    Customer weird;
    
    char x;
    int y;

    cin >> x;


    if(x == 'R' || x == 'r'||x == 'B' || x == 'b' ){
        if(x == 'R' || x == 'r'){
            cin >> normal.num_account;
            cin >> normal.premium_channels;
            cin >> normal.num_con;            
        }
        else{
            cin >> weird.num_account;
            cin >> weird.premium_channels;
            cin >> weird.num_con;
        }
    }

    cout << "FU";

    return 0;
}