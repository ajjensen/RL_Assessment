/* Rocket Lab Assessment: Task #1
This program prompts the user for an integer between 0 and 99,999. The input is then used to 
create an exponential, where the input is the base and the digits of the input in reverse order
form the exponent.

Since the largest integer most 64-bit systems can store is 2^64 - 1, we must have special handling
for any inputs over 36.

The code below uses the following algorithm which performs stepwise multiplication and stores the
result at each step in a vector:

    Power(base, exp) 
    1. Create an vector res[] and store each digit of the input (base) in res[]. 
    2. Do following for all numbers from i=1 to res.size() (for each digit in the input) 
        … Multiply base with res[] and update res[] to store the multiplication result.
    
    Multiply(base, current) 
    1. Initialize carry as 0. 
    2. Do following for i=0 to res_size-1 
        … a. Find prod = res[i]*base + carry. 
        … b. Store last digit of prod in res[i] and remaining digits in carry. 
    3. Store all digits of carry in res[]. 

This algorithm was based on one found at the link below. It was improved by using a vector rather than
arrays to store the final number for simplicity:

https://www.geeksforgeeks.org/writing-power-function-for-large-numbers/

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> mult(int, vector<int>);
void pow(int, int);

int main(void){
    string userPrompt = "Please enter an integer between 0-99999: ";
    string base_str;

    cout << userPrompt;
    cin >> base_str;
    
    // Check for appropriate input
    try{
        for(int i = 0; i < base_str.size()-1; i++){
            if( std::isdigit(base_str[i]) == 0 ){
                throw base_str;
            }
        }
    }
    catch(string badInput){
        cout << "\n\n" << "Your input \'" << badInput << "\' contains non-numeric characters.\n";
        cout << "Please enter an integer." << endl;
        return 0;
    }
    
    // Reverse base and assign to exponent
    string exp_str;
    bool leading_zeros = true;

    for( int i = base_str.size()-1; i >= 0; i = i-1 ){
        if( leading_zeros & base_str[i] == '0') {
        } else {
            exp_str.push_back(base_str[i]);
            leading_zeros = false;
        }   
    }

    // Cast base and exponent to integers 
    size_t sz;
    int base = stoi(base_str, &sz);
    int exp = stoi(exp_str, &sz);

    // Perform exponential operation
    pow(base, exp);

    return 0;
}

vector<int> mult(int x, vector<int> cur){
    
    // Initialize carry
    int carry = 0;
 
    // One by one multiply n with
    // individual digits of res[]
    for (int i = 0; i < cur.size(); i++) {
        int prod = cur[i] * x + carry;
        
        // Store last digit of
        // 'prod' in res[]
        cur[i] = prod % 10;
        
        // Put rest in carry
        carry = prod / 10;
    }
    
    while (carry) {
        cur.push_back(carry % 10);
        carry = carry / 10;
    }
    
    return cur;
}

void pow(int base, int exp){
    
    // Special case if exp is 0
    if(exp == 0 ){
        std::cout << "1";
        return;
    }
    
    vector<int> res;
    int temp = base;
    
    // Initialize res by storing each digit at each index
    while (temp != 0) {
        res.push_back(temp % 10);
        temp = temp / 10;
    }
    
    // Perform each multiplication and update the result at every iteration
    for(int i = 1; i < exp; i = i+1) {
        res = mult(base, res);
    }
    
    // Output Result
    std::cout << "\nResult: " << base <<"^"<< exp << " is \n";
    for (int i = res.size() - 1; i >= 0; i--){
        std::cout << res[i];
    }
    std::cout << endl << endl;
}