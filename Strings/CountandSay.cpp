class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }

        //create
        string say = countAndSay(n-1);

        //process
        string res="";
        for(int i=0;i<say.size();i++)
        {   
            int count=1;
            char ch=say[i];

            while(i<say.size()-1 && say[i]==say[i+1])
            {
                count++;
                i++;
            }
            res += to_string(count) +ch;
        }

        return res;
    }
};
