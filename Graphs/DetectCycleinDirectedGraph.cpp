bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathVis)
{
    vis[node]=1;
    pathVis[node]=1;

    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it,adj,vis,pathVis)==true)
            {
                return true;
            }
        }

        //already visited and also pathVisited then it's a cycle
        else if(vis[it]==1 && pathVis[it]==1)
        {
            return true;
        }
    }

    //when we dont find a cycle in this direction of node we will mark pathVis as 0 and
    //return false

    pathVis[node]=0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    // code here

    vector<int> vis(V,0);
    vector<int> pathVis(V,0);

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,adj,vis,pathVis)==true)
                return true;
        }
    }
    return false;
}
