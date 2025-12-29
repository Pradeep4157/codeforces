#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int first,second,weight;
        cin>>first>>second>>weight;
        (dp[first][second]==0)?dp[first][second]=weight:dp[first][second]=min(dp[first][second],weight);
        (dp[second][first]==0)?dp[second][first]=weight:dp[second][first]=min(dp[second][first],weight);
        adj[first].push_back(second);
    }
    int k,time;
    cin>>k>>time;
    for(int i=0;i<k;i++){
        int first,second;
        cin>>first>>second;
        (dp[first][second]==0)?dp[first][second]=time:dp[first][second]=min(dp[first][second],time);
        (dp[second][first]==0)?dp[second][first]=time:dp[second][first]=min(dp[second][first],time);
        adj[first].push_back(second);
    }
    // now i need to connect the neighbors of 
    return 0;
}
