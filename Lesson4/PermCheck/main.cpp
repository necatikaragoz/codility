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
    int offset = value % BitSize ;
    *vec |= (1 << offset);
}

int solution(vector<int> &A)
{
    unsigned int onlyOneCheck = 0;
    unsigned int maxVal = 0;
    unsigned int minVal = -1;

    for(vector<int>::iterator it = A.begin(); it != A.end(); it++)
    {
        if(*it > maxVal)
        {
            maxVal = *it;
        }
        ++onlyOneCheck;
   }

    int index = maxVal / BitSize ;
    int offset = maxVal % BitSize ;

   if(onlyOneCheck > A.size() || maxVal != A.size())
   {
       return (false);
   }

    int NewArr[index + 1];
    memset(NewArr, 0, index *sizeof(A[0]));

    NewArr[0] = 0x1;

    for(vector<int>::iterator it = A.begin(); it != A.end(); it++)
    {
        int index = *it / BitSize ;

        BitSet(&NewArr[index], *it);
   }

   int i = 0;
   for(i = 0; i < index; i++)
   {
      if(NewArr[i] != -1)
      {
          return(false);
      }
   }

   int bitNo = 0;
   for(bitNo = 0; bitNo <= offset; bitNo++)
   {
       if( ( (NewArr[i] >> bitNo) & 0x1 ) == 0)
       {
           return(false);
       }
   }
   return(true);
}


int main()
{
 cout << "PermCheck" << endl;

    //int A[] = {1, 3, 1, 4, 2, 3, 5, 4};
    int A[] = {1, 5, 3, 4, 2};

    vector<int> solutionVector (A, (A + sizeof(A) / sizeof(A[0]) ) );

     int retVal = solution(solutionVector);

    cout << retVal << endl;

     int B[] = {1000000000};

    vector<int> solutionVector2 (B, (B + sizeof(B) / sizeof(B[0]) ) );

     retVal = solution(solutionVector2);

     cout << retVal;

    return 0;
}
