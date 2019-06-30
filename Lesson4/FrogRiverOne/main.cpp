#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int *NewArr = new int[X];

    memset(NewArr, 0 ,  X * sizeof(int));

    int positionCnt = 0;

    for(unsigned int i = 0 ; i < A.size(); i++)
    {
        int tempVal = A.at(i);
        if(tempVal <= X)
        {
            if( NewArr[tempVal -1] == 0)
            {
               positionCnt ++;
            }
            ++NewArr[tempVal-1];
        }

        if(positionCnt == X)
        {
            delete [] NewArr;
            return(i);
        }
    }

    delete [] NewArr;
    return(-1);

}

int main()
{
    //int A[] = {2, 3, 1, 5, 6, 7, 9, 10, 8};
    int A[] = {1, 3, 1, 4, 2, 3, 5, 4};

    vector<int> denemeVector (A, A + sizeof(A) / sizeof(int) );

    int returnVal =  solution(5, denemeVector);
    cout << returnVal;

    return 0;
}
