#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;

void solved(){
    int n,k;
    cin>>n>>k;
    int ans =0,check=0;
    if(n==k){
        cout<<"0\n";
    }else{
        int x=n,y=n;
        while(y>0&&x>0){
            x=x/2;
            y=(y+1)/2;
            ans++;
            if(k>=x&&k<=y){
                check=1;
                break;
            }
        }
        cout<<((check==0)?-1:ans)<<"\n";
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