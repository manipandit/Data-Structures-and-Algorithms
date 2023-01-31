void topoSort(int node,vector<pair<int,int>> adj[], vector<int> &vis,stack<int> &st)
     {
         vis[node]=1;
         
         for(auto it:adj[node])
         {
             int v = it.first;
             if(!vis[v])
             {
                 topoSort(v,adj,vis,st);
             }
         }
         
         st.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        vector<pair<int,int>> adj[N];
        
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        
        //step1 : find toposort
        stack<int> st;
        vector<int> vis(N,0);
        
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                topoSort(i,adj,vis,st);
            }
        }
        
        //step2: find dist
        vector<int> dist(N,1e9);
        
        //dist of src node to src
        dist[0]=0;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto it:adj[node])
            {
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v])
                {
                    dist[v]  = dist[node] + wt;
                }
            }
            
        }
        
        for(auto &d:dist)
        {
            if(d==1e9)
            {
                d=-1;
            }
        }
        
        return dist;
    }
