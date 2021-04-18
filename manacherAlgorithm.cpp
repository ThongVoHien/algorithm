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
#define stop() int _stop;cin>>_stop;
#define PrintAll(x) for (auto i:x) cout<<i<<" ";line();
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int si=1e5+10;


// append special character (@) 
// between any two characters in original string
string Adjust(string& str){ 
    string tmp="@";
    strf(i,str){
        tmp = tmp + str[i] + "@";
    }
    // cout << tmp << endl;
    return tmp;
}

// expand from center to the maximum radi
// until the substring is no longer a palindrome
// Finish: str[center-radi:center+radi]: longest 
//           palindrome centered at "center"
// TODO: check if exceed the original string index
int expand(int center, int radi, string& str){
    while (center > radi && str[center-radi-1] == str[center+radi+1]){
        radi++;
    }
    return radi;
}

/*
    Manager Algorithm:
    + Find longest sub-palindromes
    + O(N)
*/

void FindLongestPalindromeManacherAlgorithm(string& str){
    // int n, r=0, mirr=0, R=0;// r: radius, R:right
    // int a[si], p[2*si+1];
    // vi vt;
    vi p(2*str.size()+1, 0);
    // p[i] = j => [i-j,;
    int mirr = 0, R = 0, r = 0;// r: radius, R:right

    int maxLength = 0;// length of longest Palindrome 
    int startingIndex = 0; // starting index of longest Palindrome

    string adjustedStr = Adjust(str);
    // reset(p);

    for (int i = 1; i < adjustedStr.length()-1;i++){
        if ( (i >= R) || (i + p[ max( 2*mirr-i, 0) ] >= R) ){
            p[i] = expand( i, p[ max( 2*mirr-i, 0) ], adjustedStr);
            if (R < p[i]+i){
                mirr = i;
                r = p[i];
                R = p[i]+i;
                if (maxLength < p[i]){ 
                    maxLength = p[i]; 
                    startingIndex = i/2 - p[i]/2; 
                }
            }
            
        }
        else p[i] = min( p[ max( 2*mirr-i, 0) ], R-i);
    }
    cout << str.substr(startingIndex, maxLength) << "\t\tlength: " << maxLength << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    string str;
    tc(){
        cin >> str;
        FindLongestPalindromeManacherAlgorithm(str);
    }
    
}

// Input                    Output
// forgeeksskeegfor         geeksskeeg
// abaaba                   abaaba
// abababa                  abababa
// abcbabcbabcba            abcbabcbabcba
// abcdefabcdcbamnsnm       abcdcba


/*
Input
7
forgeeksskeegfor         
abaaba                   
abababa                  
abcbabcbabcba            
abcdefabcdcbamnsnm      
abcdeedcbamnpnm
mnpnmabcdeedcba


--------
Output:
geeksskeeg      length: 10
abaaba      length: 6
abababa     length: 7
abcbabcbabcba       length: 13
abcdcba     length: 7
abcdeedcba      length: 10
abcdeedcba      length: 10
*/




