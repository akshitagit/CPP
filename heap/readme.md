# Heaps

```
Basic:
Heaps are the data structures which gives us the more prioritised element in constant time with logarithmic insert complexity.

Time Complexity: 
to insert n elements -> O(n*log(n)) 
to get top priority element -> O(1)
to remove n elements -> O(n*log(n))
```

## 1. Max Heap (Larger the element, higher the priority)
## 2. Min Heap (Least the element, more the priority)
## 3. Max and Min Heaps using STL

## Class Interface in maxHeap and minHeap
```cpp
    class Heap{
        private:
            vector<int> heap;
            void heapify();
            void siftUp();
            void siftDown();
        public:
            Heap();
            void insert(int);
            int remove();
            int getTop();
            void printHeap();
    };
```

* Feel free to alter code while learning this data structure.
* Use printHeap() function, wherever you want to make debugging easier.

## STL methods
```cpp
    some basic methods:
    push() -> pushes element into heap
    pop()  -> removes top prioritised element from heap
    empty() -> gives a boolean true if heap is empty
    size() -> gives you the size of heap
    top()  -> gives you the top element aka element with more priority
```
* These are accessed using ```' . '``` property.