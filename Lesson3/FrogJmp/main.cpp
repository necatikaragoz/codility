#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>

using namespace std;


int solution(int X, int Y, int D)
{
    int distance = (Y - X);
    double fcnt = distance / (double)D;
    int icnt = distance / D;


    cout << "distance = " << distance << " fcnt = " << fcnt << " icnt = " << icnt << endl;

    double val = fcnt - (double)icnt ;
    cout << "val = " << val << endl;
    printf("flatval = %f \n",val);

    if(fcnt-(double)icnt >= 0)
    {
        ++icnt;
    }

    return icnt;
}

int main()
{
    cout << "Hello world! " << endl;


    int retVal = solution(10,85,30);

    cout << "retval = " << retVal << endl;


    retVal = solution(5, 105, 3);

    cout << "retval = " << retVal << endl;

    return 0;
}
