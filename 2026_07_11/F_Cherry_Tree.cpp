#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;


void solved(){
    int n;
    cin>>n;
    vector<int> g[n+1];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<bool,3>> dp(n+1);
    auto dfs=[&g,&dp] (auto &self,int u,int fa) ->void{
        int check = 0;
        array<bool,3> cur= {true,false,false};
        for(int v:g[u]){
            if(v==fa) continue;
            check=1;
            self(self,v,u);
            array<bool,3> nxt={false,false,false};
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(cur[i]&&dp[v][j]){
                        nxt[(i+j)%3]=1;
                    }
                }
            }
            cur=nxt;
        }
  
        if(!check){
            dp[u]={false, true, false};
            return;
        }
        dp[u]=cur;
        dp[u][1]=1;
    };
    dfs(dfs,1,0);
    if(dp[1][0]){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
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