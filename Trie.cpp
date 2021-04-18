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

const int si=1e3;
int n,q;
int a[si+10];
string str;

// Note:
// + Each string has an integer key
// + If want to store string only, can assign all key to 1 (dont assign to 0 if dont want to consider substring)
// + Pay attention to key = 0!!! (means it is a substring of a string in the trie, but does not guarantee it is in trie itself)

// Trie:
// + Create a trie: O(W*L), W: num. words, L: averange length of word
struct node{
public:
    char ch;
    node* next[si+10];
    vi occ;
    int val;
};
struct trie{
    node* root;
    trie();
    void Printf();
    void Printf( node*, string);
    int query( string ); // query the key of a string
    void Scan();
    void scan( node* );
    void CheckAdd( string, int ); // add a string with a key to trie
    void rs( node* );
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    trie t;
    int a;
    upf(i,1,n){
        cin >> str >> a;
        t.CheckAdd( str, a);
        t.Printf();
    }
    string tmp;
    upf(i,1,q){
        cin >> tmp;
        printf("Val of '%s' is %d\n", tmp.c_str(), t.query(tmp));
    }
}
/*
Test 1:
8 9
the 1
a 3
there 6
answer 9
any 3
by 4
bye 7
their 100

the
test
bye
their
by
any
a
there
th


--------
Val of 'the' is 1
Val of 'test' is -1
Val of 'bye' is 7
Val of 'their' is 100
Val of 'by' is 4
Val of 'any' is 3
Val of 'a' is 3
Val of 'there' is 6
Val of 'th' is 0???


==========
Test 2:
8 9
the 1
a 1
there 1
answer 1
any 1
by 1
bye 1
their 1

the
test
bye
their
by
any
a
there
th


--------
Val of 'the' is 1
Val of 'test' is -1
Val of 'bye' is 1
Val of 'their' is 1
Val of 'by' is 1
Val of 'any' is 1
Val of 'a' is 1
Val of 'there' is 1
Val of 'th' is 0

*/


trie:: trie(){
    root=new node;
    root->ch = ' ';
    root->val = -1;
    
}

void trie:: Printf(){
    string tmp;
    Printf(root,tmp);
}

void trie:: Printf(node* cur, string tmp){
    if (cur!=root){
        tmp = tmp+cur->ch;
        cout<<tmp<<endl;
    }
    for (auto i:cur->occ)
        Printf( cur->next[i], tmp);
    tmp.pop_back();
}

void trie:: Scan(){
    scan(root);
}

void trie:: scan(node* cur){
    for (auto i:cur->occ){
        scan( cur->next[i]);
    }
}//scan all node to modify/find....

int trie:: query( string str ){
    node* cur = root;
    strf(i,str){
        int k = str[i] - '0';
        if ( cur->next[k]== NULL)
            return -1;// not exist
        cur=cur->next[k];
    }
    return cur->val;// found
}

void trie:: CheckAdd( string str, int key){
    node* cur=root;
    strf(i,str){
        int k = str[i] - '0';
        if (cur->next[k] == NULL){
            cur->occ.pb(k);
            cur->next[k] = new node;
            cur = cur->next[k];
            rs(cur);
            cur->ch = str[i];
        }
        else
            cur = cur->next[k];
    }
    if (cur->val==0){// not exist
        cur->val = key; // add
    }
}

void trie:: rs(node* cur){
    upf(i,0,si) cur->next[i] = NULL;
    cur->val = 0;
}



