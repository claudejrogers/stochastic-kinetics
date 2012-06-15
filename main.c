//
//  main.c
//  stochastic_test
//
//  Created by Claude Rogers on 6/12/12.
//  Copyright (c) 2012 California Institute of Technology. All rights reserved.
//

#include "stochastic_kinetics.h"

// Lokia reaction, Figure 8

void lokia_h(double *h, int *y)
{
    h[0] = y[0];
    h[1] = y[0]*y[1];
    h[2] = y[1];
}

void get_h(double *h, int *y)
{
    h[0] = 1.0;
    h[1] = y[0];
    h[2] = 0.5*y[0]*y[1]*(y[0] - 1);
    h[3] = y[0];
}

int main(int argc, const char * argv[])
{

    // Lokia
    int yl[] = {1000, 1000};
    int update_lokia[3][2] = {
        {1, 0},
        {-1, 1},
        {0, -1}
    };
    double cl[] = {10.0, 0.01, 10.0};
    gillespie("lokia.dat", yl, 2, 3, update_lokia, cl, lokia_h, 30);

    // Brusselator
    int y[] = {1000, 2000};
    int update_matrix[4][2] = {
        {1, 0},
        {-1, 1},
        {1, -1},
        {-1, 0}
    };
    double c[] = {5000.0, 50.0, 0.00005, 5.0};
    gillespie("brusselator.dat", y, 2, 4, 
              update_matrix, c, get_h, 15.0);
    return 0;
}

