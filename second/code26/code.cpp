#include<iostream>
#include<math.h>
using namespace std;
int main(){
 int N;
 char c;
 cin>>N>>c;
 int height = ceil(N / 2.0 );
 for(int i = 0;i < height ;i++){
   if(i == 0 || i == height - 1){
     for(int j = 0 ; j < N;j++)
       cout<<c;
   }
   else{
     for(int j = 0 ; j < N;j++){
      if(j == 0 || j == N-1)
        cout<<c;
      else
        cout<<' ';
     }
   }
   cout<<endl;
 }
 return 0;
}
