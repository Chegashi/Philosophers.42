#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>

#include "philo.h"
// int mails = 0;
// pthread_mutex_t mutex;

// void    *routine()
// {
//     for (int i = 0; i < 10000000; i++) {
//         pthread_mutex_lock(&mutex);
//         mails++;
//         pthread_mutex_unlock(&mutex);
//     }
//     return NULL;
// }

// int main()
// {
//     pthread_t th[8];
//     int i;
//     pthread_mutex_init(&mutex, NULL);
//     for (i = 0; i < 8; i++) {
//         if (pthread_create(th + i, NULL, &routine, NULL) != 0) {
//             perror("Failed to create thread");
//             return 1;
//         }
//         printf("Thread %d has started\n", i);
//     }
//     for (i = 0; i < 8; i++) {
//         if (pthread_join(th[i], NULL) != 0) {
//             return 2;
//         }
//         printf("Thread %d has finished execution\n", i);
//     }
//     pthread_mutex_destroy(&mutex);
//     printf("Number of mails: %d\n", mails);
//     return 0;
// }
#include <sys/time.h>
#include <stdio.h>

int main()
{
    struct timeval current_time;

    printf("INT_MAX: %d\nUINT_MAX : %u\nLONG_MAX : %ld\nULONG_MAX:%lu\n", INT_MAX, UINT_MAX, LONG_MAX, ULONG_MAX);
    for (int i = 0; i < 10; i++)
    {
        gettimeofday(&current_time, NULL);
        printf("seconds : %ld\tmicro seconds : %d\t micro seconds : %ld\n",current_time.tv_sec, current_time.tv_usec, current_time.tv_sec * 1000 + current_time.tv_usec/1000);
        usleep(1000000);
    }
   return 0;
}