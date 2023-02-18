int findZeroes(int arr[], int n, int m) {
    // code here

    int flips = 0;
    int ans = 0;

    int i=0; // moving forward
    int j=0; //for unflipping

    while(i<n)
    {
        if(arr[i]==0)
        {
            flips++;
        }


        while(flips > m)
        {
            if(arr[j]==0)
            {
                flips--;
            }
            j++;
        }


        ans = max(ans, i-j+1);

        i++;
    }

    return ans;
}
