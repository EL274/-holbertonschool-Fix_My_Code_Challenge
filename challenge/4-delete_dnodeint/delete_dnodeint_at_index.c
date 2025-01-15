#include "listes.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int p;

    if (*head == NULL)
    {
        return (-1);
    }

    current = *head;

    // Traverser jusqu'au nœud à supprimer
    for (p = 0; p < index && current != NULL; p++)
    {
        current = current->next;
    }

    // Si l'index est hors de portée
    if (current == NULL)
    {
        return (-1);
    }

    // Si le nœud à supprimer est la tête de la liste
    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        // Relier le nœud précédent au nœud suivant
        current->prev->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
    }

    // Libérer la mémoire du nœud supprimé
    free(current);

    return (1);
}
