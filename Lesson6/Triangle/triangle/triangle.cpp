// triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;
/**/

void printVector(vector<int>& A)
{
	for (int i = 0; i < (int)A.size(); i++)
	{
		cout << A.at(i);
	}
	cout << endl;
}



int solution(vector<int>& A)
{
	if (A.size() >= 3)
	{
		sort(A.begin(), A.end());
		for (int i = 0; i < A.size()-2; i++) {
			if (A[i] + A[i + 1] > A[i + 2])
				return 1;
		}
	}
	return 0;
}


int main()
{
    cout << "Hello World!\n";

	cout << "Triangle!" << endl;

	/**/
	vector<int> A = { 10, 2, 5, 1, 8, 20 };

	int retVal = solution(A);

	cout << "retVal = " << retVal << endl;


	/**/
	vector<int> A1 = { 10, 50, 5, 1 };

	int retVal1 = solution(A1);

	cout << "retVal1 = " << retVal1 << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
