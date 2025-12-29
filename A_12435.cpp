#include<bits/stdc++.h>
#define long int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int>arr(5);
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    int count=0;
    for(int i=0;i<4;i++){
        if(arr[i]!=i+1){
            swap(arr[i],arr[i+1]);
            count++;
        }
    }
    cout<<((count==1)?"Yes":"No")<<endl;
    return 0;
}
