#include <sys/time.h>
#include <stdio.h>

int main()
{

    struct timeval tv;
    long time;
    long time2;

    gettimeofday(&tv, NULL);
    time = tv.tv_sec * 1000;
    time += tv.tv_usec / 1000;
    sleep(1);
    gettimeofday(&tv, NULL);
    time2 = tv.tv_sec * 1000;
    time2 += tv.tv_usec / 1000;
    time2 = time2 - time;
    printf("Time passed: %ld")
    return (0);
}