#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// Empty stack


int solution(string &S)
{
    stack<int> mystack;
    bool started = false;

    int a[2] = {40,41};

    char lastChar = 0;
    if(S.size())
    {
        for(int i =0; i < S.size(); i++)
        {
            char readChar = S.at(i);
            if( (a[0] == readChar) )
            {
                mystack.push(readChar);
                lastChar = readChar;
                started = true;
            }
            else if((a[1] == readChar) )
            {
                if( (!mystack.empty()) && (mystack.top() == a[0]) && ( readChar == a[1] ) )
                {
                    mystack.pop();
                }
                else
                {
                    return 0;
                }
            }

        }
    }
    else
    {
        started  = true;
    }

    if(started && (mystack.size() == 0) )
    {
        return 1;
    }
    return 0;
}

int main()
{
    cout << "Nesting" << endl;

    string s1 ="(()(())())";

    string s2 ="())";

    string s3 ="((((";

    string s4;

	int retVal = solution(s1);

	cout << "solution1 = " << retVal << endl;

	retVal = solution(s2);

	cout << "solution2 = " << retVal << endl;

	retVal = solution(s3);

	cout << "solution3 = " << retVal << endl;

	retVal = solution(s4);

	cout << "solution4 = " << retVal << endl;

}
