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
#define INS insert
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
#define X first
#define Y second
#define bug(x) cout << #x << "=" << x <<" ";
#define line() cout << endl;
#define Sbug(x) cout << #x << "=" << x <<"\n";
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
#define sd(n) scanf("%d",&n)
#define slf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define prd(n) printf("%d",n)
#define prs(n) printf("%s",n)
#define PQ priority_queue
#define IT iterator
#define stop() int _stop;cin>>_stop;
#define PrintAll(x) for (auto i:x) cout<<i<<" ";line();
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define LSBIT(i) ((i) & -(i)) // Return the least-significant set bit in i

#include <limits.h>
const int min_int = INT_MIN;
const int max_int = INT_MAX;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int si=1000;

// Add delta to element with index i (zero-based)
void update(vector<int>&fenwichTree, int x, int delta){
    for(; x <= n; x += LSBIT(x+1))
        fenwichTree[x] += delta;
}

// Returns the sum of the first i elements (indices 0 to i-1)
int sum(vector<int>&fenwichTree, int x){
    int sum = 0;
    for(; x > 0; x -= LSBIT(x))
        sum += fenwichTree[x];
    return sum;
}

// Returns the sum of elements from i to j-1
// Equivalent to prefix_sum(j) - prefix_sum(i), but faster
int range_sum(vector<int>& fenwichTree, 
    unsigned int i, unsigned int j)
{
    int sum = 0;
    assert(0 <= i && i <= j);
    for (; j > i; j -= LSBIT(j))
        sum += fenwichTree[j-1];
    for (; i > j; i -= LSBIT(i))
        sum -= fenwichTree[i-1];
    return sum;
}

// Build Fenwich Tree from original array
void build_fenwich_tree(vector<int>& originalArray, 
    vector<int>&fenwichTree){

    upf(i, 0, originalArray.size()-1){
        update(fenwichTree, i, originalArray[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int k, tmp;
    vector<int> array, fenwichTree;
    cin >> n >> k;
    upf(i, 0, n-1){
        cin >> tmp;
        array.PB(tmp);
        update(a,i);
    }

    build_fenwich_tree(array, fenwichTree);

    cout << sum(k) << endl;
    return 0;
}
