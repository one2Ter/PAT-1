#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;
struct Tree{
   multimap<string,string> Path;
};
typedef multimap<string,string>::iterator MI;
pair<int,int> BFS(Tree &tree);
int main(){
  int N,M;
  cin>>N>>M;
  Tree tree;
  string Parent,Child;
  int ChildNum = 0;
  for(int i = 0;i < M;i++){
     cin>>Parent>>ChildNum; 
     for(int j = 0;j < ChildNum;j++){
       cin>>Child;
       tree.Path.insert(make_pair(Parent,Child));
     }
  }
  pair<int,int>result  = BFS(tree);
  cout<<result.first<<" "<<result.second;
  return 0;
}

pair<int,int> BFS(Tree &tree){
  queue<string> Q;
  Q.push("01");
  int Max = 0;
  int depth = 1;
  int MaxDepth = 1; 
  int visitedCnt = 0;
  int CurrentLevelCnt = 1;
  int NextLevelCnt = 0;
  while(!Q.empty()){
    string tmp = Q.front();
    //cout<<"tmp = "<<tmp<<endl;
    Q.pop();
    visitedCnt++;
    MI itr = tree.Path.lower_bound(tmp);
    while(itr != tree.Path.upper_bound(tmp)){
       string Child = itr->second;
       //cout<<"Child = "<<Child<<endl;
       Q.push(Child);
       NextLevelCnt++;
       itr++;
    }
    if(visitedCnt == CurrentLevelCnt){
      if(Max < visitedCnt){
        Max = visitedCnt;
        MaxDepth = depth;
      }
      visitedCnt = 0;
      CurrentLevelCnt = NextLevelCnt;
      NextLevelCnt = 0;
      depth++;
    }
  }
  return make_pair(Max,MaxDepth);
}
