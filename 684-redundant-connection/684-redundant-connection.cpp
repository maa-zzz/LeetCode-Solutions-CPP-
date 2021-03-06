class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<bool>&vis, int cur, int par = -1){
        if(vis[cur]){
            return true;
        }
        vis[cur] = true;
        for(auto child: graph[cur]){
            if(child != par and dfs(graph, vis, child, cur)){
                return true;
            }
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        vector<bool> vis(n+1);
        for(auto it:edges){
            fill(begin(vis), end(vis), false); //reset visited array
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            if(dfs(graph,vis,it[0])){
                return it;
            }
        }
        return { }; //if unreachable
    }
};