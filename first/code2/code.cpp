#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <limits.h>
#define NOTAVERTEX "None"
#define INFINITY INT_MAX
using namespace std;
struct Graph{
  multimap<string,string>Path;
  map<string,int>Happiness;
  map<string,int>Dist; 
  map<pair<string,string> ,int>Cvw;//cost
  map <string,int> Cvh;//happy
  map<string,string>Parent;
  map<string, vector< vector<int> > >Shortest;
};
typedef multimap<string,string>::iterator MUI;
typedef map<string,int>::iterator MI;
void BuildTable(Graph &A,const string &src,const string &dst,int Cost);
int SearchDist(Graph &A,const string &src,const string &dst);
int main(){
 int CityNum;
 int Routes;
 string Start,Destination = "ROM";
 Graph gar;
 cin>>CityNum>>Routes>>Start;
 gar.Parent.insert(make_pair(Start,NOTAVERTEX));
 gar.Happiness.insert(make_pair(Start,0));
 vector<vector<int> > sh;
 gar.Shortest.insert(make_pair(Start,sh));
 for(int i = 0;i < CityNum - 1;i++){
    string name;
    int happness;
    cin>>name>>happness;
    gar.Happiness.insert(make_pair(name,0));
    gar.Cvh.insert(make_pair(name,happness));
    gar.Dist.insert(make_pair(name,INFINITY));
    gar.Parent.insert(make_pair(name,NOTAVERTEX));
    vector<vector<int> >empty;
    gar.Shortest.insert(make_pair(name,empty));
}
 for (int i = 0; i < Routes; i++){
    string s,d;
    int cost;
    cin>>s>>d>>cost;
    BuildTable(gar,s,d,cost);
 }
 /*
 cout<<"Path"<<endl;
 MUI itr = gar.Path.begin();
 for(;itr != gar.Path.end();itr++){
    cout<<itr->first<<" "<<itr->second<<endl;
 }
 */
 int dist = SearchDist(gar,Start,Destination);
 cout<<gar.Shortest.find("ROM")->second.size();
 cout<<" "<<dist; 
 int Max = 0,MaxAverage = 0;
 vector <vector <int> > array = gar.Shortest.find("ROM")->second; 
 for(int i = 0; i < array.size() ; i++){
   vector<int> oneLine = array[i];
   int Sum = 0;
   int ASum = 0;
   for(int j = 0; j < oneLine.size(); j++){
      Sum += oneLine[j];
   }
   ASum = Sum / oneLine.size();
   if(Sum > Max) 
     Max = Sum;
   if(MaxAverage < ASum)
     MaxAverage = ASum;
 }
 cout<<" "<<Max<<" "<<MaxAverage;
 cout<<endl;
 stack<string>S;
 string city ="ROM";
 while(gar.Parent.find(city)->second != NOTAVERTEX){
    S.push(city);
    city = gar.Parent.find(city)->second; 
 }
 S.push(Start);
 while(S.size() > 1){
    cout<<S.top()<<"->";  
    S.pop();
 }
 cout<<"ROM"<<endl;
  return 0;
}


void BuildTable(Graph &A,const string & src,const string &dst,int Cost){
      if(src.empty() || dst.empty() || Cost < 0) return; 
      A.Path.insert(make_pair(src,dst));
      A.Path.insert(make_pair(dst,src));
      A.Cvw.insert(make_pair( make_pair(src,dst),Cost));
      A.Cvw.insert(make_pair( make_pair(dst,src),Cost));
}

int SearchDist(Graph &A,const string & src,const string &dst){
     queue<string>Q;
     vector<string>Abandoned; 
     Q.push(src);
     string tmp;
     A.Dist.find(src)->second = 0;
     while(!Q.empty()){
       tmp = Q.front();
       //cout<<"tmp = "<<tmp<<endl;
       Q.pop();
       Abandoned.push_back(tmp);
       if(tmp == dst) break;
       MUI beg = A.Path.lower_bound(tmp);
       while(beg != A.Path.upper_bound(tmp)){
           string child = beg->second;
           //cout<<"child = "<<child<<endl;
           int flag = false;
           for(int i = 0;i < Abandoned.size();i++ ){
               if(child == Abandoned[i]){
                 // cout<<"abandon"<<endl;
                  flag = true;
                  break;
               }
           }
           if(flag == true){
              //cout<<"hey"<<endl;
              beg++;
             // cout<<"Flag == true"<<endl;
              continue;
           }
           if(A.Dist.find(child)->second > A.Dist.find(tmp)->second + A.Cvw.find(make_pair(tmp,child))->second){
              Q.push(child);
              A.Parent.find(child)->second = tmp;
              A.Dist.find(child)->second = A.Dist.find(tmp)->second + A.Cvw.find(make_pair(tmp,child))->second;
              A.Happiness.find(child)->second = A.Happiness.find(tmp)->second + A.Cvh.find(child)->second;  
           
               (A.Shortest.find(child)->second).clear();
               if((A.Shortest.find(tmp)->second).size() != 0)
                  A.Shortest.find(child)->second = A.Shortest.find(tmp)->second;                
               else{
                  vector<int> oneline;
                  (A.Shortest.find(child)->second).push_back(oneline);
               }

               vector< vector <int> >::iterator itr = (A.Shortest.find(child)->second).begin();
               for( ;itr != (A.Shortest.find(child)->second).end(); itr++){
                  (*itr).push_back(A.Cvh.find(child)->second);                      
               }
 
            }
           else if(A.Dist.find(child)->second == A.Dist.find(tmp)->second + A.Cvw.find(make_pair(tmp,child))->second){

               vector< vector<int> > Tmparray = A.Shortest.find(tmp)->second;
               vector< vector <int> >::iterator itr = Tmparray.begin();
                for( ;itr != Tmparray.end(); itr++){
                 (*itr).push_back(A.Cvh.find(child)->second);                      
                  (A.Shortest.find(child)->second).push_back(*itr);
               }
              
              int index = 0;
              int MaxAverage = 0; 
              vector<vector <int> > Childarray = A.Shortest.find(child)->second;
              for(int i = 0 ;i < Childarray.size();i++){
                    int sum = 0;
                    int size = (Childarray[i]).size();
                 for(int j = 0; j < size; j++){
                    sum += Childarray[i][j];
                 }
                 if(MaxAverage < sum / size){
                    MaxAverage = sum / size;
                    index = i;
                 }
              }              


              
             if((A.Happiness.find(child)->second < A.Happiness.find(tmp)->second + A.Cvh.find(child)->second ) || (index == Childarray.size() - 1)){
              Q.push(child);
              A.Parent.find(child)->second = tmp;
              A.Dist.find(child)->second = A.Dist.find(tmp)->second + A.Cvw.find(make_pair(tmp,child))->second;
              A.Happiness.find(child)->second = A.Happiness.find(tmp)->second + A.Cvh.find(child)->second;  
             }
              
              
          }            
          beg++;
       }
     }
          if(A.Dist.find(dst)->second != INFINITY){
              return A.Dist.find(dst)->second;
          }
          else 
              return INFINITY; 
}



