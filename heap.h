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
        if (size == 0) {
            weightArr[0] = idx;
            size++;
            return;
        }
        if (!weightArr[2*size + 1]) {
            weightArr[2*size + 1] = idx;
            size++;
            return;
        }
        if (!weightArr[2*size + 2]) {
            weightArr[2*size + 2] = idx;
            size++;
        }
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) {
            cout << "Empty Heap.\n" << endl;
            return -1;
        }
        return -1; //placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        if (size == 0) {
            cout << "Empty Heap.\n" << endl;
            return;
        }
        while (pos > 0) {
            if (weightArr[pos] < weightArr[(pos - 1)/2]) {
                int tmp = weightArr[pos];
                weightArr[pos] = weightArr[(pos - 1)/2];
                weightArr[(pos - 1)/2] = tmp;
            }
            //recursive call with the parent node.
            upheap((pos - 1)/2, weightArr);
        }

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        if (size == 0) {
            cout << "Empty Heap.\n" << endl;
            return;
        }
        while (pos < size) {
            if (weightArr[pos] > weightArr[2*pos + 1] && weightArr[pos] > weightArr[2*pos + 2]) {
                int tmp = weightArr[pos];
                weightArr[pos] = weightArr[2*pos + 1];
                weightArr[2*pos + 1] = tmp;

            }
            if (weightArr[pos] > weightArr[2*pos + 2]) {
                int tmp = weightArr[pos];
                weightArr[pos] = weightArr[2*pos + 2];
                weightArr[2*pos + 2] = tmp;

            }
        }
    }
};

#endif