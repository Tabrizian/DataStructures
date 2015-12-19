#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <conio.h>
#include <queue>
#include <stack>

using namespace std;

struct node {
    struct node *lp;
    struct node *rp;
    char data;
};

struct node *create_node(char data) {
    struct node *new_node = (struct node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->rp = NULL;
    new_node->lp = NULL;
    return new_node;
}

struct node *add_left(char data, struct node *parent) {
    struct node *new_node = create_node(data);
    parent->lp = new_node;
}

struct node *add_right(char data, struct node *parent) {
    struct node *new_node = create_node(data);
    parent->rp = new_node;
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

void post_order(struct node *root) {
    if (root == NULL) return;
    post_order(root->lp);
    post_order(root->rp);
    cout << root->data << " ";

}

void reverse_bst(struct node *root) {
    if (root == NULL) return;
    else {
        swap(root->rp, root->lp);
        reverse_bst(root->rp);
        reverse_bst(root->lp);
    }
}

int single_child(struct node *root) {
    if (root == NULL) return 0;
    else if (root->rp != NULL ^ root->lp != NULL) return single_child(root->rp) + single_child(root->lp) + 1;
    else return single_child(root->rp) + single_child(root->lp);
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

void post_order_non_recursive(struct node *root) {
    stack<struct node *> currents;
    currents.push(root);
    bool visited[] = {false, false, false};
    while (!currents.empty()) {
        if (currents.top()->lp != NULL && !visited[0]) {
            cout << "Left :" << currents.top()->data << endl;
            currents.push(currents.top()->lp);

        } else if (currents.top()->rp != NULL && !visited[1]) {
            cout << "Right :" << currents.top()->data << endl;
            currents.push(currents.top()->rp);
        } else {
            cout << currents.top()->data << " ";
            struct node *temp = currents.top();
            currents.pop();
            if (!currents.empty()) {
                if (currents.top()->lp == temp) {
                    cout << "Right is visited! " << endl;
                    visited[0] = true;
                }
                else if (currents.top()->rp == temp) {
                    visited[1] = true;
                    cout << "Left is visited! " << endl;
                } else {
                    cout << "?????? " << endl;
                    visited[0] = false;
                    visited[1] = false;
                }
            }

        }
    }
    cout << endl;
}

int depth(struct node *root) {
    if (root == NULL) return 0;
    else
        return max(depth(root->lp), depth(root->rp)) + 1;
}

queue<struct node *> saff;

void print_tree(struct node *root) {
    if (root == NULL) return;
    if (root->lp != NULL) saff.push(root->lp);
    if (root->rp != NULL) saff.push(root->rp);

    cout << root->data << endl;
    if (!saff.empty()) {
        struct node *keep = saff.front();
        saff.pop();
        print_tree(keep);
    }
    else
        print_tree(NULL);

}

struct node *same_grandpa(struct node *x, struct node *y, struct node *root) {

}



int sum(struct node *root) {
    if (root == NULL) return 0;
    else return sum(root->rp) + sum(root->lp) + root->data;
}

int size(struct node *root) {
    if (root == NULL) return 0;
    else return size(root->lp) + size(root->rp) + 1;
}

int num_leaves(struct node *root) {
    if (root == NULL) return 0;
    if (root->rp == NULL && root->lp == NULL) return 1;
    else return num_leaves(root->rp) + num_leaves(root->lp);
}


int main() {
    struct node *root = create_node('F');
    add_left('D', root);
    add_left('G', root->lp);
    add_left('B', root->lp->lp);
    add_right('K', root);
    add_right('L', root->rp);
    add_right('A', root->lp);
    add_left('C', root->lp->rp);
    add_right('E', root->lp->lp);
    add_left('I', root->rp);
    cout << num_leaves(root);
    return 0;
}
