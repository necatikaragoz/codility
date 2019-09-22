#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;



int solution(vector<int> &A)
{
    map<int ,int> mymap;
    map<int,int>::iterator it;

    for(auto x: A)
    {
        it = mymap.find(x);
        if (it == mymap.end())
        {
            mymap[x] = 1;
        }
        else
        {
            mymap[x] = mymap[x]+1;
        }
    }
    int maxVal = 0;
    int lead = -1;
    for (std::map<int,int>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr)
    {
         //std::cout << itr->first << " => " << itr->second << '\n';
         if(itr->second > maxVal)
         {
             maxVal = itr->second;
             lead = itr->first;
         }
    }

    int leftLeadsCnt = 0;
    int equalCnt = 0;
    for(std::size_t i = 0; i < A.size(); ++i)
    {

        if(A[i] == lead)
        {
            leftLeadsCnt++;
        }
        int rightLeadsminValue = (A.size() - i ) ;
        int leftLeadsminValue = i ;

        if(  ( (i+1) < (leftLeadsCnt *2) ) &&
             ( rightLeadsminValue  <= ((maxVal - leftLeadsCnt)*2) ) )
        {
            equalCnt ++;
        }

    }

    return equalCnt ;

}


int FindLeader(vector<int> &A)
{
    map<int ,int> mymap;
    map<int,int>::iterator it;

    for(auto x: A)
    {
        it = mymap.find(x);
        if (it == mymap.end())
        {
            mymap[x] = 1;
        }
        else
        {
            mymap[x] = mymap[x]+1;
        }
    }
    int maxVal = 0;
    int lead = -1;
    for (std::map<int,int>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr)
    {
         //std::cout << itr->first << " => " << itr->second << '\n';
         if(itr->second > maxVal)
         {
             maxVal = itr->second;
             lead = itr->first;
         }
    }

    return lead ;
}


int main()
{
    cout << "EquiLeader!" << endl;

    vector<int> A1 = {4,3,4,4,4,2};


    int retVal = solution(A1);

     cout << "solution 1 => " << retVal << " == 2"  << endl;

    return 0;
}
