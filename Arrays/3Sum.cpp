class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++)
        {
            int a = nums[i];

            int start = i+1, end=n-1;
            int target = -a;  // a+b+c=0 , b+c = -a

            //two sum
            while(start < end)
            {
                if(nums[start] + nums[end] == target)
                {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    
                    while(start< end && nums[start] == nums[start+1])
                    {
                        start++;
                    }

                    while(start< end && nums[end] == nums[end-1])
                    {
                        end--;
                    }

                    start++;
                    end--;
                }

                else if(nums[start] + nums[end] < target)
                {
                    start++;
                }

                else 
                {
                    end--;
                }
            }

            while(i+1<n && nums[i] == nums[i+1])
            {
                i++;
            }
        }

        return ans;
    }
};
