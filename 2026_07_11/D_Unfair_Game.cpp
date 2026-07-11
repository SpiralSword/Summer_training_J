#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;


void solved(){
    int n,k;
    cin>>n>>k;
    vector C(61, vector<int>(61 + 1));
    C[0][0] = 1;
    for(int i = 1; i <= 60; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= 60; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    int ans=0;
    for(int i=0;i<__lg(n);i++){
        for(int j=max(k-i,0LL);j<=i;j++){
            ans+=C[i][j];
        }
    }
    cout<<ans+(__lg(n)>=k)<<'\n';


}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--){
        solved();
    }
    return 0;
}