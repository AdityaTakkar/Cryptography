#include <bits/stdc++.h>
using namespace std;
#define int uint64_t
int pow(int a, int n, int mod){
    int b=1;
    while(n>0){
        if(n%2==1){
            b=(b*a)%mod;
        }
        a=(a*a)%mod;
        n=n/2;
    }
    return b;
}
// 2124679 8877691
int32_t main(){
    int a=2,i=2;
    int x,y;
    cin >> x >> y;
    int n = x*y;
    assert(n>=0);
    int iterations;
    cin >> iterations;
    while(iterations--){
        a = pow(a,i,n)%n;
        int d = gcd(a-1,n);
        if(d>1){
            cout << d << " " << n/d << "\n";
            return 0;
        }
        else{
            i+=1;
        }
    }
}