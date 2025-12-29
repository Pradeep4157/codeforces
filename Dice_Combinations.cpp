    #include<bits/stdc++.h>
    #define long int64_t
    using namespace std;
    const long mod=1e9+7;
    unordered_map<long,long>dp;
    long recursion(long n,long currsum){
        if(currsum>n) return 0;
        if(currsum==n) return 1;
        if(dp.find(currsum)!=dp.end()) return dp[currsum];
        long ans=0;
        if(currsum+1<=n) ans=(ans+recursion(n,currsum+1))%mod;
        if(currsum+2<=n) ans=(ans+recursion(n,currsum+2))%mod;
        if(currsum+3<=n) ans=(ans+recursion(n,currsum+3))%mod;
        if(currsum+4<=n) ans=(ans+recursion(n,currsum+4))%mod;
        if(currsum+5<=n) ans=(ans+recursion(n,currsum+5))%mod;
        if(currsum+6<=n) ans=(ans+recursion(n,currsum+6))%mod;
        return dp[currsum]=ans; 
    }
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        long n;
        cin>>n;
        dp.reserve(1<<20);
        cout<<recursion(n,0)<<endl;
        
        return 0;
    }
