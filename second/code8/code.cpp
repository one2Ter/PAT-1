#include<iostream>
using namespace std;
int WinDrawLost(const char &, const char &);
void Record(const char &,int game[3]);
char Max(int game[3]);

int main(){
 int N;
 int GA[3] = {0};
 int GB[3] = {0};
 int countA[3]={0}; 
 int countB[3]={0};

 cin>>N;
 while(N--){
  char A,B; 
  cin>>A>>B;
  if(WinDrawLost(A,B) == 1){
    GA[0]++;
    GB[2]++;
    Record(A,countA);
  }
  else if(WinDrawLost(A,B) == 0){
    GA[1]++;
    GB[1]++;
  }
  else{
    GA[2]++;
    GB[0]++;
    Record(B,countB);
  }
 }

 cout<<GA[0]<<" "<<GA[1]<<" "<<GA[2]<<endl;
 cout<<GB[0]<<" "<<GB[1]<<" "<<GB[2]<<endl;
 cout<<Max(countA)<<" "<<Max(countB);
 
 


 return 0;
}


int WinDrawLost(const char &A,const char &B){
   int result;
   if( (A == 'C' && B == 'J') || (A == 'J' && B == 'B') || (A == 'B' && B == 'C')){
       result = 1;
   }
   else if(A == B){
       result = 0;
   }
   else
       result = -1;
   return result;
}

void Record(const char & player,int game[3]){
  if(player == 'C') game[0]++;
  else if(player == 'J') game[1]++;
  else game[2]++; 
}

char Max(int game[3]){
 char tmp = 'C';
 int max = 0;
 if(game[max] < game [1]){
         tmp = 'J';
         max = 1;
 }
 if(game[max] <= game[2]){
        tmp = 'B';
        max = 2;
 }
    return tmp;
}

