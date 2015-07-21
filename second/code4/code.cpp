/*
Holmes
*/
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<ctype.h>
using namespace std;
int main(){
 int n = 4;
 string Days[]={
  "MON","TUE","WED","THU","FRI","SAT","SUN"
 };
 int day,hour,sec;
 vector<string>str;
 while(n--){
 string oneLine;
 cin>>oneLine;
 str.push_back(oneLine);
 }
 /*
  month and day 
 */
int length = 0;
length = str[0].size() < str[1].size() ?str[0].size() : str[1].size();
int index = 0;
for(int i = 0;i < length;i++){
   if(str[0][i] == str[1][i]){
        if(index == 0){
         if(isalpha(str[0][i]) && isupper(str[0][i]) && str[0][i] <= 'G'){
           day = str[0][i] - 64;
           index++; 
         }
        }
        else if(index ==1){ 
         if(isalpha(str[0][i]) && str[0][i]<='G'){
              hour = str[0][i] - 64 + 9;
              break;
          }
          else if(isdigit(str[0][i])){
              hour = str[0][i]-48;
              break;
          }
        }
       }      
}

/*
 seconds
*/

 length = str[2].size()<str[3].size()?str[2].size():str[3].size();
 for(int i=0;i<length;i++){
   if(str[2][i] == str[3][i] && isalpha(str[2][i])){
      sec = i;
      break;
   }
 }
  cout<<Days[day-1]<<" ";
  if(hour<10)
     cout<<"0"<<hour<<":"; 
  else
     cout<<hour<<":";
  if(sec<10)
     cout<<"0"<<sec;
  else
     cout<<sec;


  
 return 0;
}
