#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getParent(int set[], int x){
    if(set[x] == x) return x;
    return set[x] = getParent(set, set[x]);
}

void union_(int set[], int a, int b){
    a = getParent(set, a);
    b = getParent(set, b);
    if(a<b) set[b] = a;
    else set[a] = b;
}

int find(int set[], int a, int b){
    a = getParent(set, a);
    b = getParent(set, b);
    if(a==b) return 1;
    else return 0;
}

class Edge{
public:
    int from, to, distance;
    Edge(int a, int b, int dist){
        from = a;
        to = b;
        distance = dist;
    }
};


bool compare(Edge &e1, Edge &e2){
    if(e1.distance < e2.distance) return true;
    return false;
}

int main(){
    int n, m, from, to, weight;
    cin>>n>>m;
    vector<Edge>v;
    for(int i=0; i<m; ++i){
        cin>>from>>to>>weight;
        v.push_back(Edge(from, to, weight));
    }

    sort(v.begin(), v.end(), compare);

    int set[n];
    for(int i=0;i<n; ++i){ set[i] = i; }

    int sum_ =0;
    for(int i=0;i<v.size(); ++i){
        if(!find(set, v[i].from -1, v[i].to-1)){
            sum_+=v[i].distance;
            union_(set, v[i].from-1, v[i].to-1);
        }
    }

    cout<<sum_;
    return 0;
}
