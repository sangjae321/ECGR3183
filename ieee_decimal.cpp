#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int exponent(string input){
    int ans = 0;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '1'){
            ans += pow(2, input.size()-1-i);
        }
    }
    return ans-127;
}

double bin_dec(string input){
    double ans = 0;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '1'){
            ans += pow(2, input.size()-1-i);
        }
    }
    return ans;
}

double bin_frac(string input){
    double ans = 0;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '1'){
            ans += 1/pow(2, i+1);
        }
    }
    return ans;
}

double ieee_decimal(string input){
    if(input == "00000000000000000000000000000000"){
        return 0;
    }
    if(input == "01111111100000000000000000000000"){
        ///IDK What to return
        return 99999999999999999999999999999999999;
    }
    if(input == "11111111100000000000000000000000"){
        ///IDK what to return
        return -9999999999999999999999999999999999;
    }
    ///Is the number negative or positive
    int s = int(input[0]) - 48;
    ///Finds the decimal number of the exponent
    int e = exponent(input.substr(1, 8));
    ///Sets the Mantissa to a string
    string m = input.substr(9);
    ///Finds the integer binary number
    string inte = "1" + m.substr(0,e);
    ///Finds the integer in decimal
    double integer = bin_dec(inte);
    ///Finds the decimal in decimal
    double decimal = bin_frac(m.substr(e));
    if(s == 0){
        return integer+decimal;
    }
    else{
        return (integer+decimal) * -1;
    }
}

int main(){
    string input = "00000000000000000000000000000000";
    cout << ieee_decimal(input) << endl;
return 0;
}
