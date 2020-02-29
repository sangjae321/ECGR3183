#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "helper.h"

using namespace std;

void assembly2binary(vector<string> a){
    ofstream file;
    file.open ("binary.txt");
    int vec_count = 0;
    while(vec_count < a.size()){
        int bits = 0;
        ///Set instruction
        if(a[vec_count] == "SET"){
            file << "00000";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Load Instruction
        else if(a[vec_count] == "LOAD"){
            file << "00001";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Store Instruction
        else if(a[vec_count] == "STORE"){
            file << "00010";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Move Instruction
        else if(a[vec_count] == "MOVE"){
            file << "00011";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Add instruction
        else if(a[vec_count] == "FADD"){
            file << "00100";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Subtract
        else if(a[vec_count] == "FSUB"){
            file << "00101";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Negate
        else if(a[vec_count] == "FNEG"){
            file << "00110";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Multiply
        else if(a[vec_count] == "FMUL"){
            file << "00111";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Divide
        else if(a[vec_count] == "FDIV"){
            file << "01000";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Floor
        else if(a[vec_count] == "FLOOR"){
            file << "01001";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Ceiling
        else if(a[vec_count] == "CEIL"){
            file << "01010";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Round
        else if(a[vec_count] == "OUND"){
            file << "01011";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Absolute Value
        else if(a[vec_count] == "FABS"){
            file << "01100";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Minimum
        else if(a[vec_count] == "MIN"){
            file << "01101";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Maximum
        else if(a[vec_count] == "MAX"){
            file << "01110";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Power
        else if(a[vec_count] == "POW"){
            file << "01111";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Exponent
        else if(a[vec_count] == "EXP"){
            file << "10000";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Square Root
        else if(a[vec_count] == "SQRT"){
            file << "10001";
            bits +=5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits +=5;
            vec_count++;
            if(a[vec_count] == "#"){
                file << "100001";
                bits +=6;
                vec_count++;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
                file << endl << decimal2ieee(stod(a[vec_count]));
            }
            else{
                file << Pdecimal2binary(stoi(a[vec_count]));
                bits += 5;
                for(int i = bits; i < 32; i++){
                    file << "0";
                }
            }
            file << endl;
            vec_count++;
        }
        ///Branch uncond
        else if(a[vec_count] == "B"){
            file << "10010";
            bits += 5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits += 5;
            for(int i = bits; i < 32; i++){
                    file << "0";
            }
            vec_count++;
            file << endl;
        }
        ///Branch Zero
        else if(a[vec_count] == "BZ"){
            file << "10011";
            bits += 5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits += 5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits += 5;
            for(int i = bits; i < 32; i++){
                    file << "0";
            }
            vec_count++;
            file << endl;
        }
        ///Branch negative
        else if(a[vec_count] == "BN"){
            file << "10100";
            bits += 5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits += 5;
            vec_count++;
            file << Pdecimal2binary(stoi(a[vec_count]));
            bits += 5;
            for(int i = bits; i < 32; i++){
                    file << "0";
            }
            vec_count++;
            file << endl;
        }
        ///No-op
        else if(a[vec_count] == "NOP"){
            file << "10101";
            bits += 5;
            for(int i = bits; i < 32; i++){
                file << "0";
            }
            file << endl;
            vec_count++;
        }
        ///Halt
        else if(a[vec_count] == "HALT"){
            file << "10110";
            bits += 5;
            for(int i = bits; i < 32; i++){
                file << "0";
            }
            file << endl;
            vec_count++;
        }
        ///If an empty line is found, simply go to the next instruction
        else{
            vec_count++;
        }
    }
    file.close();
}
///Main function parses through the input file
int main(){
    ifstream input("testInput.txt");
    vector<string> instructions;
    string line;
    int inst_count;
    int line_count = 0;
    while(getline(input, line)){
        ///Get rid of the commas
        while(line.find(",") != string::npos){
            line.erase(line.find(','),1);
        }
        ///Get rid of R's to help with setting registers, Round is taken care of in the method
        while(line.find("R") != string::npos){
            line.erase(line.find('R'),1);
        }
        while(line.find("LINE") != string::npos){
            line.erase(line.find("LINE"), 4);
        }
        ///Deletes comments
        while(line.find("-") != string::npos){
            line.erase(line.find('-'));
        }
        ///Trims the end of the line of spaces
        line.erase(line.find_last_not_of(" ")+1);
        ///Checks if the line is empty (Meaning the line started with a comment)
        if(line != ""){
            ///Gets the number of instructions from the beginning of the file
            if(line_count == 0){
                inst_count = stoi(line);
                line_count++;
            }
            else if(line_count <= inst_count){
                ///Insert instructions into vector
                while(line.find(" ") != string::npos){
                    string inst = line.substr(0, line.find(" "));
                    instructions.push_back(inst);
                    line.erase(0, line.find(" ")+1);
                }
                ///Insert immediate value or last instruction
                if(line[0] == '#'){
                    instructions.push_back(line.substr(0,1));
                    instructions.push_back(line.substr(1));
                }
                else{
                    instructions.push_back(line);
                }
                line_count++;
            }
        }
    }
    input.close();
    cout << "FOUND " << inst_count << " INSTRUCTIONS" << endl;
    for(int i = 0; i < instructions.size(); i++){
        cout << instructions[i] << endl;
    }
    cout << "STARTING ENCODING" << endl << "..." << endl;
    assembly2binary(instructions);
    cout << "FINISHED ENCODING" << endl;
    return 0;
}
