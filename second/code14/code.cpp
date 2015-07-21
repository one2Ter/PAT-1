#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main(){
  /**
  [+-][1-9]"."[0-9]+E[+-][0-9]+ 
 */
 string  Scientific ;
 cin>>Scientific;
 char Fsign,Ssign;
 char FNum[1000],SNum[1000];
 char FirstHalf[10000];
 char SecondHalf[10000];
 int zeroNum = 0;
 sscanf(Scientific.c_str(),"%[^E]",FirstHalf);
 sscanf(Scientific.c_str(),"%*[^E]E%s",SecondHalf);
 sscanf(FirstHalf,"%c%s",&Fsign,FNum);
 sscanf(SecondHalf,"%c%s",&Ssign,SNum);
 zeroNum = abs(atoi(SecondHalf));
 if(Fsign == '-')
   cout<<"-";
 if(Ssign == '-'){
   cout<<"0.";
   int zeros = abs(atoi(SecondHalf)) - 1;
   for(int i = 0;i < zeros;i++){
    cout<<"0";
   }
 }
 bool flag = false;
 int index = 0;
 for(int i = 0;i < strlen(FNum);i++){
   if(FNum[i] == '.') flag = true;
   if(FNum[i] != '.'){
     cout<<FNum[i];
     if(flag == true)
        index ++ ;
   }
 }
 if(Ssign == '+'){
    while(index++ < zeroNum){
       cout<<"0";
    }
 }

 return 0;
}
