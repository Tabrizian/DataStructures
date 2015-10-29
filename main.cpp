#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *fp;
    struct node *bp;
};

struct node* create_node(int data)
{
    struct node *result = (struct node *) malloc(sizeof(node));
    result->data = data;
    result->fp = NULL;
    result->fp = NULL;
    return result;
}


int main()
{
    struct node* first_x = create_node(10);
    print_list(merge_lists(first_y,first_x));
    return 0;
}
