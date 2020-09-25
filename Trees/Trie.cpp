#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Trie{
public:
	Trie *alpha[26];
	bool isEnd;

	Trie(){
		isEnd=false;
		for(int i=0;i<26;i++) alpha[i]=NULL;
	}
	
	void insertTrie(string word){
		Trie *tmp=this;
		for(char letter:word){
			if(tmp->alpha[letter-97]==NULL) 
				tmp->alpha[letter-97]= new Trie();
			tmp = tmp->alpha[letter-97];
		}
		tmp->isEnd = true;
	}

	bool searchTrie(string word){
		Trie *tmp=this;
		for(char letter:word){
			if(tmp->alpha[letter-97]==NULL) return false;
			tmp = tmp->alpha[letter-97];
		}
		if(!(tmp->isEnd) ) return false;

		return true;
	}

};


int main(){
	Trie t1;
	t1.insertTrie("abcd");
	t1.insertTrie("fdg");
	t1.insertTrie("abc");
	cout<<t1.searchTrie("fdg")<<" ";
	cout<<t1.searchTrie("fg")<<" ";
	cout<<t1.searchTrie("gfkuh")<<" ";
	cout<<t1.searchTrie("abcd")<<" ";
}