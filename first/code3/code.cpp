#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#include <iomanip>
using namespace std;

int LevelTraverse(map<int,vector<int> > &nodes,map<int,int> &m);
int main(){
 int N;
 float Price,Rate;
 map<int, vector<int> >nodes;
 map<int,int>m;
 cin>>N>>Price>>Rate;
 
 int Index;
 for(int i = 0 ; i < N;i++){
    cin>>Index;
    nodes[Index].push_back(i);
 } 
 int depth = LevelTraverse(nodes,m);
 float cal = Price * pow((1 + Rate / 100),depth - 1 );
 cout<<fixed;
 cout<<setprecision(2);
 cout<<cal<<" "<<m[depth - 1]; 
 return 0;
}

int LevelTraverse(map<int,vector<int> > &nodes,map<int,int> &m){
  if(!nodes.size()) return 0;
  queue<int>Q;
  Q.push(nodes[-1][0]);
  int depth = 0;
  int nextLevelCnt = 0,currentLevelCnt = 1;
  int visitedCnt = 0;
  int index = -1;
  while(!Q.empty()){
     index = Q.front();
     Q.pop();
     visitedCnt++;  
     
     for(int i = 0;i < nodes[index].size() ; i++){
        Q.push(nodes[index][i]);
        nextLevelCnt++;
     }

     if(visitedCnt == currentLevelCnt){
        m.insert(make_pair(depth,visitedCnt));
        visitedCnt = 0;
        currentLevelCnt = nextLevelCnt;
        nextLevelCnt = 0;
        depth++;
     }
  }
  return depth; 
}
