void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int ind1,ind2;
        
        for(ind1=n-2; ind1>=0; ind1--)
        {
            if(arr[ind1] < arr[ind1+1])
            {
                break;
            }
        }
        
        if(ind1 < 0)
        {
            reverse(arr.begin(),arr.end());
        }
        else
        {
            for(ind2=n-1; ind2>ind1; ind2--)
            {
                if(arr[ind2]>arr[ind1])
                {
                    break;
                }
            }
            
            swap(arr[ind1],arr[ind2]);
            
            reverse(arr.begin()+ind1+1 , arr.end());
        }
        
        
        
    }
