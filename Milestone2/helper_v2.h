#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
#include <fstream>
using namespace std;

///Other helper functions
    int binary2decimal (string input){
        int ans = 0;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '1'){
                ans += pow(2, input.size()-1-i);
            }
        }
        return ans;
    }

    string decimal2binary (int input){
        vector<int> bits;
        string out;
        while (input > 0){
            bits.push_back(input % 2);
            input /= 2;
        }
        for(int i = bits.size()-1; i >= 0; i--){
            out+=(char(bits[i]+48));
        }
        return out;
    }
    ///Outputs 5 bits
    string Pdecimal2binary (int input){
        vector<int> bits;
        string out;
        for(int i = 0; i < 5; i++){
            bits.push_back(input % 2);
            input /= 2;
        }
        for(int i = bits.size()-1; i >= 0; i--){
            out+=(char(bits[i]+48));
        }
        return out;
    }

///MILESTONE 0:

    ///DECIMAL TO IEEE
    string whole(double input){
        int whole = int(input);
        vector<int> a;
        string out;
        while(whole > 0){
            a.push_back(whole % 2);
            whole /= 2;
        }
        for(int i = a.size()-1; i >= 0; i--){
            out.append(to_string(a[i]));
        }
        return out;
    }

    string decimal(double input){
        double decimal = input - int(input);
        vector<int> a;
        string out;
        for(int i = 0; i < 23; i++){
            a.push_back(int(decimal*2));
            decimal = (decimal * 2) - int(decimal * 2);
        }
        for(int i = 0; i < a.size(); i++){
            out.append(to_string(a[i]));
        }
        return out;
    }

    string decimal2exponent (int input){
        vector<int> bits;
        string out;
        for(int i = 0; i < 8; i ++){
            bits.push_back(input % 2);
            input /= 2;
        }
        for(int i = bits.size()-1; i >= 0; i--){
            out+=(char(bits[i]+48));
        }
        return out;
    }

    string decimal2ieee(double input){
        if(input == 0){
            return "00000000000000000000000000000000";
        }
        string out;
        string w = whole(input);
        string d = decimal(input);
        int exponent = (w.size()-1) + 127;
        string exp = decimal2exponent(exponent);
        w = w.substr(1, w.size());
        if(input < 0){
            out.append("1");
        }
        else{
            out.append("0");
        }
        out.append(exp);
        out.append(w);
        out.append(d);
        out = out.substr(0, 32);
        return out;
    }


    ///IEEE TO DECIMAL

    int exponent(string input){
        int ans = 0;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '1'){
                ans += pow(2, input.size()-1-i);
            }
        }
        return ans-127;
    }

    double bin_dec(string input){
        double ans = 0;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '1'){
                ans += pow(2, input.size()-1-i);
            }
        }
        return ans;
    }

    double bin_frac(string input){
        double ans = 0;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '1'){
                ans += 1/pow(2, i+1);
            }
        }
        return ans;
    }

    double ieee2decimal(string input){
    if(input == "00000000000000000000000000000000"){
        return 0;
    }
    if(input == "01111111100000000000000000000000"){
        cout << "INF" << endl;

    }
    if(input == "11111111100000000000000000000000"){
        cout << "-INF" << endl;

    }
    if(input.substr(1,8) == "11111111"){
        cout << "NAN" << endl;

    }
    ///Is the number negative or positive
    int s = int(input[0]) - 48;
    ///Finds the decimal number of the exponent
    int e = exponent(input.substr(1, 8));
    ///Sets the Mantissa to a string
    string m = input.substr(9);
    ///Finds the integer binary number
    string inte = "1" + m.substr(0,e);
    ///Finds the integer in decimal
    double integer = bin_dec(inte);
    ///Finds the decimal in decimal
    double decimal = bin_frac(m.substr(e));
    if(s == 0){
        return integer+decimal;
    }
    else{
        return (integer+decimal) * -1;
    }
}




