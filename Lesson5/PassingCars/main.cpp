#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <string.h>
#include <bitset>
#include <cmath>

using namespace std;


int solution (vector<int> &A)
{
    int firstValue = A.at(0);
    unsigned int pairCnt = 0;
    unsigned int pairMultiplyCnt = 1;
    bool IsCountable = false;

    if(firstValue == 0)
    {
        IsCountable = true;
    }

    for(vector<int>::iterator it = (A.begin() + 1) ; it!=A.end(); it ++)
    {
       // printf("iterator value = %d \n", *it);
       if(firstValue && (*it == 0)
       {
            IsCountable = true;
            firstValue = 0;
       }

        if(IsCountable)
        {
            if(*it == firstValue)
            {
                pairMultiplyCnt++;
            }
            else
            {
                pairCnt += (pairMultiplyCnt * 1);
            }
        }

    }

    if(1000000000 < pairCnt)
    {
        pairCnt = -1;
    }

    return pairCnt;
}

int main()
{
    cout << "PassingCars" << endl;

    //int A[] = {0, 1, 0, 1, 1};
    int A[] = {0, 1};

    vector<int> solutionVector (A, (A + sizeof(A) / sizeof(A[0]) ) );

    int retVal = solution(solutionVector);
    printf("output = %d\n", retVal);

    return 0;
}
