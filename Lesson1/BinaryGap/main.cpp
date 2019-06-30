#include <iostream>
#include <stdio.h>

using namespace std;

#define CHECK_BIT(var, pos) ((var) & (1<<(pos)))

bool IsBitSet(int val, int cnt)
{
    return (val&(1<<cnt));
}


int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    int returnVal = 0;
    int localMax = 0;

    bool cntIsActive = false;
    int testData = N;

    for(int bitVal = 0; bitVal < 31 ; bitVal ++)
    {

        //if( (1 << bitVal)  & N)
        int shidftedTestValue = testData >> bitVal;
        if(shidftedTestValue & 0x00000001)
        {
            //one detected
            if(cntIsActive)
            {
                //if cnt is activated before
                if(localMax >= returnVal)
                {
                    //check the  local max bigger then return val
                    returnVal = localMax;
                }
                localMax = 0;
            }
            else
            {
                //if cnt is not activated before
                cntIsActive = true;
            }
        }
        else{
            //increase gap value local max
            if(cntIsActive)
            {
                localMax++;
            }
        }
    }


    return returnVal;
}



int main()
{
    cout << "Hello world!" << endl;

    int val = 561892;
    int val2 = 529;

    int n1 = solution(val);
    int n2 = solution(val2);
    printf("deneme1= %d, \n deneme2 = %d",n1, n2);


    return 0;
}
