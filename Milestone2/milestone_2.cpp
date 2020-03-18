#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>
#include "helper_v2.h"
using namespace std;

int main() {
    /** txtParse() parses through the text file entered as the argument(assembly format) and returns a vector of strings of assembly commands.
        assembly2binary() encodes the vector of strings entered as the argument and outputs it as 32 bit numbers to binary.txt
        binParse() parses through the text file entered as the argument (formatted according to our documentation) and returns a vector of strings of encoded data
        execute() takes the vector of strings of binary encoded operations and executes them
    */
    assembly2binary(txtParse("testInput.txt"));
    execute(binParse("binary.txt"));
}
