#define _GNU_SOURCE
#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    //read function parameter
    int set, associativity, block_bits, opt;
//    printf("%d\n",getopt(argc, argv, "sEbt:"));
//    opt = getopt(argc, argv, "sEbt:");
 //   printf("%d\n",opt);
    char* file_name;
    while ((opt = getopt(argc, argv, "s:E:b:t:")) != -1) {
        switch (opt) {
        case 's':
           set = atoi(optarg);
           break;
        case 'E':
            associativity = atoi(optarg);
            break;
        case 'b':
            block_bits = atoi(optarg);
            break;
        case 't':
            file_name = optarg; 
            break;
        default: //'?'
            fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n", argv[0]);
            exit(EXIT_FAILURE);
            break;
        }
    }


    printf("s = %d, E = %d, b = %d, t = %s\n", set, associativity, block_bits, file_name);
    // read file
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(file_name, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("line length %zu:\n", read);
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
    //printSummary(0, 0, 0);
    return 0;
}
