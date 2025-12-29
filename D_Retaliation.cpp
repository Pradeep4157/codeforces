#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        bool peak=0;
        for(int i=0;i<n-1;i++){
            if((arr[i]>arr[i-1] && arr[i]>arr[i+1])||(arr[i]<arr[i-1] && arr[i]<arr[i+1])) peak=1;
            
        }
        

    }
    return 0;
}
