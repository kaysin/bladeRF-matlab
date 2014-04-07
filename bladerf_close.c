#include <math.h>
#include <matrix.h>
#include <mex.h>
#include "libbladeRF.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    struct bladerf *dev;
	long long *ip;

	if (nrhs < 1)
		return;

	ip = (long long *)mxGetPr(prhs[0]);
	
	dev = *ip;

	bladerf_close(dev);
}

