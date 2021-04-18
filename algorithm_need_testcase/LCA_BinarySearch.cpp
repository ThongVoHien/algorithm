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
#include <list>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define upf(i,m,n) for (int i=m;i<=n;i++)
#define downf(i,n,m) for (int i=n;i>=m;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << "=" << x <<" ";
#define line() cout << endl;
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
#define pq priority_queue
#define it iterator
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
using namespace std;

//const int no_edge=1000;
const int no_node=1000;
int N,M,k,x,y;

vi node[no_node];
int mark[no_node],res,*road[no_node],Size[no_node];
//vi road[no_node];
list<int> l;
// road[i]: road from scr to i
// Size[i]: size of road[i]
void dfs_process(int s)
{
    l.push_back(s);
    road[s]=new int[l.size()];
    copy(l.begin(), l.end(), road[s]);
    Size[s]=(int)l.size();
    mark[s]=1;
    int pos;
    for (int i=0;i<node[s].size();i++){
        pos=node[s][i];
        if (mark[pos]==0){
            mark[pos]=1;
            dfs_process(pos);
        }
    }
    l.pop_back();
}
void dfs(int s)
{
    reset(mark);
    res=0;
    dfs_process(s);
    
}
void dfs_initiate()
{
    cin>>N>>M;
    for (int i=1;i<=M;i++){
        cin>>x>>y;
        if (x!=y){
            node[x].pb(y);
        }
    }
}
int BinarySearch(int x,int y,int left,int right){
    int R=(right+left)/2;
    if (road[x][R]==road[y][R]){
        if (road[x][R+1]==road[y][R+1])
            return BinarySearch( x , y , R , right );
        else return road[x][R];
    }
    else{
        if (road[x][R-1]!=road[y][R-1])
            return BinarySearch( x , y , left , R );
        else return road[x][R-1];
    }
}
int LCA(int x, int y){
    return BinarySearch(x,y,0, (int)min(sizeof(road[x]),sizeof(road[y])));
}
int main()
{
    dfs_initiate();
    int start=1;
    dfs(start);
    tc(){
        int x,y;
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
}



