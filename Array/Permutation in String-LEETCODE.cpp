/* Problem no 567 from arrays
Solution in Cpp */

Concise C++ Sliding Window solution, beats 95%
25
VIEWS
0
Last Edit: September 25, 2020 11:15 AM

tguo40
tguo40
 10
Always maintain a sliding window of length s1.length().
num = no. of distinct char in s1, --num occurs only when the counter for a char goes to 0.

bool checkInclusion(string s1, string s2) {
    int count[26] {0};
    int num = 0;
    for (char c : s1) { 
	    if (count[c-'a']++ == 0) ++num; 
    }
        
    int begin = 0, end = 0;
    while (end < s2.length()) {
        if (end - begin + 1 < s1.length()) {
            if (--count[s2[end++]-'a'] == 0) --num;
        }
        else { // Always maintain a window of size s1.length()
            if (--count[s2[end]-'a'] == 0) --num;
            if (num == 0) return true;
            else if (count[s2[begin++]-'a']++ == 0) ++num;
            ++end;
        }
    }
   
	return false;
}
