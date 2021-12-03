#include <iostream>
#include <string>
using namespace std;

int main(void){
    string userPrompt = "Please enter an integer between 0-99999:";
    string base_str;

    cout << userPrompt << endl;
    cin >> base_str;
    
    /* Reverse base and assign to exponent */
    string exp_str;
    bool leading_zeros = true;

    for( int i = base_str.size()-1; i >= 0; i = i-1 ){
        if( leading_zeros & base_str[i] == '0') {
        } else {
            exp_str.push_back(base_str[i]);
            leading_zeros = false;
        }   
    }

    /* Cast base and exponent to integers */
    size_t sz;
    int base = stoi(base_str, &sz);
    int exp = stoi(exp_str, &sz);

    /* FIX ME: remove output */
    cout << "base: " << base << endl;
    cout << "exponent: " << exp << endl;

    /* Perform exponential operation */

    return 0;
}