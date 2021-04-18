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
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
#define stop() int _stop; cin >> _stop;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int si=11;
int N, M, k, in[si];
vi node[si];
stack<int>st;
int mark[si];
void dfs(int s){
//    bug(s);
    mark[s]++;
    for (int i=0;i<node[s].size();i++){
        if (mark[node[s][i]]==0)
            dfs(node[s][i]);
    }
    st.push(s);
}
void topo(){
    for (int i=1;i<=N;i++){
        sort(node[i].begin(),node[i].end(),greater<int>());
    }
    for (int i=N;i>0;i--){
        if (in[i]==0 && mark[i]==0){
            dfs(i);
        }
    }

    // print in topological order
    int tmp;
    while (!st.empty()){
        tmp=st.top();
        st.pop();
        cout << tmp << " ";
    }
    cout << endl;
}
void initiate(){
    reset(in);
    reset(mark);
    cin>>N>>M;
    int x, y;
    for (int i=1;i<=M;i++){
        cin>>x>>y;
        in[y]++;
        node[x].pb(y);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    initiate();
    topo();
}



