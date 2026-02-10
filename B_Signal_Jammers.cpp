#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    

    so we need to find for eveyr 

    x from 1..n

    what are the jammers 

    where ai*u + bi*v == x.. 

    if we replace x = p + q

    then it is these p's + q's possible..

    maybe min one of these.. 

    then for 1..n 

    1 is never possible.. 

    p's should be possible from ai*u 

    and q's should only be possible from bi*v... 

    then maybe for all the p's 

    i can find using maybe factors of it.. 

    now i know all the factors of the current number.. 

    and this will be rootp 
4
    if there was no  q.. 

    so i iterate from 1..n for every p

    i find all the factors of that.. 

    and this will be root n 

    and count the no of a's for each of these factors in the array.. 

    and that's it.. 

    now similarly for q there would be some count of numbers.. 

    but we cant take min of this because they might come from different ai's and bi's .. 


    

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
