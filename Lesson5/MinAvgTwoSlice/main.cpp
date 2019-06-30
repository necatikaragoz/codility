#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits>
#include <stdio.h>      /* printf */
#include <assert.h>     /* assert */

using namespace std;

int solution(vector<int> &A)
{
    float minAvg = std::numeric_limits<float>::max();
    int minValIndex = 0;

    int length = A.size();

    int* pSums = new int[length + 1];

    //memset(sums, 0, length+1);
    pSums[0] = 0;

    for(int i = 0; i < A.size(); i++)
    {
        pSums[i + 1] = pSums[i] + A[i];
    }

    for(int i = 0; i < A.size()-1; i++)
    {
        int i0 = i;
        int i1 = i + 1;

        float localAvg = (pSums[i1 + 1] - pSums[i0]) / 2.0f;

        if (localAvg < minAvg)
        {
                minAvg = localAvg;
                minValIndex = i;
        }

       if (i < length - 2)
        {
            int i2 = i + 2;
            float localAvg3 = (pSums[i2 + 1] - pSums[i0]) / 3.0f;

            if (localAvg3 < minAvg)
            {
                minAvg = localAvg3;
                minValIndex = i;
            }
        }

    }

    return minValIndex;

}


int main()
{

    cout << "MinAvgTwoSlice!" << endl;

    std::vector<int> A = {4, 2, 2, 5, 1, 5, 8};

    int retVal = solution(A);

    cout << "retVal = " << retVal << endl;
    /**/
    std::vector<int> A1 = {5, 6, 3, 4, 9};

    int retVal1 = solution(A1);

    cout << "retVal1 = " << retVal1 << endl;
    /**/
    std::vector<int> A2 = {-3, -5, -8, -4, -10};

    int retVal2 = solution(A2);

    cout << "retVal2 = " << retVal2 << endl;

    return 0;
}
