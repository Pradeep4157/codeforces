#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    
    so the only constraints are that it should be <=a after n days && EXACTLY b after 2*n days 

    now it gives some hints towards using factors 

    because all the factors will also be calc with root n of 1e14 which is 1e7 with tc also 


    so how does it go ??

    there are 2 checkpoints : 

        a and b 

        
        we only need that till n the prod is <= a && till b prod == b 


        lets say a was not there how many ways would be there ?

        

        instead of keeping all the divisors if i just keep prime divisors then they all need to be multiplied to get b 


        then what are the ways if a wasnt there ?

            then if the days arent enough then we would have to combine some of them 


            is it of the type where we calc all the comb - wrong combinations 


            what are all the combinations ?

                if div_count = prime divisors of b 

                if ( div_count < 2*n ) : 
                    
                    i can use anything and just add 1 to the remaining empty places 


                    


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
