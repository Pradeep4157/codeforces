#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    
    S(i,j) = sum from i .. j of arr

    T(i,j) = it is min of sum%M , (M-sum)%M;

    so one thing we can see from T(i,j) is that T(i,j) no matter what arr values are .. 

        it is always going to be in the range {0,M/2}

    f(A,M) = it is the min of T(i,j) over all possible {i,j}

    for n == 1 : 
        
        int numbers = (n - 1) / 2; 

        sum=(numbers*(numbers+1))/2;

        sum*=2;

        if(m is even) sum+=m/2;

    

*/
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while(t--){

    }
    return 0;
}
