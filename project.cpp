#include <iostream>

using namespace std;

//function to convert to binary and print  
void printBinary(int n, int a)
{
    //creates an array to store each bits
    int arr[a]; 
  
    //loop and convert the number by getting remainder of 2
    int i = 0; 
    while (n > 0) { 
        
        arr[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    //prints the binary
    for (int j = i - 1; j >= 0; j--) 
        cout << arr[j]; 
}
    //union to allocate to the same memory 32bits
typedef union{
    float f;
    struct SP
    {
        unsigned int fraction : 23;    
        unsigned int exponent : 8;    
        unsigned int sign : 1;
    }SP;
}myfloat;


int main(){
    myfloat var;  
    
    //user input
    std::cout << "Enter real number: " << endl;
    std::cin >> var.f;

    //prints IEEE 754 Single Precision    
    std::cout << var.SP.sign << " ";
    printBinary(var.SP.exponent, 8);
    std::cout << " ";
    printBinary(var.SP.fraction, 23);
    std::cout << endl;
    
    return 0;
}


   