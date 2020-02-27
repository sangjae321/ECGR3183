#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    
    string line;
    vector<string>inLine;
    fstream myfile("Instruction.txt");
    
    while(getline(myfile,line)){
        inLine.push_back(line);
        
    }


//erase comments
for (int i = 0; i < inLine.size(); i++){
    if (inLine[i][0] == '-'){
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

  
  
  
    for (auto i: inLine){
        
        
        
      cout << i <<endl;
    }
    
    
    
    return 0;
}