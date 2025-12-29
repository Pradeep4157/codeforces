#include<bits/stdc++.h>
using namespace std;
long long calc(long  long l){
    string ls=to_string(l);
    char first=ls[0];
    long long numbers=first-'0'-1;
    return numbers;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long l,r;
    cin>>l>>r;
    if(l<10) l=10;
    long long sum=0;
    while(l<=r-10){
        long long rem=l%10-1;
        sum+=max(0LL,calc(l)-rem);
        l+=10;
    }

    cout<<sum<<endl;
    return 0;
}
