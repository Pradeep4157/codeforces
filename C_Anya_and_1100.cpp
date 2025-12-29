#include<bits/stdc++.h>
#define long int64_t
using namespace std;
bool is_1100_(string& s, int i){
    return (i+3<s.size() && s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'); 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long t;
    cin >> t; 
    while(t--){
        string s;
        cin>>s;
        set<int>pres;
        for(int i=0;i<s.size();i++){
            if(is_1100_(s,i)) pres.insert(i);
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int index,number;
            cin>>index>>number;
            index--;
            if((s[index]-'0')==number){
                if(!pres.empty()) cout<<"YES"<<endl;
                else cout<<"NO"<<endl ;
                continue;
            }
            else{
                s[index]=number+'0';
                for(int j=index-3;j<=index;j++){
                    if(pres.count(j)) pres.erase(j);
                }
                for(int j=index-3;j<=index;j++){
                    if(is_1100_(s,j)) pres.insert(j);
                }
                if(!pres.empty()) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }

    }
    return 0;
}
