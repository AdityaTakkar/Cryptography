#include <bits/stdc++.h>
using namespace std;

int invpow(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }
    return res%m;
}

int main(){
    //g^a=x mod m
    // a = np - q , where n>=1 and n<ceil(m/n) and 0<=q<=n
    //write is as g^(np-q) = x mod m
    // g^(np)mod m = x*(g^q)mod m
    // use meet in the middle to find the p and q
    //give g, x, m
    // we have to find a in less than O(m)
    int g,x,m;
    cin >> g >> x >> m;
    g%=m;x%=m;
    map<int,int>value;
    int prod=g;
    int f=1;
    for(int i=1;i<=m;i++){
        if(prod%m==x){
            cout <<"soln from brute force " << i << "\n";
            f=0;
            // break;
        }
        prod=(prod*g)%m;
        // cout << prod << "\n";
    }
    cout << "\n";
    int n=sqrt(m)+1;
    for(int p=1;p<=n;p++){
        value[invpow(g,n*p,m)]=p;
        // cout << invpow(g,n*p,m) << "\n";
    }
    // cout << "\n";
    for(int q=0;q<=n;q++){
        int k=(invpow(g,q,m)*x)%m;
        // cout << k << "\n";
        if(value.find(k)!=value.end()){
            // if(value[k]*n-q<=m)
            cout <<"--> shanks algo " <<  (value[k]*n-q)%m << "\n";
        }
    }
    if(f==1)
    cout << -1 << "\n";
}
