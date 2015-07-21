#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<iomanip>
#include<string>
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

 map<int,myList>M;
 vector<myList>L;
 cin>>FirstAddress>>Num>>k;

 M.clear();
 L.clear();
 for(int i = 0; i < Num; i++){
     int addr;
     int data;
     int next;
     cin>>addr>>data>>next;
     myList tmp; 
     tmp.Address = addr;
     tmp.Data = data;
     tmp.Next = next;
     M.insert(pair<int,myList>(addr,tmp)); 
 }
 
 for(int i = 0;i < M.size() && FirstAddress != -1; i++){
    map<int,myList>::iterator itr =  M.find(FirstAddress);
    L.push_back(itr->second);
    FirstAddress = (itr->second).Next;
 }

int time = L.size() / k;
for(int j = 0;j < time; j++){
   reverse(L.begin() + j * k,L.begin() + j * k + k );
 }
 cout << setfill('0'); 
 for(int i = 0; i < L.size(); i++){
    if( i == L.size() -1)
       cout<<setw(5)<<L[i].Address<<" "<<L[i].Data<<" -1"<<endl;
    else
       cout<<setw(5)<<L[i].Address<<" "<<L[i].Data<<" "<<setw(5)<<L[i+1].Address<<endl;
}

 return 0;
}
