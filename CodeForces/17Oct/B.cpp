#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t; 
    
    while (t--) {
        int k;
        cin >> k; 
        vector<int>a(k);
        for(int i=0;i<k;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int n,m;
        int i=0,j=k-1;
        while(i<j){
            long long ans=a[i]*a[j];
            if(ans==k-2){
                n=i,m=j;
                break;
            }
            else if(ans>k-2){
                j--;
            }
            else{
                i++;
            }
        }
        cout<<a[n]<<" "<<a[m]<<endl;
    }
    return 0;
}
