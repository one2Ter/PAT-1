#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Node{
    int Address;
    int Data;
    int Next;
};
int main(){
    int FirstAddress;
    int Num;
    int k;
    cin >> FirstAddress >> Num >> k;
    vector<Node> L;
    int Position[100000];
    int cnt = 0;
    L.clear();
    memset(Position, -1, sizeof(Position));
    for (int i = 0; i < Num; ++i) {
        Node node;
        cin >> node.Address >> node.Data >> node.Next;
        L.push_back(node);
        Position[node.Address] = cnt++;
    }
    vector<Node> linkLst;
    linkLst.clear();
    int p = FirstAddress;
    int i;
    for (i = 0; i < Num; ++i) {
        Node node = L[Position[p]];
        linkLst.push_back(node);
        p = node.Next;
        if (p == -1) {
            break;
        }
    }

    int time = (int)linkLst.size() / k;
     for(int j = 0;j < time; j++){
        reverse(linkLst.begin() + j * k,linkLst.begin() + j * k + k );
   }
 cout << setfill('0'); 
 for(int i = 0; i < linkLst.size(); i++){
    if( i == linkLst.size() -1)
       cout<<setw(5)<<linkLst[i].Address<<" "<<linkLst[i].Data<<" -1"<<endl;
    else
       cout<<setw(5)<<linkLst[i].Address<<" "<<linkLst[i].Data<<" "<<setw(5)<<linkLst[i+1].Address<<endl;
}
    return 0;
}
