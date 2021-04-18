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
#define vtf(i,vt) for (int i=0;i<vt.size();i++)
#define strf(i,str) for (int i=0;i<str.length();i++)
#define downf(i,n,m) for (int i=n;i>=m;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define MP make_pair
#define MT make_tuple
#define eb emplace_back
#define X first
#define Y second
#define bug(x) cout << #x << "=" << x <<" ";
#define line() cout << endl;
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
#define PQ priority_queue
#define IT iterator
#define stop() int _stop;cin>>_stop;
#define PrintAll(x) for (auto i:x) cout<<i<<" ";line();
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int si = 1e2+10;
int n, f[si], parent[si], m;

int findRoot( int i ){
    return ( (parent[i] != i) ? 
        (parent[i] = findRoot(parent[i])) : i );
}

void unionNodes( int x, int y){
    parent[findRoot(x)] = findRoot(y);
}

int areNodesConnected( int x, int y){
    return ((findRoot(x) == findRoot(y)) ? 1 : 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    upf(i,1,n) parent[i] = i;
    int x, y;
    upf(i,1,m){
        cin >> x >> y;
        unionNodes(x, y);
    }
    int q;
    cin >> q;
    upf(i,1,q){
        cin >> x >> y;
        cout << areNodesConnected(x, y) << endl;
    }
}
