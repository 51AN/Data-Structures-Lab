#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int,bool>> pq;

    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a;
        cin>>b;

        pq.push(make_pair(a, true));

        pq.push(make_pair(b, false));
    }


    int checkRoom = 0;
    int max = 0;
    while(pq.size() != 0)
    {
        pair<int, int> top = pq.top();

        if(top.second)
        {
            checkRoom++;
        }
        else if(!top.second)
        {
            checkRoom--;
        }

        
        if(max < checkRoom)
        {
            max = checkRoom;
        }

        pq.pop();

    }

    cout<<max<<endl;




    return 0;
}