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

const int si=1e3;
int n, a[si];

struct node{
    int val, L, R;
    node* left,* right;
};
// val: sum of the range [L,R] in the original sequence
// left, right: point to the children node

// initiate part of a tree (from st to en)
node* Range( int *a , int st , int en ){
    node* cur;
    cur = new node;
    if (st == en){
        cur->val = a[st];
        cur->left = cur->right = NULL;
    }
    else{
        int tmp = (st+en)/2;
        cur->left = Range(a, st, tmp);
        cur->right = Range(a, tmp+1, en);
        cur->val = cur->left->val + cur->right->val;
    }
    cur->L = st; cur->R = en;
    return cur;
}

// initiate the tree
node* SegmentTree( int* a , int n){
    return Range(a,1,n);
}

// print the tree with bfs
void printfTree( node *cur ){
    if (cur->left!=NULL) printfTree(cur->left);
    cout << cur->val << endl;
    if (cur->right!=NULL) printfTree(cur->right);
}

// return sum of a range (from st to en) of the sequence
int SumRange( node* cur , int st , int en ){
    if (st<=cur->L && cur->R<=en) return cur->val;
    int S=0;
    if (cur->left->L<=st && st<=cur->left->R)
        S+=SumRange(cur->left, st, min(cur->left->R, en) );
    if (cur->right->R>=en && en>=cur->right->L)
        S+=SumRange(cur->right, max(st, cur->right->L), en);
    return S;
}

// change value of a "position" into "key"
int Update( node* cur , int pos , int key ){
    if (cur->L == pos && cur->R == pos){
        int old = cur->val;
        cur->val = key;
        return old;
    }
    int old=0;
    if (pos>cur->left->R) old = Update( cur->right , pos , key );
    else old = Update( cur->left , pos , key );
    cur->val = cur->val+key-old;
    return old;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    upf(i,1,n) cin >> a[i];
    node* Seg = SegmentTree(a,n);
    int x,y;
    tc(){
        cin >> x >> y;
        Update(Seg,x,y);
        printfTree(Seg); // for testing purpose
    }
}


