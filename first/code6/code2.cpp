#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Car{
    string PNumber;
    int TotalTime;
    bool state;
};
bool Compare(Car A,Car B);
int main(){
 int N,K;
 cin>>N>>K;
 vector<Car>Parking(N);
 for(int i = 0; i < N; ++i){
   int hour,min,sec;
   string Pname,Time,state;
   cin>>Pname>>Time>>state;
   sscanf(Time.c_str(),"%d:%d:%d",&hour,&min,&sec);
   Parking[i].TotalTime = (hour * 3600) + (min * 60) + sec;  
   if(state == "in")
      Parking[i].state = true;
   else
      Parking[i].state = false;
 }
 sort(Parking.begin(),Parking.end(),Compare); 
 vector<Car> validCars;
 vector<string> resNumbers;
 int total = -1,Max = 0,lastin;
 string tmp;
 bool first = true, inflag = true; 
 for(int i = 0; i < N;++i){
     if(first || tmp != Parking[i].state){
        first = 0;
        if(!in){
           validCars.pop_back();
        }
        if(total > Max){
           resNumbers.clean();
           resNumbers.push_back(tmp);
           Max = total;
        }
       else if(total == Max){
           resNumbers.push_back(tmp);
       }
       tmp = Parking[i].PNumber;
       inflag = true;
       total = 0;
     }
     if(inflag){

     }
     else{


     }
 }
 return 0;
}
bool Compare(Car A,Car B){
  return (A.PNumber < B.PNumber) || (A.PNumber == B.PNumber && A.TotalTime < B.TotalTime);
}
