#include <iostream>
#include <cmath>
#include <stdio.h>
#include <limits.h>
#include <string>
using namespace std;
int main(){
 string P,A;
 cin>>P>>A;
 int p[3] = {0},a[3] = {0}; 
 sscanf(P.c_str(),"%d.%d.%d",&p[0],&p[1],&p[2]);
 sscanf(A.c_str(),"%d.%d.%d",a,a+1,a+2);
 
 int Psum,Asum;
 Psum = (p[0] * 17) * 29 + p[1] * 29 + p[2];
 Asum = (a[0] * 17) * 29 + a[1] * 29 + a[2];

 int delta = Asum - Psum;
 if(delta < 0) cout<<"-";
 delta = abs(delta); 
 cout<<delta / 29 / 17<<"."<<delta / 29 % 17 <<"."<<delta - ( delta / 29 / 17 ) * 29 * 17 - (delta / 29 % 17) * 29 ; 

 return 0;
}
