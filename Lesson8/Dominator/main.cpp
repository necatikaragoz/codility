#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int solution(vector<int> &A)
{

    int val = 0;
    int dominator = -1;
    int dominatorIndex = 0;
    unsigned int size = 0;
    unsigned int count = 0;

    for(int i = 0;i< A.size(); i++)
    {
        if(size)
        {
            if(A[i] == val)
            {
                ++size;
            }
            else
            {
                --size;
            }
        }
        else
        {
            ++size;
            val = A[i];
            dominatorIndex  = i;
        }
    }

    int canditate = -1;

    if(size)
    {
        canditate = val;
        count = 0;
    }

    for(auto x : A)
    {
        if(x == canditate)
        {
            ++count;
        }
    }

    if(count > (A.size() / 2 ))
    {
        dominator  = dominatorIndex;
    }

    return dominator;
}


int main()
{
    cout << "Dominator!" << endl;

    vector<int> A1 = { 3, 4, 3, 2, 3, -1, 3, 3};


    int retVal = solution(A1);

    cout << "solution 1 => " << retVal << " == 3"  << endl;

    /*vector<int> A2 = {1, 2, 3, 3, 2, 1};

    retVal = solution(A2);

     cout << "solution 2 = " << retVal << " == 3" <<endl;*/

    return 0;
}
