#include<bits/stdc++.h>
#define long int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long t;
    cin >> t; 
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int>l(n);
        for(int i=0;i<n;i++) cin>>l[i];
        vector<int>b;
        for(int i=0;i<n;i++){
            if(l[i]==0) b.push_back(a[i]);
        }
        sort(b.rbegin(),b.rend());
        int j=0;
        for(int i=0;i<n;i++){
            if(l[i]==0) a[i]=b[j++];
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}
