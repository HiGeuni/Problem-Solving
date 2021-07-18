#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
   cin.tie();
   ios_base::sync_with_stdio(false);
   int M, N;
   cin>>M>>N;
   vector<int>v(2*M-1, 1);
   for(int t=0; t<N; ++t){
       int zero, one, two;
       cin>>zero>>one>>two;
       for(int i = zero; i<zero + one; ++i)
           v[i] += 1;
       for(int i = zero + one; i< zero+one+two; ++i){
           v[i] += 2;
       }
   }

   for(int i=0;i<M; ++i){
       for(int j=0;j<M; ++j){
           if(j == 0){
               cout<<v[M-i-1]<<" ";
           }else{
               cout<<v[M+j-1]<<" ";
           }
       }
       cout<<endl;
   }
   return 0;
}
