//Zipped String
//Hard
//
//Question :- Given lowercase alphabet strings a, b, and c return whether there's any way of obtaining c by merging characters in order from a and b.
//
//Constraints:-
//
//0 ≤ n ≤ 1,000 where n is the length of a
//0 ≤ m ≤ 1,000 where m is the length of b
//0 ≤ k ≤ 1,000 where k is the length of c
//
//
//Example 1:-
//Input:-
//a = "abc"
//b = "def"
//c = "abdefc"
//Output:-
//true
//Explanation:-
//abdefc is an interleave since abc and def can be interleaved with: abdefc
//
//Example 2:-
//Input:-
//a = "ab"
//b = "cd"
//c = "abdc"
//Output:-
//false
//Explanation:-
//Even though ab is in the right order in abdc, cd is backwards, so this is not an interleaving.




//Intuition : -
//Recursion
//
//The idea is simple, our recursive function keeps tracking the index we have used for string a and b, and the current index of c, and call itself for further check.
//
//I thought it might have some performance issue, but it turns out to be OK, 2ms and beats 99.4%.
//
//Implementation
//The reason this recursive solution is fairly performant is that, the choice of characters is very limited, and you cannot skip them. For a certain character of c, if we cannot find a match in a and b at their current checking position, we can simply return false.
//
//If we modify the condition a little bit, we may see huge performance degradation. For example, c does not need to use all characters from a and b, let say a=axyz, b=buvw,c=xuyvz is a valid use case.
//
//Time Complexity
//O(n), most of the time, we check a.size() + b.size() times. Depending on the strings, it can be worse than O(n) sometimes
//
//Space Complexity
//O(n), the recursive stack depth is proportional to the length of a, b and c

bool go(string& a, int ai, string& b, int bi, string& c, int ci) {
    if (ci >= c.size()) return true;
    if (ai < a.size() && c[ci] == a[ai] && go(a, ai + 1, b, bi, c, ci + 1))
        return true;
    else if (bi < b.size() && c[ci] == b[bi] && go(a, ai, b, bi + 1, c, ci + 1))
        return true;
    return false;
}

bool solve(string a, string b, string c) {
    if (a.size() + b.size() != c.size()) return false;
    return go(a, 0, b, 0, c, 0);
}
