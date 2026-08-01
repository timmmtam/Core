#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

int	x = 0;

void	*routine(void* mutex)
{
	u_int64_t	tid;

	pthread_threadid_np(NULL, &tid);
	printf("Hello from thread: %llu\n", tid);
	pthread_mutex_lock(mutex);
	for (int i = 0; i < 100000; i++)
		x++;
	pthread_mutex_unlock(mutex);
	sleep(1);
	printf("I love my life\n");
	return (NULL);
}

int	main(void)
{
	pthread_t	th[10];
	int			i;
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < 10)
	{
		if (pthread_create(th + i, NULL, &routine, &mutex))
			return (1);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(*(th + i), NULL))
			return (2);
		i++;
	}
	printf("%d\n", x);
	pthread_mutex_destroy(&mutex);
	return(0);
}
