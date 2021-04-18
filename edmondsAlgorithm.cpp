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
#define MP make_pair
#define MT make_tuple
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
const int INF = 1000000000;


int bfs(vector<vector<int> >& rGraph, int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int> > q; // first: node, second, minimum flow so far on this path
    q.push(MP(s, INF));

    // BFS loop
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        upf(next, 0, rGraph[cur].size()) {
            if (parent[next] == -1 && rGraph[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, rGraph[cur][next]);

                // reach sink node
                if (next == t)
                    return new_flow;
                q.push(MP(next, new_flow));
            }
        }
    }

    // not able to reach sink
    return 0;
}

/* 
    Edmonds-Karp Algorithm:
    + finding maximum flow
    + Complexity O(VE^2)
*/
int maxflowEdmondsKarp(vector<vector<int> >& graph, int s, int t) {
    int maximum_flow = 0;
    vector<int> parent(graph.size());
    int new_flow;

    // clone residual graph from original graph
    vector<vector<int> > rGraph;
    upf(u, 0, graph.size()-1){
    	rGraph.PB(vector<int>());
    	upf(v, 0, graph.size()-1){
    		rGraph[u].PB(graph[u][v]);
    	}
    }

    // Find minimum residual capacity of the edges along
    // the path filled by BFS (on residual graph).
    while (new_flow = bfs(rGraph, s, t, parent)) {
    	
    	// Add path flow to overall flow
        maximum_flow += new_flow;
        
        // update residual capacities of the edges and
        // reverse edges along the path
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            rGraph[prev][cur] -= new_flow;
            rGraph[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return maximum_flow;
}

int main(){
    ios_base::sync_with_stdio(0);

    // Example
    vector< vector<int> > graph { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
 
    printf("The maximum possible flow is %d\n", maxflowEdmondsKarp(graph, 0, 5));

}




