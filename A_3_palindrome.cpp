#include<bits/stdc++.h>
#define long int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string res;
    bool bturn=false;
    for(int i=0;i<n;i++){
        if(i%2==0) bturn^=1;
        if(bturn) res+='b';
        else res+='a';
        
    }
    cout<<res<<endl;
    return 0;
}
