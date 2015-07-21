#include <iostream>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <ctype.h>
using namespace std;
int main(){
 string Standard;
 string Actual;
 cin>>Standard;
 cin>>Actual;
 list <char> container;
 set <char> Dic;
 for(int i = 0;i < Standard.size();i++){
    set<char>::iterator it;
    if((it = Dic.find(toupper(Standard[i]))) != Dic.end()) continue;

   /* 
    if(isalpha(Standard[i])){
       if(islower(Standard[i]))
        container.push_back(toupper(Standard[i]));
       else
        container.push_back(Standard[i]);
    }
    else
   */
        container.push_back(toupper(Standard[i]));
    Dic.insert(toupper(Standard[i]));    


    for(int j = 0;j < Actual.size(); j++){
       if(Standard[i] == Actual[j]){
          container.pop_back();
          Dic.erase(Standard[i]);
          break;
       }
    }
 }
 list <char>::iterator itr = container.begin();
 for(;itr != container.end();itr++)
    cout<<*itr; 

 

 return 0;
}
