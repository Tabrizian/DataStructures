#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;
//Tag equals to 0, int, 1, link.
struct node
{
    short tag;
    union{
        int data;
        struct node* link_in;
    };
    struct node *link;
};

struct node* create_node(int data)
{
    struct node *result = (struct node *) malloc(sizeof(node));
    result->data = data;
    result->link = NULL;
    result->tag = 0;
    return result;
}

struct node* create_node(struct node* link_in)
{
    struct node *result = (struct node *) malloc(sizeof(node));
    result->link_in = link_in;
    result->link = NULL;
    result->tag = 1;
    return result;
}

void add_end(struct node * first, int data)
{
    struct node *current;
    for(current=first; current->link!=NULL; current=current->link);
    struct node *new_node = create_node(data);
    current->link = new_node;
}

void add_end(struct node * first, struct node* link_in)
{
    struct node *current;
    for(current=first; current->link!=NULL; current=current->link);
    struct node *new_node = create_node(link_in);
    current->link = new_node;
}

void print_list(struct node *first)
{
    struct node *current;
    cout << "[";
    for(current=first; current!=NULL; current=current->link)
    {
        if(current->tag == 0)
            cout<<current->data;
        if(current->link != NULL)
            cout<<", ";
        if(current->tag == 1)
            print_list(current->link_in);


    }
    cout << "]";
}

int list_size(struct node *first){
    int siz = 0;
    struct node* current;
    for(current=first; current!=NULL; current=current->link)
    {
        if(current->tag == 0)
            siz ++;
        if(current->tag == 1)
            siz += list_size(current->link_in);

    }
    return siz;
}
int list_depth(struct node *first){
    int depth = 0;
    struct node* current;
    for(current=first; current!=NULL; current=current->link)
    {
        if(current->tag == 1)
            depth = list_depth(current->link_in);

    }
    return depth + 1;
}
int find_max(int a,int b){
    if(a >= b)
        return a;
    else
        return b;
}
int max_path(struct node*first){
    struct node* current = first;
    int path = 0;
    if(current == NULL){
        return 0;
    }
    if(current->tag == 0)
            return max_path(first->link)+1;
    else
        return find_max(max_path(current->link_in),max_path(current->link));

}

//void add_front(struct node** first,int data)
//{
//    struct node* new_node = create_node(data);
//    new_node->link =*first;
//    *first = new_node;
//}
//
//void delete_end(struct node* first)
//{
//    struct node* current;
//    for(current = first; current->link->link!=NULL; current=current->link);
//    free(current->link);
//    current->link=NULL;
//}
//
//void delete_front(struct node** first)
//{
//    struct node* new_first = (*first)->link;
//    free(*first);
//    *first = new_first;
//}
//
//void insert_next_node(struct node* current_node,int data)
//{
//    struct node* new_node = create_node(data);
//    struct node* next = current_node->link;
//    current_node->link = new_node;
//    new_node->link = next;
//}

//void reverse_list(struct node** first)
//{
//    struct node* neighbs[3] = {NULL, NULL,*first};
//    while(neighbs[2])
//    {
//        neighbs[1] = neighbs[2];
//        neighbs[2]=neighbs[2]->link;
//        neighbs[1]->link = neighbs[0];
//        neighbs[0] = neighbs[1];
//
//    }
//
//    *first = neighbs[1];
//}
int main()
{
    struct node* first = create_node(50);
    add_end(first,60);
    add_end(first,70);
    add_end(first,80);
    add_end(first,90);
    add_end(first,100);
    add_end(first,70);
    struct node* second = create_node(20);
    add_end(second,70);
    add_end(second,80);
    add_end(second,90);
    add_end(second,12);
    add_end(second,23);
    add_end(first,second);
    add_end(first,90);
    add_end(first,100);
    add_end(first,70);
    cout<<max_path(first);
    return 0;
}
