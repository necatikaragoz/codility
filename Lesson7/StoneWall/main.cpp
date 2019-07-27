#include <iostream>
#include <stack>
#include <vector>

using namespace std;



int solution(vector<int> &H)
{
    vector<int> temp;

    int blockCnt = 1;

    int blockSize = H[0];
    for (int i = 1; i < (int)H.size(); i++)
    {
        if(H[i] == blockSize)
        {// it can be represent with same block
            continue;
        }
        else if(H[i] > blockSize)
        { //now truncated block comed
            temp.push_back(H[i] - blockSize);
            continue;
        }
        else
        {
            blockCnt++;
            blockSize = H[i];
            if(!temp.empty())
            {
                blockCnt += solution(temp);
            }
        }
    }

    if(!temp.empty())
    {
        blockCnt += solution(temp);
    }
    H.clear();
    return blockCnt;
}

int main()
{
    cout << "Stone Wall!" << endl;

    vector<int> A1 = { 8, 8, 5, 7, 9, 8, 7, 4, 8};


    int retVal = solution(A1);

    cout << "solution 1 = " << retVal << " == 7"  << endl;

    vector<int> A2 = {1, 2, 3, 3, 2, 1};

    retVal = solution(A2);

     cout << "solution 2 = " << retVal << " == 3" <<endl;

    return 0;
}
