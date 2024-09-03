#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
    //check if the link list is null
    if (*head == NULL)
    {
        return(NULL);
    }
    // create nodes to traverse the linked list
    listint_t *new;
    listint_t *current;

    // assign nodes
    new = malloc(sizeof(listint_t));
    current = *head;
    // Check if malloc succeeded
    if (new == NULL)
    {
        return NULL;
    }

    // Traverse the linked list
    while (current != NULL && current->next != NULL)
    {
        // Check if the current position is the correct insertion point
        if (current->n < number && current->next->n >= number)
        {
            // Assign the value of number to the new node
            new->n = number;
            // Connect the new node to the next node
            new->next = current->next;
            // Connect the current node to the new node
            current->next = new;
            // Return the new node
            return new;
        }
        // Move to the next node
        current = current->next;
    }
    // Return NULL if the correct position is not found
    return NULL;
}