#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue
{
    char ID[20];
    int wait;
    struct queue *next;
} queue;

// Create node
queue *makeNode(char *ID, int wait){
    queue *q = (queue*) malloc(sizeof(queue));
    q->next = NULL;
    strcpy(q->ID, ID);
    q->wait = wait;
    return q;  // ✅ MUST return
}

// Add node to queue
queue *addNode(queue *head, char *ID, int wait){
    if (head == NULL)
    {
        return makeNode(ID, wait);  // ✅ use actual wait
    }
    else
    {
        queue *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        queue *newNode = makeNode(ID, wait);

        // cumulative wait
        newNode->wait = curr->wait + wait;

        curr->next = newNode;
        return head;
    }
}

// Print output
void printOutput(queue *head){
    if (head == NULL)
    {
        printf("ORDER\nWAIT\n");
        return;
    }

    int total = 0;
    queue *curr = head;

    printf("ORDER");

    while (curr != NULL)
    {
        printf(" %s", curr->ID);
        total += curr->wait;
        curr = curr->next;
    }

    printf("\nWAIT %d", total);
}

int main(){
    int n;
    scanf("%d", &n);

    queue *head = NULL;

    char buffer[20];
    int wait;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            // first input only ID
            scanf("%s", buffer);
            head = addNode(head, buffer, 0);
        }
        else
        {
            scanf("%d %s", &wait, buffer);
            head = addNode(head, buffer, wait);
        }
    }

    printOutput(head);

    return 0;
}
