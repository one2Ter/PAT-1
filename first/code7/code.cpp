#include<iostream>
#include<vector>
using namespace std;
int main(){
 int N;
 cin>>N;
 bool first = true;
 int ML = 0;
 int FirstIndex = 0;
 for(int i = 2; i * i < N;i++){
    int count = 1;
    int tmp = N / i;
    if(first){
     if(N % i == 0){
       FirstIndex = i;
       first = false;
     } 
    }
    if(N % i == 0){
    for(int j = i + 1; j < N;j++){
       if(tmp % j == 0){
         tmp /= j; 
         count++;
       }
       else
         break; 
    }
    }
    if(count > ML){
       ML = count;
       FirstIndex = i;
    }
  }
  if(first == true){
     FirstIndex = N;
  }


  cout<<ML<<endl;
   for(int i = 0 ; i < ML ; i++ ){
     if(i == 0)
        cout<<FirstIndex;
     else
        cout<<"*"<<FirstIndex + i;
   }
  return 0;
}
