#include<bits/stdc++.h>
#define ll int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t; 
    while(t--){
        ll n;
        cin>>n;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<ll>prefix(n);
        ll prefsum=0;
        for(ll i=0;i<n;i++){
            prefsum+=arr[i];
            prefix[i]=prefsum;
        }
        ll res=1;
        for(ll i=0;i<n-1;i++){
            ll prefsum=prefix[i];
            ll suffsum=prefix[n-1]-prefix[i];
            ll currgcd=__gcd(prefsum,suffsum);
            
            res=max(res,currgcd);
        }
        cout<<res<<endl;
    }
    return 0;
}
