list_t *extract_head(list_t **head) {
    list_t *p = *head;  // Step 1: Set p to point to the head of the list
    if (*head != NULL) {
        *head = (*head)->next;  // Step 2: Update head to point to the next node
        free(p);  // Step 3: Free the extracted head node to prevent memory leaks
        return NULL;  // Return NULL after freeing the node
    }
    return NULL;  // Return NULL if the list was empty
}
<<<<<<< HEAD
=======

// Example usage
int main() {
    // Create linked list nodes using dynamic memory allocation
    list_t *head = (list_t *)malloc(sizeof(list_t));
    list_t *second = (list_t *)malloc(sizeof(list_t));
    list_t *third = (list_t *)malloc(sizeof(list_t));

    // Check if memory allocation was successful
    if (head == NULL || second == NULL || third == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Assign data and link the nodes
    head->key = 10;           // Assign value to the first node
    head->next = second;      // Link the first node to the second node

    second->key = 20;         // Assign value to the second node
    second->next = third;     // Link the second node to the third node

    third->key = 30;          // Assign value to the third node
    third->next = NULL;       // The third node is the last, so its next pointer is NULL

    // Extract the head node
    extract_head(&head);  // Extract and free the head node

    // Print the remaining list
    list_t *current = head;
    while (current != NULL) {
        printf("Node with value: %d\n", current->key);
        current = current->next;
    }

    // Free the remaining nodes
    free(second);
    free(third);

    return 0;
}

/*
Description of the Code:

1. **Structure Definition (`list_t`)**:
   - The linked list node is defined using the `typedef struct list`. Each node contains:
     - `key`: An integer representing the value stored in the node.
     - `next`: A pointer to the next node in the list.

2. **`extract_head` Function**:
   - This function takes a double pointer to the head of the linked list (`list_t **head`).
   - The function extracts the current head node and updates the head pointer to point to the next node in the list.
   - The extracted head node is then freed to prevent memory leaks.

3. **Memory Allocation**:
   - The `malloc` function is used to dynamically allocate memory for the linked list nodes.
   - Memory allocation is checked to ensure it was successful. If `malloc` returns `NULL`, an error message is printed, and the program exits.

4. **Linking Nodes**:
   - The nodes are linked together by setting the `next` pointer of each node to point to the next node in the sequence.
   - The last node's `next` pointer is set to `NULL` to indicate the end of the list.

5. **Extracting the Head Node**:
   - The `extract_head` function is called to remove and free the head node from the list.
   - This ensures that the memory occupied by the head node is released to prevent memory leaks.

6. **Printing the Remaining List**:
   - After extracting the head node, the remaining list is printed to show the updated structure of the linked list.

7. **Memory Deallocation**:
   - After the linked list operations are complete, the `free` function is used to deallocate the memory assigned to each node, preventing memory leaks.

This code demonstrates basic linked list operations, including node creation, linking, extracting the head node, and proper memory management. It serves as a foundational example for understanding linked list manipulation in C.
*/
>>>>>>> 9b139abe3e35c62f87782e6a285b4a93a3bd454c
