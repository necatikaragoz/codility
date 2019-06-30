#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
    unsigned int totalCnt = A.size();
    totalCnt = ( (totalCnt + 1) * (totalCnt+2)) / 2;

    unsigned int result = 0;

    for(int i = 0 ; i < A.size(); i++)
    {
        result += A.at(i);
    }

    return (totalCnt - result);

}


int main()
{

    int A[] = {2, 3, 1, 5, 6, 7, 9, 10, 8};

    vector<int> denemeVector (A, A + sizeof(A) / sizeof(int) );

    int result = solution(denemeVector);
    cout << result;

    return 0;
}
