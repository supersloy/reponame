#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct linked_list {
    node *head;
    node *tail;
    int size;
} linked_list;

linked_list create_empty_list() {
    linked_list list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    return list;
}

node create_node(int value) {
    node temp_node;
    temp_node.data = value;
    temp_node.next = NULL;
    return temp_node;
}

void free_list(linked_list* list)
{
    free(list->head);
    free(list->tail);
    free(list);
}

void free_node(node *pNode)
{
    free(pNode->next);
    free(pNode);
}

void print_list(linked_list list) {
    node *processing_node = list.head;
    printf("List elements: ");
    for (int i = 0; i < list.size; ++i) {
        printf("%d ", processing_node->data);
        processing_node = processing_node->next;
    }
    printf("\n");
}

/**
 * Inserts node in a list after other node.
 * If other node is NULL then inserts node in start of the list.
 * @param list of nodes .
 * @param insertion_node node to be inserted.
 * @param pre_node node that will be before inserted node.
 */
void insert_node(linked_list *list, node *insertion_node, node *pre_node) {
    //Error things
    if (insertion_node == NULL) {
        printf("There is a call of function insert_node to insert NULL object instead of node.");
        printf("That call ignored");
        return;
    }
    if (list == NULL) {
        printf("There is a call of function insert_node, but list points on NULL.");
        printf("That call ignored");
        return;
    }
    //\Error things
    //If previous node points on NULL then insertion node will be inserted in start of the list.
    if (pre_node == NULL) {
        insertion_node->next = list->head;
        list->head = insertion_node;
        if (list->tail == NULL) {
            list->tail = insertion_node;
        }
    } else {
        if (pre_node == list->tail)
            list->tail = insertion_node;
        insertion_node->next = pre_node->next;
        pre_node->next = insertion_node;
    }
    list->size++;
}

/**
 * Delete node in a list.
 * Does not free the memory of node.
 * If node is NULL then method do nothing.
 * @param list of nodes.
 * @param deletion_node to be deleted in list.
 */
void delete_node(linked_list *list, node *deletion_node) {
    //Error thing
    if (list == NULL) {
        printf("There is a call of function delete_node, but list points on NULL.");
        printf("That call ignored");
        return;
    }

    if (deletion_node == NULL)
        return;

    //Check whether head of the list is the deletion node
    if (deletion_node == list->head) {
        list->head = list->head->next;
        if (list->head == NULL)
            list->tail = NULL;
    } else {
        //Find previous node.
        node *pre_node = list->head;
        while (pre_node->next != deletion_node && pre_node->next != NULL)
            pre_node = pre_node->next;
        //Error thing
        if (pre_node->next == NULL) {
            printf("There is attempt to delete node that does not exist in list via delete_node_in_list method call.");
            printf("That call ignored");
            return;
        }
        pre_node->next=deletion_node->next;
        if(list->tail==deletion_node)
            list->tail=pre_node;
    }
    list->size--;
}

int main() {
    linked_list list = create_empty_list();

    node node1 = create_node(1);
    node node2 = create_node(2);
    node node3 = create_node(3);
    node node4 = create_node(4);

    print_list(list);
    insert_node(&list, &node1, NULL);   //insert node 1 in the list
    print_list(list);
    insert_node(&list, &node2, &node1); //insert node 2 after node 1
    print_list(list);
    insert_node(&list, &node3, &node1); //insert node 3 after node 1
    print_list(list);
    insert_node(&list, &node4, &node3); //insert node 3 after node 1
    print_list(list);

    delete_node(&list, &node3);         //delete 3 node
    print_list(list);
    delete_node(&list, &node1);         //delete 1 node
    print_list(list);
    delete_node(&list, &node2);         //delete 2 node
    print_list(list);
    delete_node(&list, &node4);         //delete 4 node
    print_list(list);

    return 0;
}

