#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <string.h>
#include <bitset>
#include <cmath>

using namespace std;


vector<int> solution(int N, vector<int> &A)
{
   vector<int> retVal(N);
   int maxCnt = 0;
   int* pRetVal = retVal.data();
   int  updateValue = 0;


   for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
   {
        if(*it <= N)
        {
            int index = *it - 1;

             if(pRetVal[index] < updateValue)
             {
                pRetVal[index] = updateValue;
             }

             ++pRetVal[index];

            if(maxCnt < pRetVal[index])
            {
                maxCnt = pRetVal[index];
            }
        }
       else
       {// *it == N+1
           updateValue = maxCnt;
           printf("updateVAl %d\n", updateValue);
      /*
      update rrue;
            */
       }
    }

    for(int k = N-1; k >=0 ; --k)
    {
       if(pRetVal[k] < updateValue)
       {
           pRetVal[k] = updateValue;
       }
     }

  return retVal;
}

int main()
{
   cout << "MaxCounters" << endl;

    //int A[] = {1, 3, 1, 4, 2, 3, 5, 4};
    int A[] = {3, 4, 4, 6, 1, 4, 4};

    vector<int> solutionVector (A, (A + sizeof(A) / sizeof(A[0]) ) );

    vector<int> retVal = solution(5, solutionVector);

    for (vector<int>::iterator it = retVal.begin(); it != retVal .end(); ++it)
    {
        cout << *it << ',';
    }

    cout << "size = " << retVal.size() << endl;

/*
     int B[] = {1000000000};

    vector<int> solutionVector2 (B, (B + sizeof(B) / sizeof(B[0]) ) );

     retVal = solution(solutionVector2);

     cout << retVal;*/

    return 0;
}
