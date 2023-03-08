int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans;

        sort(nums.begin(),nums.end());
        int diff = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int first = nums[i];

            //2 sum - 2 pointer technique
            int start = i+1 , end = n - 1;
            
            while(start < end)
            {
                int sum = first + nums[start] +  nums[end];
                if( sum == target)
                {
                    return sum;
                }

                if(abs(sum - target) < diff)
                {
                    diff = abs(sum - target);
                    ans = sum;
                }

                if(sum > target)
                {
                    end--;
                }
                else start++;
                
            }
           
        }
         return ans;
    }
