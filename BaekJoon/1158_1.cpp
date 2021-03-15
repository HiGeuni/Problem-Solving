#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, idx = 0;
    cin>>n>>k;
    vector<int>v(n);

    cout<<"<";

    for(int i=0; i<n; ++i)
        v[i] = i+1;
    
    while(v.size()!=0){
        idx = (idx+(k-1)) % v.size();
        
        cout<<v[idx];
        
        v.erase(v.begin() + idx);
        
        if(v.size()!=0)
            cout<<", ";
        
    }
    cout<<">";
    return 0;
}
