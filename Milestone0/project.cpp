#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;









double binaryToDecimal(string binary, int len) 
{ 
    // Fetch the radix point 
    size_t point = binary.find('.'); 
  
    // Update point if not found 
    if (point == string::npos) 
        point = len; 
  
    double intDecimal = 0, fracDecimal = 0, twos = 1; 
  
    // Convert integral part of binary to decimal 
    // equivalent 
    for (int i = point-1; i>=0; --i) 
    { 
        // Subtract '0' to convert character 
        // into integer 
        intDecimal += (binary[i] - '0') * twos; 
        twos *= 2; 
    } 
  
    // Convert fractional part of binary to 
    // decimal equivalent 
    twos = 2; 
    for (int i = point+1; i < len; ++i) 
    { 
        fracDecimal += (binary[i] - '0') / twos; 
        twos *= 2.0; 
    } 
  
    // Add both integral and fractional part 
    return intDecimal + fracDecimal; 
} 










//function to convert to binary and print  
void printBinary(int n, int a)
{

	//creates an array to store each bits
	int *arr=new int[a];

	//loop and convert the number by getting remainder of 2
	int i = 0;
	while (1) {
		arr[i] = n % 2;
		n = n / 2;
		i++;
		if (n == 0) {
			while (i < a) {
				arr[i] = 0;
				i++;
			}
			break;
		}
	}
	//prints the binary
	for (int j = i-1 ; j >= 0; j--)
		cout << arr[j];
	delete[] arr;
}


void toDecimal(string s){
    char *bits = new char[s.length()];
    string signal = "";
    string tempExp = "";
    string tempFrac = "";
    int exp = 0;
    float dec = 0;
    
    for (int i = 0; i < s.length(); i++) { 
        bits[i] = s[i];
        if(i == 0)
        signal = signal + bits[i];
        else if(i > 0 && i < 9)
        tempExp = tempExp + bits[i]; 
        else
        tempFrac = tempFrac + bits[i];
    }
        
       
        
        
        exp = std::stoi(tempExp, 0, 2);
        exp = exp - 127;
      
      
        
        
     
    string hold = "1" + tempFrac;
    
    
    
    
    
    if(exp > 0)
    int a = 0;
    while(1){
    
    
    pow(hold[a], )
    
    
    
    
    a++;
    }
    
    cout << hold << endl;
     dec = stof(hold);
       
     
        
        
    double fract = binaryToDecimal(hold, hold.length());
    
    
    
    
}





































//union to allocate to the same memory 32bits
typedef union {
	float f;
	struct SP
	{
		unsigned int fraction : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	}SP;
}myfloat;





int main() {
	myfloat var;

	//user input
	std::cout << "Enter real number: " << endl;
	std::cin >> var.f;

	//prints IEEE 754 Single Precision    
	std::cout << var.SP.sign << ' ';
	printBinary(var.SP.exponent, 8);
	std::cout << ' ';
	printBinary(var.SP.fraction, 23);
	std::cout << endl;


	string binary;
	std::cout << "Enter binary number: " << endl;
	std::cin >> binary;
	toDecimal(binary);
	return 0;
	
} 
