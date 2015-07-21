#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>
using namespace std;
void InsertionSort(vector <int> & A,int step);
//void MergeSort(vector <int> & A,int p,int r);
//void Merge(vector <int> &A,int p,int q,int r);

void MergeSortIteration(vector<int> & A,int step);

int main(){
 int N;
 cin>>N;
 bool Flag = false;
 vector <int> A;
 vector <int> B;
 vector <int> Array;
 for( int i = 0; i < N;i++){
    int Digit;
    cin>>Digit;
    A.push_back(Digit);
    B.push_back(Digit);
 } 
 for( int i = 0; i < N;i++){
    int Digit;
    cin>>Digit;
    Array.push_back(Digit);
 }

  for(int i = 0; i < A.size(); i++){
    InsertionSort(A,i);
    while(equal(A.begin(),A.end(),Array.begin())){
       InsertionSort(A,++i); 
       if(equal(A.begin(),A.end(),Array.begin())){
            continue;
       }
       else{ 
        cout<<"Insertion Sort"<<endl;
        for( i = 0 ;i < A.size()-1;i++)
              cout<<A[i]<<" ";
         cout<<A[i];
         Flag = true;
       }

    }
  }

  if(Flag == false){
   for(int j = 1; j < B.size(); j++){
      MergeSortIteration(B,j);
      if(equal(B.begin(),B.end(),Array.begin())){
        cout<<"Merge Sort"<<endl;
        MergeSortIteration(B,j+1);
        int i;
        for(i = 0 ;i < B.size()-1;i++)
             cout<<B[i]<<" ";
        cout<<B[i];     
      }
   }
  } 
  return 0;
}

void InsertionSort(vector <int> & A , int step){
   int i,j;
   if(step > A.size())
         step = A.size();
   for( j = 1 ;j < step;j++){
      int key = A[j];
      for(i = j - 1;i >= 0 && A[i] > key;i--){
          A[i+1] = A[i];
      }
     A[i+1] = key;
   }

}
/*
void MergeSort(vector <int> &A,int p,int r){
   if(p < r){
       int q = floor((p + r) / 2);
       MergeSort(A,p,q);
       MergeSort(A,q+1,r);
       Merge(A,p,q,r);
   }  
}

void Merge(vector <int> &A,int p,int q,int r){
     int len1 = q - p + 1;
     int len2 = r - q;
     vector <int> L(len1,0);
     vector <int> R(len2,0);
     int i,j;
     for(i = 0;i < len1;i++)
       L[i] = A[p + i];
     for(j = 0;j < len2;j++)
       R[j] = A[q + j + 1];
     L[len1] = INT_MAX;
     R[len2] = INT_MAX;
     i = 0;
     j = 0;      
     for(int k = p;k <= r;k++){
        if(L[i] <= R[j])
         A[k] = L[i++];
        else
         A[k] = R[j++];
     }
     for(int i = 0; i < A.size();i++)
          cout<<A[i]<<" ";
     cout<<endl;
}
*/

void MergeSortIteration(vector <int> &A,int step){
     int len = 1;  
     int count = 1;
     while(len/2 < A.size()){
      if(A.size() / len > 0){
       for(int i = 0;i <= A.size() - len ; i += len){
         sort(A.begin() + i,A.begin() + i + len);
       }
      }
      else{
         sort(A.begin(),A.end());
      }
      if(step == count) return;    
      len *= 2;
      count++; 
     }
}


