#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) cin >> arr[i];
    
    long long count = 1;
    long long xorr = 0;
    for (long long i = 0; i < n; i++) xorr = (xorr ^ arr[i]);
    
    unordered_set<long long> val;
    val.insert(xorr);
    
    for (long long i = 0; i < n; i++) {
        long long currxorr = xorr ^ arr[i];
        for (long long j = 0; j < n; j++) {
            if(i==j) continue;
            long long temp = currxorr ^ arr[j];
            temp ^= (arr[i] + arr[j]);
            if (!val.count(temp)) {
                count+=n;
                val.insert(temp);
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
