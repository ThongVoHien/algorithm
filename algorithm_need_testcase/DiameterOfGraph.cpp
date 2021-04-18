// Find diameter of a tree
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
#define mp make_pair
#define X first
#define Y second
#define bug(x) cout << #x << "=" << x <<" ";
#define line() cout << endl;
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
#define p_q priority_queue
#define it iterator
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int no_edge=1000;
const int no_node=1000;
int N,M,k,x,y,mark[no_node],p[2],level[no_node];
vi node[no_node];
//p: two points on diameter of the tree

void bfs(int s,int res){
    reset(mark);
    queue<int> q;
    int pos;
    q.push(s);
    level[s]=1;
    mark[s]=1;
    
    while (!q.empty()){
        pos=q.front();
        p[res]=pos;
        for (int i=0;i<node[pos].size();i++)
        {
            if (!mark[node[pos][i]])
            {
                mark[node[pos][i]]=1;
                level[node[pos][i]]=level[pos]+1;
                q.push(node[pos][i]);
            }
        }
        q.pop();
    }
}
int Diameter(){
    int start=1;
    bfs(start,0);
    bfs(p[0],1);
    cout << p[0] << " " << p[1] << endl;
    return p[1]-p[0];
    
}
void graph_initiate(){
    cin >> N >> M;
    upf(i,1,M){
        cin >> x >> y;
        if (x!=y){
            node[x].pb(y);
            node[y].pb(x);
        }
    }
}
int main()
{
    graph_initiate();
    cout<<Diameter()<<endl;
}
/*
Algorithm:
1) BFS on a random node and find the longest node A
2) BFS on A and find longest node B
3) AB is the diameter

*/
