#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename T>
struct link_list_node {
    link_list_node *next;
    T key;
};

template <typename T>
bool add_node(link_list_node<T> **head, link_list_node<T> *node)
{
    if (!head) {
        cerr << "Null pointer of head" << endl;
        return false;
    }

    if (!node) {
        cerr << "Null pointer of node" << endl;
        return false;
    }

    cout << "add node: " << node->key << " " << static_cast<void *>(node) << endl;

    if (!(*head)) {
        *head = node;
    } else {
        link_list_node<T> *next_node = *head;
        while (next_node->next) {
            next_node = next_node->next;
        }

        next_node->next = node;
    }

    // cout << "head: " << (*head)->key << " " << static_cast<void *>(*head) << endl;
    return true;
}

template <typename T>
void print_list(const link_list_node<T> *head)
{
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }

    const link_list_node<T> *node = head;
    while (node) {
        cout << node->key << " " << static_cast<const void *> (node) << endl;
        node = node->next;
    }
    cout << endl;
}

template <typename T>
bool delete_node(link_list_node<T> **head, T key)
{
    cout << "Delete key: " << key << endl;
    if (!head) {
        cerr << "Null pointer of head" << endl;
        return false;
    }

    if ((*head)->key == key) {
       link_list_node<T> *node = *head;
       *head = node->next;
       delete node;
       return true;
    }

    link_list_node<T> *next_node = *head;

    while (next_node->next) {
        if (next_node->next->key == key) {
            link_list_node<T> *node = next_node->next;
            next_node->next = node->next;
            delete node;
            return true;
        }

        next_node = next_node->next;
    }

    return false;
}

template <typename T>
void clear_list(link_list_node<T> **head)
{
    cout << "Clear list" << endl;
    while (*head) {
       link_list_node<T> *node = *head;
       *head = (*head)->next;
       delete node;
    }
}

int main()
{
    link_list_node<int> *head = NULL;

    for (int i = 3; i < 10; ++i) {
        auto *node = new link_list_node<int>();
        node->key = i;
        node->next = nullptr;

        add_node(&head, node);
    }

    print_list(head);

    delete_node(&head, 3);
    print_list(head);

    delete_node(&head, 6);
    print_list(head);

    delete_node(&head, 9);
    print_list(head);

    clear_list(&head);
    print_list(head);
}