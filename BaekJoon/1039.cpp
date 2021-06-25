#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

string swap_(string s,int i,int j){
    string newString = s;
    int tmp = newString[i];
    newString[i] = newString[j];
    newString[j] = tmp;
    return newString;
}

int main(){
    int ans=0;
    string n;
    int k;
    cin>>n>>k;
    int length = n.size();
    priority_queue<string>pq;
    pq.push(n);
    for(int l=0;l<k; ++l){
        priority_queue<string>newPq;
        bool visit[1000001] = {false, };
        while(!pq.empty()){
            string s = pq.top();pq.pop();
            for(int i=0;i<length; ++i){
                for(int j=i+1;j<length; ++j){
                    string temp = swap_(s, i, j);
                    int tInt = stoi(temp);
                    if(temp[0] != '0' && temp.size() == length && !visit[tInt]){
                        visit[tInt] = true;
                        newPq.push(temp);
                    }
                }
            }
        }
        if(newPq.size()==0){
            ans = -1;
            break;
        }
        pq = newPq;
    }
    if(ans == -1){
        cout<<ans;
    }else{
        cout<<pq.top();
    }
    return 0;
}