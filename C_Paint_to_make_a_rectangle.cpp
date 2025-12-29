#include<bits/stdc++.h>
#define long int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    int top=-1,bottom=-1,left=-1,right=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char curr=arr[i][j];
            char mirror=arr[i][m-1-j];
            if(curr=='#'){
                if(top==-1) top=i;
                if(left==-1) left=j;
                else left=min(left,j);
                if(right==-1) right=j;
                else right=max(right,j);
                if(bottom==-1) bottom=i;
                else bottom=max(bottom,i);

            }
            
        }

    }
    bool possible=1;
    for(int i=top;i<=bottom;i++){
        for(int j=left;j<=right;j++){
            if(arr[i][j]=='#'||arr[i][j]=='?') continue;
            else{
                possible=0;
                break;
            }
        }
    }
    cout<<((possible)?"Yes":"No")<<endl;
    
    return 0;
}
