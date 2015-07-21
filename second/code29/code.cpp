#include <iostream>
#include <string>
#include <map>
#include <algorithm> 
using namespace std;
int main(){
 string A;
 string B;
 cin>>A>>B;
 map<char,int>Atable;
 map<char,int>Btable;
 for(int i = 0;i < A.size();i++){
  map<char,int>::iterator itr = Atable.find(A[i]); 
  if(itr != Atable.end())
     itr->second++;
  else
     Atable.insert(make_pair(A[i],1));
 }
 for(int j = 0; j < B.size();j++){

  map<char,int>::iterator itr = Btable.find(B[j]);
  if(itr != Btable.end())
      itr->second++;
  else
     Btable.insert(make_pair(B[j],1));
 }
 int Morecount = 0;
 int Needcount = 0;
 bool flag = true;
 map<char,int>::iterator Br,Ar;
 for(Br = Btable.begin();Br != Btable.end(); Br++ ){
   int NeedNum = Br->second;
   Ar = Atable.find(Br->first);
   int AvalNum;
   if(Ar != Atable.end()){
      AvalNum = Ar->second;
       if(AvalNum >= NeedNum){
         Morecount += AvalNum - NeedNum;
       }
       else{
        flag = false;
        Needcount += NeedNum - AvalNum;  
       } 
   }
  else{
      flag = false;
      Needcount += NeedNum;
  }  
 } 

 if(flag == true)
    cout<<"Yes "<<A.size() - B.size();
 else{
    cout<<"No "<<Needcount;
 }
 return 0;
}
