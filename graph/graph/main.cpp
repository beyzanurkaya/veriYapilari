#include <iostream>

using namespace std;

struct Node
{
    int value;
    struct Node* next;
};

struct NodeList
{
    struct Node* head;
};

struct Graph
{
    int graphSize;
    struct NodeList* arr;
};

struct Node* newNode(int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}

struct Graph* newGraph(int graphSize)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->graphSize = graphSize;
    graph->arr = (struct NodeList*)malloc(graphSize * sizeof(struct NodeList));

    int i;
    for(i = 0; i < graphSize; i++)
    {
        graph->arr[i].head = NULL;
    }

    return graph;
}

void edge(struct Graph* graph, int src, int dest)
{
    struct Node* node = newNode(dest);
    node->next = graph->arr[src].head;
    graph->arr[src].head = node;

    node = newNode(src);
    node->next = graph->arr[dest].head;
    graph->arr[dest].head = node;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->graphSize; ++v)
    {
        struct Node* pCrawl = graph->arr[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->value);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}


int main()
{
    int graphSize = 5;
    struct Graph* graph = newGraph(graphSize);
    edge(graph, 0, 1);
    edge(graph, 0, 4);
    edge(graph, 1, 2);
    edge(graph, 1, 3);
    edge(graph, 1, 4);
    edge(graph, 2, 3);
    edge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
