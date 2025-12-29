#include<bits/stdc++.h>
#define long int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long n,m,k;
    cin>>n>>m>>k;
    vector<vector<long>>arr(n,vector<long>(m));
    for(long i=0;i<n;i++){
        for(long j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    
    return 0;
}
