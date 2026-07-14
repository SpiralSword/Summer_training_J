#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;


void solved(){
    string t,s;
    set<string> P;
    while(cin>>t&&t!="."){
        P.insert(t);
    }
    while(cin>>t){
        s+=t;
    }
    int n=s.size();
    vector<int> f(n+1,0);
    f[0]=1;
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(i,10LL);j++){
            if(!f[i-j]) continue;
            if(P.count(s.substr(i-j,j))){
                f[i]=1;
                break;
            }
        }
        if(f[i]) ans=i;
    }
    cout<<ans<<"\n";

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