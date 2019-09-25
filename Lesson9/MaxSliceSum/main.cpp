#include <iostream>
#include <vector>
#include <stack>
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> &A)
{
    int maxIndex = 0;
    int minIndex = 0;

    int maxValue = INT_MIN;

    int sum = 0;

    for(int i = 0; i<A.size(); i++)
    {
        sum += A[i];

        if(maxValue < sum )
        {
            maxValue = sum;
            maxIndex = i;
        }
        else if(A[i] > maxValue)
        {
            maxIndex = i;
        }
    }

    sum = 0;

    int maxValue2 = INT_MIN;

    for(int i = maxIndex; i >= 0; i--)
    {
        sum += A[i];
        if(maxValue2 < sum )
        {
            maxValue2 = sum;
            minIndex = i;
        }
    }

    sum = 0;
    for(int i = maxIndex; i <= maxIndex ; i++)
    {
        sum += A[i];
    }

    if(sum > maxValue2)
    {
        maxValue2 = sum;
    }
    if(maxValue > maxValue2)
    {
        maxValue2 = maxValue;
    }


    return maxValue2;
}

int main()
{
    cout << "MaxSliceSum!" << endl;

    vector<int> A1 = {3,2,-6,4,0};


    int retVal = solution(A1);

    cout << "solution 1 => " << retVal << " == 5"  << endl;

    return 0;
}
