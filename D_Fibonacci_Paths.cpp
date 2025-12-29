#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    
    directed graph.. 

    values are there for each node.. 

    some simple paths such that atleast 2 nodes should be there. 


    any 2 adj nodes are valid..

    because they are like base of the sequence and dont depend

    on anything.. 

    i dont think we need mod but we will just take..

    so maybe dfs works because in case of a cycle the sequence

    will get fucked and we will break anyways.. 

    so but if the current two adj nodes are already vis.. 

    so we just add the paths that we found by these 2 nodes 

    & continue.. 

    one more thing.. 

    if these 2 nodes we visited already but the dp[nei] == 0 

    that means 

7
    3 
        10  13
    5
5







*/
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<int>>adj(n+1);
        for(int i=0;i<m;i++){
            int first,second;
            cin>>first>>second;
            adj[first].push_back(second);
        }

    }
    return 0;
}
