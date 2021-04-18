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
#define pb push_back
#define ins insert
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define X first
#define Y second
#define bug(x) cout << #x << "=" << x <<" ";
#define line() cout << endl;
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
#define p_q priority_queue
#define it iterator
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int no_node=1e3,logN=18;
int n,sp[logN][no_node],a[no_node],level[no_node];
vi point[no_node];

void tree_initiate()
{
    int x;
    cin>>n;
    for (int i=2;i<=n;i++){
        cin>>x;
        point[i].pb(x);
        point[x].pb(i);
    }
}
void dfs(int s)
{
    for (auto pos:point[s]){
        if (level[pos]==0){
            level[pos]=level[s]+1;
            sp[0][pos]=s;
            dfs(pos);
        }
    }
}

void printfTable(){
    upf(i,1,n) cout<<i<<"\t";
    line();
    upf(l,0,logN){
        upf(i,1,n){
            cout<<sp[l][i]<<"\t\n"[i==n];
        }
    }
}
void SparseTableLCA(){
    upf(l,1,logN){
        upf(i,1,n){
            sp[l][i]=sp[l-1][sp[l-1][i]];
        }
    }
}
int LCA(int x,int y){
    if (level[x]<level[y])
        swap(x,y);
    while (level[x]>level[y])
        x=sp[(int)log2(level[x]-level[y])][x];
    if (x==y) return x;
    downf(i,logN-1,0){
        if (sp[i][x]!=sp[i][y]){
            x=sp[i][x];
            y=sp[i][y];
        }
    }
    return sp[0][x];
}
int main()
{
    ios_base::sync_with_stdio(0);
    tree_initiate();
    reset(level);reset(sp);
    level[1]=1;
    dfs(1);
    SparseTableLCA();
    printfTable();
    tc(){
        int x,y;
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
}
