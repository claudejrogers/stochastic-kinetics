//
//  main.c
//  stochastic_test
//
//  Created by Claude Rogers on 6/12/12.
//  Copyright (c) 2012 California Institute of Technology. All rights reserved.
//

#include "stochastic_kinetics.h"

void get_h(double *h, int *y)
{
    h[0] = 1.0;
    h[1] = y[0];
    h[2] = 0.5*y[0]*y[1]*(y[0] - 1);
    h[3] = y[0];
}

int main(int argc, const char * argv[])
{

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

