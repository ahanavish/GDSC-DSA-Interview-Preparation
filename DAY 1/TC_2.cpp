//https://www.interviewbit.com/problems/nestedcmpl3/

/*
Since i gets updated as i=i/2 with every iteration and condition for inner loop is j<i 
so the no of iterations with every updation of i reduces by a factor of 2. 
Hence, at the first time: N iterations
              second time: N/2 iterations and so on 
Adding all the no of iterations, we get O(N+N/2+N/4….)
                                    thus O(N)
*/