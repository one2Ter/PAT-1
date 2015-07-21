#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct Student{
  int id;
  int Vir;
  int Gift;
  int Total;
};

bool BigTohead(Student i,Student j);
int main(){
   long int N;
   int L,H;
   cin>>N>>L>>H;   
  /*
   N = 100000;
   L = 68;
   H = 86; 
  */

   vector<Student>VandG;
   vector<Student>VbutNotG; 
   vector<Student>Sec;
   vector<Student>last;
   int count = 10000000;
   while(N--){
    Student tmp; 
    int ID;
    int V;
    int G;
    cin>>ID>>V>>G;
   /*
    ID = count++;    
    V = rand()%60+40;
    G = rand()%40+60;
    cout<<ID<<" "<<V<<" "<<G<<endl;
   */ 
    tmp.id = ID;
    tmp.Vir = V;
    tmp.Gift = G;
    tmp.Total = V+G; 
     if(tmp.Vir >= H && tmp.Gift >= H){
         VandG.push_back(tmp);
      }  
      else if(tmp.Vir >= H && tmp.Gift >= L && tmp.Gift <H){
         VbutNotG.push_back(tmp);
      }
      else if(tmp.Vir >=L && tmp.Gift >= L && tmp.Vir >= tmp.Gift){
         Sec.push_back(tmp);
      }
      else if(tmp.Vir >=L && tmp.Gift >= L){
         last.push_back(tmp);
      } 

  }
   
  cout<<VandG.size()+VbutNotG.size()+Sec.size()+last.size()<<endl;
  sort(VandG.begin(),VandG.end(),BigTohead);
  sort(VbutNotG.begin(),VbutNotG.end(),BigTohead);
  sort(Sec.begin(),Sec.end(),BigTohead); 
  sort(last.begin(),last.end(),BigTohead);
   /*
     print the high score student
  */
  for(long int i = 0;i < VandG.size();i++)
    cout<<VandG[i].id<<" "<<VandG[i].Vir<<" "<<VandG[i].Gift<<endl;
   
   /*
     print the second score student
  */
  for(long int i = 0;i < VbutNotG.size();i++)
    cout<<VbutNotG[i].id<<" "<<VbutNotG[i].Vir<<" "<<VbutNotG[i].Gift<<endl;
   /*
     print the three high score student
  */
  for(long int i = 0;i < Sec.size();i++)
    cout<<Sec[i].id<<" "<<Sec[i].Vir<<" "<<Sec[i].Gift<<endl;
   
  /*
    print the fourth high score student
  */ 
  for(long int i = 0;i < last.size();i++)
    cout<<last[i].id<<" "<<last[i].Vir<<" "<<last[i].Gift<<endl;
 

   return 0;
}

bool BigTohead(Student i,Student  j){
  if(i.Total  == j.Total){
    if(i.Vir == j.Vir)
     return i.id < j.id;
    else
     return i.Vir >j.Vir; 
  }
  else 
     return i.Total >j.Total;
}
