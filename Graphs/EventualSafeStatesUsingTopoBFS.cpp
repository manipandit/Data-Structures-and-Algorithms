vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        
        vector<int> revAdj[V];
        vector<int> indegree(V,0);
        
        for(int i=0;i<V;i++)
        {
            // i ->it  --> reverse it->i
            for(auto it:adj[i])
            {
                revAdj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int> safeNodes;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            safeNodes.push_back(node);
            
            for(auto it:revAdj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
