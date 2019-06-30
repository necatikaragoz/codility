#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

enum DnaIndexEnum
{
   DIE_Aindex,
   DIE_Cindex,
   DIE_Gindex,
   DIE_LastIndex
};

struct DnaIndexStc
{
    int DnaType[DIE_LastIndex];
};


vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{

    const int M = P.size();
    const int N = S.size();

    DnaIndexStc* pDnaIndex =  new DnaIndexStc[N+1];

    for(int k = 0; k < DIE_LastIndex;k++)
    {
        pDnaIndex[0].DnaType[k] = 0;
    }

     for(int i = 1; i <= N; i++)
    {
        // update new values
        for(int k = 0; k < DIE_LastIndex;k++)
        {
            pDnaIndex[i].DnaType[k] = (pDnaIndex[i-1].DnaType[k]) ;
        }

        DnaIndexEnum index = DIE_Gindex;
        if(S[i-1] == 'A' )
        {
            pDnaIndex[i].DnaType[DIE_Aindex]++;
        }
        else if(S[i-1] == 'C' )
        {
                pDnaIndex[i].DnaType[DIE_Cindex]++;
        }
        else if(S[i-1] == 'G' )
        {
            pDnaIndex[i].DnaType[DIE_Gindex]++;
        }
    }

    vector<int> retVal(P.size());


    for(int queryNo = 0; queryNo < M; queryNo++ )
    {
        retVal[queryNo] = 4;//checkMinFactor(S, P.at(queryNo), Q.at(queryNo));
        int startIndex = Q[queryNo];
        int stopIndex  = P[queryNo];
        for(int k = 0; k < DIE_LastIndex;k++)
        {
            if(pDnaIndex[startIndex + 1].DnaType[k] - pDnaIndex[stopIndex].DnaType[k] > 0)
            {
                retVal[queryNo] = k+1;
                break;
            }
        }
    }
    delete[] pDnaIndex;
    return(retVal);
}




int main()
{
    cout << "GenomicRangeQuery!" << endl;


    string S =  "CAGCCTA";
    std::vector<int> P = {2, 5, 0};
    std::vector<int> Q = {4, 5, 6};

    vector<int> retVal = solution(S, P, Q);

    for (vector<int>::iterator it = retVal.begin(); it != retVal .end(); ++it)
    {
        cout << *it << ',';
    }

    cout << "size = " << retVal.size() << endl;


    string S1 =  "C";
    std::vector<int> P1 = {0};
    std::vector<int> Q1 = {0};

    vector<int> retVal1 = solution(S1, P1, Q1);

    for (vector<int>::iterator it = retVal1.begin(); it != retVal1 .end(); ++it)
    {
        cout << *it << ',';
    }

    cout << "size = " << retVal1.size() << endl;

    return 0;
}
int checkMinFactor(string &S, int p, int q )
{
    int factor = 0;
    int minFactor = 0;

    for(int mf = p; mf <= q; mf++ )
    {
        minFactor = 0;

        if(S[mf] == 'A' )
        {
            return 1;
        }
        else if(S[mf] == 'C' )
        {
            minFactor = 2;
        }
        else if(S[mf] == 'G' )
        {
            minFactor = 3;
        }
        else
        {
            minFactor = 4;
        }
        factor =  factor | (1 << minFactor);
    }

    for(int i = 2; i <= 4; i++ )
    {
        if( (factor >> i) & 0x01 == 1)
        {
            return i;
        }
    }

}

