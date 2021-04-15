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
#define InS insert
#define mP make_pair
#define mT make_tuple
#define EB emplace_back
#define X first
#define Y second
#define bug(x) cout << #x << "=" << x <<" ";
#define line() cout << endl;
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

const int si=1000;

int n, m, k, mark[si];
vi node[si];

/* 
    simple and short dfs
*/
// warning for multiple edges over two points
void dfs(int s){
    mark[s] = 1;
    for ( auto pos: node[s]) if ( mark[pos]==0 )
        dfs(pos);
}

/* 
    advance dfs keeps track of in and out value
*/

//int in[si], out[si], cnt;
// in[i]: time discovering i/first meet node i
// out[i]: time getting out of node i
//void dfs( int s ){
//    mark[s] = 1;
//    in[s] = ++cnt;
//    for ( auto pos: node[s])
//        if ( mark[pos]==0 )
//            dfs(pos);
//    out[s] = ++cnt;
//}

int main(){
    cin >> n >> m;
    int x, y;
    
    upf(i,1,m){
        cin >> x >> y;
        if ( x!=y ){
            node[x].PB(y);
        }
    }
    
    reset(mark);
    dfs( 1 );
}




