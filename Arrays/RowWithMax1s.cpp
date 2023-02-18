int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int rowNumber = -1;
	    
	    
	    int leftMostOne = -1;
	    
	    int j=m-1;
	    //check 0th row and find leftMost one
	    while(j>=0 && arr[0][j] == 1) 
	    {
	        
            rowNumber = 0;
            leftMostOne = j;
	        
	        j--;
	    }
	    
	    
	    //check for other rows
	    for(int i=1; i<n; i++)
	    {
	        while(j>=0 && arr[i][j]==1)
	        {
	            rowNumber = i;
	            leftMostOne = j;   
	            
	            j--;
	        }
	    }
        
        return rowNumber;	    
	}
