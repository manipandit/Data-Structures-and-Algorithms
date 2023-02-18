class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return;

        
        
        int i=0;
        
        for(int j=0;j<n;j++)
        {
            if(nums[j]!=0)  //non-zero numbers has to be at the beginning
            {
                swap(nums[j],nums[i]);
                i++;
            }
        }
    }
};
