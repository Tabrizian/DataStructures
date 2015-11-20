#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct node{
    struct node * lp;
    struct node * rp;
    int data;
};

struct node* create_node(int data){
    struct node * new_node = (struct node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->rp = NULL;
    new_node->lp = NULL;
    return new_node;
}
struct node* add_left(int data,struct node* parent){
    struct node * new_node = create_node(data);
    parent->lp = new_node;
}

struct node* add_right(int data,struct node* parent){
    struct node * new_node = create_node(data);
    parent->rp = new_node;
}

void pre_order(struct node* root){
    if(root == NULL) return;
    cout<<root->data<<endl;
    pre_order(root->lp);
    pre_order(root->rp);
}

void in_order(struct node* root){
    if(root == NULL) return;
    in_order(root->lp);
    cout<<root->data<<endl;
    in_order(root->rp);
}

void post_order(struct node* root){
    if(root == NULL) return;
    post_order(root->lp);
    post_order(root->rp);
    cout<<root->data<<endl;
}

int what(int x){
    return x;
}
queue<struct node*> saff;
void print_tree(struct node* root){
    if(root == NULL) return;
    if(root->lp != NULL) saff.push(root->lp);
    if(root->rp != NULL) saff.push(root->rp);

    cout<<root->data<<endl;
    if(!saff.empty()){
        struct node* keep = saff.front();
        saff.pop();
        print_tree(keep);
    }
    else
        print_tree(NULL);

}

int main(){
    struct node* root = create_node(10);

    add_left(20,root);
    add_left(30,root->lp);
    add_right(40,root);
    add_right(50,root->rp);

    print_tree(root);

    return 0;
}
