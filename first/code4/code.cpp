#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int DFS(int M,int N,int L);
int M,N,L,T;
bool Map[62][1286][128];
struct Point{
  int x;
  int y;
  int z;
  Point(int z,int x,int y):z(z),x(x),y(y){};  
};
int main(){
 cin>>M>>N>>L>>T;
 int Data;
 for(int i = 0; i < L; i++ ){
   for(int j = 0 ; j < M;j++){
     for(int k = 0 ; k < N; k++){
         cin>>Data;
         if(Data)
            Map[i][j][k] = true;
         else
            Map[i][j][k] = false;
     }
   }
 }

 int count = 0;
 for(int i = 0; i < L; i++ ){
   for(int j = 0 ; j < M;j++){
     for(int k = 0 ; k < N; k++){
        int tmp = DFS(i,j,k);
        if(tmp >= T)
          count += tmp;
     }
   }
 }
 
 cout<<count<<endl; 
 return 0;
}


int DFS(int i,int j,int k){
    if(!Map[i][j][k]) return 0;
    int count = 0;
    queue<Point>Q;
    Q.push(Point(i,j,k));
    while(!Q.empty()){
      int x = Q.front().x;
      int y = Q.front().y;
      int z = Q.front().z;
      Q.pop();
      if(Map[z][x][y] ){
        Map[z][x][y] = false;
        count++;
        if(x > 0)
           Q.push(Point(z,x - 1,y));
        if(x + 1 < M)
           Q.push(Point(z,x + 1,y));
        if(z > 0)
          Q.push(Point(z - 1,x,y));
        if(z + 1< L)
          Q.push(Point(z + 1,x,y)); 
        if(y > 0)
          Q.push(Point(z,x,y - 1));
        if(y + 1< N)
          Q.push(Point(z,x,y + 1));
      }
    }
    return count; 
}
