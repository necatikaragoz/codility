#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVector(vector<int>& A)
{

	for(auto x : A)
	{
		cout << x << "";

	}

}

int solution(vector<int>& A)
{
    int sum=0;

    cout << "size = " << A.size();

    vector<int> start(A.size(),0);

    vector<int> end(A.size(),0);

    for (unsigned int i=0; i< A.size(); i++)
    {
        if ( (int)i < A[i])
        {
            start[0]++;
        }
        else
        {
            start[i-A[i]]++;
        }

        if (i+A[i]>=A.size())
        {
            end[A.size()-1]++;
        }
        else
        {
            end[i+A[i]]++;
        }
    }
    int active=0;
    for (unsigned int i=0;i<A.size();i++)
    {
        sum += active * start[i] + (start[i] * (start[i]-1) ) / 2;
        if (sum>10000000) return -1;
        active+=start[i]-end[i];
    }
    return sum;
}

int main()
{

	cout << "NumberOfDiscIntersections!" << endl;

	std::vector<int> A = { 1, 5, 2, 1, 4, 0};

	//printVector(A);

	int retVal = solution(A);

	cout << "retVal = " << retVal << endl;
}
