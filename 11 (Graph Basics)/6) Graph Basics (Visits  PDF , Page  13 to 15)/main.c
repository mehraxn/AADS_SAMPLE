#include <stdio.h>
#include <stdlib.h>

// Define constants for vertex colors
#define WHITE 0
#define GREY 1
#define BLACK 2

typedef struct Edge {
    struct Vertex *dst;
    struct Edge *next;
} edge_t;

typedef struct Vertex {
    int id;
    int color;
    int dist;
    struct Vertex *pred;
    struct Edge *head;
    struct Vertex *next;
} vertex_t;

typedef struct Graph {
    vertex_t *g;
    int nv; // Number of vertices
} graph_t;

// Function prototypes
graph_t *graph_load(const char *filename);
vertex_t *graph_find(graph_t *g, int id);
void graph_attribute_init(graph_t *g);
void graph_bfs(graph_t *g, vertex_t *src);
void graph_dispose(graph_t *g);
void *queue_init(int size);
void queue_put(void *queue, void *element);
int queue_empty_m(void *queue);
void queue_get(void *queue, void **element);
void queue_dispose(void *queue, void (*free_func)(void *));

// Main function
int main(int argc, char *argv[]) {
    graph_t *g;
    vertex_t *src, *n;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <graph_file>\n", argv[0]);
        return 1;
    }

    g = graph_load(argv[1]);
    printf("Initial vertex? ");
    scanf("%d", &i);
    src = graph_find(g, i);

    if (!src) {
        fprintf(stderr, "Vertex %d not found in the graph.\n", i);
        graph_dispose(g);
        return 1;
    }

    graph_attribute_init(g);
    graph_bfs(g, src);

    n = g->g;
    printf("List of vertices:\n");
    while (n != NULL) {
        if (n->color != WHITE) {
            printf("%2d: %d (%d)\n",
                   n->id, n->dist, n->pred ? n->pred->id : -1);
        }
        n = n->next;
    }

    graph_dispose(g);
    return 0;
}

// BFS function
void graph_bfs(graph_t *g, vertex_t *n) {
    void *qp;
    vertex_t *d;
    edge_t *e;

    qp = queue_init(g->nv);

    n->color = GREY;
    n->dist = 0;
    n->pred = NULL;
    queue_put(qp, (void *)n);

    while (!queue_empty_m(qp)) {
        queue_get(qp, (void **)&n);
        e = n->head;

        while (e != NULL) {
            d = e->dst;

            if (d->color == WHITE) {
                d->color = GREY;
                d->dist = n->dist + 1;
                d->pred = n;
                queue_put(qp, (void *)d);
            }

            e = e->next;
        }

        n->color = BLACK;
    }

    queue_dispose(qp, NULL);
}

// Function to initialize graph attributes
void graph_attribute_init(graph_t *g) {
    vertex_t *n = g->g;
    while (n != NULL) {
        n->color = WHITE;
        n->dist = -1;
        n->pred = NULL;
        n = n->next;
    }
}

// Function to find a vertex in the graph by ID
vertex_t *graph_find(graph_t *g, int id) {
    vertex_t *n = g->g;
    while (n != NULL) {
        if (n->id == id) {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

// Function to dispose of the graph
void graph_dispose(graph_t *g) {
    vertex_t *n = g->g;
    while (n != NULL) {
        edge_t *e = n->head;
        while (e != NULL) {
            edge_t *temp_e = e;
            e = e->next;
            free(temp_e);
        }
        vertex_t *temp_n = n;
        n = n->next;
        free(temp_n);
    }
    free(g);
}

// Dummy queue functions (Replace with actual queue implementation)
void *queue_init(int size) {
    return malloc(size * sizeof(void *)); // Simplified queue initialization
}

void queue_put(void *queue, void *element) {
    // Simplified for illustration
}

int queue_empty_m(void *queue) {
    return 0; // Simplified for illustration
}

void queue_get(void *queue, void **element) {
    // Simplified for illustration
}

void queue_dispose(void *queue, void (*free_func)(void *)) {
    free(queue);
}

// Function to load a graph from a file (dummy implementation)
graph_t *graph_load(const char *filename) {
    // Dummy implementation: Replace with actual graph loading code
    return NULL;
}
