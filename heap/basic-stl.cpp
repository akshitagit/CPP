#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> array{-1,1,-2,2,-3,3,-4,4,0};
    
    //by default it uses maxheap condition
    priority_queue<int> maxHeap;
    
    //method1: push
    for(auto num : array){
        maxHeap.push(num);
    }
        
    //method2: constructor
    priority_queue<int> maxHeap2{array.begin(),array.end()};
    
    
    //minHeap using std::greater
    priority_queue<int,vector<int>,greater<int>> minHeap;
    //follows same methods of pushing
    
    //pop
    maxHeap.pop();
    
    //top
    int top_element = maxHeap.top();
    
    //empty
    bool isEmpty = maxHeap.empty();
    
    //size
    int size = maxHeap.size();
}