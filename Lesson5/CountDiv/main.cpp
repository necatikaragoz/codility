#include <iostream>
#include <stdio.h>

using namespace std;

int solution(int A, int B, int K)
{
    int cnt = 0;

    if( (A % K) == 0 )
    {
        cnt ++;
    }

    int cnt1 = B / K;
    int cnt2 = A / K;

    return (cnt1 - cnt2 + cnt);

}


int main()
{
    cout << "CountDiv!" << endl;

    int retVal = solution(6,11,2);

    printf("result1 = %d \n", retVal);

    retVal = solution(11,345,17);

    printf("result2 = %d \n", retVal);

    return 0;
}
