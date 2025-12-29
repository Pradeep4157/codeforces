#include<bits/stdc++.h>
#define long int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while(t--){
        int m,a,b,c;
        cin>>m>>a>>b>>c;
        int seated=0;
        int m1=m,m2=m;
        seated+=min(m1,a);
        m1-=seated;
        int remseated=min(m1,c);
        seated+=remseated;
        c-=remseated;
        int seconseated=min(b,m2);
        seated+=seconseated;
        m2-=seconseated;
        int remseated2=min(m2,c);
        seated+=remseated2;
        cout<<seated<<endl;
    }
    return 0;
}
