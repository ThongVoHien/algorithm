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
#define vtf(i,vt) for (int i=0;i<vt.size();i++)
#define strf(i,str) for (int i=0;i<str.length();i++)
#define downf(i,n,m) for (int i=n;i>=m;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define MP make_pair
#define MT make_tuple
#define eb emplace_back
#define X first
#define Y second
#define bug(x) cout << #x << "=" << x <<" ";
#define line() cout << endl;
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
#define PQ priority_queue
#define IT iterator
#define stop() int _stop;cin>>_stop;
#define PrintAll(x) for (auto i:x) cout << i << " ";line();
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef pair<int,double> pid;

const int SI=1e2+10; // maximum no. of points
const double inf=1e10+10;
int n;
double x[SI],y[SI];
vi hull;

int findSrc(){
    double tmpx,tmpy;
    int src;
    tmpx=x[1]; tmpy=y[1]; src=1;
    upf(i,2,n){
        if (tmpx>x[i]){
            tmpx=x[i]; tmpy=y[i]; src=i;
        }
        else if (tmpx == x[i] && y[i]<tmpy){
            tmpx = x[i]; tmpy = y[i]; src = i;
        }
    }
    return src;
}

double angle(int a, int b){
    return ( (x[a] != x[b]) ? (y[b]-y[a])/(x[b]-x[a]) : (inf) );
}

bool sortSecond( pid a, pid b){
    return ( (a.Y != b.Y)  ? (a.Y<b.Y):(a.X<b.X) );
}
bool test(int nx){
    ll p = hull[hull.size()-2], c = hull[hull.size()-1];
    double val = (y[c] - y[p]) * (x[nx] - x[c]) - (x[c] - x[p]) * (y[nx] - y[c]);
    return (val >= 0)? true: false; // > 0: clock, = 0: colinear or < 0: counterclock wise
}

void ConvexHull(){
    cin >> n;
    upf(i,1,n) cin >> x[i] >> y[i];
    vector< pid > vd;
    int src = findSrc();
    
    upf(i,1,n) if (i != src) vd.pb({i,angle(src,i)});
    sort(all(vd),sortSecond);
    vd.pb({src,0});
    hull.pb(src);hull.pb(vd[0].X);
    for (int i = 1;i<vd.size();i++){
        while ( test( vd[i].X ) ) hull.pop_back();
        hull.pb(vd[i].X);
    }
    hull.pop_back();
    for (auto i : hull) cout << x[i] << " " << y[i] << endl;
    hull.clear();
}
int main(){
    ios_base::sync_with_stdio(0);
    ConvexHull();
}
