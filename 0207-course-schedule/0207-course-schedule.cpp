class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<vector<int>>& adj,vector<int> &pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj,pathVis)==false) return false;
            }
            else if(pathVis[it]) return false;
        }
        pathVis[node]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
                if(dfs(i,vis,adj,pathVis)==false) return false;
            }
        }
        return true;
    }
};