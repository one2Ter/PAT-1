#include <iostream>
#include <ctype.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
bool Checksum(const string & ID);
bool CheckDigit(const string &ID);
int WeightTable[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char MTable[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
int main(){
 int N;
 vector<string>IDarray;
 map<string,bool> M;
 cin>>N;
 while(N--){
  string ID;
  cin>>ID;
  if(CheckDigit(ID)){ 
      M.insert( pair <string,bool> (ID,Checksum(ID)));
      IDarray.push_back(ID);
  }
  else{
      M.insert( pair <string,bool> (ID,false));
      IDarray.push_back(ID);
  }
     
 }
 bool flag = true; 
 for(int i = 0; i < IDarray.size();i++){
   map<string,bool>::iterator itr;
   itr = M.find(IDarray[i]);
   if(itr->second == false){
        cout<<IDarray[i]<<endl;
        flag = false;
   } 
}
 if(flag == true)
    cout<<"All passed";



 return 0;
}

bool Checksum(const string &ID){
  int sum = 0;
  for(int i = 0; i < ID.size()-1;i++){
    sum += WeightTable[i] * (ID[i] - 48);
  }
  int Z = sum % 11;
  if(ID[17] == MTable[Z])
      return true;
  else 
      return false;
}

bool CheckDigit(const string &ID){
   for(int i = 0 ; i < ID.size() - 1;i++){
      if(!isdigit(ID[i])){
        return false;
      }
   }
   return true;
}
