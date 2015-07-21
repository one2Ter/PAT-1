#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main(){
 int n;
 vector<int>array;
 cin>>n; 
 while(n--){
  int a;
  cin>>a;
  array.push_back(a);
 }
 
 vector<int>::iterator itr = array.begin();
 int sum[5]={0};
 for(;itr!=array.end();itr++){
   if(((*itr) % 5 == 0 ) && ((*itr) % 2 == 0)){
     sum[0] += (*itr);
   } 
 }
 if(sum[0]!=0)
   cout<<sum[0]<<" ";
 else
   cout<<"N ";
 
 itr = array.begin();
 bool sign = true;
 for(;itr!=array.end();itr++){
  if( (*itr) % 5 ==1 ){
    if(sign)
       sum[1] += (*itr);
    else
       sum[1] -= (*itr);
    sign=!sign;
  } 
 }

 if(sum[1]!=0)
   cout<<sum[1]<<" ";
 else
   cout<<"N ";
 
 itr = array.begin();
 for(;itr!=array.end();itr++){
  if((*itr) % 5 == 2)
    sum[2]++;
 }

 if(sum[2]!=0)
   cout<<sum[2]<<" ";
 else
   cout<<"N ";
 
 
 itr = array.begin();
 int i=0;
 for(;itr!=array.end();itr++){
   if((*itr) % 5 == 3){
     sum[3] += (*itr);
     i++;
   }
 }
 float tmp;
 if(i!=0)
    tmp = (float)sum[3]/(float)i; 

 if(sum[3]!=0){
    cout<< fixed <<setprecision(1)<<tmp<<" ";
 }  
 else
   cout<<"N ";
 
 itr = array.begin();
 for(;itr!=array.end();itr++){
   if((*itr) % 5 ==4){
     if((*itr)>sum[4])
        sum[4] = (*itr);
   }
 }

 if(sum[4]!=0)
   cout<<sum[4];
 else
   cout<<"N";
 
  
 return 0;
}
