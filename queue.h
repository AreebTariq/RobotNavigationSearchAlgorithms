// A C program to demonstrate linked list based implementation of queue
//ref: https://www.geeksforgeeks.org/queue-linked-list-implementation/
#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

#define INVALID_VALUE 0xFFFFFF										/*An invalid value macro*/

// A linked list (LL) node to store a queue entry
typedef struct Node_Coordinates 
{
    int row;
    int column;
}Node_Coordinates;


typedef struct  QNode 
{
    Node_Coordinates node_coordinates;
    Node_Coordinates parent_node_coordinates;
    int depth_of_node;
    float evaluation_function_cost;
    float cost_from_root;

    struct QNode* next;
}QNode;

// The queue, front stores the front node of LL and rear stores the
// last node of LL
typedef struct  
{
    struct QNode* front, * rear;
    int size;
}Queue;


// A utility function to create a new linked list node.
struct QNode* Queue_Node(Node_Coordinates node_coordinates, float cost_from_root, Node_Coordinates parent_coordinates, int depth_of_node, float evaluation_function_cost);

// A utility function to create an empty queue
struct Queue* createQueue();

// The function to add a key k to q
void add_front_of_queue(Queue* queue, Node_Coordinates node_coordinates, float cost_from_root, Node_Coordinates parent_coordinates, int node_depth, float evaluation_function_cost);

// The function to add a key k to q
void add_end_of_queue(Queue* queue, Node_Coordinates node_coordinates, float cost_from_root, Node_Coordinates parent_coordinates, int node_depth, float evaluation_function_cost);

void add_in_increasing_queue(Queue* queue, Node_Coordinates node_coordinates, float cost_from_root, Node_Coordinates parent_coordinates, int node_depth, float evaluation_function_cost);

// Function to remove a key from given queue q
void remove_front_of_queue(Queue* queue);

void display_queue(Queue* queue, int grid_size);

void delete_queue(Queue* queue);



