#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Double pointer to the head of the linked list.
 * @number: The number to insert into the list.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
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
    // Assign the value of number to the new node
    new->n = number;

    if (!current || current->n >= number)
    {
        new->next = *head;
        *head = new;
        return new;
    }

    // Traverse the linked list
    while (current != NULL && current->next != NULL)
    {
        // Check if the current position is the correct insertion point
        if (current->next->n > number)
        {
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
    // connect current to new
    current->next = new;
    // Return the new node
    return new;
}