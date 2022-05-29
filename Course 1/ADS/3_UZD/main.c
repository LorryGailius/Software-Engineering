// Laurynas Gailius PS 2 grupe 1 pogrupis
// Stud id 554

#include <sim_bank.h>
#include <time.h>

int main(int argc, char** argv)
{
    srand(time(NULL));

    if (argc == 1) {
        printf("Usage: %s filename\n", argv[0]);
    }
    else {

    char *filename;

    if(argc != 2) {
        printf("Too many arguments!\n Usage: %s filename\n", argv[0]);
        return 0;
    }

    filename = argv[1];
    
    param_t parameters;

    FILE * is = fopen(filename, "rb");

    if(is == NULL) return 0;

    fscanf(is, "%zu", &parameters.iterations);
    if(feof(is)) {printf("Too few arguments in file!\n"); return 0;}
    fscanf(is, "%zu", &parameters.cashier_cnt);
    if(feof(is)) {printf("Too few arguments in file!\n"); return 0;}
    fscanf(is, "%zu", &parameters.time_per_client);
    if(feof(is)) {printf("Too few arguments in file!\n"); return 0;}
    fscanf(is, "%zu", &parameters.client_chance);

    fclose(is);

    printf("File name is: %s\n\n", filename);
    printf("Iterations: %zu\n", parameters.iterations);
    printf("Cashier Count: %zu\n", parameters.cashier_cnt);
    printf("Time spent per client: %zu\n", parameters.time_per_client);
    printf("Chance of client per cycle: %zu%%\n\n", parameters.client_chance);

    simulate_bank(parameters);
    }

    return 0;
}