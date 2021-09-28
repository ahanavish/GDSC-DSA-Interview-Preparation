// https://practice.geeksforgeeks.org/problems/circular-tour/1#

class Solution
{
  public:
    int tour(petrolPump arr[], int n)
    {
        int start, curr_petrol = 0;
 
        for (int i = 0; i < n; i++)
            if (arr[i].petrol >= arr[i].distance) 
            {
                start = i;
                break;
            }
 
        for (int i = start; i < n;) 
        {
            curr_petrol = curr_petrol + arr[i].petrol - arr[i].distance;
            if (curr_petrol < 0) 
            {
                i++;
                for (; i < n; i++)
                    if (arr[i].petrol >= arr[i].distance) 
                    {
                        start = i;
                        curr_petrol = 0;
                        break;
                    }
            }
            else
                i++;
        }
 
        if (curr_petrol < 0)    //at the end, for checking if circular iteration is possinle from here
            return -1;
     
        for (int j = 0; j < start; j++) 
        {
            curr_petrol = curr_petrol + arr[j].petrol - arr[j].distance;
            if (curr_petrol < 0)
                return -1;
        }
    }
};