#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <time.h>

using namespace std;

struct Results {
  int * A;
  int N; // Length of the array
};



struct Results solution(int A[], int N, int K) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    for(int loop = 0 ;loop <K; loop++)
    {
        int lastValue = A[N-1];
        for(int val = N-1; val > 0; val-- )
        {
            A[val] = A[val-1];
        }
        A[0] = lastValue;
    }

    result.A = A;
    result.N = N;
    return result;
}

vector<int> solution(vector<int> &A, int K)
{
    struct Results result;

    if(A.size())
    {

        for(int loop = 0; loop < K; loop++)
        {
            int lastValue = A.back();

            //printf("lastvalue = %d \n ", lastValue);
            for(vector<int>::size_type i = A.size()-1 ; i > 0 ; i--)
            {
          //      printf("i = %d, A[i]= %d, A[i-1]= %d \n ", i, A[i], A[i-1]);

                A[i] = A[i-1];

            }
             A.front() = lastValue;
        //printf("a0= %d,  a1= %d, a2 = %d, a3= %d, a4 = %d\n", A.at(0), A.at(1),A.at(2), A.at(3), A.at(4));
        }
    }
    return A;
}


int main()
{
    cout << "Hello world!" << endl;
    int A[] = {3, 8, 9, 7, 6};
    int K = 3;

    printf("a0= %d,  a1= %d, a2 = %d, a3= %d, a4 = %d\n", A[0], A[1],A[2], A[3], A[4]);

    vector<int> denemeVector (A, A + sizeof(A) / sizeof(int) );

    vector<int> merhaba = solution(denemeVector, K);


   //printf("deneme1= %d, \n deneme2 = %d", merhaba.front(), merhaba.back());
   printf("a0= %d,  a1= %d, a2 = %d, a3= %d, a4 = %d\n", merhaba.at(0), merhaba.at(1),merhaba.at(2), merhaba.at(3), merhaba.at(4));

    return 0;
}
