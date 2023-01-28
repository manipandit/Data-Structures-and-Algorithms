class Solution {
public:
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &vis,vector<int> &pathVis,
    vector<int> &check)
    {
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it,graph,vis,pathVis,check)==true)
                {
                    check[node]=0;
                    return true;
                }
            }
            
            //already visited and also pathVisited then it's a cycle
            else if(vis[it]==1 && pathVis[it]==1)
            {
                check[node]=0;
                return true;
            }
        }
        
        //when we dont find a cycle in this direction of node we will mark pathVis as 0 and
        //return false
        
        check[node]=1; //not associated with cycle so safenode
        pathVis[node]=0;
        return false;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;
        
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> check(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,graph,vis,pathVis,check);
            }
        }
        
        for(int i=0;i<V;i++)
        {
            if(check[i]==1)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
