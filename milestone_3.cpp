#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>
#include "helper_v3.h"
using namespace std;

int main() {
    /** interpret() parses through the text file entered as the argument(assembly format) and returns a vector of strings of assembly commands.
        convert() encodes the vector of strings entered as the argument and outputs it as 32 bit numbers to binary.txt
        decode() parses through the text file entered as the argument (formatted according to our documentation) and returns a vector of strings of encoded data
        setMem() looks at the memory declarations at the end of the input Assembly code
        execute() takes the vector of strings of binary encoded operations and executes them
    */
    convert(interpret("testInput.txt"));
    vector<string> instructionMemory = decode("binary.txt");
    vector<double> memory = setMem("testInput.txt");
    execute(instructionMemory, memory);
}
