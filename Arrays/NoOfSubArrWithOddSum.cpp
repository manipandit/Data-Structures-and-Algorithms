class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        int count = 0;

        //Optimal Approach TC = O(N) SC = O(1) Intuition - odd + odd = even , odd + even = odd
        int even = 0, odd = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] & 1) //odd
            {
                swap(even, odd);
                odd++;
            }
            else
            {
                even++;
            }

            count += odd;
            count %= mod;
        }
        return count;

        // Brute Approach -Generate all sub arrays and find odd sum in those and count - TC = O(N^2)
        // for(int i=0; i<n; i++)
        // {
        //     int sum = 0;
        //     for(int j=i; j<n; j++)
        //     {
        //         sum += arr[j];
        //         if( sum % 2 == 1)
        //         {
        //             count++;
        //         }
        //     }
        // }
        // return count % mod;
    }
};
