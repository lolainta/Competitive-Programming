#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>

#define endl '\n'
#define all(v) begin(v),end(v)
#define mp(x,y) make_pair(x,y)
#define mpp(w,x,y,z) mp(mp(w,x),mp(y,z))
#define ub upper_bound
#define lb lower_bound
#define fst first
#define scd second

#ifndef lolainta
#define DBN(...)
#define DBN1D(...)
#define DBN2D(...)
#define dbn(...)
#endif

using namespace std;

typedef long long loli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;
typedef pair<pll,pll> pllll;
typedef string str;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<loli> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<str> vs;

const loli md=1e6+7;
// const int inf=0x3fffffff;
const loli inf=1ull<<60;

inline loli mod(const loli&x){
    return (x%md+md)%md;
}
inline loli mod(const loli&x,const loli&m){
    return (x%m+m)%m;
}

void pre(){

}

void solve(){

}

int main(){
    cout<<fixed<<setprecision(8);
#ifdef lolainta
    cerr<<"========== Start Executing ==========\n";
    ios_base::sync_with_stdio(false);cin.tie(0);
#endif
    pre();
    int _=1;
//    cin>>_;
    vl __(_);
    iota(all(__),1);
    for(auto i:__){
		i=i;
#ifdef lolainta
        // cout<<"Case "<<i<<": ";
        cerr<<"========== Case "<<i<<" ==========\n";
#endif
        solve();
    }
#ifdef lolainta
    cerr<<"=====================================\n";
#endif
    return 0;
}
