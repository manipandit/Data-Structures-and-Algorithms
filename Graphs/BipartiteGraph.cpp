// Using DFS
bool dfs(int node,int col,vector<int> adj[],vector<int> &color)
{
	color[node]=col;

	for(auto it:adj[node])
	{
	    if(color[it]==-1)
	    {
		if(dfs(it,!col,adj,color)==false)
		{
		    return false;
		}
	    }
	    else if(color[it]==color[node])
	    {
		return false;
	    }
	}

	return true;

}
bool isBipartite(int V, vector<int>adj[]){
    // Code here

    vector<int> color(V,-1);
    for(int i=0;i<V;i++)
    {
	if(color[i]==-1)
	{
	    if(dfs(i,0,adj,color)==false)
		return false;
	}
    }

    return true;
}




// Using BFS
bool check(int startNode,int V,vector<int> adj[],vector<int> &color)
{
    queue<int> q;

    q.push(startNode);
    color[startNode]=0;

    while(!q.empty())
    {
	int node=q.front();
	q.pop();

	for(auto adjNode: adj[node])
	{
	    if(color[adjNode]==-1)
	    {
		color[adjNode]= !(color[node]);
		q.push(adjNode);
	    }
	    //adj nodes having same color
	    else if(color[adjNode]==color[node])
	    {
		return false;
	    }
	}
    }

    return true;
}
bool isBipartite(int V, vector<int>adj[]){
    // Code here

    vector<int> color(V,-1);
    for(int i=0;i<V;i++)
    {
	if(color[i]==-1)
	{
	    if(check(i,V,adj,color)==false)
		return false;
	}
    }

    return true;
}
