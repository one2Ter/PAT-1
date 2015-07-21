#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
struct Car{
   string Plate_num;
   int TotalSec;
   vector<pair<int,bool> >Ptime;
};
void InitCarInformation(vector<Car> &Parking,vector<int> query);
bool Compare(pair<int,bool> A,pair<int,bool> B);
int CalTimePeriod(int A,int B);
void PrintTime(int Sec);

int main(){
 int N,K;
 vector<Car> Parking;
 vector<int> Query;
 map<string,int>myMap; 
 cin>>N>>K;
 string PlateNum;
 string Time;
 string state;
 int hour,min,sec;
 int Tseconds;
 map<string,int>::iterator got;
 int counter = 0;
 for(int i = 0;i < N;i++){
  cin>>PlateNum>>Time>>state;
  sscanf(Time.c_str(),"%d:%d:%d",&hour,&min,&sec);
  Tseconds = hour * 3600 + min * 60 + sec; 
  bool exist = false;
  got = myMap.find(PlateNum);
  
  if(got != myMap.end())
      exist = true;
  
  if(exist == false ){  
    Car A;
    A.Plate_num = PlateNum;
    A.TotalSec = 0;
    if(state == "in")
      A.Ptime.push_back(make_pair(Tseconds,false));
    else
      A.Ptime.push_back(make_pair(Tseconds,true));
    Parking.push_back(A);  
    myMap.insert(make_pair(PlateNum,counter++));  
  }
  else{
    int j = (*got).second;
    if(state == "in")
      Parking[j].Ptime.push_back(make_pair(Tseconds,false));
    else
      Parking[j].Ptime.push_back(make_pair(Tseconds,true));
  }
 }
 string startTime;
 for(int j = 0;j < K ;j++){
     int hour,min,sec; 
     cin>>startTime;
     sscanf(startTime.c_str(),"%d:%d:%d",&hour,&min,&sec);
     int time = hour * 3600 + min * 60 + sec;
     Query.push_back(time);
 }
/*
 for(int i = 0 ; i < Parking.size(); i++){
   Car  A= Parking[i];
   cout<<A.Plate_num<<endl;
   for(int j = 0 ; j < A.Ptime.size(); j++){
      cout<<A.Ptime[j].first<<" ";
   }
   cout<<endl;
 }
*/

 InitCarInformation(Parking,Query);
 return 0;
}


void InitCarInformation(vector<Car> &Parking,vector<int> query){
   if(Parking.size() == 0) return;
   int num = query.size();
   int N = Parking.size();
   int *Q = (int*)malloc(num * sizeof(int*));   
   vector <string> Longest;
   int max = 0;
   for(int i = 0 ;i < N; i++){
      Car tmp = Parking[i];
      sort(tmp.Ptime.begin(),tmp.Ptime.end(),Compare);
      bool Inflag = false;
      bool Paired = true;
      pair<int,bool>last;
      vector<pair<int, bool> >::iterator itr = tmp.Ptime.begin();
       for(;itr != tmp.Ptime.end();itr++){
          if((*itr).second == false){
            if(Paired == true){//prev is out and current is in 
               last = *itr;
               Paired = false;
            }
            else{//prev is in and current is in
               last = *itr;
            }
          }
          else{
             if(Paired == false){// prev is in, and current is out
               Paired = true;
               tmp.TotalSec += CalTimePeriod(last.first,(*(itr)).first); 
               if(tmp.TotalSec > max){
                 max = tmp.TotalSec;
                 Longest.clear();
                 Longest.push_back(tmp.Plate_num);
               }
               else if(tmp.TotalSec == max){
                 Longest.push_back(tmp.Plate_num);
               }

               for(int m = 0 ;m < num; m++){
                 int starttime = query[m]; 
                 if(last.first < starttime && (*itr).first > starttime) 
                    Q[m]++;
              }

              }
           }   
      }
      
    }

   for(int i = 0; i < num;i++ ){
     cout<<Q[i]<<endl;
   }
   sort(Longest.begin(),Longest.end());
   for(int i = 0 ; i < Longest.size();i++)
     cout<<Longest[i]<<" ";
   PrintTime(max);
}

bool Compare(pair<int,bool> A,pair<int,bool> B){
    return A.first < B.first; 
}

int CalTimePeriod(int A,int B){
   return B - A;       
}
void PrintTime(int Sec){
   int hour,min,sec;
   hour = Sec / 3600;
   min = (Sec % 3600) / 60;
   sec = (Sec % 3600) % 60;
   cout<<setfill('0');
   cout<<setw(2)<<hour<<":"<<setw(2)<<min<<":"<<setw(2)<<sec;
}
