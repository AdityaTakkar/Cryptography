#include <bits/stdc++.h>
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

map<int,int>perm,subs;
vector<int> substitute(vector<int>&a){
    vector<int>rr(16);
            int x=8,num=0;
    for(int i=0;i<=16;i++){
        if(i>0 and i%4==0){
            num=subs[num];
            for0(k,4){
                rr[i-k-1]=num%2;
                num/=2;
            }
            x=8;num=0;
        }
            num+=x*a[i];
            x/=2;
    }
    return rr;
}

void prt(vector<int>&v){
    for0(i,v.size()){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void solve(){
    string key,input;
    cout << "what is the key\n";
    cin >> key ;
    cout << "what is plaintext";
    cin >> input;
    if(!(key.length()<=16 and input.length()<=16)){
        cout << "Length exceeded";
    }
    // First XOR -- XOR of key and plaintext
    vector<int> k(16),plaintext(16);
    for(int i=15;i>=16-input.length();i--){
        plaintext[i]=int(input[input.length()-16+i])-int('0');
    }
    for(int i=15;i>=16-key.length();i--){
        k[i]=int(key[key.length()-16+i])-int('0');
    }
        // prt(plaintext);
        // prt(k);
    //Doing First XOR
    vector<int> beforeFirstSubs(16);
    for(int i=0;i<16;i++){
        beforeFirstSubs[i]=(k[i]^plaintext[i]);
    }
        // prt(beforeFirstPerm);
    //creating permutation map
    subs={{0,14},{1,4},{2,13},{3,1},{4,2},{5,15},{6,11},{7,8},{8,3},{9,10},{10,6},{11,12},{12,5},{13,9},{14,0},{15,7}};
    // NOW DOING PERMUTATION 
    vector<int> afterFirstSubs(16);
    afterFirstSubs=substitute(beforeFirstSubs);
        // prt(afterFirstPerm);
    // now doing substitution
    perm={{1,1},{2,5},{3,9},{4,13},{5,2},{6,6},{7,10},{8,14},{9,3},{10,7},{11,11},{12,15},{13,4},{14,8},{15,12},{16,16}};
    vector<int>afterPerm(16);
    for(int i=0;i<16;i++){
        afterPerm[perm[i]]=afterFirstSubs[i];
    }
        // prt(afterSubs);
    //Now XOR again with key;
    vector<int>BeforeSecSubs(16);
    for(int i=0;i<16;i++){
        BeforeSecSubs[i]=(afterPerm[i]^k[i]);
    }
    // prt(BeforeSecPerm);
    // now again permutation
    vector<int>afterSecSubs=substitute(BeforeSecSubs);
    // prt(afterSecPerm);
    // Now again XOR with key
    vector<int>ans(16);
    for(int i=0;i<16;i++){
        ans[i]=(afterSecSubs[i]^k[i]);
        cout << ans[i] << " ";
    }

}

int main(){
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

int t=1;
while(t--){
    solve();
}
    
    return 0;
}