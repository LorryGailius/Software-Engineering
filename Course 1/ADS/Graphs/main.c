// Laurynas Gailius PS 2 grupe 1 pogrupis
// Stud id 554

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define MAX_CITIES 16
#define MAX_FLIGHTS MAX_CITIES - 1
#define MAX_NAME_LEN 86

typedef struct flight_t
{
    int start, duration;
    char from[MAX_NAME_LEN], to[MAX_NAME_LEN];
} flight_t;

typedef struct graph_t
{
    char cities[MAX_CITIES][MAX_NAME_LEN];
    flight_t flights[MAX_CITIES][MAX_FLIGHTS];
    size_t city_count;
    size_t flight_count[MAX_CITIES];
} graph_t;

typedef struct path_t 
{
    char cities[MAX_NAME_LEN][MAX_FLIGHTS];
    size_t city_count;
    int total_time;
} path_t;

void print_path(FILE *os, path_t *path) {
    if(path->city_count == 0) {
        fprintf(os, "Path does not exist\n");
        return;
    }
    fprintf(os, "Flight will take %d time units\n", path->total_time);
    for(size_t i = 0; i < path->city_count; ++i) {
        fprintf(os, "[%s]", path->cities[i]);
    }
}

flight_t read_flight(FILE *is) {
    flight_t flight;
    int read = fscanf(is, "%s %s %d %d", flight.from, flight.to, &flight.start, &flight.duration);
    assert(read == 4);
    return flight;
}

int get_city_index(graph_t *graph, const char *city) {
    for(size_t i = 0; i < graph->city_count; ++i) {
        if(!strcmp(city, graph->cities[i])) {
            return i;
        }  
    }
    return -1;
}

void add_flight(graph_t *graph, flight_t flight) {
    bool origin_exist = false;
    bool destination_exist = false;

    // add flight values to matrix
    for (size_t i = 0; i < MAX_CITIES; i++) {
        if (!strcmp(graph->cities[i], flight.from))
        {
            origin_exist = true;
            graph->flights[i][graph->flight_count[i]++] = flight;
        }
        if(!strcmp(graph->cities[i], flight.to)) {
            destination_exist = true;
        }
    }
    if(!origin_exist) {
        // add origin city if not in the graph
        size_t city_index = graph->city_count;
        strcpy(graph->cities[city_index], flight.from);
        graph->flights[city_index][graph->flight_count[city_index]++] = flight;
        graph->city_count++;
    }
    if(!destination_exist) {
        // add destination city if not in the graph
        strcpy(graph->cities[graph->city_count++], flight.to);
    }
}

void fill_graph(graph_t *graph, const char *filename) {
    FILE *is = fopen(filename, "rb");
    while(!feof(is)) {
        flight_t flight = read_flight(is);
        add_flight(graph, flight);
    }
    fclose(is);
}

void find_path(graph_t *graph, const char *from, const char *to, path_t *path) {

    int dist[MAX_CITIES][MAX_CITIES];
    // initialize each dist to ∞ except to themselves
    for(size_t i = 0; i < graph->city_count; ++i) {
        for(size_t j = 0; j < graph->city_count; ++j) {
            dist[i][j] = INT32_MAX >> 1;
        }
    }
    
    int next[MAX_CITIES][MAX_CITIES];
    // initialize to invalid indices
    for(size_t i = 0; i < graph->city_count; ++i) {
        for(size_t j = 0; j < graph->city_count; ++j) {
            next[i][j] = -1;
        }
    }

    // Set durations of straight-forward flights
    for(size_t i = 0; i < graph->city_count; ++i) {
        for(size_t j = 0; j < graph->flight_count[i]; ++j) {
            int to_index = get_city_index(graph, graph->flights[i][j].to);
            dist[i][to_index] = graph->flights[i][j].duration;
            next[i][to_index] = to_index;
        }
    }

    // Set weights of each vertex
    for(size_t i = 0; i < graph->city_count; ++i) {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    for(size_t k = 0; k < graph->city_count; ++k) {
        for(size_t i = 0; i < graph->city_count; ++i) {
            for(size_t j = 0; j < graph->city_count; ++j) {
                bool isShorter = dist[i][j] > dist[i][k] + dist[k][j];
                if(isShorter) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    int idx1 = get_city_index(graph, from);
    int idx2 = get_city_index(graph, to);
    path->total_time = dist[idx1][idx2];

    if(next[idx1][idx2] == -1) return;

    strcpy(path->cities[path->city_count++], graph->cities[idx1]);
    while(idx1 != idx2) {
        idx1 = next[idx1][idx2];
        strcpy(path->cities[path->city_count++], graph->cities[idx1]);
    }
}


int main(int argc, char **argv) {

    graph_t graph = {{0}, {0}, 0, {0}};
    path_t path = {{0}, 0, 0};

    if(argc == 2)
    {
        fill_graph(&graph, argv[1]);

        printf("Cities:\n");
        for (size_t i = 0; i < graph.city_count; i++)
        {
            printf("[%s] | ", graph.cities[i]);
        }
        puts("");
        printf("Choose Destination and Origin:\n");
        char destination[MAX_NAME_LEN], origin[MAX_NAME_LEN];
        scanf("%s %s", destination, origin);

        find_path(&graph, origin, destination, &path);
        print_path(stdout, &path);

    }
    else if (argc == 4)
    {
        fill_graph(&graph, argv[1]);
        find_path(&graph, argv[2], argv[3], &path);
        print_path(stdout, &path);
    }
    else
    {
        printf("Usage:\n%s [flight_file_name] [destination]  [origin]\nOr\n%s [flight_file_name]",argv[0], argv[0]);
    }
    

    return 0;
}