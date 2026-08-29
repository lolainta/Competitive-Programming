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

#ifdef lolainta
// Debug macros - only active with -Dlolainta
#define dbn(x) std::cerr << #x << " = " << x << '\n'
#define DBN(...) do { std::cerr << "[" << #__VA_ARGS__ << "] = "; _dbn_print(__VA_ARGS__); std::cerr << '\n'; } while(0)
#define DBN1D(v) std::cerr << #v << " = "; for (auto&& x : v) std::cerr << x << ' '; std::cerr << '\n'
#define DBN2D(v) std::cerr << #v << " = \n"; for (auto&& r : v) { for (auto&& x : r) std::cerr << x << ' '; std::cerr << '\n'; }

template<typename T> void _dbn_print(T&& x) { std::cerr << x; }
template<typename T, typename... U> void _dbn_print(T&& x, U&&... u) { std::cerr << x << ", "; _dbn_print(std::forward<U>(u)...); }
#endif

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
    ios_base::sync_with_stdio(false);cin.tie(0);
    cout<<fixed<<setprecision(8);
#ifdef lolainta
    cerr<<"========== Start Executing ==========\n";
#endif
    pre();
    int _=1;
    cin>>_;
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
