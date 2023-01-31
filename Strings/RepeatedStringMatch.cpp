int repeatedStringMatch(string a, string b) {
        string temp = a;
        int count = 1;
        while(a.size() < b.size())
        {
            a += temp;
            count++;
        }

        if( a.find(b) != -1)
        {
            return count;
        }
        a += temp;
        count++;

        if( a.find(b) != -1)
        {
            return count;
        }

        return -1;
    }
