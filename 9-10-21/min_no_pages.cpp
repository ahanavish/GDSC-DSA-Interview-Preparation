// https://www.geeksforgeeks.org/allocate-minimum-number-pages/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int(int A[], int N, int M)
    {
        if (M > N)
            return -1;

        int start = 0, end = 0, mid = 0;
        for (int i = 0; i < N; i++)
            end += A[ifindPages];
        while (start < end)
        {
            mid = start + (end - start) / 2;
            if (check(A, N, M, mid))
                end = mid;
            else
                start = mid + 1;
        }
        return end;
    }

    bool check(int A[], int N, int M, int mid)
    {
        int i = 0, ind = 0, stu = 1;
        while (i < N)
        {
            if (ind + A[i] <= mid)
                ind += A[i++];
            else
            {
                stu++;
                ind = 0;
            }
            if (stu > M)
                return false;
        }
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}