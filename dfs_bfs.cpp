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

void dfs(vector<vector<ull>> adj_list, ull start){
    vector<bool> visited(adj_list.size(), false); // visited array
    stack<ull> dfs_stack; // stack
    dfs_stack.push(start); // push starting node
    while(!dfs_stack.empty()){
        ull v = dfs_stack.top(); // get current node
        dfs_stack.pop(); // pop
        if (!visited[v]){
            cout << v << " ";
            visited[v] = true; // visit v
        }
        for (auto i = adj_list[v].end() - 1; i != adj_list[v].begin() - 1; --i) // push neighbors of v in stack in reverse order
            if (!visited[*i]){
                dfs_stack.push(*i);
            }

    }
}

void bfs(vector<vector<ull>> adj_list, ull start){
    vector<bool> visited(adj_list.size(), false); // visited array
    list<ull> queue; // queue
    visited[start] = true;
    queue.push_back(start); // push starting node
 
    while(!queue.empty()){
        ull v = queue.front(); //get current node
        cout << v << " ";
        queue.pop_front(); // pop
        for(auto i = adj_list[v].begin(); i != adj_list[v].end(); ++i){ 
            if(!visited[*i]){
                visited[*i] = true; // visit neighbors of v
                queue.push_back(*i); // push neighbors of v in queue
            }
        }
    }
}



int main(){
    vector<ull> v(0);
    vector<vector<ull>> adj_list1(9,v);
    adj_list1[0].push_back(1);
    adj_list1[0].push_back(3);
    adj_list1[1].push_back(0);
    adj_list1[1].push_back(2);
    adj_list1[2].push_back(1);
    adj_list1[2].push_back(6);
    adj_list1[3].push_back(0);
    adj_list1[3].push_back(4);
    adj_list1[3].push_back(5);
    adj_list1[4].push_back(3);
    adj_list1[5].push_back(3);
    adj_list1[5].push_back(6);
    adj_list1[5].push_back(7);
    adj_list1[6].push_back(2);
    adj_list1[6].push_back(5);
    adj_list1[6].push_back(7);
    adj_list1[6].push_back(8);
    adj_list1[7].push_back(5);
    adj_list1[7].push_back(6);
    adj_list1[8].push_back(6);
    dfs(adj_list1,0);
    cout << endl;
    bfs(adj_list1,0);
    //vector<vector<ull>> adj_list1;
}

