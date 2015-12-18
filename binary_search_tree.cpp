//
// Created by dell-iman on 12/18/2015.
//

#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct node {
    struct node *lp;
    struct node *rp;
    int data;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->rp = NULL;
    new_node->lp = NULL;
    return new_node;
}

struct node *add_left(int data, struct node *parent) {
    struct node *new_node = create_node(data);
    parent->lp = new_node;
    return new_node;
}

struct node *add_right(int data, struct node *parent) {
    struct node *new_node = create_node(data);
    parent->rp = new_node;
    return new_node;
}

struct node *search(int data, struct node *root) {
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;
    else if (root->data < data)
        return search(data, root->rp);
    else
        return search(data, root->lp);
}

bool insert(struct node *root, int data) {

}

int sum(struct node *root) {
    if (root == NULL) return 0;
    else return sum(root->rp) + sum(root->lp) + root->data;
}

int size(struct node *root) {
    if (root == NULL) return 0;
    else return size(root->lp) + size(root->rp) + 1;
}

int depth(struct node *root) {
    if (root == NULL) return 0;
    else
        return max(depth(root->lp), depth(root->rp)) + 1;
}

void pre_order(struct node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    pre_order(root->lp);
    pre_order(root->rp);
}

void in_order(struct node *root) {
    if (root == NULL) return;
    in_order(root->lp);
    cout << root->data << " ";
    in_order(root->rp);
}

int i = 0;

void post_order(struct node *root) {
    i++;
    if (root == NULL) return;
    post_order(root->lp);
    post_order(root->rp);
    cout << root->data << " ";

}

void level_order(struct node *root) {
    static queue<struct node *> currents;
    struct node *current_node = root;
    while (current_node) {
        cout << current_node->data << " ";
        if (current_node->lp != NULL) currents.push(current_node->lp);
        if (current_node->rp != NULL) currents.push(current_node->rp);
        current_node = currents.front();
        currents.pop();
    }
}

int main() {
    struct node *root = create_node(50);
    add_right(70, root);
    add_left(25, root);
    add_right(30, root->lp);
    add_left(13, root->lp);
    add_left(60, root->rp);
//    struct node *ans = search(25, root);
//    if (ans == NULL)
//        cout << "Not Found!" << endl;
//    else
//        cout << ans->data;
    in_order(root);
    return 0;
}
