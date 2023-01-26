class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //creating adjacency list
        unordered_map<int,vector<pair<int,int>>> adj; // u->{v,cost};

        vector<int> dist(n,INT_MAX);

        for(vector<int> &vec : flights) 
        {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];
            
            adj[u].push_back({v, cost});
        }

        queue<pair<int,int>> q; //u->cost
        q.push({src,0}); // cost of visiting src from src = 0

        dist[src]=0;

        int steps=0; 
        while(!q.empty() && steps<=k)
        {
            int size = q.size();

            while(size--)
            {
                int u = q.front().first;
                int d = q.front().second;
                
                q.pop();

                for(pair<int,int> &p:adj[u])
                {
                    int v = p.first;
                    int cost = p.second;

                    if(d+cost < dist[v])
                    {
                        dist[v]=d+cost;

                        q.push({v,d+cost});
                    }
                }
            }

            steps++;
        }

        if(dist[dst]==INT_MAX){
            return -1;
        }
        else return dist[dst];
    }
};
