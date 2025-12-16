tc-
sc-
queue is used 


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n);
	
	
	for(int i=0;i<n;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	    
	}
	
	vector<int> vis(n,0);
	queue<int> q;
	vector<int> bfs;
	
	vis[0]=1; //mark first node as visited
	q.push(0); //q mai first node push kardo
	
	while(!q.empty()){
	    int node=q.front();
	    q.pop();
	    
	    bfs.push_back(node);
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            vis[it]=1;
	            q.push(it);
	        }
	    }
	}
	
	for(int x:bfs){
	    cout<<x<<" ";
	}
	
	

}
