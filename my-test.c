#include <omp.h>
#include <stdio.h>

int main(void) {
    #pragma omp parallel
    printf(
        "thread number: %d / total number of threads: %d\n",
        omp_get_thread_num(),
        omp_get_num_threads()
    );
    return 0;
}
