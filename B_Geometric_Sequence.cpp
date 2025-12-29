#include<bits/stdc++.h>
#define long int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<long>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    bool possible=1;
    for(int i=1;i<n-1;i++){
        if((arr[i]*arr[i])!=(arr[i-1]*arr[i+1])){
            possible=0;
            break;
        }
    }
    cout<<((possible)?"Yes":"No")<<endl;
    return 0;
}
