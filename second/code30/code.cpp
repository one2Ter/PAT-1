#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
 string N;
 cin>>N;
 vector<int> A; 
 vector<int> P;
 vector<int> T;
 int Cp = 0,Ct = 0;
 for(int i = 0;i < N.size(); i++){
  if(N[i] == 'P')
    P.push_back(i);
  else if(N[i] == 'A'){
    A.push_back(i);
  }
  else if(N[i] == 'T'){
    T.push_back(i); 
  }
 }
 int count = 0;
 int countP = 0,countT = 0;
 int Pindex = 0,Tindex = 0;
 for(int i = 0; i < A.size(); i++){
    int AData = A[i];
    while(Pindex < P.size()){
      int PData = P[Pindex];
      if(PData < AData){
         Pindex++;
      }
      else
        break;
    }
   countP = Pindex; 

    while(Tindex < T.size() ){
      int TData = T[Tindex];
      if(TData < AData){
        Tindex++;
      }
      else
       break;
    }
    countT =( T.size() - Tindex );
    count = (count + countP * countT ) % 1000000007;
 } 
 
 cout<<count;
 return 0;
}
