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
#define noline(x) upf(i,1,x) cout << endl;
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

const int si = 1e5+10;
//const ull INF = 1e16;


void build_sparse_table(vector<vector<ll> >& array, 
        vector<vector<ll> >& sparseTable){

    upf(i, 0, 20){
        sparseTable.PB(new vector<ll>());
    }

    upf(i,0,n-1) {
        sparseTable[0].PB(a[i]);
    }

    upf(i,1, ll(log2(n) )) {
        upf(j,0,n-1){
            sparseTable[i].PB(sparseTable[i-1][j] + 
                sparseTable[i-1][ j+ (1<<(i-1)) ]);
        }
    }
}

ll range_sum_query(vector<ll>& sparseTable, ll x, ll y){
    ll sum = 0;
    ll len = y - x + 1;
    while (len){
        // C1: take each 1-bit from left to right
//        for ( tmp = 0; (1<<tmp) <= len; tmp++);
//        tmp--;
//        bug(tmp);
//        sum += sparseTable[tmp][x];
//        x+= (1<<tmp);
//        len-= (1<<tmp);
        

        // C2: take each 1-bit from right to left
        int mostRight1Bit;
        mostRight1Bit = len & ( (~len)+1); // extract most-right 1-bit
        
        sum += sparseTable[ (int)log2(mostRight1Bit) ][x];
        x += mostRight1Bit;

        len = len^mostRight1Bit; // turn off that bit

    }
    return sum;
}

int main(){
    ll n, q;
    vector<ll> array, sparseTable;
    tc(){
        reset(sparseTable);
        scanf("%lld",&n);
        upf(i,0,n-1){
            scanf("%lld", &tmp);
            array.PB(tmp);
        }

        build_sparse_table(array, sparseTable);
        scanf("%lld", &q);
        ll x, y;
        upf(i,1,q){
            scanf("%lld %lld", &x, &y);
            x--; y--;
            printf("%lld\n", range_sum_query(sparseTable, x, y) );
        }
    }
    
}




