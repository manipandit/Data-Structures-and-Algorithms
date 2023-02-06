#include <bits/stdc++.h>
using namespace std;


long maximumSumSubarray(int k, vector<int> &arr, int n)
{
    // code here
    long maxi = INT_MIN;

    int i = 0, j = 0;
    long sum = 0;
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            maxi = max(maxi, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return maxi;
}


//Brute Approach
/*
long maximumSumSubarray(int k, vector<int> &arr, int n)
{
    int maxi=INT_MIN;
    for(int i=0;i<n-k+1;i++)
    {
        int sum=0;
        for(int j=i;j<i+k;j++)
        {
            sum += arr[j];
        }
        maxi = max(maxi,sum);
    }
    return maxi;
}
*/
