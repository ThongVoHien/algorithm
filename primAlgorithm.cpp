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


// Prim Algorithm
// Complexity (V+E)log(V)
// Careful with repeating edges + directed graph?!?

const int si=1000;
const int INF = 1000000000;

struct compareSecond{
    bool operator()(pii x,pii y){
        return x.Y > y.Y;
    }
};
/* 
    findMinimumSpanningTree using Prim Algorithm
*/
void findMinimumSpanningTree(vector<vector<pii> >& graph){
    //
    // INITIALIZATION
    //
    vector<bool> inMST(graph.size(), false); // track a node in MST or not
    vector<int> dist(graph.size(), INF); // track the key of each node in pq
    vector<int> parent(graph.size(), -1); // track MST edges

    int cost = 0; 
    priority_queue<pii, vector<pii>, compareSecond > pq;

    // starting with a random node
    int src = 0;
    dist[src] = 0;
    pq.push(make_pair(src, dist[src]));
    
    //
    // GREEDY
    //
    while (!pq.empty()){
        // pick out node not in MST with smallest "dist" value
        pii node = pq.top();
        pq.pop();

        int node_id = node.first;
        int node_dist = node.second;

        if (!inMST[node_id]){
            inMST[node_id] = true;
            cost += node.second;

            // check all edges starting at this node
            for (auto& edge: graph[node_id]){
                // obtain neighbor
                int other_node = edge.first;
                int len = edge.second;

                if (inMST[other_node]) continue;

                // update dist value in pq
                if (dist[other_node] > len){
                    dist[other_node] = len;
                    parent[other_node] = node_id;
                    pq.push(make_pair(other_node, dist[other_node]));
                }
            }
        }
    }

    //
    // PRINT MST
    //
    for (int i = 0; i <graph.size(); i++){
        if (parent[i] != -1){
            printf("(%d, %d)\n", parent[i], i);
        }
    }
    printf("Cost = %d", cost);
}


int main(){
    int V, E;
    cin >> V >> E;

    vector< vector<pii> > graph;
    
    upf(i,1,V){
        graph.PB(vector<pii>());
    }

    int x, y, w;
    upf(i, 1, E){
        cin >> x >> y >> w;
        if ( x != y ){
            graph[x].PB( MP(y, w) );
            graph[y].PB( MP(x, w) );
        }
    }

    findMinimumSpanningTree(graph);
}




