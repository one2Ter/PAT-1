#include<iostream>
#include<algorithm>
using namespace std;
bool Compare(int,int);
bool Compare_1(int,int);
int ArrayToNum(int array[4]);
int main(){
  int N;
  cin>>N;
  int increase[4];
  int decrease[4];
  int delta = 0;
  while(N != 6174){
   if(N % 1111 == 0){
       cout<< N << " - " << N <<" = 0000"<<endl;
       break;     
    }
    int ten = 1000;
    for(int i = 0;i < 4;i++){
      decrease[i] = N / ten;
      increase[i] = decrease[i];
      N %= ten;
      ten /= 10;
    }
      
    
    sort(increase,increase+4,Compare_1); 
    sort(decrease,decrease+4,Compare);
    int A,B;
    A = ArrayToNum(increase);
    B = ArrayToNum(decrease); 
    N = B - A;
    cout<<B<<" - ";
    if(A < 10)
      cout<<"000";
    else if(A < 100)
      cout<<"00";
    else if(A < 1000)
      cout<<"0"; 
     cout<<A<<" = "<<N<<endl;
  }

  return 0;
}

bool Compare(int A,int B){
   return A >= B;  
}
bool Compare_1(int A,int B){
   return A <= B;  
}

int ArrayToNum(int array[4]){
   int tmp = 0;
   for(int i=0;i<4;i++)
      tmp = tmp *10 + array[i];
   return tmp;
}


