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
    result->link = NULL;
    return result;
}

int main()
{
    struct node* first_y = create_node(10);
    struct node* first_x = create_node(15);
    print_list(merge_lists(first_y,first_x));
    return 0;
}
