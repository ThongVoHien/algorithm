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
typedef pair<pii,ll>pp;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

using namespace std;

const int SIZE=100001;

int N,M,k,x,y,id[SIZE],val;
pp p[SIZE];
vi node[SIZE];

bool SortS(pp x, pp y){
    return x.second<y.second;
}
int root(int i){
    while (id[i]!=i){
        i=id[i];
    }
    return i;
}
bool isCircle(int seg){
    return (root(p[seg].first.first)==root(p[seg].first.second));
}
void connect(int seg){
    int tmp=id[root(p[seg].first.first)];
    id[root(p[seg].first.second)]=tmp;
}
void kruskal(){
    int S=0;
    sort(p,p+M,SortS);
    for (int i=0;i<M;i++){
        // check isCircle
        if (!isCircle(i)){
            // add and union
            connect(i);
//            cout<<p[i].first.first<<" "<<p[i].first.second<<endl;
            S+=p[i].second;
        }
    }
    cout << S << endl;
}
int main()
{
    cin>>N>>M;
    reset(id);
    for (int i=0;i<M;i++){
        id[i] = i;
        cin >> x >> y >> val;
        p[i].first=make_pair(x,y);
        p[i].second=val;
    }
    kruskal();
}



