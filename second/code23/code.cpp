#include <iostream>
#include <ctype.h>
#include <string>
#include <set>
using namespace std;
int main(){
 string Badkeys;
 string Input;
 set<char>mySet;
 bool NoUpper = false;
 cin>>Badkeys>>Input;
 for(int i = 0 ;i < Badkeys.size();i++){
  if(Badkeys[i] == ',' || Badkeys[i] == '.' || Badkeys[i] == '-' || Badkeys[i] == '+'){
   NoUpper = true;
   mySet.insert(Badkeys[i]); 
  }
  else if(isalpha(Badkeys[i])){
    mySet.insert(toupper(Badkeys[i]));
    mySet.insert(tolower(Badkeys[i]));
  }
  else 
    mySet.insert(Badkeys[i]); 
 }
 set<char>::iterator itr;
 for(int j = 0; j < Input.size(); j++){
  itr = mySet.find(Input[j]);
  if(isupper(Input[j])){
    if(NoUpper == true)
       continue;
    else{
      if(itr == mySet.end())
           cout<<Input[j]; 
    }
  }
  else{
      if(itr == mySet.end())
           cout<<Input[j]; 
  }

 }

 return 0;
}
