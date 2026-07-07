#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;


void solved(){
    int k,x;
    cin>>k>>x;
    cout<<k*x+1<<"\n";
    
    // if(k==1){
    //     cout<<x+1<<'\n';
    // }else if(x==1){
    //     cout<<3<<"\n";   
    // }else{
    //     cout<<lcm(k,x)+gcd(k,x)<<'\n';
    // }

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