#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
struct Man{
  string Name;
  int year;
  int month;
  int day;
  float age;
};
bool Over200(const Man & A);
bool AfterCurrentdate(const Man & B);
int ToAge(const Man & C);
const int Cyear = 2014;
const int Cmonth = 9;
const int Cday = 6;

int main(){
 int N;
 cin>>N;
 vector<Man>myVector;
 while(N--){
  string name;
  char birth[20];
  int y,m,d;
  cin>>name>>birth;
  sscanf(birth,"%d/%d/%d",&y,&m,&d);  
  Man tmp;
  tmp.Name = name;
  tmp.year = y;
  tmp.month = m;
  tmp.day = d;
  tmp.age = ToAge(tmp); 
  myVector.push_back(tmp); 
 }

 int maxindex = 0;
 int minindex = 0;
 string maxname = "";
 string minname = ""; 
 if(myVector.size() == 0){
     cout<<"0";
     return 0;
 }
 vector<Man>newArray;
 for(int i = 0; i<myVector.size(); i++){
   if(!Over200(myVector[i]) && !AfterCurrentdate(myVector[i])){
        newArray.push_back(myVector[i]);
   }
 }
 for(int i = 0; i < newArray.size(); i++){
   if(newArray[i].age >= newArray[maxindex].age)
        maxindex = i;
   if(newArray[i].age <= newArray[minindex].age)
        minindex = i;
 }


  //cout<<"maxindex = "<<maxindex<<" minindex = "<<minindex<<endl;
 /*
 vector<Man>::iterator itr = myVector.begin();
 for(int i = 0;itr != myVector.end() && i < myVector.size();){
    if(Over200(*itr) || AfterCurrentdate(*itr)){
      itr = myVector.erase(itr);
    }
    else{
      if((*itr).age >= myVector[maxindex].age){
         maxindex = i;
         maxname = myVector[maxindex].Name;
      }
      if((*itr).age <= myVector[minindex].age){
         minindex = i;
         minname = myVector[minindex].Name;
      }
      itr++;
      i++;      
    } 
 }
 */
 
 cout<<newArray.size()<<" ";
 //cout<<myVector.size()<<" ";
 cout<<newArray[maxindex].Name<<" "<<newArray[minindex].Name; 
  return 0;
}

bool Over200(const Man & A){
  if(Cyear - A.year > 200)
      return true;
  else {
   if(Cyear - A.year == 200){
    if(Cmonth - A.month > 0){
        return true;
    }
    else if(Cmonth - A.month == 0){
        if(Cday - A.day > 0){
           return true;
        }
     }
   }
  }
  return false;
}

bool AfterCurrentdate(const Man & B){
    if(B.year > Cyear){
        return true;
    }
    else{
       if(B.year == Cyear){
          if(B.month > Cmonth){
            return true;
          }
          else if(B.month == Cmonth){
            if(B.day > Cday)
              return true;
          }
       }
    }
   return false;
}


int ToAge(const Man & C){
    int Totaldays = 0;
    Totaldays = Cday - C.day;
    Totaldays += (Cmonth - C.month) * 31;
    Totaldays += (Cyear - C.year) * 365;
    return Totaldays; 
}
