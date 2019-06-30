#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>

using namespace std;


int solution(vector<int> &A)
{
    int value = 0;

    for(int i=0; i < A.size(); i++)
    {
        value = value ^ A.at(i);
    }

    return value;
}

int main()
{
    cout << "Hello world! " << endl;

    int A[] = {3, 7, 9, 7, 3};
    int K = 3;

    printf("a0= %d,  a1= %d, a2 = %d, a3= %d, a4 = %d\n", A[0], A[1],A[2], A[3], A[4]);

    vector<int> denemeVector (A, A + sizeof(A) / sizeof(int) );

    int retVal = solution(denemeVector);

    cout << "retval = " << retVal << endl;

    return 0;
}
