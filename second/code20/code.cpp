#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
 int N,P;
 cin>>N>>P;
 vector<int> myVector;
 while(N--){
  int tmp;
  cin>>tmp;
  myVector.push_back(tmp);
 }
 sort(myVector.begin(),myVector.end());
 
 int max = 0;
 for(int i = 0;i < myVector.size();i++){
    int M = myVector[i] * P;
    for(int j = i + max; j < myVector.size();j++){
        if(myVector[j] <= M){
           max = j - i + 1;
        }
        else
           break;
    }
    
 }

 cout<<max;



 return 0;
}
