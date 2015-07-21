#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;
struct Node{
  int Address;
  int Next;
  int val;
};
int main(){
 set<int>SetVal;
 map<int,Node>myMap;
 vector<Node>Noduplicate;
 vector<Node>Duplicate; 

 int Start;
 int N;
 cin>>Start>>N;
 int addr,nextaddr;
 int value;
 set<int>::iterator it; 
 for(int i = 0; i < N; i++){
    cin>>addr>>value>>nextaddr;
    //Node node;
    //node.Address = addr;
    //node.val = value;
    //node.Next =nextaddr;  
    //myMap.insert(make_pair(addr,node));
     myMap[addr].Address = addr;
     myMap[addr].val = value;
     myMap[addr].Next = nextaddr;
 }

  int index = Start;
 while(myMap.find(index)!= myMap.end() && index != -1){
    Node node = myMap[index];
    int value = abs(node.val);    
    int next = node.Next; 
    if(SetVal.find(value) == SetVal.end()){
          SetVal.insert(value);  
          Noduplicate.push_back(node);   
    }
    else
         Duplicate.push_back(node);
    index = next;
 }


for(int i = 0 ;i < Noduplicate.size();i++){
    cout<<setfill('0');
    cout<<setw(5)<<Noduplicate[i].Address<<" "<<Noduplicate[i].val<<" ";
    if(i < Noduplicate.size() - 1) 
      cout<<setw(5)<<Noduplicate[i + 1].Address<<endl;
    else
      cout<<"-1"<<endl;
}

for(int i = 0 ;i < Duplicate.size();i++){
    cout<<setw(5)<<Duplicate[i].Address<<" "<<Duplicate[i].val<<" ";
    if(i < Duplicate.size() - 1)
      cout<<setw(5)<<Duplicate[i + 1].Address<<endl;
    else
      cout<<"-1"<<endl;
 }
  return 0;
}
