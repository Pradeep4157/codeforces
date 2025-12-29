#include<bits/stdc++.h>
#define long int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool sfirst=false,pfirst=false;
        int index=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='s'){
                index=i;
                sfirst=true;
                break;
            }
            else if(s[i]=='p'){
                pfirst=true;
                index=i;
                break;
            }
        }
        if(sfirst==true){
            if(index>0) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else{
            bool cannot=false;
            for(int i=index+1;i<n;i++){
                if(s[i]=='s'){
                    cannot=true;
                    break;
                }
            }
            if(cannot==true) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}
