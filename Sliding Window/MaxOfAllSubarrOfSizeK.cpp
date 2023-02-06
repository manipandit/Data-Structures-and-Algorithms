#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here

    vector<int> ans;
    list<int> l;

    int i = 0, j = 0;

    while (j < n)
    {

        while (!l.empty() && arr[j] > l.back())
        {
            l.pop_back();
        }

        l.push_back(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());

            if (arr[i] == l.front())
            {
                l.pop_front();
            }

            i++;
            j++;
        }
    }
    return ans;

}

//Brute Approach
/*
vector<int> max_of_subarrays(int *arr,int n,int k)
{
    vector <int> ans;

    for(int i=0;i<n-k+1;i++)
    {
        int maxi = arr[i];
        for(int j=i;j<i+k;j++)
        {
            maxi = max(maxi,arr[j]);
        }
        ans.push_back(maxi);
    }

    return ans;
}
*/
