#include <iostream>
#include <map>
using namespace std;

int main(){
 int N;
 cin>>N;
 map<int,int>myMap;
 while(N--){
  int ID,score;
  cin>>ID>>score;
  myMap[ID]+=score;
  } 
 int ID;
 int maxValue = 0;
 map<int,int>::iterator itr = myMap.begin();
 for(;itr != myMap.end();itr++){
    if(maxValue < itr -> second){
       maxValue = itr -> second;
       ID = itr->first;
    }
  // cout<<itr->first<<" "<<itr->second<<endl;
 } 
 cout<<ID<<" "<<maxValue; 
 return 0;
}


