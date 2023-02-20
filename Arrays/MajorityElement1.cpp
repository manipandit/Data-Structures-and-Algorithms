//Moore Voting Algorithm
int majorityElement(int a[], int size)
 {

      //Moore voting algo
      int count = 0;
      int element = 0;

     for(int i=0;i<size;i++)
     {
         if(count == 0)
         {
             element = a[i];
         }

         if(element == a[i])
         {
             count++;
         }
         else
         {
             count--;
         }
     }


      //to handle cases where there's no majority element in arr
      int newCount = 0;
      for(int i=0;i<size;i++)
      {
          if(element == a[i])
          {
              newCount++;
          }
      }

     return newCount > size/2 ? element : -1;

  }
