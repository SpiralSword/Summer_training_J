#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;
const int inf = 999999999;

void solved(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1,0),sum1(n+1,0),sum2(n+1,0),f(n+1,inf);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum1[i]=sum1[i-1]+(a[i]==1);
        sum2[i]=sum2[i-1]+(a[i]==2);
    }
    f[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            int cnt1 = sum1[i]-sum1[j-1];
            int cnt2 = sum2[i]-sum2[j-1];
            if(cnt1==0||cnt2==0||abs(cnt1-cnt2)<=m){
                f[i]=min(f[i],f[j-1]+1);
            }
        }
    }
    cout<<f[n];





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