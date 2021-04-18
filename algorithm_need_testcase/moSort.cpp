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
#include <list>
#include <time.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define upf(i,m,n) for (int i=m;i<=n;i++)
#define downf(i,n,m) for (int i=n;i>=m;i--)
#define all(a) a.begin(),a.end()
#define PB push_back
#define INS insert
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
#define X first
#define Y second
#define bug(x) cout << #x << "=" << x <<" ";
#define line() cout << endl;
#define noline(x) upf(i,1,x) cout << endl;
#define Sbug(x) cout << #x << "=" << x <<"\n";
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
#define sl(n) scanf("%lld",&n)
#define slf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pl(n) printf("%lld",n)
#define ps(n) printf("%s",n)
#define PQ priority_queue
#define IT iterator
#define stop() int _stop;cin>>_stop;
#define PrintAll(x) for (auto i:x) cout<<i<<" ";line();
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int si = 1e2+10;
const ull INF = 1e16;
ull n, k, a[si], q, l[si], r[si], id[si], ans[si], no[si], f[si], maxi;
bool MoSort( int x, int y){
    if ( l[x]/(int)sqrt(n) != l[y]/(int)sqrt(n) )
        return ( l[x]/(int)sqrt(n) <= l[y]/(int)sqrt(n) );
    return r[x] < r[y];
}
void add( int ith){
    no[ f[ a[ith] ] ]--;
    no[ ++f[ a[ith] ] ]++;
    maxi = max( f[ a[ith] ], maxi);
}
void eliminate( int ith){
    no[ f[ a[ith] ] ]--;
    no[ --f[ a[ith] ] ]++;
    maxi = max( f[ a[ith] ], maxi);
}
int main(){
    ios_base::sync_with_stdio(0);
    reset(f);
    cin >> n >> q;
    upf(i,1,n) cin >> a[i];
    a[0] = 0;
    upf(i,1,q){ id[i] = i; cin >> l[i] >> r[i]; }
    sort( id+1, id+q+1, MoSort);
    int left = 0, right = 0;
    f[0] = 1;
    maxi = 0;
    upf(i,1,q){
        while ( right != r[ id[i] ] ){
            if ( right < r[ id[i] ]) add( ++right );
            else eliminate( right-- );
        }
        while ( left != l[ id[i] ]){
            if (left < l[ id[i] ]) eliminate( left++ );
            else add( --left );
        }
        while ( no[maxi]==0) maxi--;
        ans[ id[i] ] = maxi;
    }
    upf(i,1,q) cout << ans[i] << endl;
}
/*
 11 4
 1 3 5 2 1 1 2 3 4 5 5
 2 3
 4 6
 5 6
 1 11
 */
 
