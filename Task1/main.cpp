#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
    
    if(exp == 0 ){
        std::cout << "1";
        return;
    }
    
    vector<int> res;
    int temp = base;
    
    // Initialize res.ans
    while (temp != 0) {
        res.push_back(temp % 10);
        temp = temp / 10;
    }
    
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

int main(void){
    string userPrompt = "Please enter an integer between 0-99999: ";
    string base_str;

    cout << userPrompt;
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

    /* Perform exponential operation */
    pow(base, exp);

    return 0;
}