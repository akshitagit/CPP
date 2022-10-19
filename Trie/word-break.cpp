// Problem Link: https://leetcode.com/problems/

// Solution: Trie+DP(memoization)Time Complexity: O(n*l + N^2)
// where, n = length of word dict
// l = length of longest word in the dict.N=length of string (s)

// Prerequisite: You should know basic concept of Trie

class Solution {
public:
    class Trie{
      public:
        Trie *child[26];
        bool isEnd = false;
    };
    void insert(string &word, Trie* root){
        Trie *cur = root;
        for(auto &ch : word){
            if(!cur->child[ch-'a']) cur->child[ch-'a'] = new Trie();
            cur=cur->child[ch-'a'];
        }
        cur->isEnd = true;
    }
    bool search(string &word, Trie* root){
        Trie *cur = root;
        for(auto &ch : word){
            if(!cur->child[ch-'a']) return false;
            cur=cur->child[ch-'a'];
        }
        return cur->isEnd;
    }
    int dp[305][305];
    bool solve(string &s, Trie *root, int n, int start){
        if(start==n) return true;
        if(dp[start][n]!=-1) return dp[start][n];
        for(int i=start; i<n; ++i){
            string str = s.substr(start,i-start+1);
            if(search(str,root)){
                if(solve(s,root,n,i+1)) return dp[start][n] = true;
            }
        }
        return dp[start][n] = false;
    }
    bool wordBreak(string &s, vector<string>& wordDict) {
        Trie *root = new Trie();
        for(auto &word : wordDict) insert(word,root);
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,root,n,0);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    string str;
    cout << "Enter the string" << endl;
    cin >> str;
    int n;
    cout << "Enter the number of words in the List" << endl;
    cin >> n;
    vector<string> wordDict(n);
    cout<<"Enter the words"<<endl;
    for(int i=0; i<n; i++){
        cin >> wordDict[i] ;
    }
    cout << s.wordBreak(str,wordDict) << endl;
    return 0;
}
