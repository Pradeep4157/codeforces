#include<bits/stdc++.h>
#define long int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long n;
    cin >> n; 
    vector<long>arr(n);
    unordered_map<long,long>mp;
    for(long i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    vector<long>dp(100002);
    dp[1]=mp[1];
    for(long i=2;i<=100001;i++){
        dp[i]=max(dp[i-1],dp[i-2]+(mp[i]*i));
    }
    cout<<dp[100001]<<endl;
    return 0;
}
