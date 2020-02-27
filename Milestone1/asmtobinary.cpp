
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "helper.h"
using namespace std;

void assembinary(vector <string>&v1);

int main() {

	vector <string> asem;
	asem.push_back("Fmul");
	asem.push_back("R9");
	asem.push_back("R7");
	asem.push_back("#");
	asem.push_back("3");
	asem.push_back("Halt");
	assembinary(asem);
	//empty bits are filled with 0
}

void assembinary(vector <string>&v1) {
	ofstream mile;
	mile.open("test.txt");
	int bits = 0;
	int spec = 0;
	for (int i = 0; i < v1.size(); i++) {
		while (1) {
			if (v1[i].compare("Set")==0||v1[i].compare("R0")==0) {
				mile << "00000" << " ";
				bits += 5;
			}
			else if (v1[i].compare("Load") == 0 || v1[i].compare("R1") == 0) {
				mile << "00001" << " ";
				bits += 5;
				if (v1[i].compare("Load") == 0) {
					spec += 1;
				}
			}
			else if (v1[i].compare("Store") == 0 || v1[i].compare("R2") == 0) {
				mile << "00010" << " ";
				bits += 5;
				if (v1[i].compare("Store") == 0) {
					spec += 1;
				}
			}
			else if (v1[i].compare("Move") == 0 || v1[i].compare("R3") == 0) {
				mile << "00011" << " ";
				bits += 5;
				if (v1[i].compare("Move") == 0) {
					spec += 1;
				}
			}
			else if (v1[i].compare("Fadd") == 0 || v1[i].compare("R4") == 0) {
				mile << "00100" << " ";
				bits += 5;
			}
			else if (v1[i].compare("Fsub") == 0 || v1[i].compare("R5") == 0) {
				mile << "00101" << " ";
				bits += 5;
			}
			else if (v1[i].compare("Fneg") == 0 || v1[i].compare("R6") == 0) {
				mile << "00110" << " ";
				bits += 5;
				if (v1[i].compare("Fneg") == 0) {
					spec += 1;
				}
			}
			else if (v1[i].compare("Fmul") == 0 || v1[i].compare("R7") == 0) {
				mile << "00111" << " ";
				bits += 5;
			}
			else if (v1[i].compare("Fdiv") == 0 || v1[i].compare("R8") == 0) {
				mile << "01000" << " ";
				bits += 5;
			}
			else if (v1[i].compare("Floor") == 0 || v1[i].compare("R9") == 0) {
				mile << "01001" << " ";
				bits += 5;
				if (v1[i].compare("Floor") == 0) {
					spec += 1;
				}
			}
			else if (v1[i].compare("Ceil") == 0 || v1[i].compare("R10") == 0) {
				mile << "01010" << " ";
				bits += 5;
				if (v1[i].compare("Ceil") == 0) {
					spec += 1;
				}
			}
			else if (v1[i].compare("Round") == 0 || v1[i].compare("R11") == 0) {
				mile << "01011" << " ";
				bits += 5;
				if (v1[i].compare("Round") == 0) {
					spec += 1;
				}
			}
			else if (v1[i].compare("Fabs") == 0 || v1[i].compare("R12") == 0) {
				mile << "01100" << " ";
				bits += 5;
				if (v1[i].compare("Fabs") == 0) {
					spec += 1;
				}
			}
			else if (v1[i].compare("Min") == 0 || v1[i].compare("R13") == 0) {
				mile << "01101" << " ";
				bits += 5;
			}
			else if (v1[i].compare("Max") == 0 || v1[i].compare("R14") == 0) {
				mile << "01110" << " ";
				bits += 5;
			}
			else if (v1[i].compare("Pow") == 0 || v1[i].compare("R15") == 0) {
				mile << "01111" << " ";
				bits += 5;
			}
			else if (v1[i].compare("Exp") == 0 || v1[i].compare("R16") == 0) {
				mile << "10000" << " ";
				bits += 5;
				if (v1[i].compare("Exp") == 0) {
					spec += 1;
				}
			}
			else if (v1[i].compare("Sqrt") == 0 || v1[i].compare("R17") == 0) {
				mile << "10001" << " ";
				bits += 5;
				if (v1[i].compare("Sqrt") == 0) {
					spec += 1;
				}
			}
			else if (v1[i].compare("B") == 0 || v1[i].compare("R18") == 0) {
				mile << "10010" << " ";
				bits += 5;
				if (v1[i].compare("B") == 0) {
					spec += 2;
				}
			}
			else if (v1[i].compare("BZ") == 0 || v1[i].compare("R19") == 0) {
				mile << "10011" << " ";
				bits += 5;
			}
			else if (v1[i].compare("BN") == 0 || v1[i].compare("R20") == 0) {
				mile << "10100" << " ";
				bits += 5;
			}
			else if (v1[i].compare("Nop") == 0 || v1[i].compare("R21") == 0) {
				mile << "10101" << " ";
				mile << "000000000000000000000000000" << endl;
			}
			else if (v1[i].compare("Halt") == 0 || v1[i].compare("R22") == 0) {
				mile << "10110" << " ";
				mile << "000000000000000000000000000" << endl;
			}
			else if (v1[i].compare("#")==0) {
				mile << "100001";
				bits += 6;
				for (int k = 32; k > bits; k--) {
					mile << "0";
				} //filled rest bits with 0 when immediate instruction 
				mile << endl;
				double temp = stod(v1[i + 1]);
				mile << decimal2ieee(temp) << endl;
				bits = 0;
				spec = 0;
			}
			else { //pb: asem.push_back("3")을 else 로 해당된다 인식하고 3의 주소값 반환함
				mile << &v1[i];
				bits += sizeof(&v1[i]);
				for (int k = 32; k > bits; k--) {
					mile << "0";
				}
				bits=0;
				mile << endl;
			} //case of BN, BZ
			if (bits == 20) {
				for (int k = 32; k > bits; k--) {
					mile << "0";
				}
				bits = 0;
				mile << endl;
			} //filled rest bits with 0 when instruction has 3 register
			else if (bits == 15 && spec == 1) {
				for (int k = 32; k > bits; k--) {
					mile << "0";
				}
				bits = 0;
				spec = 0;
				mile << endl;
			}
			else if (bits == 10 && spec == 2) {
				for (int k = 32; k > bits; k--) {
					mile << "0";
				}
				bits = 0;
				spec = 0;
				mile << endl;
			}
			break;
		}
	}
	mile.close();

}
/*What I can't complete: 
 not check when immediate number and label case*/