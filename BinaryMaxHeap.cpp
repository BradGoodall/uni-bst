#include "BinaryMaxHeap.h"

int BinaryMaxHeap::leftChildIndex(int parent)
{
    int leftIndex = 2 * parent + 1;
    if (leftIndex < heap.size())
        return leftIndex;
    else
        return -1;
}

int BinaryMaxHeap::rightChildIndex(int parent)
{
    int rightIndex = 2 * parent + 2;
    if (rightIndex < heap.size())
        return rightIndex;
    else
        return -1;
}

int BinaryMaxHeap::parentIndex(int child)
{
    int parent = (child - 1) / 2; //Uses integer division (ignores decimal)
    if (child == 0)
        return -1;
    else
        return parent;
}

//After inserting, we heapify up from where the new inserted element ended up
//Compares current node to parent and swaps the larger node to the top
//Recursive Function - Each swap we call heapifyUp on the higher level where we swapped value
void BinaryMaxHeap::heapifyUp(int index)
{
    //IF index is not the root (top of the tree)
    //AND parent index is within heap bounds (not negative)
    //AND current nodes salary > parent nodes salary
    if (index >= 0 && parentIndex(index) >= 0 && heap[index]->salary > heap[parentIndex(index)]->salary)
    {
        //If so, swap values between current node and parent
        Employee* temp = heap[index];
        heap[index] = heap[parentIndex(index)];
        heap[parentIndex(index)] = temp;
        //Since we swapped, lets run heapifyUp again recursively on the parent from here
        heapifyUp(parentIndex(index));
    }
}

//Down is less efficient to up because we have to compare both children first before moving down
//Usually called when destroyed root of tree
//Recursive Function - Keeps calling itself as it swaps down the tree
void BinaryMaxHeap::heapifyDown(int index)
{
    //Get left and right children indexes
    int childL = leftChildIndex(index);
    int childR = rightChildIndex(index);
    //Child variable representing path we'll compare down
    int childIndex = childL;
    //IF childL is not -1 AND childR is not -1
    //AND right childs salary is larger than lefts
    if (childL >= 0 && childR >= 0 && heap[childR]->salary > heap[childL]->salary)
    {
        //make right child index the focus instead of left
        childIndex = childR;
    }

    //IF child index is not the root node and is not -1
    //AND current node's salary is less than child node's
    if (childIndex > 0 && heap[index]->salary < heap[childIndex]->salary)
    {
        //We should swap current with child, because we want larger ones closer to the top
        Employee* temp = heap[index];
        heap[index] = heap[childIndex];
        heap[childIndex] = temp;
        //Recurse further down
        heapifyDown(childIndex);
    }
}

//Inserts at the lowest next free spot in the tree, this keeps things balanced
void BinaryMaxHeap::insert(Employee* element)
{
    heap.push_back(element);
    heapifyUp(heap.size() - 1);
}

void BinaryMaxHeap::deleteMax()
{
    //Can't delete if heap is empty
    if (heap.size() == 0)
    {
        cout << "Heap empty!" << endl;
        return;
    }
    //Copy value in last element into root
    heap[0] = heap[heap.size() - 1];
    //Delete last element
    heap.pop_back();
    //Then heapifyDown starting from root (index 0)
    heapifyDown(0);
}

//Get root eployee node from heap tree structure (or first element in our vector)
Employee* BinaryMaxHeap::extractMax()
{
    //If heap empty, no employee to return
    if (heap.size() == 0)
        return NULL;
    else
        return heap.front();
}

void BinaryMaxHeap::showHeap()
{
    cout << "Heap -->";
    for (Employee* e : heap)
    {
        cout << "[" << e->salary << " " << e->name << "] ";
    }
    cout << endl;
}

int BinaryMaxHeap::size()
{
    return heap.size();
}
