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

    vector<int>v;
    map<int,int>mp;

    while(true){
        int x;
        cin>>x;
        if(x==-1){
            break;

        }
        v.push_back(x);
    }
    int target;
    cin>>target;

    for(int i = 0 ; i < v.size() ; i++){
        for(int j = i + 1 ; j < v.size() ; j++){
            if((v[i] + v[j])== target){
                mp.insert(make_pair(v[i],v[j]));
            }
        }
    }

    map<int, int>::iterator itr;

    for(itr = mp.begin() ; itr!=mp.end() ; ++itr){
        cout<<"("<<itr->first<<","<<itr->second<<") ";
    }
    if(mp.empty()){
        cout<<"No pair found"<<nl;
    }

    re;
}