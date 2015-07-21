#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool Compare(int,int);
int main(){
 vector<int>Array;
 int N = 10;
  

 for(int i = 0;i < N;i++){
   int tmp;
   cin>>tmp; 
   for(int k = 0; k < tmp;k++)
        Array.push_back(i); 
  }


  sort(Array.begin(),Array.end(),Compare);
   for(int i = 0; i < Array.size();i++){
     if(Array[i] != 0 ){
       swap(Array[i],Array[0]);
       break;
     }
   }
  for(int i = 0 ;i < Array.size(); i++)
    cout<<Array[i]; 
  cout<<endl;
 

 return 0;
}

bool Compare(int a,int b){
   return a < b;
}
