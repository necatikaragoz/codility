#include <QCoreApplication>
#include <vector>
#include <iostream>
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

bool descentingSort(int a, int b)
{
    return  (a>b);
}

int solution(vector<int> &A)
{
    /*firs sort the line and */
    sort(A.begin(), A.end(), descentingSort);

    int neg = A.back();
    int temp = A.back();
    A.pop_back();
    neg *= A.back();
    A.push_back(temp);

    int pos = A.at(0)*A.at(1);
    int pos2 = A.at(1)*A.at(2);

    if(A.at(0) > 0 )
    {
        if(neg > pos || neg > pos2)
        {
            return neg*A.at(0);
        }
    }

    return (A.at(0)*A.at(1)*A.at(2));

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Max Product of three!" << endl;

    std::vector<int> A = {-3, 1, 2, -2, 5, 6};


    int retVal = solution(A);

    cout << "retVal = " << retVal << endl;


    /**/
    std::vector<int> A1 = {10, 10, 10};

    int retVal1 = solution(A1);

    cout << "retVal1 = " << retVal1 << endl;


    /**/
    std::vector<int> A2 = {-5, -6, -4, -7, -10};

    int retVal2 = solution(A2);

    cout << "retVal2 = " << retVal2 << endl;


    /**/
    std::vector<int> A3 = {-10, -2, -4};

    int retVal3= solution(A3);

    cout << "retVal3 = " << retVal3 << endl;



    return a.exec();
}
