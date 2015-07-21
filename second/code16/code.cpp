#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
int main(){
 int C1,C2;
 cin>>C1>>C2;
 int delta =(int)((float)(C2 - C1) / 100.0 + 0.5);
 int hour =(delta / 3600);
 cout<<setfill('0');
 cout<<setw(2)<<hour<<":";
 delta = delta % 3600;
 int min =(delta / 60);
 delta = delta % 60;
 cout<<setw(2)<<min<<":";
 cout<<setw(2)<<delta;


 return 0;
}
