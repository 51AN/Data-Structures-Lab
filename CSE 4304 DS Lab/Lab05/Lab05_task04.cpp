#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

int main()
{
    priority_queue<pair<int,bool>> pq;

    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        

        pq.push({a,true});

        pq.push({b,false});
    }


    int checkRoom = 0;
    int maxRoom = 0;
    while(!pq.empty())
    {
       
        if(!pq.top().second)
        {
            checkRoom++;
        }
        else if(pq.top().second)
        {
            checkRoom--;
        }

        maxRoom = max(maxRoom, checkRoom);
        
        pq.pop();

    }

    cout<<maxRoom<<endl;




    return 0;
}