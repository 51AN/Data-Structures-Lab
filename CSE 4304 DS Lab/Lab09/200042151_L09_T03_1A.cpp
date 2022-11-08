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

#define base 26

using namespace std;

void rabin_karp_hashing(string given, string find){

    int q = INT_MAX;
    int hash_g = 0;
    int hash_f = 0;
    int h = 1;
    int N = given.length();
    int M = find.length();
    int i,j;

    for(i = 0 ; i < M - 1 ; i++){
        h = (h * base) % q;
    }

    for(i = 0 ; i < M ; i++){
        hash_f = (base * hash_f  + find[i]) % q;
        hash_g = (base * hash_g  + given[i]) % q;
    }


    for(i = 0 ; i <= N - M ; i++){


        if(hash_f == hash_g){
            for(j = 0; j < M; j++){
                if(given[i + j] != find[j]){
                    break;
                }
            }

            if(j == M){
                cout<<find<<" occurs at index : "<<i<<nl;
            }
        }

        if(i < N - M){
            hash_g = (base * (hash_g - given[i] * h) + given[i + M]) % q;

            if(hash_g < 0){
                hash_g += q;
            }
        }

    }

}

int main(){

    fastIO;

    string given, find;
    cin>>given>>find;

    rabin_karp_hashing(given, find);


    re;
}