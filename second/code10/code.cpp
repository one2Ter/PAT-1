#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct MoonCake{
   float Price;
   int Total;
   int Num;
};

bool Compare(MoonCake A , MoonCake B);
int main(){
 int N,Weight;
 cin>>N>>Weight;
 vector<int>Num;
 vector<int>TPrice;
 vector<MoonCake>Q;
 /*
   input the num array
 */
 for(int j = N;j > 0;j--){
   int num;
   cin>>num;
   Num.push_back(num);    
 } 
/*
   input the price array
*/
 for(int j = N;j > 0;j--){
   int price;
   cin>>price;
   TPrice.push_back(price);    
 }

 for(int k = 0; k < N;k++){
    MoonCake tmp;
    tmp.Num = Num[k];
    tmp.Total = TPrice[k];
    tmp.Price = (float) TPrice[k]/ (float) Num[k];
    Q.push_back(tmp);  
 }

 sort(Q.begin(),Q.end(),Compare);
 
 
 float OptimalTotalPrice = 0;
 int W = 0;
 int index = 0;
 /*
 while(W < Weight){
  if(Q[index].Num>0){
      W++;
      Q[index].Num--;
      OptimalTotalPrice +=Q[index].Price;
  } 
  else{
     index++;
  }
 }
 */
 while(Weight){
    if(Weight >= Q[index].Num){
      Weight -= Q[index].Num;
      OptimalTotalPrice += Q[index].Total;
      index++;  
    }
    else{
      OptimalTotalPrice += Weight * Q[index].Price;
      Weight = 0;
    }
 }

 cout<<fixed<<setprecision(2)<<OptimalTotalPrice;
 return 0;
}


bool Compare(MoonCake A ,MoonCake B){
    return A.Price>B.Price;
}
