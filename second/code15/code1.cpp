#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
struct myList{
  int Address;
  int Data;
  int Next;
};
int main(){
 int FirstAddress;
 int Num;
 int k;
 int data[100000];
 int nextAddress[100000];
 vector<myList>L;
 cin>>FirstAddress>>Num>>k;
 for(int i = 0; i < Num; i++){
    int addr; 
    cin>>addr;
    cin>>data[addr]>>nextAddress[addr];
 }

 while(FirstAddress != -1){
     myList tmp;
     tmp.Address = FirstAddress; 
     tmp.Data = data[FirstAddress];
     tmp.Next = nextAddress[FirstAddress];
     L.push_back(tmp);
     FirstAddress = tmp.Next;
 }

 


if( k >  0){ 
for(int j = 0;j < Num / k; j++){
 L[j * k].Next = L[j * k + k - 1].Next;
 for(int i = k - 1 + j * k;i > j * k;i--){
    L[i].Next = L[i - 1].Address; 
 }  
   reverse(L.begin() + j * k,L.begin() + j * k + k );
   if(j + 1 < Num / k){
      L[j * k + k - 1].Next =L[(j + 1) * k + k -1].Address;
   } 
 }
}

 cout << setfill('0'); 
 for(int i = 0; i < Num-1; i++)
    cout<<setw(5)<<L[i].Address<<" "<<L[i].Data<<" "<<setw(5)<<L[i].Next<<endl;

    cout<<setw(5)<<L[Num - 1].Address<<" "<<L[Num - 1].Data<<" "<<L[Num - 1].Next<<endl;

 return 0;
}
