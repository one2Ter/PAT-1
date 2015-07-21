#include<iostream>
#include<vector>
using namespace std;
int main(){
 
 int n;
 cin>>n;
 vector<bool>Flag;

 while(n--){
  long long int a,b,c; 
  bool flag = false;
  cin>>a>>b>>c;
  if(a+b>c)
     flag = true;
  Flag.push_back(flag);
 }

 for(int i=0;i<Flag.size();i++){
  cout<<"Case #"<<i+1<<": "<<boolalpha<<Flag[i]<<endl;
 } 
 


 return 0;
}
