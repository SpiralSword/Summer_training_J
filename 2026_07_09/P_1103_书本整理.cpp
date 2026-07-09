#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;


void solved(){
    int n,k;
    cin>>n>>k;
    vector<pii> a(n+1,{0,0});
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    sort(all(a));
    int ans = 99999999;
    vector<vector<int>> f(n+1,vector<int>(n+1,999999999999)); // f[i][j] 第i本书,保留j本一定保留第i本的最小差异度
    for(int i=1;i<=n;i++) f[i][1]=0; // f[i][j] = min(f[p][j-1]+abs(w[i]-w[p]))
    
    for(int i=1;i<=n;i++){
        for(int j=2;j<=min(n-k,i);j++){
            for(int p=1;p<i;p++){
                f[i][j]=min(f[i][j],f[p][j-1]+abs(a[i].second-a[p].second));
            }
        }
    }   
    for(int i=1;i<=n;i++) ans = min(ans,f[i][n-k]);
    cout<<ans;
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