#include<bits/stdc++.h>
#define ll int64_t
using namespace std;
ll count(ll n){
    ll ans=0;
    while(n)
    {
        ans+=(n%10);
        n/=10;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t; 
    while(t--){
        ll n;
        cin>>n;
        ll ans1=0,ans2=0;
        for(ll j=n;j>=n/2;j--){
            ll left=n-j;
            ll leftcount=count(left);
            ll rightcount=count(j);
            if(abs(leftcount-rightcount)<=1){
                ans1=j;
                ans2=left;
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
