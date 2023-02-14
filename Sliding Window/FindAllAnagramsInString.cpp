bool allZeros(vector<int> &v)
    {
        for(auto &ele:v)
        {
            if(ele!=0)
            {
                return false;
            }
        }

        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        
        vector<int> freq(26,0);

        for(auto &ch:p)
        {
            freq[ch-'a']++;
        }

        int i=0,j=0;
        int n=s.size(), k=p.size();
        while(j<n)
        {
            freq[s[j] - 'a']--;

            if(j-i+1 == k)
            {
                if(allZeros(freq))
                {
                    ans.push_back(i);
                }

                freq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
