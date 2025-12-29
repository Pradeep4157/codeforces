#include<bits/stdc++.h>
#define long int64_t
using namespace std;
const int mod=1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long n,x;
    cin>>n>>x;
    vector<long>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    vector<long>dp(x+1,INT_MAX);
    dp[0]=0;
    
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<=x;j++){
            dp[j]=min(dp[j],1+dp[j-arr[i]]);
        }
    }    
    cout<<((dp[x]>=INT_MAX)?-1:dp[x])<<endl;

    return 0;
}
