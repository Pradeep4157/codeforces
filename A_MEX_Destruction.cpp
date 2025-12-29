#include<bits/stdc++.h>
#define long int64_t
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long t;
    cin >> t; 
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        bool cannot=true;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                cannot=false;
                break;
            }
        }
        if(cannot){
            cout<<0<<endl;
            continue;
        }
        vector<int>zeroes;
        bool twoneeded=false;
        for(int i=1;i<n-1;i++){
            if(arr[i]==0){
                twoneeded=true;
                zeroes.push_back(i);
            }
        }
        if(twoneeded==false){
            cout<<1<<endl;
            continue;
        }
        else{
            bool leftside=false,rightside=false,twoneeded1=false;
            for(int i:zeroes){
                int left=i-1;
                int right=i+1;
                while(left>=0){
                    if(arr[left]!=0){
                        leftside=true;
                        break;
                    }
                    left--;
                }
                while(right<n){
                    if(arr[right]!=0){
                        rightside=true;
                        break;
                    }
                    right++;
                }
                if(leftside==true && rightside==true){
                    twoneeded1=true;
                    break;
                }

            }
            if(twoneeded1==false) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
    return 0;
}
