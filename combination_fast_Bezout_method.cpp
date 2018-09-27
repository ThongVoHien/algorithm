#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define X first
#define Y second
#define bug(x) cout << #x << " = " << x << endl;
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
#define stop() cin >> _stop;

using namespace std;
typedef long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

using namespace std;
const ll MOD = 1000000007;

pll Bezout(ull A,ull B,pll ShowA, pll ShowB){
    if (B==0) return ShowA;
    if (A>B){
        pll tmp;
        tmp = make_pair(ShowA.X-A/B*ShowB.X,ShowA.Y-A/B*ShowB.Y);
        return Bezout(B,A%B,ShowB,tmp);
    }
    else return Bezout(B,A,ShowB,ShowA);
}
pll findBezout(ull a,ull b){
    return Bezout(a,b,make_pair(1,0),make_pair(0,1));
}// return pair (X,Y) that X.a + Y.b = 1
ull OptimalCombination(ll n, ll k){ // return nCk
    ull result = 1;
    pll BezoutPair;
    if (k>n/2) k=n-k;
    for (ll i=0;i<k;i++){
        if (i+1>n) break;
        result = (result*(n-i))%MOD;
        if (result%(i+1)!=0){
            BezoutPair = findBezout(MOD,i+1);
            if (BezoutPair.Y<0)
                result = ( (MOD - (-BezoutPair.Y)%MOD) * result) %MOD;
            else result = (result*(BezoutPair.Y%MOD))%MOD;
        }
        else tmp/=(i+1);
    }
    return result;
}
int main(){
    ull n,k;
    clock_t start,finish;
    tc(){
        cin>>n>>k;
        // compute running time for each combination
        start = clock();
        cout << OptimalCombination(n,k) << endl;
        finish=clock();
        cout << (finish-start)/(double)CLOCKS_PER_SEC << endl;
    }
}
