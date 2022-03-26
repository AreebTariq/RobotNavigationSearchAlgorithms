// A C program to demonstrate linked list based implementation of queue
//ref: https://www.geeksforgeeks.org/queue-linked-list-implementation/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


// A utility function to create a new linked list node.
struct QNode* Queue_Node(Node_Coordinates node_coordinates, float cost_from_root, Node_Coordinates parent_coordinates, int depth_of_node, float evaluation_function_cost)
{
    QNode* temp = (QNode*)malloc(sizeof(QNode));

    temp->node_coordinates.row              = node_coordinates.row;
    temp->node_coordinates.column           = node_coordinates.column;
    temp->parent_node_coordinates.row       = parent_coordinates.row;
    temp->parent_node_coordinates.column    = parent_coordinates.column;
    temp->depth_of_node                     = depth_of_node;
    temp->cost_from_root                    = cost_from_root;
    temp->evaluation_function_cost          = evaluation_function_cost;
    temp->next                              = NULL;

    return temp;
}

// A utility function to create an empty queue
struct Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// The function to add a key k to q
void add_end_of_queue(Queue* queue, Node_Coordinates node_coordinates, float cost_from_root, Node_Coordinates parent_coordinates, int node_depth, float evaluation_function_cost)
{
    // Create a new LL nodqueuee
    QNode* temp = Queue_Node(node_coordinates, cost_from_root, parent_coordinates, node_depth, evaluation_function_cost);

    // If queue is empty, then new node is front and rear both
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = temp;
        queue->size++;
        return;
    }

    // Add the new node at the end of queue and change rear
    queue->rear->next = temp;
    queue->rear = temp;
    queue->size++;
}


// The function to add a key k to q
void add_front_of_queue(Queue* queue, Node_Coordinates node_coordinates, float cost_from_root, Node_Coordinates parent_coordinates, int node_depth, float evaluation_function_cost)
{
    // Create a new LL node
    QNode* temp = Queue_Node(node_coordinates, cost_from_root, parent_coordinates, node_depth, evaluation_function_cost);

    // If queue is empty, then new node is front and rear both
    if (queue->front == NULL)
    {
        queue->front = queue->rear = temp;
        queue->size++;
        return;
    }

    // Add the new node at the end of queue and change rear
    temp->next = queue->front;
    queue->front = temp;
    queue->size++;
}


// Function to remove a key from given queue q
void remove_front_of_queue(Queue* queue)
{
    // If queue is empty, return NULL.
    if (queue->front == NULL)
    {
        return;
    }

    // Store previous front and move front one node ahead
    QNode* temp = queue->front;

    queue->front = queue->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (queue->front == NULL)
    {
        queue->rear = NULL;
        queue->size = 0;
        free(temp);
        return;
    }
    queue->size--;
    free(temp);
}

//TODO: implementation needs update
void print_queue(Queue* queue, int grid_size)
{
    QNode* temp = queue->front;
    printf("Fringe State (row,column)  : ");

    if (temp == NULL || queue->size == 0)
    {
        printf("Fringe is empty\n");
        return;
    }

    int queue_size = queue->size;
    for (int i = 0; i < queue_size;i++)
    {
        int row = temp->node_coordinates.row;
        int col = temp->node_coordinates.column;
        //TODO: implementation needs update
        int remapped_row = grid_size - (row / 10);
        int remapped_col = (col % 10) + 1;

        printf("(%d, %d)  ",remapped_row,remapped_col);

        temp = temp->next;
    }
    printf("\n");

}

void delete_queue(Queue* queue)
{
    if (queue != NULL)
    {
        while (queue->front != NULL)
        {
            remove_front_of_queue(queue);
        }
    }
    if (queue != NULL)
    {
        free(queue);
//        queue->front = queue->rear = NULL;
  //      queue->size = 0;
    }
 }

void add_in_increasing_queue(Queue* queue, Node_Coordinates node_coordinates, float cost_from_root, Node_Coordinates parent_coordinates, int node_depth, float evaluation_function_cost)
{
    QNode* temp = Queue_Node(node_coordinates, cost_from_root, parent_coordinates, node_depth, evaluation_function_cost);
    QNode* nav_pointer = queue->front;

    // If queue is empty, then new node is front and rear both
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = temp;
        
    }
    else
    {
        if (evaluation_function_cost == INVALID_VALUE)
        {
            if (temp->cost_from_root >= queue->rear->cost_from_root)
            {
                queue->rear->next = temp;
                queue->rear = temp;
            }
            else if (temp->cost_from_root <= queue->front->cost_from_root)
            {
                temp->next = queue->front;
                queue->front = temp;
            }
            else
            {
                while (nav_pointer->next != NULL && nav_pointer->next->cost_from_root < temp->cost_from_root)
                {
                    nav_pointer = nav_pointer->next;
                }

                temp->next = nav_pointer->next;
                nav_pointer->next = temp;
            }
        }
        else
        {
            if (temp->evaluation_function_cost >= queue->rear->evaluation_function_cost)
            {
                queue->rear->next = temp;
                queue->rear = temp;
            }
            else if (temp->evaluation_function_cost <= queue->front->evaluation_function_cost)
            {
                temp->next = queue->front;
                queue->front = temp;
            }
            else
            {
                while (nav_pointer->next != NULL && nav_pointer->next->evaluation_function_cost < temp->evaluation_function_cost)
                {
                    nav_pointer = nav_pointer->next;
                }

                temp->next = nav_pointer->next;
                nav_pointer->next = temp;
            }
        }
    }
    queue->size++;
}

