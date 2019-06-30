#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits>
#include <stdio.h>      /* printf */
#include <map>
#include <algorithm>    // std::sort

using namespace std;


void printVector(vector<int> &A)
{
    for(int i = 0; i< A.size(); i++)
    {
        cout << A.at(i);
    }
    cout << endl;
}

int solution(vector<int> &A)
{
    if(A.size())
    {
        sort(A.begin(),A.end());

        int distinctValCnt = 1;
        int tempVal = A.at(0);

        for(int i = 1; i < A.size(); i++)
        {
            if(tempVal != A.at(i))
            {
                distinctValCnt++;
                tempVal = A.at(i);
            }

        }
        return distinctValCnt;
    }
    else
    {
        return 0;
    }
}


int main()
{

	const volatile int local = 10;
	int *ptr = (int*) &local;
	printf("Initial value of local : %d \n", local);
	*ptr = 100;
	printf("Modified value of local: %d \n", local);
	return 0;

    cout << "Distinct!" << endl;

    std::vector<int> A = {4, 2, 2, 5, 1, 5, 8};

   // printVector(A);

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
