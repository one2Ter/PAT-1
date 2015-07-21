#include<iostream>
#include<math.h>
using namespace std;
int main(){
  int A,B,N;
  cin>>A>>B>>N;
  int sum = A + B;
  int index = 0;
  while( pow(N,index) < sum){
      index++;
  }
  string result;
  while(index > 0){
     int digit = sum / pow(N,--index);
     result.push_back(digit + 48);
     sum %= (int)pow(N,index); 
  }  

  cout<<result;

  return 0;
}
