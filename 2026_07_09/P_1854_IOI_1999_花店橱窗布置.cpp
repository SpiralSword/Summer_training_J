#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;
const int inf = 999999999;

void solved(){
    int F,V;
    cin>>F>>V;
    vector<vector<int>> a(F+1,vector<int>(V+1,0)),f(V+1,vector<int>(F+1,-inf)),pre(V+1,vector<int>(F+1,0));
    for(int i=1;i<=F;i++){
        for(int j=1;j<=V;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=V;i++) f[i][1]=a[1][i];

    for(int i=2;i<=V;i++){
        for(int j=1;j<=min(i,F);j++){
            for(int p=max(j-1,1LL);p<i;p++){
                if(f[i][j]<f[p][j-1]+a[j][i]){
                    pre[i][j]=p;
                    f[i][j]=f[p][j-1]+a[j][i];
                }
            }
        }
    }
    int ans=-inf;
    vector<int> pos(F+1,0);
    for(int i=F;i<=V;i++){
        if(ans<f[i][F]){
            pos[F]=i;
            ans=f[i][F];
        }
    }
    for(int i=F-1;i>0;i--){
        pos[i]=pre[pos[i+1]][i+1];
    }
    cout<<ans<<"\n";
    for(int i=1;i<=F;i++){
        cout<<pos[i]<<' ';
    }

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