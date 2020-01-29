#include <iostream>
using namespace std;


typedef union{
    float f;
    struct FP
    {
        unsigned int fraction : 23;    
        unsigned int exponent : 8;    
        unsigned int sign : 1;
    }FP;
}myfloat;
   

int main(){
    myfloat var;  
    
    std::cout << "Enter real number: " << endl;
    std::cin >> var.f;
    
}

