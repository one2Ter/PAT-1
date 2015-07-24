#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef multimap<int,int>::iterator MUI;
struct Graph{
 multimap<int,int>Path;
};

int main(){
 Graph gar;
 int N,L;
 cin>>N>>L;
 int Num;
 for(int i = 1 ; i <= N;i++){
     cin>>Num;
     int Followers;
    for(int j = 0 ; j < Num; j++){
       cin>>Followers;
       gar.Path.insert(make_pair(Followers,i));
    }
 }
 
 cin>>Num;
 vector<int>Target;
 int Data;
 for(int i = 0 ; i < Num; i++){
  cin>>Data; 
  Target.push_back(Data); 
 }

 for(int k = 0 ; k < Num; k++){
   queue<int>Q;
   Q.push(Target[k]);
   set<int>exist;
   int level = 0;
   int currentCnt = 1;
   int nextCnt = 0;
   int visited = 0;
   while(!Q.empty() && level < L){
     int tmp = Q.front();
     Q.pop();
     visited ++;
     MUI itr = gar.Path.lower_bound(tmp);   
     while(itr != gar.Path.upper_bound(tmp)){
	int Child = itr->second;
	if(exist.find(Child) == exist.end() && Child != Target[k]){
           exist.insert(Child);	
	   Q.push(Child);
	   nextCnt ++;
	}
       ++itr;
     }
     if(visited == currentCnt){
        currentCnt = nextCnt;
        nextCnt = 0;
        visited = 0;
        level++;	
     }
     
   }
   cout<<exist.size()<<endl;
   //set<int>::iterator it = exist.begin();
   //while(it != exist.end()){
   //   cout<<*it++<<" ";
  // }
 }



 return 0;
}
