#include<iostream>
#include<queue>

using namespace std;




int main(){

    vector<int>v;
    queue<int>q;
    int x,k;
    
    for(int i =0 ; ; i++)
    {
        cin>>x;
        if(x == -1)
        {
            break;
        }
        v.push_back(x);
        q.push(i);

    }

    cin>>k;
    int cnt = 0;
    while(true)
    {

        
        

        v[q.front()]--;
        if(v[q.front()] == 0)
        {
            cnt++;
            if(q.front() == k)
            {
                break;
            }
            else{
                q.pop();
            }
            
        }
        else
        {
            q.push(q.front());
            q.pop();
            cnt++;
        }

    }

    cout<<cnt;


}