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
    if (inLine[i][0] == '-' || isdigit(inLine[i][0])){
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
//replace( inLine[i].begin(), inLine[i].end(), ' ', '\0');  
}


  
//remove end spaces
for (int i = 0; i < inLine.size(); i++){
    while(inLine[i].size() && isspace(inLine[i].back())){
        inLine[i].pop_back();
    }
}


  string a = "";
  int counter1 = 0;


vector<string>temp;

//parsing
for (int i = 0; i < inLine.size(); i++){
   for (int j = 0; j < inLine[i].length(); j++){
       
     
 
      
     
       try{
        a = inLine[i].substr(inLine[i].rfind(' ')+1,inLine[i].length());
        inLine[i].replace(inLine[i].rfind(' '),inLine[i].length(),"");
        temp.push_back(a);
        
     //    cout << a << endl;
       }catch(exception& e){
          
       }
        
       
    }
     if(counter1 == 0){
                a = inLine[i].substr(0, inLine[i].find(" "));
                temp.push_back(a);
                reverse(temp.begin(),temp.end());  
                instruct.insert(instruct.end(), temp.begin(), temp.end());
                temp.clear();
              //  cout << a << endl;
                counter1++;
               
            }
    
    
    counter1 = 0;
}





    for (auto i: instruct){
        
        
        
      cout << i <<endl;
    }
    
   
    
    return 0;
}