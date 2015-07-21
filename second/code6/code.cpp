#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
using namespace std;

string NumToString(int N);


int main(){
 int A,Da,B,Db;
 cin>>A>>Da>>B>>Db;
 string Ast,Bst;

 Ast = NumToString(A);
 Bst = NumToString(B);
 
 int countA = 0,countB = 0;
 for(int i=0;i<Ast.size();i++){
   if(Ast[i] == Da+48)
     countA++;
 }
for(int i=0;i<Bst.size();i++){
   if(Bst[i] == Db+48)
     countB++;
 }

 string Astr,Bstr;
 Astr.resize(countA,'1');
 Bstr.resize(countB,'1');
 A = Da * atoi(Astr.c_str());
 B = Db * atoi(Bstr.c_str());
 cout<<A+B<<endl;
 
 return 0;
}


string NumToString(int N){
  int ten = 1;
  int length = 0;
  int copy = N;
  string result = "";
  while(copy/ten > 0){
    ten*=10;
    length++;
  }
  ten = pow(10,length-1);
  result.resize(length);
  for(int i=0;i<length;i++){
    result[i] = N / ten + 48;
    N %= ten;
    ten/=10;    
  }
  return result;
}
