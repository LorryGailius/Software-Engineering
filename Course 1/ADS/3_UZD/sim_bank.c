#include <sim_bank.h>

results_t simulate_bank(param_t p) {
    size_t *cashiers = calloc(p.cashier_cnt, sizeof(size_t));
    size_t busyness = 0;
    queue_t queue = create_queue();
    results_t result = {0, 0, 0, 0};
    size_t total_customers = 0;

    for(size_t i = 0; i < p.iterations; ++i) {
        /// Generate a customer
        const size_t N = 100 / p.client_chance;
        if(rand() % N == 0) { 
            ++total_customers;
            enqueue(&queue, &i, sizeof(size_t));
            result.max_queue_length = MAX(queue.elem_cnt, result.max_queue_length);
        }

        // Asign clients to cashiers
        for(size_t j = 0; j < p.cashier_cnt; ++j) {
            if((cashiers[j] == 0) && (queue.elem_cnt > 0)) {
                cashiers[j] = p.time_per_client;
                size_t *start_time = dequeue(&queue);
                size_t wait_time = i - *start_time;
                free(start_time);
                result.max_wait_time = MAX(wait_time, result.max_wait_time);
                result.min_wait_time = MIN(wait_time, result.min_wait_time);
                
            }
        }
        
        // Update cashier time
        for(size_t j = 0; j < p.cashier_cnt; ++j) {
            if(cashiers[j] > 0) {
                --cashiers[j];
                ++busyness;
            }
        }
    }

    free_queue(&queue);

    result.avg_cashier_busyness = (100 * busyness) / (p.cashier_cnt * p.iterations);

    printf("Total customers: %zu\n", total_customers);

    printf("Avg cashier busyness: %zu%%\n", result.avg_cashier_busyness);
    printf("Max queue length: %zu\n", result.max_queue_length);
    printf("Min queue length: %zu\n", result.min_wait_time);
    printf("Max wait time: %zu\n", result.max_wait_time);

    return result;
}