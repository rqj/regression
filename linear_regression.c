#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "linear_regression.h"

/* Set Learning rate of linear regression. */
void set_learning_rate_lin(struct linreg_dataset_t *a, float b)
{
	// Set learning rate
	a->learning_rate = b;
}

/* Perform linear_regression */
void linear_regression(struct linreg_dataset_t *a, int sampledatasize)
{
	// Loop linear regression as many as sampledatasize
	for (int i = 0; i < sampledatasize; i++)
	{
		// Hypothesis function: hyp = B0 + B1*feat1 + B2*feat2
		float hypothesis = a->B0 + a->B1 * (a->feat1[i]) + a->B2 * (a->feat2[i]);
	
		// Calculate hypothesis error against actual output
		float err_lin = hypothesis - a->sys_output[i];  
		
		// Gradient descent: update each parameters to minimize error
		a->B0 = a->B0 - a->learning_rate * err_lin;
		a->B1 = a->B1 - a->learning_rate * err_lin * (a->feat1[i]);
		a->B2 = a->B2 - a->learning_rate * err_lin * (a->feat2[i]);
		
		// Calculate cost function in moving average mode (not as summation): (hyp - y)^2
		a->cost_function = a->cost_function_prev + (hypothesis - (a->sys_output[i]))*(hypothesis - (a->sys_output[i]));
		a->cost_function_prev = a->cost_function/2;  
	}
}



