#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Stack
{
public:
    int * arr;
    int arr_size = 0;
    int pos1 = 0;
    int pos2 = 0;
public:
    Stack();
    int pop1();
    void push1(int data);
    int pop2();
    void push2(int data);
    bool isEmpty1();
    bool isEmpty2();
    bool isFull1();
    bool isFull2();
};

Stack::Stack()
{
    arr_size = 30;
    arr = (int *)malloc(30*sizeof(int));
    pos2 = arr_size - 1;
}

int Stack::pop1()
{
    if(arr_size == 0) return 2;
    else
    {
        pos1--;
        return arr[pos1];
    }
}

int Stack::pop2()
{
    if(arr_size == 0) return 2;
    else
    {
        pos2++;
        return arr[pos2];
    }
}

void Stack::push1(int data)
{
    arr[pos1] = data;
    pos1++;
}

void Stack::push2(int data)
{
    arr[pos2] = data;
    pos2--;
}

bool Stack::isEmpty1(){
    if(pos1 == 0){
        return true;
    } else {
        return false;
    }
}
bool Stack::isEmpty2(){
    if(pos2 == arr_size - 1){
        return true;
    } else {
        return false;
    }
}

bool Stack::isFull1(){
    if(pos1 - 1 == pos2)
        return true;
    else
        return false;

}

bool Stack::isFull2(){
    if(pos1 - 1 == pos2)
        return true;
    else
        return false;
}

int main()
{
    Stack s1;
    for(int i = 0; i < 20 ; i++)
    {
        s1.push1(i);

    }
    for(int i = 0; i < 10 ; i++)
    {
        s1.push2(i);
    }

    s1.pop1();

    cout<< "S1: " << s1.isFull1() << " S2: " << s1.isFull2() <<endl;


    return 0;
}
