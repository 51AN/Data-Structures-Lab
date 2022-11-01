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


class Trie {
public:
    int trie[300005][50];
    int id = 1;
    int endmark[300005];
    int pre[300005];
    Trie() {
        memset(trie,0,sizeof(trie));
        memset(endmark,0,sizeof(endmark));
        memset(pre,0,sizeof(pre));
    }
   
    void insert(string word) {
        int row = 1;
        for(int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';
            if(trie[row][ch] == 0)
            {
                trie[row][ch] = ++id;
            }
            row = trie[row][ch];
            pre[row]++;
        }
        endmark[row] = 1;
       
    }
   
    bool search(string word) {
        int row = 1;
        for(int i = 0; i < word.size();i++)
        {
            bool checkForChar = false;
            if(word[i] == '.'){
                
                for(int j = 0 ; j < 50 ; j++){
                    if(trie[row][j] != 0){
                        checkForChar = true;
                        row = trie[row][j];
                        break;
                    }
                }
                if(!checkForChar){
                    return false;
                }

            }
            else{
                int ch = word[i] - 'a';
                if(trie[row][ch] == 0) return false;
                row = trie[row][ch];
            }
            

        }
        return (endmark[row] == 1);
    }
   
    bool startsWith(string prefix) {
        int row = 1;
        for(int i = 0; i < prefix.size();i++)
        {
            int ch = prefix[i] - 'a';
            if(trie[row][ch] == 0) return false;
            row = trie[row][ch];

        }
        return (pre[row] >= 1);
    }
};

class WordDictionary{

public :
    Trie* obj = new Trie();
    WordDictionary(){
        cout<<"Object Created"<<nl;
    }

    void addWord(string word){
        obj->insert(word);
        cout<<"Word Added"<<nl;
    }

    bool search(string word){
        //return obj->search(word);

        if(obj->search(word))
        {
            cout<<"Word Found"<<nl;
            return true;
        }
        else{
            cout<<"Word not found"<<nl;
            return false;
        }
    }

};


int main(){

    fastIO;

    

    WordDictionary wd;

    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    
    wd.search("pad");
    wd.search("dad");
    wd.search(".ad");
    wd.search("b..");
    




    re;

}