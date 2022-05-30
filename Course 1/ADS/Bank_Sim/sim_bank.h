#ifndef SIM_BANK_H
#define SIM_BANK_H

#include <stdio.h>
#include <stdint.h>
#include <queue.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct results_t {
    size_t avg_cashier_busyness;
    size_t max_queue_length;
    size_t min_wait_time;
    size_t max_wait_time;
} results_t;

typedef struct param_t {
    size_t iterations; 
    size_t cashier_cnt; 
    size_t time_per_client;
    size_t client_chance;
  
} param_t;

results_t simulate_bank(param_t p);

#endif