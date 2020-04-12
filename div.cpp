string div(string a, string b) {
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
	int exp = exa - exb;




	//convert to int
	unsigned int mantissa_A, mantissa_B = 0;
	mantissa_a = "1" + mantissa_a;
	mantissa_b = "1" + mantissa_b;
	string check1 = mantissa_a.substr(0, 5);
	string check2 = mantissa_b.substr(0, 5);
	mantissa_A = stoi(check1);
	mantissa_B = stoi(check2);
	string mantissa_c = "";


	unsigned cur = 1;
	unsigned divided = 0;
	int c = binary2decimal(check1);
	int d = binary2decimal(check2);





	int carry = 0;
	string sum;
	string mainSig = "0";
	string one = "00000000000000000000001";
	//complement of 2 if it's negative
	if (signal_a == "1" && signal_b == "0") {
		for (int i = 0; i < mantissa_a.length(); i++) {

			if (mantissa_a[i] == '1') {
				mantissa_a[i] = '0';

			}
			else {
				mantissa_a[i] = '1';
			}

		}
		reverse(mantissa_a.begin(), mantissa_a.end());
		reverse(one.begin(), one.end());

		for (int i = 0; i < mantissa_a.length(); i++) {
			if (i < mantissa_a.size()) carry += (mantissa_a[i] - '0');
			if (i < one.size()) carry += (one[i] - '0');
			sum.push_back(carry % 2 + '0');
			carry /= 2;
		}
		if (carry) sum.push_back('1');
		reverse(sum.begin(), sum.end());
		mantissa_a = sum;


	}

	if (signal_a == "0" && signal_b == "1") {
		for (int i = 0; i < mantissa_b.length(); i++) {
			if (mantissa_b[i] == '1') {
				mantissa_b[i] = '0';
			}
			else {
				mantissa_b[i] = '1';
			}

		}


		reverse(mantissa_a.begin(), mantissa_a.end());
		reverse(one.begin(), one.end());

		for (int i = 0; i < mantissa_b.length(); i++) {
			if (i < mantissa_b.size()) carry += (mantissa_b[i] - '0');
			if (i < one.size()) carry += (one[i] - '0');
			sum.push_back(carry % 2 + '0');
			carry /= 2;
		}
		if (carry) sum.push_back('1');
		reverse(sum.begin(), sum.end());

		mantissa_b = sum;



	}

//condition if divisor equals dividend or divisor is greater than dividend
	if (d > c)
		mantissa_c = "00000000000000000000000";

	else if (d == c)
		mantissa_c = "00000000000000000000001";
	else {
		
		unsigned k = 1 << (sizeof(unsigned) * 8 - 1);
		while (((d & k) == 0) && ((d << 1) <= c)) {
			d <<= 1;
			cur <<= 1;
		}
		while (cur != 0) {
			if (c >= d) {
				c -= d;
				divided |= cur;
			}
			cur >>= 1;
			d >>= 1;
		}
	}


	mantissa_c = decimal2binary(divided);

	for (int i = 0; i < 23 - mantissa_c.length(); i++) {
		mantissa_c = mantissa_c + "0";
	}



	
	string finExp = decimal2binary(127 + exp);


	//get signal
	if ((signal_a == "1" && signal_b == "0") || (signal_a == "0" && signal_b == "1")) {
		mainSig = "1";
	}
	if ((signal_a == "0" && signal_b == "0") || (signal_a == "1" && signal_b == "1")) {
		mainSig = "0";
	}

	
	string g = mainSig + finExp + mantissa_c;

	return g;

}
