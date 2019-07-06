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

    int a[6] = {40,41,123,125,91,93};

    char lastChar = 0;
    if(S.size())
    {
        for(int i =0; i < S.size(); i++)
        {
            char readChar = S.at(i);
            if( (a[0] == readChar) || (a[2] == readChar) || (a[4] == readChar))
            {
                mystack.push(readChar);
                lastChar = readChar;
                started = true;
            }
            else if((a[1] == readChar) || (a[3] == readChar) || (a[5] == readChar) )
            {
                bool popoccured = false;
                for(int k = 0; k < 6; k+=2 )
                {
                    if( (mystack.top() == a[k]) && ( readChar == a[k + 1] ) )
                    {
                        mystack.pop();
                        popoccured = true;
                        break;
                    }
                }
                if(!popoccured)
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
    cout << "Brackets" << endl;

    string s1 ="{[()()]}";

    string s2 ="([)()]";

    string s3 ="{{{{";

    string s4;

	int retVal = solution(s1);

	cout << "solution1 = " << retVal << endl;

	retVal = solution(s2);

	cout << "solution2 = " << retVal << endl;

	retVal = solution(s3);

	cout << "solution3 = " << retVal << endl;

	retVal = solution(s4);

	cout << "solution4 = " << retVal << endl;

    return 0;
}
