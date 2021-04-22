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
#define bug(x) cout << #x << " = " << x << endl;
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

using namespace std;
// const int si=5004;
// const int MOD=1e9;
const int INF = 1e9;

//string str;
//
//int LIS(){
//    int DP[si];
//    reset(DP);
//    DP[0]=-1e8;
//    int maxLength=0;
//    upf(i,1,n){
//        upf(j,0,maxLength-1){
//            if (DP[j]<a[i] && DP[j+1]>a[i])
//            {
//                DP[j+1]=a[i];
//                break;
//            }
//        }
//        if (DP[maxLength]<a[i]){
//            maxLength++;
//            DP[maxLength]=a[i];
//        }
//    }
//    return maxLength;
//}

// O(nlogn)
int LIS_opt(vector<int>& array){
    vector<int> DP(array.size()+10, 0);
    DP[0] = -INF;
    int maxLength = 0;
    long int tmp;
    
    upf(i, 0, array.size()-1){
        tmp = lower_bound(DP.begin(), DP.begin() + maxLength+1, array[i]) - DP.begin() - 1;
        if (tmp == maxLength){
            maxLength++;
            DP[maxLength] = array[i];
        }
        else{
            DP[tmp+1] = array[i];
        }
    }

    // print LIS
    upf(i, 1, maxLength){
        cout << DP[i] << " ";
    }
    cout << endl;

    return maxLength;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, tmp;
    tc(){
        vector<int> array;

        cin >> n;
        upf(i,1,n){
            cin >> tmp;
            array.push_back(tmp);
        }
        cout << "Largest length is " << LIS_opt(array) << endl;
    }
}

/*
2
9
2 5 3 7 11 8 10 13 6
------
2 3 5 8 10 13


*/

