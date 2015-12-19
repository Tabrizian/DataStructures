//
// Created by dell-iman on 12/19/2015.
//

#include <iostream>

#define MAX_SIZE 100
using namespace std;

class max_heap {
    int elements[MAX_SIZE];
    int last = 0;
public:
    void insert(int data);

    int find_max();
};
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void max_heap::insert(int data) {
    if(last == MAX_SIZE) return;
    if (last == 0) {
        elements[0] = data;
        last++;
    }
    else {
        bool added = false;
        int i = last;
        last++;
        while(!added) {
            if (elements[i / 2] >= data) {
                elements[i] = data;
                added = true;
            } else {
                elements[i] = data;
                swap(elements[i], elements[i / 2]);
                i = i / 2;
            }
        }
    }
}



int main() {
    max_heap heap;
    heap.insert(20);
    heap.insert(18);
    heap.insert(22);
    heap.insert(13);
    heap.insert(15);
    heap.insert(10);
    heap.insert(9);
    heap.insert(26);

    return 0;
}