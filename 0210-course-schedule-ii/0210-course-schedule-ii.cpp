class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<vector<int>>& adj,vector<int> &pathVis,vector<int> &order){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj,pathVis,order)==false) return false;
            }
            else if(pathVis[it]) return false;
        }
        pathVis[node]=0;
        order.insert(order.begin(),node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<int> rand;
        int m=prerequisites.size();
        vector<int> vis(numCourses);
        vector<int> pathVis(numCourses);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<m;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,adj,pathVis,order)==false) return rand;
            }
        }
        return order;
    }

};