#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Node{
   int Val;
   int ID;
   Node * left;
   Node * right;
   Node(int i):Val(0),ID(i),left(NULL),right(NULL){}
};

void InOrderTree(Node * root,vector<int>&Array);
void TreePrint(Node * root,int N);

int main(){
 int N;
 cin>>N;
 map<int,Node*>exist;
 int Data1,Data2;
 for(int i = 0 ; i < N;++i){
   cin>>Data1>>Data2; 
   if(exist.find(i) == exist.end()){
      exist[i] = new Node(i); 
   }
   if(Data1 != -1){
      if(exist.find(Data1) == exist.end()){
         exist[Data1] = new Node(Data1); 
      }
      exist[i]->left = exist[Data1]; 
   }
   if(Data2 != -1){
      if(exist.find(Data2) == exist.end()){
         exist[Data2] = new Node(Data2); 
      }
      exist[i]->right = exist[Data2]; 
   }
 }
vector<int>myVector;
 int Data;
 for(int j = 0 ; j < N ;j++){
   cin>>Data;
   myVector.push_back(Data); 
 }
 sort(myVector.begin(),myVector.end());
 vector<int>Position;
 InOrderTree(exist.find(0)->second,Position);
 for( int i = 0 ;i < N;i++){
   if(exist.find(Position[i]) != exist.end())
    exist.find(Position[i])->second->Val = myVector[i];
 }
 TreePrint(exist.find(0)->second,N);
}

void InOrderTree(Node * root,vector<int>&Array){
    if(root != NULL){
      InOrderTree(root->left,Array);
      Array.push_back(root->ID);
      InOrderTree(root->right,Array);
    }
}

void TreePrint(Node * root,int N){
    if(root == NULL) return;  
    queue<Node*> Q;
    Q.push(root);
    int count = 0; 
    while(!Q.empty()){
       Node * tmp = Q.front();
       cout<<tmp->Val;
       if(count != N -1)
          cout<<" ";
       Q.pop();
       count++;
       if(tmp->left != NULL)
	   Q.push(tmp->left);
       if(tmp->right != NULL) 
           Q.push(tmp->right);
    }
}
