class Solution {
public:
    vector<vector<int>> ans;
    int n;

    //Approach-2
    // TC = O(N!xN)  SC=O(N)
    void solve(vector<int> &nums,int ind)
    {
        if(ind>=n)
        {
            ans.push_back(nums);
            return;
        }


        for(int i=ind;i<n;i++)
        {
            swap(nums[i],nums[ind]);
            solve(nums,ind+1);
            swap(nums[i],nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        n=nums.size();
        solve(nums,0);
        return ans;  
    }

    //Approach-1
    /*  TC = O(N!xN)  SC=O(N)+O(N)+O(N)
    void solve(vector<int> &nums,vector<int> &vis,vector<int> &ds)
    {
        if(ds.size()>=n)
        {
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                ds.push_back(nums[i]);
                solve(nums,vis,ds);
                
                //backtrack
                vis[i]=0;
                ds.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        n=nums.size();
        vector<int> vis(n,0);
        vector<int> ds;
        solve(nums,vis,ds);
        return ans;  
    }
    */

    
};
