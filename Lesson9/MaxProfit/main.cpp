#include <iostream>
#include <stack>
#include <vector>
#include <map>


using namespace std;


int solution(vector<int> &A)
{
    int maxIndex = 0;
    int minIndex = 0;
    int maxProfit = 0;

    for(int i = 1; i< A.size(); i++)
    {
        int dailyGap = A[i] - A[i-1];

        if( (A[i] - A[minIndex]) > maxProfit)
        {
            maxProfit = A[i] - A[minIndex];
            maxIndex = i;
        }
        else
        {
             if(A[i] < A[minIndex] )
             {
                 minIndex = i;
             }
        }
    }

    return maxProfit;
}

int main()
{
    cout << "MaxProfit!" << endl;

    vector<int> A1 = {23171,21011,21123,21366,21013,21367};


    int retVal = solution(A1);

     cout << "solution 1 => " << retVal << " == 356"  << endl;

    return 0;
}
