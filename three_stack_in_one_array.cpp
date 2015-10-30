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
    int pos3 = 0;
    bool is_to_right = true;
public:
    Stack();
    int pop1();
    void push1(int data);
    int pop2();
    void push2(int data);
    int pop3();
    void push3(int data);
    bool isEmpty1();
    bool isEmpty2();
    bool isEmpty3();
    bool isFull1();
    bool isFull2();
    bool isFull3();
    int spaceBetween1and3();
    int spaceBetween2and3();
};

Stack::Stack()
{
    arr_size = 30;
    arr = (int *)malloc(30*sizeof(int));
    pos2 = arr_size - 1;
    pos3 = arr_size / 2;
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
int Stack::pop3()
{
    if(arr_size == 0) return 2;
    else
    {
        if(is_to_right)
            pos3--;
        else
            pos3++;
        return arr[pos3];
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
void Stack::push3(int data)
{
    arr[pos2] = data;
    if(is_to_right)
        pos3++;
    else
        pos3--;
}

bool Stack::isEmpty1()
{
    if(pos1 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Stack::isEmpty2()
{
    if(pos2 == arr_size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isEmpty3()
{
    if(pos3 == arr_size / 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull1()
{
    if(is_to_right)
    {
        if(pos1 == arr_size / 2)
        {
            return true;
        }
    }
    else
    {
        if(pos1 - 1 == pos3)
        {
            return true;
        }
    }
    return false;

}

bool Stack::isFull2()
{
    if(is_to_right)
    {
        if(pos3 - 1 == pos2)
            return true;
    }
    else
    {
        if(pos3 == arr_size / 2)
            return true;
    }
    return false;
}

bool Stack::isFull3()
{
    if(is_to_right)
    {
        if(pos3 - 1 == pos2)
            return true;
    }
    else
    {
        if(pos1 - 1 == pos3)
        {
            return true;
        }
    }
    return false;
}

int Stack::spaceBetween1and3(){
    if(is_to_right){
        return arr_size / 2 - pos1 + 1;
    }else{
        return pos3 - pos2 + 1;
    }
}

int Stack::spaceBetween2and3(){
    if(is_to_right){
        return pos2 - pos3 + 1;
    }else{
        return  pos2 - arr_size/2 + 1;
    }
}

int main()
{
    Stack s1;
    for(int i = 0; i < 10 ; i++)
    {
        s1.push2(i);

    }
    s1.push3(5);
    cout<<s1.spaceBetween2and3()<<endl;

    return 0;
}
