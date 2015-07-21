#include <iostream>
#include <math.h>
using namespace std;
int main(){
 int N;
 char sign;
 cin>>N>>sign;
 int count = 1;
 while(2 * pow(count,2) - 1 <N){
   count++;
 }
 /*
  an = 2 * n - 1
 */
 if(count == 1){
    cout<<sign<<endl;
    cout<<"0"<<endl;
    return 0;
 }
 for(int i = count - 1;i >= 1;i-- ){
    for(int j = 0;j < count - 1 - i; j++ ){
      cout<<" ";
    }
    for(int j = 0;j < 2 * i - 1;j++)
      cout<<sign;
       cout<<endl;
 } 
 for(int i = 1; i < count -1 ;i++){
    for(int j = count - i;j > 2 ; j-- ){
      cout<<" ";
    }
    for(int j = 0;j < 2 * ( i + 1 ) - 1;j++)
      cout<<sign;
   cout<<endl;
 }
 cout<<N - (2 * pow(count-1,2) - 1)<<endl;
 return 0;
}
