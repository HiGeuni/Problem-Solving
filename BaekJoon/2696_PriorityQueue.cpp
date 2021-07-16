#include<iostream>
#include<queue>
using namespace std;

int main(){
    cin.tie();
    ios_base::sync_with_stdio(false);
    int Tc;
    cin>>Tc;
    for(int i=0;i<Tc; ++i){
        int N;
        cin>>N;
        vector<int>ans;
        priority_queue<int>maxPq;
        priority_queue<int, vector<int>, greater<> > minPq;
        for(int j=1;j<N+1; ++j){
            int tmp;
            //maxHeap
            cin>>tmp;
            if(maxPq.empty() && minPq.empty()) maxPq.push(tmp);
            else{
                if(maxPq.top() < tmp){
                    minPq.push(tmp);
                }else{
                    maxPq.push(tmp);
                }
                if(maxPq.size() > minPq.size()){
                    while(maxPq.size() - minPq.size() > 1){
                        int t = maxPq.top();
                        maxPq.pop();
                        minPq.push(t);
                    }
                }else if(maxPq.size() == minPq.size()) {
                }
                
                    while(maxPq.size() < minPq.size()){
                        int t = minPq.top();
                        minPq.pop();
                        maxPq.push(t);
                    }
                }
            }
            if(j & 1){
                ans.push_back(maxPq.top());
            }
        }
        for(auto x : ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}