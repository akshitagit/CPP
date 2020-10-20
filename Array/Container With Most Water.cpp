/*
Given n non-negative integers a1, a2, ..., an , 
where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints
of the line i is at (i, ai) and (i, 0). Find two lines,
which, together with the x-axis forms a container,
such that the container contains the most water.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation:In this case, the max area of water the container can contain is 49.
*/

// Solution
// The aim is to maximize the area formed between the vertical lines. 
// The area of any container is calculated using the shorter line as length 
// and the distance between the lines as the width of the rectangle.
// Area = length of shorter vertical line * distance between lines
// We can definitely get the maximum width container as the outermost lines 
// have the maximum distance between them. However, this container might not
// be the maximum in size as one of the vertical lines of this container could be really short.
// Start with the maximum width container and go to a shorter width container 
// if there is a vertical line longer than the current containers shorter line. 
// This way we are compromising on the width but we are looking forward to a longer length container.

#include<bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int currentarea = 0;
    int left = 0,right = height.size()-1;
    while(left < right) {
        currentarea = max(currentarea, min(height[left],height[right])*(right - left));
        if(height[left] < height[right])
            left++;
        else
            right--;
    }
    return currentarea;
}

int main() {

    vector<int> height{1,8,6,2,5,4,8,3,7};

    cout << maxArea(height);

    return 0;
}