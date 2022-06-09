#include <iostream>

struct node {
    int value;
    node* left;
    node* right;
};

node* create_node(int value) {
    node *tmp = new node();
    tmp->value = value;
    tmp->left = nullptr;
    tmp->right = nullptr;
    return tmp;
}

node* search(node *tree, int value) {
    if (tree->value > value && tree->left != nullptr)
        return search(tree->left, value);
    if (tree->value < value && tree->right != nullptr) 
        return search(tree->right, value);
    return tree;
}

void push(node *tree, int value) {
    node *p = search(tree, value);
    if (p->value < value)
        p->right = create_node(value);
    else 
        p->left = create_node(value);
}

void disp(node *tree, bool descending) {
    if (tree != nullptr) {
        node *pl = tree->left, *pr = tree->right;
        if (descending) {
            pl = tree->right;
            pr = tree->left;
        }
        if (pl != nullptr)
            disp(pl, descending);
        std::cout << tree->value << " ";
        if (pr != nullptr)
            disp(pr, descending);
    }
}

int main () {
    node tree = *create_node(8);
    int values[] = {9, 4, 7, 11, 5, 10, 6};
    for (int value: values)
        push(&tree, value);
    
    disp(&tree, true); 
    std::cout << std::endl;

    disp(&tree, false);
    std::cout << std::endl;

    return 0;
}
