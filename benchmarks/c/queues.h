#ifndef LINEAR_TYPES_BENCHMARKS_C_QUEUES_H 
#define LINEAR_TYPES_BENCHMARKS_C_QUEUES_H 

typedef struct node_t {
    int id;
    struct node_t* next;
} node_t;

typedef struct queue_t {
    node_t* start;
    node_t* end;
} queue_t;


/*
 * Prints a queue, this is used from the FFI, in order to access info from a C structure.
 */ 
void print_queue(queue_t* queue);

/*
 * Creates a queue and allocates it
 */
queue_t* create_queue(void);

/*
 * Frees a queue and all of its nodes.
 */
void clear_queue(queue_t* queue);

/*
 * Creates and allocates a node_t holding the id field.
 */
node_t* create_node(int id);

/*
 *  Creates, allocates and appends a node_t to the given queues.
 */
void push(queue_t* queue, int id);

/* Pops a node_t from the queue.
 *   - The node has to be deallocated by the caller.
 *   - If the queue is empty the return value is a null pointer
 */
node_t* pop(queue_t* queue);

/*
 * Removes the node at position `position` from the `queue`, also deallocates it.
 * If the deletion is successful the return value is 0, otherwise 1 (no other errors code yet).
 */
int delete_node(queue_t* queue, int position);

#endif /* LINEAR_TYPES_BENCHMARKS_C_QUEUES_H */
