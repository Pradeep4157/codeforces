#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    
    ok so we have n numbers which is perm from 0.. n - 1 

    and we have m queries , 

        each is l,r  && these can be duplicate   

        for each of these m queries they will take the subarray , find mex and insert that in ms 

        and at the end they will take mex(ms) which needs to be minimized 

        mex ( mex ) 

        if there is only 1 query then i will just include 0 in that query so the ms mex insertion > 0 && mex ( ms ) == 0 : 

        when there are multiple queries , then it is almost impossible for 0 to not be in the mex 

        what we need is that the hole that is in the ms should be as small as possible 

        to do that mex that we get from the array should be as big as possible ??

        the more these l, r get mexes , the smaller the hole is going to be 

        when there are multiple queries : 

            only some of the overlapping segments will have mex > 0 remaining all will have mex == 0 : 

            
        
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
