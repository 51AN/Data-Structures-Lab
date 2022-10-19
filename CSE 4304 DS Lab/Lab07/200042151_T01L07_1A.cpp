#include<bits/stdc++.h>
#define ll                                               long long int
#define fastIO  (ios::sync_with_stdio(0),cin.tie(0));
#define re                        return 0;
#define nl                                                "\n"
#define f(i,n)                                           for(int i = 0 ; i < n ; i ++)
#define f1(i,n)                                          for(int i = 1 ; i <= n ; i ++)
#define fb(i,n)                                          for(int i = n - 1 ; i => 0 ; i --)
#define v(i)                                             vector<int>v[i];
#define sortv(a)                                         sort(a.begin(),a.end())
#define test(t)                                          ll t; cin>>t; while(t--)
#define YES                                              cout<<"YES"<<endl
#define NO                                               cout<<"NO"<<endl


using namespace std;


class MedianQueue{

public:
priority_queue<int, vector<int>, greater<int> >upper;
priority_queue<int>lower;


    void AddNum(int x){

        if(upper.empty()  && lower.empty()){
            upper.push(x);
        }
        else{
            if(x>=upper.top()){
                upper.push(x);
            }
            else{
                lower.push(x);
            }



        }


        if(upper.size() - lower.size() == 2){
        
            lower.push(upper.top());
            upper.pop();
        }
        else if(lower.size() - upper.size() == 2){
            
            upper.push(lower.top());
            lower.pop();
        }


        
    }

    void FindMedian(){
      
        if(lower.size()>upper.size()){
            cout<<(double)lower.top()<<nl;
            //cout<<(double)(lower.top())<<nl;
        }
        else if(lower.size()<upper.size()){
            cout<<(double)upper.top()<<nl;
            //cout<<(double)(upper.top())<<nl;
        }
        else{
            cout<<(((double)lower.top() + (double)upper.top())/(double)2.0)<<nl;
            //cout<< (double(lower.top()) + double(upper.top()))/2<<nl;
        }
        
    }

};


int main(){

    fastIO;

    MedianQueue mq;

    mq.AddNum(5);
    mq.AddNum(6);
    mq.AddNum(7);
    mq.AddNum(8);
    mq.FindMedian();
    // mq.AddNum(8);
    // mq.FindMedian();



    re;

}