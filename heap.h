//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;

    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) {
            cout << "Empty Heap.\n" << endl;
            return -1;
        }
        int smallestIndex = data[0];
        data[0] = data[size-1];
        size--;
        downheap(0, weightArr);
        return smallestIndex;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0 && weightArr[data[pos]] < weightArr[data[(pos-1)/2]]) {
            //swap child and parent
            int tmp = data[pos];
            data[pos] = data[(pos - 1)/2];
            data[(pos - 1)/2] = tmp;
            //set pos to parent index
            pos = (pos - 1) / 2;
        }

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        //looping while parent is still internal node
        while (2*pos+1 < size ) {
            int left = 2*pos+1;
            int right = 2*pos+2;
            int smallestIndex = left;

            if (right < size && weightArr[data[right]] < weightArr[data[left]]) {
                smallestIndex = right;
            }

            if (weightArr[data[pos]] <= weightArr[data[smallestIndex]]) {
                break;
            }
            int tmp = data[pos];
            data[pos] = data[smallestIndex];
            data[smallestIndex] = tmp;
            pos = smallestIndex;
        }

    }
};

#endif