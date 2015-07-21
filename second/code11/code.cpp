#include<iostream>
#include<string>
using namespace std;
int main(){
 string N; 
 int Record[10] = {0};  
 cin>>N;
 for(int i = 0;i < N.size();i++){
   switch(N[i]){
     case '0':
        Record[0]++;
     break;
     case '1':
        Record[1]++;
     break;
     case '2':
        Record[2]++;
     break;
     case '3':
        Record[3]++;
     break;
     case '4':
        Record[4]++;
     break;
     case '5':
        Record[5]++;
     break;
     case '6':
        Record[6]++;
     break;
     case '7':
        Record[7]++;
     break;
     case '8':
        Record[8]++;
     break;
     case '9':
        Record[9]++;
     break;
     default:break;
   }
 }
 
 for(int i = 0; i < 10;i++){
    if(Record[i]>0)
      cout<<i<<":"<<Record[i]<<endl;
 }
 return 0;
}
