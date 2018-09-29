#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;

class heap
{
    int size = 0;
    int capacity = 10;
    int *items = new int[capacity];

private:
    int getLeftChildIndex(int index) { return index*2 + 1 ; }
    int getRightChildIndex(int index) { return index*2 + 2 ; }
    int getParentIndex(int index) { return (index-1)/2 ; }

    bool hasLeftChildIndex(int index) { return index*2 + 1 < size ; }
    bool hasRightChildIndex(int index) { return index*2 + 2 < size ; }
    bool hasParentIndex(int index) { return (index-1)/2 < size ; }

    int LeftChild(int index) { return items[getLeftChildIndex(index)] ; }
    int RightChild(int index) { return items[getRightChildIndex(index)] ; }
    int Parent(int index) { return items[getParentIndex(index)] ; }

    void swap( int index1, int index2 ) {
        int temp = items[index2];
        items[index2] = items[index1];
        items[index1] = temp;
    };

    void ensureCapacity() {
        if(size == capacity) {
            int *newArr = new int[capacity*2];
            for(int i=0; i< size; i++) {
                newArr[i] = items[i];
            }
            delete [] items;
            *items = *newArr;
        }
    }

    
public:
    void show() {
        for(int i=0; i< size; i++) {
            cout<<items[i]<<' '<<endl;
        }
    }
    int peek() {
        return items[0];
    }
    int poll() {
        int item = items[0];
        items[0] = items[size-1];
        size--;
        heapifyDown();
        return item;
    }
    void add(int item) {
        ensureCapacity();
        items[size] = item;
        size++;
        heapifyUp();
    }
    void heapifyUp() {
        int index = size;
        while(hasParentIndex(index) && items[index] > Parent(index)) {
            swap(index, getParentIndex(index));
            index = getParentIndex(index);
        }
    }
    void heapifyDown();
};

void heap::heapifyDown() {
    int index = 0;
    while(hasLeftChildIndex(index)) {
        int smallerChildIndex = getLeftChildIndex(index);
        if(hasRightChildIndex(index) && RightChild(index) < LeftChild(index)) {
            smallerChildIndex = getRightChildIndex(index);
        }
        if(items[index] < items[smallerChildIndex]) {
            break;
        }
        else {
            swap(smallerChildIndex, index);
        }
        index = smallerChildIndex;
    }
}

int main() {
    heap h;
    auto start = high_resolution_clock::now();
    h.add(2);
    h.add(5);
    h.add(3);
    h.poll();
    h.add(9);
    h.add(12);
    h.show();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nTime taken:: "<< duration.count()<<"\n"; 
    return 0;
}
