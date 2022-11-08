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


int main(){

    fastIO;

    unordered_map<int,int>ump;

    while(true){
        int x;
        cin>>x;

        if(x == -1){
            break;
        }
        ump[x]++;
    }
    bool isSet = true;
    while(true){
        int y;
        cin>>y;

        if(y==-1){
            break;
        }

        if(ump.find(y) == ump.end()){
            isSet = false;
            break;
        }

    }

    if(isSet){
        YES;
    }
    else{
        NO;
    }

    re;
}