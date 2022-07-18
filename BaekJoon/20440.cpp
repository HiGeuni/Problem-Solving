#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, ts, te;
    cin>>n;
    vector<pii>v;
    vector<int>coord;

    for(int i=0; i<n; ++i){
        cin>>ts>>te;
        v.push_back({ts, te});
        coord.push_back(ts);
        coord.push_back(te);
    }
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());

    vector<int>pSum(coord.size(), 0);

    for(int i=0; i<n; ++i){
        int sidx = lower_bound(coord.begin(), coord.end(), v[i].first) - coord.begin();
        int eidx = lower_bound(coord.begin(), coord.end(), v[i].second) - coord.begin();
        pSum[sidx]++;
        pSum[eidx]--;
    }

    int max_ = pSum[0];
    int sans = 0;
    for(int i=1; i<coord.size(); ++i){
        pSum[i] += pSum[i-1];
        if(pSum[i] > max_){
            sans = i;
        }
        max_ = max(pSum[i], max_);
    }

    cout<<max_<<"\n";

    int eans=sans + 1;
    
    for(int i=sans + 1; i < coord.size(); ++i){
        if(pSum[i] != max_){
            eans = i;
            break;
        }
    }
    cout<<coord[sans]<<" "<<coord[eans]<<'\n';

    return 0;
}
