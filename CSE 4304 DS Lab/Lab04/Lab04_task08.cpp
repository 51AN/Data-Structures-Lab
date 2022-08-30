#include<iostream>
#include<queue>
#include<stack>


using namespace std;




int main(){

    int n,k;
    cin>>n>>k;

    queue<int>q;
        
        for(int i = 1; i<=n; i++)
        {
            q.push(i);
        }
        
        
        while(q.size() != 1)
        {
            
           int m = 1;
           while(m<k)
           {
               q.push(q.front());
               q.pop();
               m++;
           }
            q.pop();
            
        }
        
        cout<<q.front();
        
}



