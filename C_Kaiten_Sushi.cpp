#include<bits/stdc++.h>
#define long int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long n,m;
    cin>>n>>m;
    vector<long>person(n);
    for(long i=0;i<n;i++)cin>>person[i];
    vector<long>taste(m);
    long maxtaste=0;
    for(long i=0;i<m;i++){
        cin>>taste[i];
        maxtaste=max(maxtaste,taste[i]);
    }
    vector<long>gte(maxtaste+1,-1);
    for(int i=0;i<n;i++){
        int curr=person[i];
        if(gte[i]==-1 ) gte[curr]=i+1;
    }
    long curr=INT_MAX;
    for(long i=0;i<(long)gte.size();i++){
        if(gte[i]==-1){
            if(curr==INT_MAX) continue;
            else gte[i]=curr;
        }
        else{
            gte[i]=min(gte[i],curr);
            curr=min(curr,gte[i]);
        }
    }
    for(auto a:taste){
        cout<<gte[a]<<endl;
    }

    return 0;
}
