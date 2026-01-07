
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int main() {
    vector<int> vec {121 , 232, 3233};
    int sum {0};
    for (int i = 0; i< vec.size() ; i++)
    {
        int v = vec[i];
        string str = to_string(v);
        int s = str.size();
        int d{0};
        vector <int> digits {};
        
        for (int i = 0; i < s ; i++)
        {
            d =  v%((int)pow(10,s - i)) - v%((int)pow(10,s-1 - i));
            d = d/((int)pow(10,s-1 - i));
            cout << "digits are " << d << endl;    
            digits.push_back(d);
        }
        int l{digits[0]};
    
        for (int i = 0; i < s ; i++)
        {
            l = (l> digits[i+1]) ? l : digits[i+1];
            cout << l << endl;
        }
        
        int encrypt{0};
        for (int i = 0; i<s ; i++)
        {
            encrypt += l * (pow(10,s-i-1));
        }
        cout << "Encryup" << encrypt;
        sum += encrypt;    
        
    }
    cout << "total sum is " << sum;

}