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
        while (pos > 0 && weightArr[data[pos]] > weightArr[data[(pos/2)+1]]) {
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

        int smallest = 2*pos + 1;
        while (smallest < size) {

            int right = 2*pos+2;

            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }

            if (weightArr[data[pos]] <= weightArr[data[smallest]])
                break;
            int tmp = data[pos];
            data[pos] = data[smallest];
            data[smallest] = tmp;
            pos = smallest;
        }
    }
};

#endif