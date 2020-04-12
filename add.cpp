//requires helper function
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <vector>
#include<sstream>

//string a and b is ieee 754
//string operation is the binary for op

string add(string a, string b, string operation) {
	string A = a;
	string op = operation;
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
		else if ( i > 0 && i <= 8) {
			exponent_a += A[i];
			exponent_b += B[i];
		}
		else {
			mantissa_a += A[i];
			mantissa_b += B[i];
		}

	}
	
	if (op == "00101") {
		if(signal_b == "1"){
			signal_b = "0";
		}
	}



	int exa = binary2decimal(exponent_a) - 127;
	int exb = binary2decimal(exponent_b) - 127;

	int exp = 0;
	int distance = 0;
	//alignment
	if ((exa - exb) > 0) {
		exp = exa;
		distance = exa - exb;
		for (int i = 0; i < (exa - exb); i++) {	

			if (i == 0) {
				mantissa_b ="1" + mantissa_b;
			}
			else {
				mantissa_b = "0" + mantissa_b;
			}
		}
		mantissa_b.erase(23,(exa-exb)+1);
		mantissa_a = "1" + mantissa_a;
		mantissa_b = "0" + mantissa_b;
	}

	else if ((exb - exa) > 0) {
		exp = exb;
		distance = exb - exa;
		for (int i = 0; i < (exb - exa); i++) {	

			if (i == 0) {
				mantissa_a ="1" + mantissa_a;
			}
			else {
				mantissa_a = "0" + mantissa_a;
			}
		}
		mantissa_a = "0" + mantissa_a;
		mantissa_b = "1" + mantissa_b;

	}
	else {
		exp = exa;
	}
	
	
	int carry = 0;
	string sum;
	string summi = "";
	string expb = "";
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
				summi.push_back(carry % 2 + '0');
				carry /= 2;
			}
			if (carry) summi.push_back('1');
			reverse(summi.begin(), summi.end());
			mantissa_a = summi;
		
		
	}

	if(signal_a == "0" && signal_b == "1") {
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
				summi.push_back(carry % 2 + '0');
				carry /= 2;
			}
			if (carry) summi.push_back('1');
			reverse(summi.begin(), summi.end());

			mantissa_b = summi;
		

	
	}
		
	//add	
		reverse(mantissa_a.begin(), mantissa_a.end());
		reverse(mantissa_b.begin(), mantissa_b.end());

		for (int i = 0; i < mantissa_a.length(); i++) {
			if (i < mantissa_a.size()) carry += (mantissa_a[i] - '0');
			if (i < mantissa_b.size()) carry += (mantissa_b[i] - '0');
			sum.push_back(carry % 2 + '0');
			carry /= 2;
		}
		if (carry) sum.push_back('1');
		reverse(sum.begin(), sum.end());
		
		

	//signal after addition
		if(signal_a == "1" && signal_b == "1"){
			mainSig = "1";
		}

		if (signal_a == "1" && exa > exb) {
			mainSig = "1";
		}

		if (signal_a == "1" && exa < exb) {
			mainSig = "0";
		}

		if (signal_b == "1" && exb > exa) {
			mainSig = "1";
		}

	    if (signal_b == "1" && exb < exa) {
			mainSig = "0";
		}

		string check1 = mantissa_a.substr(0, 5);
		string check2 = mantissa_b.substr(0, 5);
		int c = binary2decimal(check1);
		int e = binary2decimal(check2);

	    if (signal_a == "1" && signal_b == "0" && exa == exb) {

			if (a > b) {
				mainSig = "1";
			}
			if (a < b) {
				mainSig = "0";
			}		
		}

		if (signal_a == "0" && signal_b == "1" && exa == exb) {
			if (a > b) {
				mainSig = "0";
			}
			if (a < b) {
				mainSig = "1";
			}
		}
		
		if (sum.length() > 23) {
			
			sum.replace(0, 1, "");
			sum.erase(23, distance);
			if (mainSig == "0") {
				
				exp = exp + 1;
			}
			if (mainSig == "1") {
				
				exp = exp - 1;
				
			}

		}
		
		exp = 127 + exp;
		expb = decimal2binary(exp);


		string total = mainSig + expb + sum;
		

	return total;


}

