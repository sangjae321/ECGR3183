#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "helper_v1.h"
using namespace std;

void assembinary(vector <string>&v1);

int main() {
    /** txtParse() parses through the text file entered as the argument(assembly format) and returns a vector of strings of assembly commands.
        assembly2binary() encodes the vector of strings entered as the argument and outputs it as 32 bit numbers to binary.txt
        binParse() parses through the text file entered as the argument (formatted according to our documentation) and returns a vector of strings of encoded data
        binary2assembly() decodes the vector of strings entered as the argument and outputs it as assembly code to assembly.txt
    */
    assembly2binary(txtParse("testInput.txt"));
    binary2assembly(binParse("binary.txt"));
}

