#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    
    string line;
    vector<string>inLine;
    vector<string>instruct;
    
    fstream myfile("Instruction.txt");
//add txt file strings to vector line by line    
    while(getline(myfile,line)){
        inLine.push_back(line);
        
    }


//erase comments
for (int i = 0; i < inLine.size(); i++){
    if (inLine[i][0] == '-' || inLine[i][0] == '0'){
        inLine.erase(inLine.begin() + i);
        i--;
    }
}

  
//erase comment within the instructions  
for (int i = 0; i < inLine.size(); i++){
   for (int j = 0; j < inLine[i].length(); j++){
        
        if(inLine[i][j] == '-'){
            
            inLine[i].replace(j,inLine[i].size(),"");
        }        
    }
}

//erase commas and spaces
for (int i = 0; i < inLine.size(); i++){
replace( inLine[i].begin(), inLine[i].end(), ',', '\0');  
replace( inLine[i].begin(), inLine[i].end(), ' ', '\0');  
}
  

  
  
  
    for (auto i: inLine){
        
        
        
      cout << i <<endl;
    }
    
    
    
    return 0;
}