#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *link;
};

struct node* create_node(int data)
{
    struct node *result = (struct node *) malloc(sizeof(node));
    result->data = data;
    result->link = NULL;
    return result;
}

void add_end(struct node * first, int data)
{
    struct node *current;
    for(current=first; current->link!=NULL; current=current->link);
    struct node *new_node = create_node(data);
    current->link = new_node;
}

void print_list(struct node *first)
{
    struct node *current;
    for(current=first; current!=NULL; current=current->link)
    {
        cout<<current->data<<endl;
    }
}

void add_front(struct node** first,int data)
{
    struct node* new_node = create_node(data);
    new_node->link =*first;
    *first = new_node;
}

void delete_end(struct node* first)
{
    struct node* current;
    for(current = first; current->link->link!=NULL; current=current->link);
    free(current->link);
    current->link=NULL;
}

void delete_front(struct node** first)
{
    struct node* new_first = (*first)->link;
    free(*first);
    *first = new_first;
}

void insert_next_node(struct node* current_node,int data)
{
    struct node* new_node = create_node(data);
    struct node* next = current_node->link;
    current_node->link = new_node;
    new_node->link = next;
}
void reverse_list(struct node** first)
{
    struct node* neighbs[3] = {NULL, NULL,*first};
    while(neighbs[2])
    {
        neighbs[1] = neighbs[2];
        neighbs[2]=neighbs[2]->link;
        neighbs[1]->link = neighbs[0];
        neighbs[0] = neighbs[1];

    }

    *first = neighbs[1];
}
void remove_item(struct node** first,int data)
{
    struct node* current = *first;
    if(current->data == data)
    {
        delete_front(first);
        current = *first;
    }
    for(current; current->link!=NULL; current=current->link)
    {
        if(current->link->data == data)
        {
            struct node *next = current->link->link;
            free(current->link);
            current->link = next;
            if(current->link == NULL)
                return;
        }

    }

}

struct node* merge_lists(struct node *first_x,struct node *first_y)
{
    if(first_x == NULL) return first_y;
    if(first_y == NULL) return first_x;
    struct node* result;
    if(first_x->data >= first_y->data)
        result = first_y;
    else
        result = first_x;
    struct node * temp = NULL;
    while(first_x!=NULL && first_y!=NULL)
    {
        /*cout<<first_x->data<<" "<<first_y->data;
        if(temp==NULL)
            cout<<" "<<"NULL"<<endl;
        else
            cout<<" "<<temp->data<<endl;
        */
        for(;first_x->link&&first_x->link->data<first_y->data;first_x=first_x->link);
        for(;first_y->link&&first_y->link->data<first_x->data;first_y=first_y->link);
        if(first_x->data>=first_y->data)
        {
            temp = first_y;
            first_y = first_y->link;
            temp->link=first_x;
        }
        else
        {
            temp = first_x;
            first_x = first_x->link;
            temp->link = first_y;
        }
    }

    return result;

}
int main()
{
    struct node* first_y = create_node(10);
    add_end(first_y,18);
    add_end(first_y,80);
    add_end(first_y,90);
    add_end(first_y,180);
    add_end(first_y,190);
    struct node* first_x = create_node(15);
    add_end(first_x,16);
    add_end(first_x,40);
    print_list(merge_lists(first_y,first_x));
    return 0;
}
