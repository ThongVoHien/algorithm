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

const int no_node=1000;
const int inf=1e8+10;
int n,N,M,k,x,y,res;
vi point[no_node],Euler;//is level necessary
int mark[no_node],a[no_node],fir[no_node];
struct node{
    int val,L,R,height;
    node* left,* right;
};
node* Seg;
void EulerPath(int s)
{
    Euler.pb(s);
//    level.pb(mark[s]);
    for (auto pos:point[s]){
        if (mark[pos]==0){
            mark[pos]=mark[s]+1;fir[pos]=sizeof(Euler);
            //
            EulerPath(pos);
            Euler.pb(s);
//            level.pb(mark[s]);
        }
    }
}
void dfs(int start)
{
    reset(mark);reset(fir);
    res=0;
    mark[start]=1;fir[start]=sizeof(Euler);
    EulerPath(start);
}
void dfs_initiate()
{
    cin>>N>>M;
    for (int i=1;i<=M;i++)
    {
        cin>>x>>y;
        point[x].pb(y);
        point[y].pb(x);
    }
}

node* Range( int st , int en ){
    node* cur;
    cur=new node;
    if (st==en){
        cur->val=Euler[st];
        cur->left=NULL;
        cur->right=NULL;
    }
    else{
        int tmp=(st+en)/2;
        cur->left=Range(st,tmp);
        cur->right=Range(tmp+1,en);
        if (mark[Euler[cur->left->val]]<mark[Euler[cur->right->val]])
            cur->val=cur->left->val;
        else cur->val=cur->right->val;
    }
    cur->L=st;cur->R=en;
    return cur;
}
node* SegmentTree( int n){
    return Range(0,n-1);
}
int MinRange( node* cur , int st , int en ){
    if (st<=cur->L && cur->R<=en){
        return cur->val;
    }
    int S=inf;
    if (cur->left->L<=st && st<=cur->left->R){
        S=MinRange(cur->left,st,min(cur->left->R,en));
    }
    if (cur->right->R>=en && en>=cur->right->L){
        if (S!=inf){
            if (mark[S]>mark[MinRange(cur->right,max(st,cur->right->L),en)])
                S=MinRange(cur->right,max(st,cur->right->L),en);
        }
        else{
            S=MinRange(cur->right,max(st,cur->right->L),en);
        }
    }
//    if (cur->left->L<=st && st<=cur->left->R){
//        tmp=MinRange(cur->left,st,min(cur->left->R,en));
//        if (S>tmp.se){
//            S=tmp.se;
//            
//        }
//        
//    }
//    if (cur->right->R>=en && en>=cur->right->L) S=min(S,MinRange(cur->right,max(st,cur->right->L),en));
    return S;
}

int LCA(int x,int y){
    if (fir[x]>fir[y]) swap(x,y);
    return MinRange( Seg , fir[x] , fir[y] );
}
void printfTree( node *cur ){
    if (cur->left!=NULL) printfTree(cur->left);
    cout<<cur->val<<endl;
    if (cur->right!=NULL) printfTree(cur->right);
}
int main()
{
    ios_base::sync_with_stdio(0);
    dfs_initiate();
    dfs(1);
    for (auto i:Euler){
        cout<<i<<" ";
    }
    line();
    int stop;
    cin>>stop;
    Seg=SegmentTree(sizeof(Euler));
    printfTree(Seg);
    tc(){
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
}


