    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
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
	    
	    vector<int> ans;
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        
	        ans.push_back(node);
	        
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    
	    
	    
	    return ans;
	}
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int> adj[K];
        
        for(int i=0;i<=N-2;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.size(),s2.size());
            for(int itr=0; itr<len; itr++)
            {
                if(s1[itr] != s2[itr])
                {
                    adj[s1[itr]-'a'].push_back(s2[itr]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(K, adj);
        string ans = "";
        
        for(auto it:topo)
        {
            ans = ans + char(it + 'a');
        }
        
        return ans;
    }
