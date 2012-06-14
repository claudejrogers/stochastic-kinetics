//
//  stochastic_kinetics.h
//  stochastic_test
//
//  Created by Claude Rogers on 6/13/12.
//  Copyright (c) 2012 California Institute of Technology. All rights reserved.
//


#ifndef stochastic_test_stochastic_kinetics_h
#define stochastic_test_stochastic_kinetics_h
#include <stdio.h>

typedef void(*H_FUNC)(double*, int*);

// Write data to file for each iteration
void write_line(FILE *f, double t, int *y, int N);


void get_a(double *a, double *h, double *c, int M);

double sum_a(double *a, int M);

int get_mu(double *a, double r2, int M);

void update_y(int *y, int *update_array, int N);

void gillespie(char *filename,
               int *y,
               int N,
               int M,
               int update_matrix[M][N],
               double *c, 
               H_FUNC get_h,
               double STOP_TIME);

#endif
