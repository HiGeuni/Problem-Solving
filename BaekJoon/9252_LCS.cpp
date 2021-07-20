#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;
    vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    for(int i=1;i<=s1.size(); ++i){
        for(int j=1;j<=s2.size(); ++j){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    string ans = "";
    unsigned long i = s1.size();
    unsigned long j = s2.size();
    while(dp[i][j] != 0){
        if(dp[i][j] == dp[i-1][j]) i -= 1;
        else if(dp[i][j] == dp[i-1][j] + 1 && dp[i][j] == dp[i][j-1] + 1){
            ans += s2[j-1];
            i-=1; j-=1;
        }else{
            j-=1;
        }
    }

    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    if(ans.size()){
        cout<<ans;
    }
    return 0;
}