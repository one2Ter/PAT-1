#include <iostream>
#include <string>
using namespace std;
int main(){
 string N;
 cin>>N;
 int P = 0;
 int PA = 0;
 int PAT = 0;
 for( int i = 0;i < N.size() ; i++){
   if(N[i] == 'P')
      P++;
   else if(N[i] == 'A'){
      PA = PA + P;
      PA = PA % 1000000007;
   }
   else{
      PAT = PAT + PA;
      PAT = PAT % 1000000007;
   }
    
 }
   cout<<PAT;
 return 0;
}
