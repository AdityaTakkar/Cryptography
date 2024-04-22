#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef uint64_t ull;
typedef int64_t ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<int64_t> vll;
typedef vector<string> vs;
typedef vector<long double> vld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;
typedef vector<vector<int64_t>> vvll;
typedef vector<vector<long double>> vvld;
typedef vector<vector<double>> vvd;
typedef vector<vector<char>> vvc;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<int64_t>>> vvvll;
typedef vector<vector<long double>> vvvld;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<vector<vector<char>>> vvvc;
typedef pair<int,int> pii;
typedef pair<int64_t,int64_t> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<ll,ll>> vpll;
typedef vector<vector<pair<ll,ll>>> vvpll;
typedef tuple<ll,ll,ll> tll;
typedef vector<tll> vtll;

#define pb push_back
#define pob pop_back()
#define forg(i,a,b) for(ll i=a;i<b;i++)
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)

void print_(vi perm,string s){
        for(int j=0;j<s.length()/perm.size();j++){
            for(int i=0;i<perm.size();i++){
                cout << s[j*perm.size()+perm[i]] ;
            }
        }
        cout << "\n";
}
// protection for your 
void solve(){
            #ifndef ONLINE_JUDGE
        freopen("output.txt","w",stdout);
        #endif
    string s;
    getline(cin,s);
    cout << "->"<< s ;
    for(int i=1;i<=10;i++){
        if(s.length()%i==0){
            cout << i << "\n";
            vector<int>rr;
            for(int j=0;j<i;j++){
                rr.pb(j);
            }
            int count =1 ;
            do {
                cout << count ;
                count ++;
                print_(rr,s);
            } while (next_permutation(rr.begin(), rr.end()));
        }
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int t=1;
while(t--){
    solve();
}
    
    return 0;
}