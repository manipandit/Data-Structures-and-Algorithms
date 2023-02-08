
//Permutations-2 :Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    //Approach-1
    // TC= O(N!xN) SC=O(N)+O(N)
    void solve(vector<int> &arr,int ind)
    {
        if(ind>=n)
        {
            ans.push_back(arr);
            return;
        }
        
        unordered_set<int> st;
        for(int i=ind;i<n;i++)
        {
            if(st.find(arr[i])!=st.end())continue; // if same num is found at ith ind we will skip this iteration
            st.insert(arr[i]);
            
            swap(arr[i],arr[ind]);
            solve(arr,ind+1);
            swap(arr[i],arr[ind]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        n=nums.size();
        solve(nums,0);
        return ans;
    }
    
};
