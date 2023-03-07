class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        //Extended Boyer-Moore Voting Algorithm
        //There can't be more than 2 majority elements at max 2 min 0
        int num1 = INT_MIN;
        int num2 = INT_MIN;
        int cnt1 = 0;
        int cnt2 = 0;
        
        for(auto ele:nums)
        {
            if(ele == num1)
            {
                cnt1++;
            }

            else if(ele == num2)
            {
                cnt2++;
            }

            else if(cnt1 == 0)
            {
                num1 = ele;
                cnt1 = 1;
            }

            else if(cnt2 == 0)
            {
                num2 = ele;
                cnt2 = 1;
            }

            else
            {
                cnt1--;
                cnt2--;
            }
        }


        //now num1 and num2 that we get from above approach has to be verified 
        cnt1 = 0 , cnt2 = 0;
        for(auto ele:nums)
        {
            if(ele == num1)
            {
                cnt1++;
            }
            else if(ele == num2)
            {
                cnt2++;
            }

        }

        if(cnt1 > (n/3))
        {
            ans.push_back(num1);
        }
        if(cnt2 > (n/3))
        {
            ans.push_back(num2);
        }

        return ans;

        

    }
};
