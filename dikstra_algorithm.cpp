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
#define upf(i,m,n) for (int i=m;i<=n;i++)
#define downf(i,n,m) for (int i=n;i>=m;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define MP make_pair
#define X first
#define Y second
#define bug(x) cout << #x << "=" << x <<" ";
#define line() cout << endl;
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
#define PQ priority_queue
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

using namespace std;
const int no_node=1e4+5;
//const int no_seg=6e4;
const int INF=1e8+10;
int n,m;//dis[i]: distance from ith to scr
vector<pii> node[no_node];
struct compare{
    bool operator()(pii x,pii y){
        return x.Y>y.Y;
    }
};

void Dikstra(int scr){
    int mark[no_node], dis[no_node], bef[no_node];
    PQ< pii, vector<pii> , compare >pq;
    pii tmp, cur;
    int d;
    reset(mark); reset(dis);
    pq.push( {scr,0} );
    dis[scr]=0;
    upf(i,1,n){
        if ( i == scr ) continue;
        pq.push( {i, INF} );
        dis[i] = INF;
    }//need optimal
    while ( !pq.empty() ){
        cur = pq.top();
        pq.pop();
        if ( mark[cur.X] ) continue;
        mark[cur.X]++;
        d=cur.Y;
        int res, seg;
        for (auto j: node[cur.X]){
            res = j.X;//considered point
            seg = j.Y;//distance between point(cur) and point(res)
            if ( d + seg < dis[res] && !mark[res]){
                pq.push( {res, d+seg} );
                dis[res] = d+seg;
                bef[res] = cur.X;
            }
        }
    }
    upf(i,1,n) if ( i != scr) cout << dis[i] << " \n"[i==n];
}
void Dikstra_quick(int scr){
    int dis[no_node];
    PQ<pii, vector<pii>, compare> pq;
    upf(i,1,n) dis[i]=INF;
    pq.push( MP(scr,0) );
    dis[scr] = 0;
    while (!pq.empty()){
        pii cur=pq.top(); pq.pop();
        for (auto i:node[cur.X]){
            if ( dis[i.X] > dis[cur.X] + i.Y ){
                dis[i.X] = dis[cur.X] + i.Y;
                pq.push( MP(i.X,dis[i.X]) );
            }
        }
    }
    upf(i,2,n) cout<<dis[i]<<" \n"[i==n];
}

//void Dikstra_opt(int scr){
//    // Dijkstra
//    priority_queue<State> q;
//    q.emplace(0,src,-1);
//    while(q.size()){
//        int dist, node, prev;
//        tie(dist, ode, prev) = q.top(); q.pop();
//        dist = -dist;
//        // ~~ find next state ~~
//        q.emplace(-new_dist, new_node, node);
//    }
//}
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int x,y,l;
    upf(i,1,m){
        cin >> x >> y >> l;
        node[x].pb( {y,l} );
    }
    Dikstra(1);
    Dikstra_quick(1);
}


