#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Stack
{
    int * arr;
    int arr_size = 0;
    int pos = 0;
public:
    Stack();
    int pop();
    void push(int data);
};

Stack::Stack(){
    arr_size = 10;
    arr = (int *)malloc(10*sizeof(int));
}

int Stack::pop()
{
    if(arr_size == 0) return 2;
    else
    {
        pos--;
        return arr[pos];
    }
}

void Stack::push(int data)
{
    if(arr_size == pos )
    {
        arr = (int *) realloc(arr,(arr_size + 10)*sizeof(int));
        arr_size = arr_size + 10;
    }
    arr[pos] = data;
    pos++;
}

int main()
{
    Stack s1;
    for(int i = 0; i < 20 ; i++)
    {
        s1.push(i);
    }

    for(int i = 0; i < 20 ; i++)
    {
        cout<<s1.pop()<<endl;
    }

    return 0;
}
