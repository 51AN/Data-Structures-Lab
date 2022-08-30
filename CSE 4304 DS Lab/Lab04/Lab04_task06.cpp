#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;




int main(){

    int n;
    cin>>n;
    queue<int>students;
    vector<int>v;
    stack<int>sand;
    int x = 0;

    for(int i = 0 ; i<n ; i++)
    {
        cin>>x;
        students.push(x);
    }
    x = 0 ;
    for(int i = 0 ; i<n ; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    reverse(v.begin(), v.end());
    
    for(int i = 0 ; i<n ; i++)
    {
        sand.push(v[i]);
    }

    int count = 0;

    while(sand.empty() == 0)
    {
        if(sand.top() == students.front())
        {
            sand.pop();
            students.pop();
            count = 0;
        }
        else{
            students.push(students.front());
            students.pop();
            count++;

            if(count>=students.size())
                break;
        }
    }
    
    cout<<students.size();



}