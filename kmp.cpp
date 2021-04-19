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
#define InS insert
#define mP make_pair
#define mT make_tuple
#define EB emplace_back
#define X first
#define Y second
#define bug(x) cout << #x << "=" << x <<" ";
#define line() cout << endl;
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
  
// Fills lps[] for given patttern [0..len_p-1]
void computeLPSArray(string& pat, ull len_p, vector<ull>& lps){
    lps[0] = 0; // lps[0] is always 0

    ull index = 1; // the loop calculates lps[i] for i = 1 to M-1
    ull len = 0; // length of the previous longest prefix suffix

    while (index < len_p) {
        if (pat[index] == pat[len]) {
            len++;
            lps[index] = len;
            index++;
        }
        else{ // (pat[index] != pat[len])
            // This is tricky. Consider the example.
            // AAACAAAA and index = 7. The idea is similar
            // to search step.
            if(len != 0){
                len = lps[len - 1];
                // Also, note that we do not increment
                // i here
            }
            else{ // if(len == 0)
                lps[index] = 0;
                index++;
            }
        }
    }
}
  
// Prints occurrences of pattern in string
void KMPSearch(string& pat, string& str){
    ull len_p = pat.length(); // length of pattern
    ull len_s = str.length(); // length of string
  
    // lps[i] will hold the "longest prefix which is also suffix" value1 for pattern[0 to i]
    vector<ull> lps (len_p);
  
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, len_p, lps);

    ull index_p = 0; // index for pat
    ull index_s = 0; // index for str
    while(index_s < len_s){

        if(pat[index_p] == str[index_s]){ // if it is a match, increment both indices
            index_p++;
            index_s++;
        }
  
        if(index_p == len_p){ // if found a match, print, reset pattern index
            cout << "Found pattern at index " << index_s - index_p << endl;
            index_p = lps[index_p - 1];
        }
  
        else if(index_s < len_s && pat[index_p] != str[index_s]){ // if mistach after index_p matches
            // Do not match lps[0..lps[j-1]] characters, because they will match anyway
            if(index_p != 0)
                index_p = lps[index_p - 1]; // jump to index_p - 1 because all previous already match
            else
                index_s = index_s + 1; // increment string index
        }
    }
}
  
// Driver program to test above function
int main(){
    string oof ("ABABCABABABABCABABABABDABACDABABCABAB");
    string rab ("ABABCABAB");
    KMPSearch(rab, oof);
    return 0;
}