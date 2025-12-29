#include<bits/stdc++.h>
#define long int64_t
using namespace std;
void recursion(unordered_map<long,long>&freq,vector<long>& arr, long left, long right, long x, long sum){
    if(sum>x) return;
    if(sum==x||left>right){
        freq[sum]++;
        return;
    }
    recursion(freq,arr,left+1,right,x,sum);
    if(sum+arr[left]<=x){
        recursion(freq,arr,left+1,right,x,sum+arr[left]);
    }
}
long mitm(vector<long> arr, int x, int n){
    unordered_map<long,long>freq1,freq2;
    freq1.reserve(1<<20);
    recursion(freq1,arr,0,n/2-1,x,0);
    freq2.reserve(1<<20);
    recursion(freq2,arr,n/2,n-1,x,0);
    long ans=0;
    for(auto a:freq1)
    {
        long sum1=x-a.first;
        if(freq2.find(sum1)!=freq2.end()){
            ans+=(a.second*freq2[sum1]);
        }

    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long n,x;
    cin>>n>>x;
    vector<long>arr(n);
    for(long i=0;i<n;i++) cin>>arr[i];
    cout<<mitm(arr,x,n)<<endl;
    return 0;
}