///MILESTONE 1:

    ///write string vector of assembly commands as 32bit binary numbers to binary.txt
    void assembly2binary(vector<string> a){
        ofstream file;
        file.open ("binary.txt");
        int vec_count = 0;
        cout << "Outputting to binary.txt...";
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
                    string temp = decimal2ieee(stod(a[vec_count]));
                    file << temp.substr(0,11);
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
        cout << "Completed" << endl;
    }

    ///Parse through a .txt of assembly language and set up a string vector of commands
    vector<string> txtParse(string input_text_file){
        ifstream input(input_text_file);
        vector<string> instructions;
        string line;
        int inst_count;
        int line_count = 0;
        if(input.is_open()){
            cout << "Parsing " << input_text_file << "...";
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
                ///Checks if the line is empty
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
            cout << "Completed" << endl;
            return instructions;
        }
        else{
            cout << "Error opening file..." << input_text_file << endl;
        }
    }

    ///write string vector of 32bit binary numbers as assembly instructions to assembly.txt
    void binary2assembly(vector<string> a){
        ofstream file;
        file.open ("assembly.txt");
        int vec_count = 0;
        cout << "Outputting to assembly.txt...";
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
                    file << " #";
                    string temp = a[vec_count].substr(21);
                    while(temp.length() < 32){
                        temp += "0";
                    }
                    file << ieee2decimal(temp);
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
        cout << "Completed" << endl;
    }

    ///Parse through a .txt of binary numbers and set up a string vector of encoded commands.
    vector<string> binParse(string input_txt_file){
        vector<string> instructions;
        ifstream input("binary.txt");
        string line;
        if(input.is_open()){
            cout << "Parsing " << input_txt_file << "...";
            while(getline(input, line)){
                string opcode = line.substr(0,5);
                instructions.push_back(opcode);
                ///If opcode requires 3 arguments
                if(opcode == "00100" || opcode == "00101" || opcode == "00111" || opcode == "01000" || opcode == "01101" || opcode == "01110"){
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
                ///If opcode is power
                else if(opcode == "01111"){
                    instructions.push_back(line.substr(5,5));
                    instructions.push_back(line.substr(10, 5));
                    if(line.substr(15,6) == "100001"){
                        instructions.push_back("100001");
                        string temp = line.substr(21);
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
            cout << "Completed" << endl;
            return(instructions);
        }
        else{
            cout << "Error opening file..." << endl;
        }
    }




///MILESTONE 2:

void execute(vector<string> a){
        int vec_count = 0;
        ///Figures out where all the lines actually are in the vector of strings for the looping
        int linetest = 0;
        vector<int> linecount;
        while(linetest < a.size()){
            linecount.push_back(linetest);
            if(a[linetest] == "00000" || a[linetest] == "00100" || a[linetest] == "00101" || a[linetest] == "00111" || a[linetest] == "01000" || a[linetest] == "01101" || a[linetest] == "01110"){
                linetest += 4;
            }
            else if(a[linetest] == "01111"){
                linetest += 5;
            }
            else if(a[linetest] == "10010"){
                linetest += 2;
            }
            else if(a[linetest] == "10101" || a[linetest] == "10110"){
                linetest ++;
            }
            else{
                linetest += 3;
            }
        }
        ///Initialize the register file
        string reg_file[32];
        for(int i = 0; i < 32; i++){
            reg_file[i] = "00000000000000000000000000000000";
        }
        while(vec_count < a.size()){
            ///Set instruction
            if(a[vec_count] == "00000"){
                cout << "SET" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = a[vec_count+2];
                vec_count += 3;
            }

            ///Load Instruction
            else if(a[vec_count] == "00001"){
                ///Cant figure out load
            }

            ///Store Instruction
            else if(a[vec_count] == "00010"){
                ///Cant figure out  store
            }

            ///Move Instruction
            else if(a[vec_count] == "00011"){
                cout << "MOVE" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = reg_file[binary2decimal(a[vec_count+1])];
                vec_count += 2;
            }

            ///Add Instruction
            else if(a[vec_count] == "00100"){
                cout << "ADD" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])])+ieee2decimal(reg_file[binary2decimal(a[vec_count+2])]));
                vec_count += 3;
            }

            ///Subtract Instruction
            else if(a[vec_count] == "00101"){
                cout << "SUB" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])])-ieee2decimal(reg_file[binary2decimal(a[vec_count+2])]));
                vec_count += 3;
            }

            ///Negate Instruction
            else if(a[vec_count] == "00110"){
                cout << "NEG" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])])*-1);
                vec_count += 2;
            }

            ///Multiply Instruction
            else if(a[vec_count] == "00111"){
                cout << "MUL" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])])*ieee2decimal(reg_file[binary2decimal(a[vec_count+2])]));
                vec_count += 3;
            }

            ///Divide Instruction
            else if(a[vec_count] == "01000"){
                cout << "DIV" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])])/ieee2decimal(reg_file[binary2decimal(a[vec_count+2])]));
                vec_count += 3;
            }

            ///Floor Instruction
            else if(a[vec_count] == "01001"){
                cout << "FLOOR" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(floor(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])])));
                vec_count +=2;
            }

            ///Ceiling Instruction
            else if(a[vec_count] == "01010"){
                cout << "CEIL" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(ceil(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])])));
                vec_count +=2;
            }

            ///Round Instruction
            else if(a[vec_count] == "01011"){
                cout << "ROUND" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(round(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])])));
                vec_count +=2;
            }

            ///Absolute Value Instruction
            else if(a[vec_count] == "01100"){
                cout << "ABS" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(abs(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])])));
                vec_count +=2;
            }

            ///Minimum Instruction
            else if(a[vec_count] == "01101"){
                cout << "MIN" << endl;
                vec_count++;
                double tempa = ieee2decimal(reg_file[binary2decimal(a[vec_count+1])]);
                double tempb = ieee2decimal(reg_file[binary2decimal(a[vec_count+2])]);
                if(tempa < tempb){
                    reg_file[binary2decimal(a[vec_count])] = decimal2ieee(tempa);
                }
                else{
                    reg_file[binary2decimal(a[vec_count])] = decimal2ieee(tempb);
                }
            }

            ///Maximum Instruction
            else if(a[vec_count] == "01110"){
                cout << "MAX" << endl;
                vec_count++;
                double tempa = ieee2decimal(reg_file[binary2decimal(a[vec_count+1])]);
                double tempb = ieee2decimal(reg_file[binary2decimal(a[vec_count+2])]);
                if(tempa > tempb){
                    reg_file[binary2decimal(a[vec_count])] = decimal2ieee(tempa);
                }
                else{
                    reg_file[binary2decimal(a[vec_count])] = decimal2ieee(tempb);
                }
            }

            ///Power Instruction
            else if(a[vec_count] == "01111"){
                cout << "POW" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(pow(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])]), ieee2decimal(a[vec_count+3])));
                vec_count+=4;
            }

            ///Exponent
            else if(a[vec_count] == "10000"){
                cout << "EXP" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(exp(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])])));
                vec_count+=2;
            }

            ///Square Root Instruction
            else if(a[vec_count] == "10001"){
                cout << "SQRT" << endl;
                vec_count++;
                reg_file[binary2decimal(a[vec_count])] = decimal2ieee(sqrt(ieee2decimal(reg_file[binary2decimal(a[vec_count+1])])));
                vec_count+=2;
            }

            ///Unconditional Branch Instruction
            else if(a[vec_count] == "10010"){
                cout << "B" << endl;
                vec_count++;
                int tempa  = ieee2decimal(reg_file[binary2decimal(a[vec_count])]);
                vec_count = linecount[tempa];
            }

            ///Branch Zero
            else if(a[vec_count] == "10011"){
                cout << "BZ" << endl;
                vec_count++;
                if(ieee2decimal(reg_file[binary2decimal(a[vec_count])]) == 0){
                    vec_count++;
                    int tempa  = ieee2decimal(reg_file[binary2decimal(a[vec_count])]);
                    vec_count = linecount[tempa];
                }
                else{
                    vec_count+=2;
                }
            }

            ///Branch Negative
            else if(a[vec_count] == "10100"){
                cout << "BN" << endl;
                vec_count++;
                if(ieee2decimal(reg_file[binary2decimal(a[vec_count])]) < 0){
                    vec_count++;
                    int tempa  = ieee2decimal(reg_file[binary2decimal(a[vec_count])]);
                    vec_count = linecount[tempa];
                }
                else{
                    vec_count+= 2;
                }
            }

            ///No-op Instruction
            else if(a[vec_count] == "10101"){
                cout << "NOOP" << endl;
                vec_count++;
            }

            ///Halt Instruction
            else if(a[vec_count] == "10110"){
                cout << "HALT" << endl;
                vec_count++;
            }

        }
        for(int i = 0; i < 32; i ++){
            cout << "R" << i << ": ";
            if(i <= 9)
                cout << " ";
             cout << reg_file[i] << ", " << ieee2decimal(reg_file[i]) << endl;
        }
        cout << "Completed" << endl;
    }





#endif // HELPER_H_INCLUDED
