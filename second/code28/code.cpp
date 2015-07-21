#include <iostream>
#include <vector>
using namespace std;
int main(){
 int N;
 cin>>N;
 int Sarray[101] = {0};
 while(N--){
   int Score; 
   cin>>Score;
   Sarray[Score]++;
 }
 int M;
 cin>>M;
 vector<int>Array;
 while(M--){
   int S;
   cin>>S;
   Array.push_back(S);
 }
 for(int i = 0;i < Array.size();i++){
  if(i != Array.size() -1)
     cout<<Sarray[Array[i]]<<" ";
  else
     cout<<Sarray[Array[i]]; 
 }
 return 0;
}
