//
//  stochastic_kinetics.c
//  stochastic_test
//
//  Created by Claude Rogers on 6/13/12.
//  Copyright (c) 2012 California Institute of Technology. All rights reserved.
//

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "stochastic_kinetics.h"

void write_line(FILE *f, double t, int *y, int N)
{
    int i;
    fprintf(f, "%f", t);
    for (i = 0; i < N; i++) {
        fprintf(f, "\t%d", y[i]);
    }
    fprintf(f, "\n");
}

void get_a(double *a, double *h, double *c, int M)
{
    int i;
    for (i = 0; i < M; i++) {
        a[i] = h[i] * c[i];
    }
}

double sum_a(double *a, int M)
{
    int i;
    double a0 = 0;
    for (i = 0; i < M; i++) {
        a0 += a[i];
    }
    return a0;
}

int get_mu(double *a, double r2, int M)
{
    int i;
    double r2a0 = r2 * sum_a(a, M);
    double total = 0.0;
    for (i = 0; i < M; i++) {
        total += a[i];
        if (r2a0 <= total) {
            return i;
        }
    }
    return 0;
}

void update_y(int *y, int *update_array, int N)
{
    int i;
    for (i = 0; i < N; i++) {
        y[i] += update_array[i];
    }
}

void gillespie(char *filename,
               int *y,
               int N,
               int M,
               int update_matrix[M][N],
               double *c,
               H_FUNC get_h,
               double STOP_TIME)
{
    FILE *fdata;
    fdata = fopen(filename, "w");
    double t = 0.0;
    write_line(fdata, t, y, N);
    double *h;
    double *a;
    h = (double *) malloc(M*sizeof(double));
    a = (double *) malloc(M*sizeof(double));
    double r1, r2, tau, a0;
    int mu;
    unsigned int iseed = (unsigned int)time(NULL);
  	srand (iseed);
    while (t < STOP_TIME) {
        get_h(h, y);
        get_a(a, h, c, M);
        a0 = sum_a(a, M);
        r1 = ((double)rand()/(double)RAND_MAX);
		r2 = ((double)rand()/(double)RAND_MAX);
        tau = (1.0 / a0) * log(1.0 / r1);
        mu = get_mu(a, r2, M);
        update_y(y, update_matrix[mu], N);
        t += tau;
        write_line(fdata, t, y, N);
    }
    free((void *)h);
    free((void *)a);
}
