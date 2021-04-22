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

ll nodeNumber(ll r, ll c, ll rows, ll columns) {
	return r*columns+c+1;
}

vector< pll > neighbors(ll r, ll c, ll rows, ll columns) {

	vector<pll> neigh;
	if (r>0)
		neigh.push_back(pll(r-1,c));
	if (r<rows-1)
		neigh.push_back(pll(r+1,c));
	if (c > 0)
		neigh.push_back(pll(r,c-1));
	if (c < columns-1)
		neigh.push_back(pll(r,c+1));

	return neigh;
}

vector< vector< pll > > matrixToGraph(vector< vector< ll > >& matrix, ll rows, ll columns) {

	vector< vector< pll > > graph;
	for (int i = 0; i < rows*columns; i++)
		graph.push_back(vector<pll>());
	for (ll i = 0; i < rows; i++) {
		for (ll j = 0; j < columns; j++) {
			ll node = nodeNumber(i, j, rows, columns);
			// cout << "Node: " << node << endl;
			vector< pll > N = neighbors(i, j, rows, columns);
			for (auto it = N.begin(); it != N.end(); it++) {
				// cout << it->X << " " << it->Y << endl;
				graph[node-1].push_back(pll(nodeNumber(it->X, it->Y, rows, columns), matrix[it->X][it->Y]-matrix[i][j]));
			}
		}
	}

	// cout << graph.size() << endl;
	return graph;
}

void printGraph(vector< vector< pll > > graph) {
	cout << graph.size() << endl;
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

    ll ROWS, COLUMNS;
    cin >> ROWS >> COLUMNS;
    ll val;

    vector< vector< ll > > matrix;
    for (ll i = 0; i < ROWS; i++) {
    	vector<ll> row;
    	for (ll j = 0; j < COLUMNS; j++) {
    		cin >> val;
    		row.push_back(val);
    	}
    	matrix.push_back(row);
    }

    // for (ll i = 0; i < ROWS; i++) {
    // 	for (ll j = 0; j < COLUMNS; j++)
    // 		cout << matrix[i][j] << " ";
    // 	cout << endl;
    // }

    vector< vector <pll> > graph = matrixToGraph(matrix, ROWS, COLUMNS);
    printGraph(graph);

    return 0;
}




