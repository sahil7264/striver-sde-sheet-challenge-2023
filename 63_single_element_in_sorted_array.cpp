int search(int* arr, int n, int key) {
    // Write your code here.
       // Write your code here.
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;
    int ref2 = arr[n - 1];
    while (low <= high)
    {
      if (arr[mid] == key) {
        return mid;
      }

        // for lef
        if (arr[mid] >= arr[0])
        {
            if (key >= arr[0] && arr[mid] >= key)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // for right
        else if (arr[mid] <= arr[n - 1])
        {
            if (key >= arr[mid] && arr[n - 1] >= key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        mid = (low + high) / 2;
       }
       return -1;
   }