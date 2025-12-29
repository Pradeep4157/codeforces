#include<bits/stdc++.h>
#define ll int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t; 
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll tfreq=false;
        ll lfreq=false;
        ll ifreq=false;
        for(auto& a:s){
            if(a=='T') tfreq++;
            else if(a=='I') ifreq++;
            else lfreq++;
        }
        if(lfreq==tfreq && tfreq==ifreq){
            cout<<0<<endl;
            continue;
        }
        int count=0;
        if(tfreq==false) count++;
        if(ifreq==false) count++;
        if(lfreq==false) count++;
        bool possible=true;
        if(count>1){
            possible=false;
        }
        int push=0;
        vector<ll>res;
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]){
                // three combinations to be checked
                // l is missing
                if((s[i]=='T'||s[i+1]=='T') && (s[i]=='I'||s[i+1]=='I')){
                    // wont make any change
                    ll maxfreq=max({lfreq,ifreq,tfreq});
                    // max or first and second are equal case
                    if(maxfreq==lfreq) continue;
                    // least of them all check
                    ll minfreq=min({lfreq,ifreq,tfreq});
                    // when 2nd and 3rd are same or it is the 2nd highest
                    if((minfreq==lfreq && (minfreq==ifreq||minfreq==tfreq))||(lfreq!=maxfreq && lfreq!=minfreq)){
                        lfreq++;
                        ll index=i+push;
                        res.push_back(index);
                        push++;
                        // if i is the second max
                        if(ifreq==minfreq){
                            if(s[i]=='T'){
                                res.push_back(i+push-1);
                            }
                            else{
                                res.push_back(i+push);
                            }
                            ifreq++;
                            push++;

                        }
                        // else t is the second max
                        else{
                            if(s[i]=='L'){
                                res.push_back(i+push-1);
                            }
                            else{
                                res.push_back(i+push);
                            }
                            tfreq++;
                            push++;
                        }
                    }
                    // when it is the least one among the 3
                    else{
                        lfreq++;
                        ll index=i+push;
                        res.push_back(index);
                        push++;
                    }
                }
                // i is missing
                else if((s[i]=='T'||s[i+1]=='T') && (s[i]=='L'||s[i+1]=='L')){
                    
                    // wont make any change
                    int maxfreq=max({lfreq,ifreq,tfreq});
                    if(maxfreq==ifreq) continue;
                    // if the 2nd and 3rd are equal
                    ll minfreq=min({lfreq,ifreq,tfreq});
                    if(minfreq==ifreq && (minfreq==tfreq||minfreq==lfreq)){

                    }
                }
                // t is missing
                else{
                    
                    // wont make any change
                    int maxfreq=max({lfreq,ifreq,tfreq});
                    if(maxfreq==tfreq) continue;
                }
                if(lfreq==tfreq && tfreq==ifreq){
                    break;
                }

            }
        }
        if(possible==false){
            cout<<-1<<endl;
            continue;
        }

    }
    return 0;
}
