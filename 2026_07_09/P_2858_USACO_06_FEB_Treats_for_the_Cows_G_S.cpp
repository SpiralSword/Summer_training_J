#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;


void solved(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>> f(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) f[i][i]=a[i]*n;
    for(int i=2;i<=n;i++){
        for(int l=1;l<=n;l++){
            int r=l+i-1;
            if(r>n) break;
            f[l][r]=max(f[l+1][r]+a[l]*(n-i+1),f[l][r-1]+a[r]*(n-i+1));
        }
    }
    cout<<f[1][n];
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int _=1;
    //cin>>_;
    while(_--){
        solved();
    }
    return 0;
}