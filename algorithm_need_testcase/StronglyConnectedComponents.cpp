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

const int no_edge=1000;
const int no_node=1000;
int N,M,k,x,y,mark[no_node];
stack<int>st;
vi node[no_node],rever[no_node];

void dfs_stack(int s)
{
    mark[s]=1;
    int pos;
    for (int i=0;i<node[s].size();i++){
        pos=node[s][i];
        if (mark[pos]==0){
            mark[pos]=1;
            dfs_stack(pos);
        }
    }
    st.push(s);
}

void dfs_all()
{
    reset(mark);
    for (int i=1;i<=N;i++){
        if (mark[i]==0)
            dfs_stack(i);
    }
    
}
/*
 void ReverseGraph(){
 upf(i,1,N) node[i].clear();
 upf(i,1,M){
 node[y[i]].pb(x[i]);
 }
 }*/
void dfs_findSSC(int s)
{
    mark[s]=1;
    int pos;
    cout<<s<<" ";
    for (int i=0;i<rever[s].size();i++){
        pos=rever[s][i];
        if (mark[pos]==0){
            dfs_findSSC(pos);
        }
    }
}
void ListSSC(){
    int cur;
    while (!st.empty()){
        if (mark[st.top()]) st.pop();
        else{
            cur=st.top();
            st.pop();
            dfs_findSSC(cur);
            line();
        }
    }
}
void SSC()
{
    cin>>N>>M;
    for (int i=1;i<=M;i++){
        cin>>x>>y;
        node[x].pb(y);
        rever[y].pb(x);
    }
    dfs_all();
    reset(mark);
    //    ReverseGraph();
    ListSSC();
}
int main()
{
    SSC();
}



