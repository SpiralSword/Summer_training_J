#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;


void solved(){
    int n;
    cin>>n;
    vector<int> a(n+2,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=a[1],a[n+1]=a[n];
    int ans=0,mx=0;
    for(int i=1;i<=n;i++){
        ans+=abs(a[i]-a[i-1]);
        if(i==1){
            mx = abs(a[1]-a[2]);
        }else if(i==n){
            mx=max(mx,abs(a[n]-a[n-1]));
        }else{
            mx=max(mx,abs(a[i]-a[i-1])+abs(a[i]-a[i+1])-abs(a[i-1]-a[i+1]));
        }
    }
    cout<<ans-(mx<=0?0:mx)<<'\n';

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