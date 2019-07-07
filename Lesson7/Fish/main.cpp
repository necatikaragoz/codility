#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> &A, vector<int> &B)
{
    stack<int> eaterSize;
    int liveCnt = 0;

    for(int i = 0; i< A.size(); i++)
    {
        if(eaterSize.size())
        {
            if(B[i])
            {// downstream
                eaterSize.push(A[i]);
            }
            else
            {//upperstream

                if( A[i] > eaterSize.top())
                {
                    do
                    {
                        eaterSize.pop();
                        if(eaterSize.empty())
                        {
                            liveCnt++;
                            break;
                        }
                    }
                    while(A[i] > eaterSize.top());
                }
            }
        }
        else
        {
            if(B[i] == 0)
            {
                liveCnt++;
            }
            else
            {
                eaterSize.push(A[i]);
            }

        }

    }

    return (liveCnt + eaterSize.size());

}

int main()
{

    cout << "Hello world!" << endl;

    vector<int> A = {4,3,2,1,5};

    vector<int> B = {0,1,0,0,0};

    int retVal = solution(A,B);

    cout << "Solution1 = " << retVal << endl;


    return 0;


}
