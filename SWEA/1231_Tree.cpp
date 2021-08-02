#include<iostream>
using namespace std;
char buf[101];
int N;

void inorder(int n){
    if(2*n <= N){
        inorder(2*n);
    }
    cout<<buf[n];
    if(2*n+1<=N){
        inorder(2*n+1);
    }
}

int main(){
    for(int tc=1; tc<=10; ++tc){
        for(int i=0; i<101; ++i) buf[i] = '0';
        int parent,child1, child2;
        char s;
        cin>>N;
        for(int i=1; i<=N; ++i){
            cin>>parent>>s;
            buf[parent]=s;
            if(2*i+1 <= N){
                cin>>child1>>child2;
            }
            else if(2*i <= N){
                cin>>child1;
            }
        }
        cout<<"#"<<tc<<" ";
        inorder(1);
        cout<<'\n';
    }
    return 0;
}