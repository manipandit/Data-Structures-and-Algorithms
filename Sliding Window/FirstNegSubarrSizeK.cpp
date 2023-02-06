#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],long long int n, long long int k) 
{
                                                 
        vector<long long> ans;
        list<long long> l;
        
        
        int i=0,j=0;
        while(j<n)
        {
            if(arr[j]<0)
            {
                l.push_back(arr[j]);
            }
            
            if(j-i+1<k)
            {
                j++;
            }
            
            else if(j-i+1==k)
            {
                if(l.size()==0)
                {
                    ans.push_back(0);
                }
                else 
                {
                    ans.push_back(l.front());
                    if(arr[i]<0)
                    {
                        l.pop_front();
                    }
                }
                
                i++;
                j++;
            }
        }
        return ans;        
 }

//Brute Approach
/*
vector<long long> printFirstNegativeInteger(long long int arr[],long long int n, long long int k) 
{
    vector<long long> ans;
    bool neg=false;
    

    for(int i=0;i<n-k+1;i++)
    {
        neg=false;
        for(int j=i;j<i+k;j++)
        {
            if(arr[j]<0)
            {
                neg=true;
                ans.push_back(arr[j]);
                break;
            }
        }
        if(neg==false)
        {
            ans.push_back(0);
        }
    }
    
    
    return ans;
}
*/
