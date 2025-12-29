#include<bits/stdc++.h>
#define ll int64_t
using namespace std;
int mod=1e9+9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++) cin>>arr[i];
    ll res=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            res=(res+arr[i-1]-arr[i]);
            arr[i]=arr[i-1];
        }

    }
    cout<<res<<endl;
    return 0;
}
