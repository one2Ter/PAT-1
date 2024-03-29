/**
题目描述
There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world.  One may rent a bike at any station and return it to any other stations in the city.
The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations.  A station is said to be in perfect condition if it is exactly half-full.  If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect.  And more, all the stations on the way will be adjusted as well. 
 When a problem station is reported, PBMC will always choose the shortest path to reach that station.  If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.




Figure 1


Figure 1 illustrates an example.  The stations are represented by vertices and the roads correspond to the edges.  The number on an edge is the time taken to reach one end station from another.  The number written inside a vertex S is the current number of bikes stored at S.  Given that the maximum capacity of each station is 10.  To solve the problem at S3, we have 2 different shortest paths:
1. PBMC -> S1 -> S3.  In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.
2. PBMC -> S2 -> S3.  This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

输入描述:
Each input file contains one test case.  For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads.  The second line contains N non-negative numbers Ci (i=1,...N) where each  Ci is the current number of bikes at Si respectively.  Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj.  All the numbers in a line are separated by a space.


输出描述:
For each test case, print your results in one line.  First output the number of bikes that PBMC must send.  Then after one space, output the path in the format: 0->S1->...->Sp.  Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.
Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC.  The judge's data guarantee that such a path is unique.

输入例子:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

输出例子:
3 0->2->3 0
*/
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;
struct Graph{
  multimap<int,int> Path;
  map<pair<int,int>,int>Cvw;
  map<int,int>Dist;
  map<int,bool>Known;
  map<int,int>Parent;
  vector<int>StoreStation;
};
typedef multimap<int,int>::iterator MI;
typedef map<pair<int,int>,int>::iterator M;
#define NOTAVERTEX -1
void BuildTable(Graph & ga,int Source,int Destination);
int SearchGraph(Graph & ga,int Source,int Destination,int Cmax);
int main(){
 Graph gar;
 int Cmax;
 int Nstations;
 int Problemindex;
 int Roads;
 cin>>Cmax>>Nstations>>Problemindex>>Roads;
 gar.StoreStation.push_back(INT_MAX);
 for(int i = 0; i < Nstations ; i++){
   int Num;
   cin>>Num;
   gar.StoreStation.push_back(Num);
   gar.Known.insert(make_pair(i,false));
   gar.Parent.insert(make_pair(i,NOTAVERTEX));
 }
 for(int i = 0; i < Roads; i++ ){
   int s,d,w;
   cin>>s>>d>>w;
   BuildTable(gar,s,d);
   gar.Cvw.insert(make_pair( make_pair(s,d), w));
   gar.Cvw.insert(make_pair( make_pair(d,s), w));
   gar.Dist.insert(make_pair(d, INT_MAX));
 }

  
  int dist = SearchGraph(gar,0,Problemindex,Cmax);
  stack<int>S;
  int vertex = Problemindex;
  int Total = 0;
  int TotalStore = gar.StoreStation[vertex];
  if(gar.StoreStation[vertex] < Cmax / 2){
   Total += Cmax / 2 - gar.StoreStation[vertex];
  }
  while(gar.Parent.find(vertex)->second != NOTAVERTEX){
    S.push(vertex);
    vertex = gar.Parent.find(vertex)->second;
    if(vertex != 0){
     if(gar.StoreStation[vertex] < Cmax / 2){
       
       Total += Cmax / 2 - gar.StoreStation[vertex];
     }
     else if(gar.StoreStation[vertex] > Cmax / 2){
      if(Total != 0)
       Total = Total - (gar.StoreStation[vertex] - Cmax / 2);
     }
     TotalStore += gar.StoreStation[vertex];
    }
  } 
  int count = S.size();
  
 // cout<<"Total = "<<Total<<"TotalStore = "<<TotalStore<<endl;  
  if(Total > 0 ){
     cout<<Total;
  } 
  else{ 
     cout<<"0";
     Total = 0;
  }
  
  cout<<" 0";
  while(!S.empty()){
    int v = S.top();
    S.pop();
    cout<<"->"<<v;
  }
  int back; 
  if(TotalStore + Total >= count * Cmax / 2)
     back = TotalStore + Total - count * (Cmax/2);
  else
     back = 0;
  cout<<" "<<back;

  return 0;
}

void BuildTable(Graph & ga,int Source,int Destination){
  ga.Path.insert(make_pair(Source,Destination));
  ga.Path.insert(make_pair(Destination,Source));
}
/**
 return the distance between Source and Destination
*/
int SearchGraph(Graph & ga,int Source,int Destination,int Cmax){
    queue<int> Q;
    Q.push(Source);
    ga.Dist.find(Source)->second = 0; 
    int tmp;
    while(!Q.empty()){
       tmp = Q.front();
       ga.Known.find(tmp)->second = true;
       Q.pop();
       MI beg = ga.Path.lower_bound(tmp);
       while(beg != ga.Path.upper_bound(tmp)){
         int child = beg->second;
            if(ga.Dist.find(child)->second > ga.Dist.find(tmp)->second + ga.Cvw.find(make_pair(tmp,child))->second){
               ga.Dist.find(child)->second = ga.Dist.find(tmp)->second + ga.Cvw.find(make_pair(tmp,child))->second;
               Q.push(child);
               ga.Parent.find(child)->second = tmp;
            }
            else if(ga.Dist.find(child)->second == ga.Dist.find(tmp)->second + ga.Cvw.find(make_pair(tmp,child))->second){
                 int CurrentParent = ga.Parent.find(child)->second;
                 if(ga.StoreStation[child] + ga.StoreStation[beg->first] < Cmax){
                   if(ga.StoreStation[CurrentParent] < ga.StoreStation[beg->first]){
                     Q.push(child);
                     ga.Parent.find(child)->second = tmp;
                   }
                 }
                 else if(ga.StoreStation[child] + ga.StoreStation[beg->first] > Cmax){
                   if(ga.StoreStation[CurrentParent] > ga.StoreStation[beg->first]){
                     Q.push(child);
                     ga.Parent.find(child)->second = tmp;
                   }
                 }
            }
         ++beg;
       }
     }
    

     if(ga.Dist.find(Destination)->second)
       return ga.Dist.find(Destination)->second;
     else 
       return INT_MAX;
}


