#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;


void solved(){
    int n;
    cin>>n;
    bool vis[(1<<n)+1]{};
    vector<int> ans;
    for(int k=n;k>0;k--){
        int mask = (1<<k)-1;
        for(int i=0;i<(1<<(n-k));i++){
            int t=(i<<k)|mask;
            if(!vis[t]){
                vis[t]=1;
                ans.push_back(t);
            }
        }
    }
    for(int i=0;i<(1<<n);i++){
        if(!vis[i]) ans.push_back(i);
    }
    for(int i:ans){
        cout<<i<<' ';
    }
    cout<<"\n";









    // int cnt = (1<<n)-1, m=n;
    // cout<<cnt;
    // while(cnt){
    //     for(int i=0;((i<<m)|cnt)<(1<<n)-1;vis[((i<<m)|cnt)]=1,i++){
    //         if(!vis[((i<<m)|cnt)]){
    //             cout<<" "<<((i<<m)|cnt);
    //         }
    //     }
    //     m--;
    //     cnt-=(1<<m);
    // }
    // for(int i=0;i<(1<<n)-1;i++){
    //     if(!vis[i]){
    //        cout<<" "<<i;
    //     }else{
    //         vis[i]=0;
    //     }
    // }
    // cout<<"\n";
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