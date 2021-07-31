//header files 
#include <bits/stdc++.h>
using namespace std;

//utility function to fill random elements in an array
void fillRandom(vector<int>&);

//class for maxHeap(INTERFACE)
class maxHeap{
//private members
private:
    //heap array
    vector<int> heap;
    //heapify function returnType-void
    void heapify();
    //sift up function returnType-void
    void siftUp();
    //sift down function returnType-void
    void siftDown(int);
//public data members
public:
    //constructor returnType - None
    maxHeap(vector<int>);
    //insert function returnType-void
    void insert(int);
    //remove function returnType-Int
    int remove();
    //function to get top element in the heap returnType-Int
    int getTop();
    //function to print heap returnType-void
    void printHeap();
};

//main function
int main(){
    //general array
    vector<int> array;
    //fill random elements in the array
    fillRandom(array);
    //create a heap object with the filled array
    maxHeap* heap = new maxHeap(array);
    
    //observe the actions done
    
    // heap->insert(33);
    // heap->remove();
    // cout<<heap->getTop<<endl;
    
    //end of the program
    return 0;
}

//constructor
maxHeap::maxHeap(vector<int> array){
    //assign the heap array member of the class with filled array
    heap = array;
    
    printHeap();
    
    //call the heapify method
    heapify();
    
    printHeap();
}

//heapify method
//generally changes the original skewed array to an array with heap property
void maxHeap::heapify(){
    //observe the last child (definitely exists)
    int last_parent = heap.size()-2;
    //get the parent of the child
    last_parent /= 2;
    
    //iterate over the parents to the top parent and call siftdown on parents
    for(int node = last_parent ; node >= 0 ; node--){
        siftDown(node);
    }
}

//insert function
void maxHeap::insert(int num){
    cout<<"Inserting -- "<<num<<endl;
    
    //push into the heap
    heap.push_back(num);
    //sift up on the last element
    siftUp();
    
    return;
}

//remove function
int maxHeap::remove(){
    cout<<"Removing -- "<<endl;
    //get the first element
    int removed_num = heap[0];
    //swap with the last element
    swap(heap[0],heap[heap.size()-1]);
    //remove the last element
    heap.pop_back();
    //sift down from the root
    siftDown(0);

    return removed_num;
}

//printheap function
void maxHeap::printHeap(){
    //range based for loop to print nums in heap
    for(auto num : heap){
        cout<<num<<" ";
    }
    cout<<endl;
}

//getTop function
int maxHeap::getTop(){
    //if heap exists, return first element
    if(this->heap.size())
    return this->heap[0];
    //return the possible minimum element
    return INT_MIN;
}

//siftUp function
//     5     insertion        4     sift up             10
//    /    ----------->      / \   ------------>       /  \ 
//   4                      5   10                    5    4
// the idea is on insert, we just want to sift up the last element (heap property holds)

void maxHeap::siftUp(){
    //get the position of last element
    int last_element = heap.size()-1;
    int parent_index;
    
    //while thr position is valid
    while(last_element > 0){
        //find the parent element
        parent_index = last_element/2;
        //if the heap property doesn't hold
        //swap the elements such that heap property holds and continue iterating
        if(heap[parent_index] < heap[last_element]){
            swap(heap[parent_index],heap[last_element]);
            last_element = parent_index;
        //else break the loop and return
        } else break;
    }
    
    return;
}

//siftDown function
//     5    deletion(remove)         1         sift down             4
//    / \   --------------->        /      ----------------->       /
//   4   1                         4                               1
//the idea is to siftdown an element to bottom such that property holds
void maxHeap::siftDown(int index){
    //given the index, get the children of the parent index
    int child_one = index*2+1;
    int child_two = index*2+2;
    int node_to_be_swapped = -1;
    
    //while children are valid(children exists)
    while(child_one < this->heap.size()){
        node_to_be_swapped = -1;
        //we can't say if second child exists based on first child, so conducting a check
        if(index*2+2 < this->heap.size()) child_two = index*2+2;
        else child_two = -1;
        
        //determining the node to be swapped
        //if child two exists and child two is smaller than child one, then node to be swapped is child two
        if(child_two != -1){
            //condition to hold the heap property
            if(heap[child_one] < heap[child_two]) node_to_be_swapped = child_two;
            else node_to_be_swapped = child_one;
        //else node to be swapped becomes child one itself
        } else node_to_be_swapped = child_one;
        
        //if it violates heap property, swap and update the index
        if(heap[node_to_be_swapped] > heap[index]){
            swap(heap[node_to_be_swapped],heap[index]);
            index = node_to_be_swapped;
            child_one = 2*index+1;
        } else child_one = heap.size();
    }
    
    return;
}

//function which fills the array with random elements
void fillRandom(vector<int>& array){
    //time entity seeded to NULL, to get random elements every time
    srand(time(NULL));
    
    //fill the array with random elements
    for(int i = 0 ; i < 10 ; i++){
        array.push_back(1+rand()%100);
    }
}