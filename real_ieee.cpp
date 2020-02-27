#include <iostream>
#include <string>

using namespace std;


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




/*void convertReal(int a) {
	long dec = 0, j = 1, r;
	while (a != 0)
	{
		r = a % 10;
		dec = dec + r * j;
		j = j * 2;
		a = a / 10;
	}
	myfloat var;
	var.f = dec;
	std::cout << var.SP.sign << " ";
	printBinary(var.SP.exponent, 8);
	std::cout << " ";
	printBinary(var.SP.fraction, 23);
	std::cout << endl;

}
*/


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


	/*int binary;
	std::cout << "Enter binary number: " << endl;
	std::cin >> binary;

	convertReal(binary);

	return 0;
	*/
}