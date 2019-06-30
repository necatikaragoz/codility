#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <string.h>
#include <bitset>
#include <cmath>


using namespace std;

const int BitSize = sizeof(int)*8;

void BitSet(int* vec, int value)
{
    int index = value / BitSize ;
    int offset = value % BitSize ;
    vec[index] |= (1 << offset);
}

int solution(vector<int> &A)
{
    bool allNegative = true;
    int maxVal = 0;
    unsigned int minVal = -1;


    for(vector<int>::iterator it = A.begin(); it != A.end(); it++)
    {
        int tempVal = *it;
        if(tempVal > 0)
        {
            allNegative = false;
            if((unsigned int)tempVal < minVal)
            {
                minVal = tempVal;
            }
        }

        if(tempVal > maxVal)
        {
            maxVal = tempVal;
        }
    }

    if(allNegative || (minVal>1))
    {
        return (1);
    }
    else
    {
        int NewArr[maxVal / BitSize];
        memset(NewArr, 0, (maxVal / BitSize) *sizeof(A[0]));

        NewArr[0] = 0x1;

        for(vector<int>::iterator it = A.begin(); it != A.end(); it++)
        {
            int tempVal = *it;
            if(tempVal > 0)
            {
                BitSet(NewArr, tempVal);
            }
        }
        unsigned int i = 0;

        for(i = 0; i != (A.size()/BitSize)+1; i++)
        {
           if(NewArr[i] != -1)
           {
               break;
           }
        }

        int bitNo = 0;
        for(bitNo = 0; bitNo < BitSize; bitNo++)
        {
            if( ( (NewArr[i] >> bitNo) & 0x1 ) == 0)
            {
                return((i * BitSize) + bitNo);
            }
        }

        return(maxVal+1);
    }

}



int main()
{
    cout << "Missing Integer" << endl;

    //int A[] = {1, 3, 1, 4, 2, 3, 5, 4};
    int A[] = {90, 91, 92, 93};

    vector<int> solutionVector (A, (A + sizeof(A) / sizeof(A[0]) ) );

     int retVal = solution(solutionVector);

    cout << retVal << endl;

     int B[] = { 1, 3, 6, 4, 1, 2};

    vector<int> solutionVector2 (B, (B + sizeof(B) / sizeof(B[0]) ) );

     retVal = solution(solutionVector2);

     cout << retVal;

    return 0;
}
