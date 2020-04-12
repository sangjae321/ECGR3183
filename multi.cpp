//require helper functions

//help from sanfoundry
int binaryproduct(int binary1, int binary2)
{
	int i = 0, remainder = 0, sum[20];
	int binaryprod = 0;

	while (binary1 != 0 || binary2 != 0)
	{
		sum[i++] = (binary1 % 10 + binary2 % 10 + remainder) % 2;
		remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
		binary1 = binary1 / 10;
		binary2 = binary2 / 10;
	}
	if (remainder != 0)
		sum[i++] = remainder;
	--i;
	while (i >= 0)
		binaryprod = binaryprod * 10 + sum[i--];
	return binaryprod;
}


string multi(string a, string b) {
	string A = a;
	//string op = operation;
	string signal_a = "";
	string exponent_a;
	string mantissa_a;
	string B = b;
	string signal_b = "";
	string exponent_b;
	string mantissa_b;

	//seperate signal, exponent, and mantissa
	for (int i = 0; i < 32; i++) {

		if (i == 0) {
			char g = A[0];
			char s = B[0];
			signal_a = (1, g);
			signal_b = (1, s);
		}
		else if (i > 0 && i <= 8) {
			exponent_a += A[i];
			exponent_b += B[i];
		}
		else {
			mantissa_a += A[i];
			mantissa_b += B[i];
		}

	}

	//get exponent
	int exa = binary2decimal(exponent_a) - 127;
	int exb = binary2decimal(exponent_b) - 127;
	int exp = exa + exb;

	
	//convert to int
	unsigned int mantissa_A, mantissa_B = 0;
	mantissa_a = "1" + mantissa_a;
	mantissa_b = "1" + mantissa_b;
	string check1 = mantissa_a.substr(0, 5);
	string check2 = mantissa_b.substr(0, 5);

	
	mantissa_A = stoi(check1);
	mantissa_B = stoi(check2);

	

	//multiply --help from sanfoundry
	long multiply = 0;
	int digit;
	int	factor = 1;


	while (mantissa_B != 0)
	{
		digit = mantissa_B % 10;
		if (digit == 1)
		{

			mantissa_A = mantissa_A * factor;
			multiply = binaryproduct(mantissa_A, multiply);

		}
		else
			mantissa_A = mantissa_A * factor;
		mantissa_B = mantissa_B / 10;
		factor = 10;
	}

	
	string mantissa_c = to_string((long long)multiply);
	string mainSig = "";
	int count = 0;

	//size

	for (int i = 0; i < mantissa_c.length(); i++) {
		count++;
	}


	//check length	
	if (mantissa_A + mantissa_B != count) {
		int dist = count - mantissa_A + mantissa_B;
		for (int i = 0; i < dist; i++) {
			exp += 1;
			mantissa_c.erase(0,1);
		}

	}


	//add remainding zeros

	while (mantissa_c.length() != 23) {
		mantissa_c += "0";
	}
	//signal
	if ((signal_a == "0" && signal_b == "0") || (signal_a == "1" && signal_b == "1")) {
		mainSig = "0";
	}
	if ((signal_a == "1" && signal_b == "0") || (signal_a == "0" && signal_b == "1")) {
		mainSig = "1";
	}
	

	string finExp = decimal2binary(127 + exp);


	string c = mainSig + finExp + mantissa_c;



	return c;
}
