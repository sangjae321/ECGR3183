#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

///DECIMAL TO IEEE
string whole(double input){
    int whole = int(input);
    vector<int> a;
    string out;
    while(whole > 0){
        a.push_back(whole % 2);
        whole /= 2;
    }
    for(int i = a.size()-1; i >= 0; i--){
        out.append(to_string(a[i]));
    }
    return out;
}

string decimal(double input){
    double decimal = input - int(input);
    vector<int> a;
    string out;
    for(int i = 0; i < 23; i++){
        a.push_back(int(decimal*2));
        decimal = (decimal * 2) - int(decimal * 2);
    }
    for(int i = 0; i < a.size(); i++){
        out.append(to_string(a[i]));
    }
    return out;
}

string decimal2ieee(double input){
    string out;
    string w = whole(input);
    string d = decimal(input);
    int exponent = (w.size()-1) + 127;
    string exp = whole(exponent);
    w = w.substr(1, w.size());
    if(input < 0){
        out.append("1");
    }
    else{
        out.append("0");
    }
    out.append(exp);
    out.append(w);
    out.append(d);
    out = out.substr(0, 32);
    return out;
}

///IEEE TO DECIMAL

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

double ieee2decimal(string input){
    if(input == "00000000000000000000000000000000"){
        cout << 0;
    }
    if(input == "01111111100000000000000000000000"){
        cout << "INF" << endl;

    }
    if(input == "11111111100000000000000000000000"){
        cout << "-INF" << endl;

    }
    if(input.substr(1,8) == "11111111"){
        cout << "NAN" << endl;

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

int binary2decimal (string input){
    int ans = 0;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '1'){
            ans += pow(2, input.size()-1-i);
        }
    }
    return ans;
}




#endif // HELPER_H_INCLUDED
