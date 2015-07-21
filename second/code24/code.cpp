#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
using namespace std;
enum Operator{Plus,Minus,Multiply,Divide};
class Rational{
 public:
   Rational():Inf(false),sign(false){
     Numerator = 0;
     Denominator = 0;
   }
   Rational(int n,int d):Inf(false),sign(false),Numerator(n),Denominator(d){
     GCD();
   }
   
   bool Inf;
   int sign;
   int Numerator;
   int Denominator;
   void setSign(int sign){
      this->sign = sign;
   }
   Rational operator +(const Rational & A);
   Rational operator -(const Rational & A);
   Rational operator *(const Rational & A);
   Rational operator /(const Rational & A);
   friend ostream & operator <<(ostream & out,const Rational & A);
   void GCD();
};
int gcd(int a,int b);

int main(){
 string A,B;
 cin>>A>>B; 
 Rational F;
 Rational S;
 if(A[0] == '-'){
     F.setSign(-1);
     A.erase(0,1);
 }
 else
     F.setSign(1);
 if(B[0] == '-'){
     S.setSign(-1);
     B.erase(0,1);
 }
 else
    S.setSign(1); 
 size_t itr;
 if((itr = A.find('/')) != string::npos)
    sscanf(A.c_str(),"%d/%d",&F.Numerator,&F.Denominator);
 else{
    sscanf(A.c_str(),"%d",&F.Numerator);
    F.Denominator = 1;
 }
 if((itr = B.find('/')) != string::npos)
   sscanf(B.c_str(),"%d/%d",&S.Numerator,&S.Denominator);
 else{
   sscanf(B.c_str(),"%d",&S.Numerator);
   S.Denominator = 1;
 }
 F.GCD();
 S.GCD();
 Rational result; 
 result = F + S;
 cout<< F << " + "<< S <<" = "<< result <<endl;
 result = F - S;
 cout<< F << " - "<< S <<" = "<< result <<endl;
 result = F * S;
 cout<< F << " * "<< S <<" = "<< result <<endl;
 result = F / S;
 cout<< F << " / "<< S <<" = "<< result <<endl;
 return 0;
}

Rational Rational::operator +(const Rational & A){
      Rational tmp;
      tmp.setSign(1);
      tmp.Numerator =(this->sign) * A.Denominator * (this->Numerator) + (A.sign) * this->Denominator * (A.Numerator);
      tmp.Denominator = A.Denominator * this->Denominator;
      if(tmp.Numerator < 0){
        tmp.setSign(-1);
        tmp.Numerator = abs(tmp.Numerator);
      }
      tmp.GCD();
      return tmp;
}

Rational Rational::operator -(const Rational & A){
      Rational tmp;
      tmp.setSign(1);
      tmp.Numerator =(this->sign) * A.Denominator * (this->Numerator ) - (A.sign) * this->Denominator * (A.Numerator);
      tmp.Denominator = A.Denominator * this->Denominator;
      if(tmp.Numerator < 0 ){
         tmp.setSign(-1);
         tmp.Numerator = abs(tmp.Numerator);
      }
      tmp.GCD();
      return tmp;
}

Rational Rational::operator *(const Rational & A){
      Rational tmp;
      tmp.setSign(1);
      tmp.Numerator = this->Numerator * A.Numerator;
      tmp.Denominator = this->Denominator * A.Denominator;
      tmp.GCD();
      tmp.setSign(this->sign * A.sign);
      return tmp;
}

Rational Rational::operator /(const Rational & A){
      Rational tmp;
      tmp.setSign(1);
      tmp.Numerator =  this->Numerator * A.Denominator;
      tmp.Denominator = this->Denominator * A.Numerator;
      tmp.GCD();
      tmp.setSign(this->sign * A.sign);
      return tmp;
}

void Rational::GCD(){
   if(this->Denominator == 0){
     this->Inf = true;   
   }
   else if(this->Numerator != 0){
     int N,D;
     N = this->Numerator;
     D = this->Denominator;
     int g = gcd(N,D);
     N /= g;
     D /= g;
     this->Numerator = N;
     this->Denominator = D;  
   }   
}
int gcd(int a, int b){
   return a % b == 0 ? b : gcd(b,a % b);
}

ostream & operator <<(ostream  & out,const Rational & A){
    if(A.Denominator == 0) out<<"Inf";
    else if(A.Numerator == 0) out<<"0";
    else{
       if(A.sign == -1)
           out<<"(-";
       if(A.Numerator % A.Denominator == 0 ){
           out<<A.Numerator / A.Denominator;
       }    
       else{
          if(A.Numerator > A.Denominator)
              out<<A.Numerator / A.Denominator<<' ';
          out<<A.Numerator % A.Denominator<<'/'<<A.Denominator;
       } 
       if(A.sign == -1)
           out<<')';
    }
    return out;
}

