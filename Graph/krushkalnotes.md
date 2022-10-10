## Notes for krushkal's algorithm 

>Used for finding minimum spanning tree 

    1. Sort all the edges  wrt edges(for that store all the edges alongwith weight in a linear data structure ) .

    2.Check if two nodes belong to same component (union find method is helpful here ) .

    3. If they do not belong to same component take them and connect them .

    4. Do not pick the nodes that belong to same component(similar parent) .


* Time Complexity :  O(m log m) + O(m*O(m alpha)) ~= O(mlog m)
* Space Complexity : O(m) + O(n) +O(n)  ~= O(n)




