#include <iostream>
#include <string>
#include <map>
#include <limits.h>
#define INFINITY INT_MAX
#define N 200
using namespace std;
struct Graph{
  map<string,int>ID;
  int CityNums;
  int Routes;
  string Start,End;
  int Cost[N];
  int Happy[N];
  int Matrix[N][N];
  int CvH[N];//happy value
  bool Known[N];
  int DifferentNums[N];
  int Nums[N];
  int Parent[N];
  string Name[N];
};
typedef map<string,int>::iterator MI;
void InitGraph(Graph & A);
void Dijkstra(Graph &A,string src);
void ReversePrint(Graph &A,int index);
int main(){
 Graph gar;
 gar.End = "ROM";
 cin>>gar.CityNums>>gar.Routes>>gar.Start; 
 gar.ID.insert(make_pair(gar.Start,0));
 gar.Name[0] = gar.Start;
 gar.CvH[0] = 0;
 InitGraph(gar);
 for(int i = 1;i < gar.CityNums; i++){
   string name;
   int happiness;
   cin>>name>>happiness;
   gar.Name[i] = name;
   gar.ID.insert(make_pair(name,i));
   gar.CvH[i] = happiness; 
 }
 for(int k = 0 ;k < gar.Routes;k++){
   string src,dst;
   int cost;
   cin>>src>>dst>>cost;
   int i = gar.ID.find(src)->second;
   int j = gar.ID.find(dst)->second;
   gar.Matrix[i][j] = gar.Matrix[j][i] = cost; 
 }
/*
 MI itr = gar.ID.begin();
 for(;itr != gar.ID.end();itr++){
   cout<<itr->first<<" "<<itr->second<<endl;
 }  
for(int i = 0; i < gar.Routes;i++){
  for(int j = 0; j < gar.Routes;j++){
    cout<<gar.Matrix[i][j]<<" ";
  }
  cout<<endl;
}
*/

 
 Dijkstra(gar,gar.Start);
 int EndIndex = gar.ID.find(gar.End)->second;
 cout<<gar.DifferentNums[EndIndex]
  <<" "<<gar.Cost[EndIndex]
  <<" "<<gar.Happy[EndIndex]
  <<" "<<gar.Happy[EndIndex]/gar.Nums[EndIndex]<<endl;
  ReversePrint(gar,gar.ID.find("ROM")->second);
 return 0;
}

void InitGraph(Graph &A){
   int Num = A.CityNums;
   for(int i = 0 ;i < Num;i++){
     for(int j = 0; j < Num;j++){
        A.Matrix[i][j] = INFINITY;
     }
   }
   for(int i = 0; i < Num; i++){
      A.Cost[i] = INFINITY;
      A.Nums[i] = INFINITY;
      A.Happy[i] = 0;
      A.DifferentNums[i] = 0;
      A.Known[i] = false; 
   }
}


void Dijkstra(Graph &A,string src){
  int startIndex = A.ID.find(src)->second;
  A.DifferentNums[startIndex] = 1;  
  A.Cost[startIndex] = 0;
  A.Nums[startIndex] = 0;
  A.Parent[startIndex] = -1;

  for(int i = 0; i < A.CityNums; i++){
    int k = -1;
   //find the smallest value of cost,like a heap or priority queue 
   for(int j = 0 ;j < A.CityNums ;j++){
       if((!A.Known[j]) && ((k < 0) || (A.Cost[j] < A.Cost[k]))){
          k = j;
       }
    }
  A.Known[k] = true; 
  for(int j = 0; j < A.CityNums; j++){//k's adjacent vertex
     if((!A.Known[j]) && (A.Matrix[k][j] < INFINITY)){
         int value = A.Cost[k] + A.Matrix[k][j];
         if( value < A.Cost[j]){
            A.Cost[j] = value;
            A.Happy[j] = A.Happy[k] + A.CvH[j];
            A.Nums[j] = A.Nums[k] + 1;
            A.DifferentNums[j] = A.DifferentNums[k];
            A.Parent[j] = k;
         }
         else if(value == A.Cost[j]){
           A.DifferentNums[j] += A.DifferentNums[k];
           int H = A.Happy[k] + A.CvH[j];
           int nums = A.Nums[k] + 1;
           if((H > A.Happy[j]) || ((A.Happy[j] == H) && (nums < A.Nums[j]))){
             A.Happy[j] = H;
             A.Nums[j] = nums;
             A.Parent[j] = k;
           }
         }
     }
  }
  }
}


void ReversePrint(Graph &A,int index){
    if(index){
      ReversePrint(A,A.Parent[index]);
      cout<<"->";
    }
    cout<<A.Name[index];
}
