// stackproblem.c – Lab 02 – Alexandra, Cramarossa

#include <stdio.h>
#include <stdlib.h>
#define max_input 80

struct node {
    struct node *next;
    char val;
};
typedef struct node node_1, *p_node;

//Makes nodes with specified value
p_node make_node(char value) {
    p_node node_new = (p_node) malloc(sizeof(node_1));
    node_new->next = NULL;
    node_new->val = value;
    return node_new;
}

//Adds value to stack entered by user
void add_stack(p_node *head, char value) {
    //See if stack is empty
    if (*head == NULL) {
        *head = make_node(value);
    } else {
        //Else statement if stack is not empty
        p_node New_Node = make_node(value);
        New_Node->next = *head;
        *head = New_Node;
    }
}

//Gets an array from user of up to 80 numbers
int main() {
    char user_input[max_input];
    p_node head = NULL;
    for (int i = 0; i < max_input; i++) {
        scanf("%c", &user_input[i]);
        if (user_input[i] == '\n') {
            break;
        }
        else {
            add_stack(&head, user_input[i]);
        }
    }
    p_node current_val = head;
    //Prints the values in reverse order of user input
    while (current_val != NULL) {
        printf("%c", current_val->val);
        current_val = current_val->next;
    }
    return 0;
}
