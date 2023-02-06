int search(string pat, string txt) {
	    // code here
	    int ans=0;
	    
	    int sz = pat.size();
	    unordered_map<char,int> mp;
	    
	    for(auto ch:pat)
	    {
	        mp[ch]++;
	    }
	    
	    int count=mp.size(); //no of unique chars
	    
	    int n=txt.size();
	    int i=0,j=0;
	    while(j<n)
	    {
	        //calculations
	        char curr = txt[j];
	        if(mp.find(curr)!=mp.end())
	        {
	            mp[curr]--;
	            
	            if(mp[curr]==0)
	            {
	                count--;
	            }
	        }
	        
	        if(j-i+1<sz)
	        {
	            j++;
	        }
	        
	        //hits window size
	        else if(j-i+1==sz)
	        {
	            if(count==0)
	            {
	                ans++;
	            }
	            
	            
	            //if  txt[i] is present in map then increment its freq before sliding
	            if(mp.find(txt[i])!=mp.end())
	            {
	                mp[txt[i]]++;
	                if(mp[txt[i]]==1)
	                {
	                    count++;
	                }
	            }
	            
	            //slide window 
	            i++;
	            j++;
	        }
	    }
	    return ans;
	    
	    
	}
