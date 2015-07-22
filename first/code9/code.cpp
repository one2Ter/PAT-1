#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 *Insertion Sort
 * */
void InsertionSort(vector <int> & A ,int step);
/*
 *Heap Sort
 * */
void PercDown(vector <int> &A,int i,int N);
void HeapSort(vector <int> &A,int N);
int LeftChild(int i);


int main(){
 int N;
 cin>>N;
 vector<int>myVector;
 vector<int>Target;
 vector<int>Standard;
 
 int Data;
 for(int i = 0;i < N;++i){
   cin>>Data;
   myVector.push_back(Data);
   Standard.push_back(Data);
 }

 for(int i = 0;i < N;++i){
   cin>>Data;
   Target.push_back(Data);
 }
 /*
  *Check whether it is InsertionSort Or Heap Sort
  if the front part is sorted and the back part is just like the input array,then it's absolutely InsertionSort,else it is a Heap Sort
  * */
 int i = 0;
 while(Target[i] <= Target[i + 1] && i < N - 1 ){
      i++; 
 }
 int Index = ++i;
 bool InsertOrHeap = false;
 if(equal(Target.begin() + Index,Target.end(),myVector.begin() + Index)){
    InsertOrHeap = true; 
 } 
 /*
  *Insertion Sort
  * */
 if(InsertOrHeap){
    cout<<"Insertion Sort"<<endl;
    InsertionSort(Target,Index); 
 }
 else{//Heap Sort
    sort(Standard.begin(),Standard.end()); 
    int k = 0; 
    while(Standard[N - 1 - k] == Target[N - 1 - k]){
        k++; 
    }
    cout<<"Heap Sort"<<endl;
    HeapSort(Target,N - k);

 }
 for(int j = 0 ; j < N ; j++){
   cout<<Target[j]; 
   if(j != N - 1)
       cout<<" ";
 }
 return 0;
}

void InsertionSort(vector <int> & A ,int step){
     int i,j;
     if(step > (int)A.size())
        step = A.size();
     for( j = 1 ;j <= step;j++){
        int key = A[j];
        for(i = j - 1;i >= 0 && A[i] > key;i--){
	   A[i+1] = A[i];
	}
	A[i+1] = key;
     }
}

int LeftChild(int i){
   return i * 2 + 1;
}
void PercDown(vector <int> &A,int i,int N){
   int Child;
   int Tmp;
   for(Tmp = A[i]; LeftChild(i) < N;i = Child){
      Child = LeftChild(i); 
      if(Child != N - 1 && A[Child + 1] > A[Child]){
         Child++;
      }  
      if(Tmp < A[Child]){
         A[i] = A[Child]; 
      } 
      else
	break;
   }
   A[i] = Tmp;
}

void HeapSort(vector <int> &A,int N){
    int i;
      for( i = N / 2 ; i >= 0; i--){
        PercDown(A,i,N);
      }
      std::swap(A[0],A[N - 1]);
      for(i = N - 1;i >= 0; i--){
        PercDown(A,0,i); 
      }	     
}
