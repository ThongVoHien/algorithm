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

int inf = std::numeric_limits<int>::max();

void printPath(unsigned int* parent, int j)
{
      
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;
  
    printPath(parent, parent[j]);
  
    printf("%d ", j);
}

void printSolution(int* dist, int n, unsigned int* parent, int src)
{
    printf("Vertex\t Distance\tPath");
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == inf) {
            dist[i] = 0;    
        }
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}

void bellmanford(int s, vector< vector< pair<int,int> > > graph) {

    int size = graph.size();
    int *dist = new int [size];
    unsigned int *parent = new unsigned int [size];

    // initialize the dist of each node as infinity and visited status as false
    for (int i = 0; i < size; i++) 
    {
        dist[i] = inf;
        parent[i] = -1;
    }

    dist[s] = 0;

    for (int k = 0; k < size-1; k++) {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int other_node = graph[i][j].first;
                if (dist[i] != inf && (dist[other_node] > (dist[i] + graph[i][j].second))) {
                    dist[other_node] = dist[i] + graph[i][j].second;
                    parent[other_node] = i;
                }
            }
        }
    }

    printSolution(dist, size, parent, s);
}

void printGraph(int size, int** graph) {
	for (int i = 0; i < size; i++) {
		cout << "Node " << i << ": ";
		for (int j = 0; j < size; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

void printGraph(vector< vector< pair<int,int> > > graph) {
	for (int i = 0; i < graph.size(); i++) {
		cout << "Node " << i << ": ";
		for (int j = 0; j < graph[i].size(); j++) {
			cout << "(" << graph[i][j].first << "," << graph[i][j].second << ") ";
		}
		cout << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0);

    int V = 10;
    int E;
    int WEIGHT = 10;
	srand(time(NULL));
    //  Let us create the example
    // graph discussed above
    vector< vector< pair<int, int> > > weighted_graph;

    // cin >> V >> E;
    // for (int i = 0; i < V; i++) {
    // 	vector< pair<int, int> > neighbors;
    // 	weighted_graph.push_back(neighbors);
    // }

    // for (int j = 0; j < E; j++) {
    //     int u, v, weight;
    //     cin >> u >> v >> weight;

    //     if (weight != 0)
    //         weighted_graph[u].push_back(pair<int,int>(v,weight));
    // }

    for (int i = 0; i < V; i++) {
        vector< pair<int, int> > neighbors;
        for (int j = 0; j < V; j++) {
            int weight = 0;
            if (i != j)
                weight = (int)(rand() % WEIGHT);
            if (weight != 0)
                neighbors.push_back(pair<int,int>(j,weight));
        }
        weighted_graph.push_back(neighbors);
    }

    bellmanford(3, weighted_graph);
    cout << endl;
}
