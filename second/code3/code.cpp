#include<iostream>
#include<math.h>
using namespace std;
int main(){
 int M,N;
 cin>>M>>N;  
 int prime[N+1];
 for(int i = 2;i<=N;i++)
   prime[i] = 1;
 for(int i = 2;i*i<=N;i++){
   if(prime[i] == 1){
     for(int j = 2*i;j<=N;j++){
        if(j%i==0)
           prime[j] = 0;
     }
   }   
  }


  for(int i = 2;i<N;i++){
     if(i>=M && prime[i]==1)
        cout<<i<<" ";
  }
  cout<<N;
 }
