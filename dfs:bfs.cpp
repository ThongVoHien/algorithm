#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

void dfs(vector<vector<int>> adj_list, int start){
    vector<bool> visited(adj_list.size(), false);
    stack<int> dfs_stack;
    dfs_stack.push(start);
    while(!dfs_stack.empty()){
        int v = dfs_stack.top();
        dfs_stack.pop();
        if (!visited[v]){
            cout << v << " ";
            visited[v] = true;
        }
        for (auto i = adj_list[v].begin(); i != adj_list[v].end(); ++i)
            if (!visited[*i]){
                dfs_stack.push(*i);
            }

    }
}

void bfs(vector<vector<int>> adj_list, int start){
    vector<bool> visited(adj_list.size(), false);
    list<int> queue;
    visited[start] = true;
    queue.push_back(start);
 
    while(!queue.empty()){
        int v = queue.front();
        cout << v << " ";
        queue.pop_front();
        for(auto i = adj_list[v].begin(); i != adj_list[v].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}



int main(){
    vector<int> v(0);
    vector<vector<int>> adj_list1(4,v);
    adj_list1[0].push_back(1);
    adj_list1[0].push_back(2);
    adj_list1[1].push_back(0);
    adj_list1[2].push_back(3);
    adj_list1[2].push_back(0);
    adj_list1[3].push_back(2);
    dfs(adj_list1,0);
    cout << endl;
    bfs(adj_list1,0);
    //vector<vector<int>> adj_list1;
}

