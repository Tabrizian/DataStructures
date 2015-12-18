#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node* link;
    node(int data);
};
node::node(int data){
    this->data = data;
    this->link = NULL;

}
class linked_list
{
public:
    node* first;
public:
    linked_list(int data);
    int size_of();
    int size_of(node* first_n);
    void add_end(int data);
    void print_list();

};
int linked_list::size_of(){
    return size_of(first);
}
int linked_list::size_of(node* first_n){
    if(first_n == NULL)
        return 0;
    else
        return (size_of(first_n->link) + 1);
}
void linked_list::add_end(int data)
{
    node *current;
    for(current=first; current->link!=NULL; current=current->link);
    node* new_node = new node(data);
    current->link = new_node;
}
linked_list::linked_list(int data)
{
    node* new_node = new node(data);
    first = new_node;
}
void linked_list::print_list()
{
    node *current;
    for(current=first; current!=NULL; current=current->link)
    {
        cout<<current->data<<endl;
    }
}

//int main()
//{
//    linked_list li(2);
//    li.print_list();
//    return 0;
//}
