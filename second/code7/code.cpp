#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int Quotient(string A,string B);
int Remainder(string A,string B);
int main(){
 string A,B;
 cin>>A>>B;

 
 string Q;
 string R;  
 int len = A.size();
 //bool flag = false;
 while(A.size() >=1){
    //cout<<"A = "<<A<<" "<<Q<<endl;
    string divider;
    int Quobit;
    int Remainderbit;
    if(A[0] - 48 >=atoi(B.c_str())){
      //cout<<"case 1"<<endl;
      divider = A.substr(0,1);
      Quobit = Quotient(divider,B);
      Remainderbit = Remainder(divider,B);
      //cout<<"Q="<<Quobit<<" R="<<Remainderbit<<endl; 
      if(A.size() == 1){
        R.push_back(Remainderbit + 48);
        Q.push_back(Quobit + 48);        
        break; 
      }
      if(Remainderbit != 0)
          A[0] = Remainderbit + 48;
      else{
          A.erase(0,1);
         
      } 
      Q.push_back(Quobit + 48);
      
      if(Remainderbit == 0){
          if(A[0] - 48 <atoi(B.c_str()) && A.size()>=1){
             Q.push_back('0');
          }
      } 
    }
    else if(A[0] - 48 < atoi(B.c_str())){
      //cout<<"case 2"<<endl; 
      if(A.size() == 1){
        // cout<<"push 0 case 0"<<endl;
        // cout<<"size == 1"<<endl;
         R.push_back(A[0]);
        // Q.push_back('0');
         break;
      }
      else{
         divider = A.substr(0,2);
         Quobit = Quotient(divider,B);
         Remainderbit = Remainder(divider,B);      
         A.erase(0,1); 
         Q.push_back(Quobit + 48); 
         if(Remainderbit != 0)
            A[0] = Remainderbit + 48;
         else{
            A.erase(0,1);
            
         }
      }
           if(A[0] - 48 < atoi(B.c_str()) && A.size()>=1 && Remainderbit == 0){
                Q.push_back('0');
            }
       if(A.size() == 0)
          R.push_back('0');

     }
   }
 
 cout<<Q<<" "<<R<<endl;
 return 0;
}

int Quotient(string A,string B){
  if(B.size() == 0) return -1; 
  return (atoi(A.c_str())) / (atoi(B.c_str())); 
}

int Remainder(string A,string B){
  if(B.size() == 0) return -1; 
  return (atoi(A.c_str())) % (atoi(B.c_str())); 
}
