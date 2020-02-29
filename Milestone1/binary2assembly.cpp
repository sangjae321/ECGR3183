#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "helper.h"

using namespace std;


void binary2assembly(vector<string> a){
    ofstream file;
    file.open ("assembly.txt");
    int vec_count = 0;
    while(vec_count < a.size()){
        ///Set instruction
        if(a[vec_count] == "00000"){
            file << "SET R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Load Instruction
        else if(a[vec_count] == "00001"){
            file << "LOAD R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Store Instruction
        else if(a[vec_count] == "00010"){
            file << "STORE R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Move Instruction
        else if(a[vec_count] == "00011"){
            file << "MOVE R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            file << " R" << binary2decimal(a[vec_count]);
            vec_count++;
            file << endl;
        }

        ///Add Instruction
        else if(a[vec_count] == "00100"){
            file << "FADD R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ", R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Subtract Instruction
        else if(a[vec_count] == "00101"){
            file << "FSUB R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ", R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Negate Instruction
        else if(a[vec_count] == "00110"){
            file << "FNEG R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Multiply Instruction
        else if(a[vec_count] == "00111"){
            file << "FMUL R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ", R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Divide Instruction
        else if(a[vec_count] == "01000"){
            file << "FDIV R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ", R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Floor Instruction
        else if(a[vec_count] == "01001"){
            file << "FLOOR R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Ceiling Instruction
        else if(a[vec_count] == "01010"){
            file << "CEIL R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Round Instruction
        else if(a[vec_count] == "01011"){
            file << "ROUND R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Absolute Value Instruction
        else if(a[vec_count] == "01100"){
            file << "FABS R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Minimum Instruction
        else if(a[vec_count] == "01101"){
            file << "MIN R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ", R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Maximum Instruction
        else if(a[vec_count] == "01110"){
            file << "MAX R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ", R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Power Instruction
        else if(a[vec_count] == "01111"){
            file << "POW R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ", R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Exponent
        else if(a[vec_count] == "10000"){
            file << "EXP R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Square Root Instruction
        else if(a[vec_count] == "10001"){
            file << "SQRT R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << ",";
            vec_count++;
            if(a[vec_count] == "100001"){
                vec_count++;
                file << " #" << ieee2decimal(a[vec_count]);
            }
            else{
                file << " R" << binary2decimal(a[vec_count]);
            }
            vec_count++;
            file << endl;
        }

        ///Unconditional Branch Instruction
        else if(a[vec_count] == "10010"){
            file << "B R";
            vec_count++;
            file << binary2decimal(a[vec_count]) << endl;
            vec_count++;
        }

        ///Branch Zero
        else if(a[vec_count] == "10011"){
            file << "BZ R";
            vec_count++;
            file << binary2decimal(a[vec_count]);
            vec_count++;
            file << " LINE" << binary2decimal(a[vec_count]) << endl;
            vec_count++;
        }

        ///Branch Negative
        else if(a[vec_count] == "10100"){
            file << "BN R";
            vec_count++;
            file << binary2decimal(a[vec_count]);
            vec_count++;
            file << " LINE" << binary2decimal(a[vec_count]) << endl;
            vec_count++;
        }

        ///No-op Instruction
        else if(a[vec_count] == "10101"){
            file << "NOP" << endl;
            vec_count++;
        }

        ///Halt Instruction
        else if(a[vec_count] == "10110"){
            file << "HALT" << endl;
            vec_count++;
        }

    }
    file.close();
}



int main(){
    vector<string> instructions;
    ifstream input("binary.txt");
    string line;
    while(getline(input, line)){
        string opcode = line.substr(0,5);
        instructions.push_back(opcode);
        ///If opcode requires 3 arguments
        if(opcode == "00100" || opcode == "00101" || opcode == "00111" || opcode == "01000" || opcode == "01101" || opcode == "01110" || opcode == "01111"){
            instructions.push_back(line.substr(5,5));
            instructions.push_back(line.substr(10,5));
            if(line.substr(15,6) == "100001"){
                instructions.push_back("100001");
                getline(input,line);
                instructions.push_back(line);
            }
            else{
                instructions.push_back(line.substr(15,5));
            }
        }
        ///If opcode is a branch
        else if(opcode == "10011" || opcode == "10100"){
                instructions.push_back(line.substr(5,5));
                instructions.push_back(line.substr(10,5));

        }
        ///If opcode is an unconditional branch
        else if(opcode == "10010"){
            instructions.push_back(line.substr(5,5));
        }
        ///If opcode is no op or halt
        else if(opcode == "10101" || opcode == "10110"){
            ///Do nothing
        }
        ///If opcode requires 2 arguments
        else{
            instructions.push_back(line.substr(5,5));
            if(line.substr(10,6) == "100001"){
                instructions.push_back("100001");
                getline(input,line);
                instructions.push_back(line);
            }
            else{
                instructions.push_back(line.substr(10,5));
            }
        }


    }
    input.close();
    vector<string> test;
    test.push_back("R0");
    binary2assembly(instructions);

return 0;
}
