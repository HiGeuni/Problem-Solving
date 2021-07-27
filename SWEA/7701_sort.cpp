#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int,int> pii;


bool compare(string s1, string s2){
    if(s1.size() == s2.size()){
        return s1<s2;
    }
    return s1.size() < s2.size();
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin>>N;
        vector<string>s(N);
        for(int i=0;i<N; ++i){
            cin>>s[i];
        }
        sort(s.begin(), s.end(), compare);
        cout<<"#"<<test_case<<'\n';
        for(int i=0;i<s.size(); ++i){
            if(i == 0){
                cout<<s[i]<<'\n';
            }
            else if(s[i] != s[i-1])
                cout<<s[i]<<'\n';
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}