#include <iostream>
#include <vector>
#include <cmath>        // std::abs

using namespace std;


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int result = 0;
    unsigned int minVal = -1;
    int part1 = 0;
    int part2 = 0;

    for(unsigned int i = 0 ; i < A.size(); i++)
    {
        result += A.at(i);
    }


    if(A.size()>2)
    {

        for(unsigned int p = 1; p < A.size()-1 ; p++)
        {
            part1 = part1 + A.at(p-1);
            part2 = result - part1;


            if( abs(part1 - part2) < minVal)
            {

                minVal = abs(part1 - part2);
            }
        }
    }
    else{

        minVal = abs(A.at(0) - A.at(1));
    }

    return (minVal);
}

int main()
{
    int A[] = {3, 1};

    vector<int> denemeVector (A, A + sizeof(A) / sizeof(int) );

    int result = solution(denemeVector);
    cout << result;
    return 0;
}
