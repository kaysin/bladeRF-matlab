#include <math.h>
#include <matrix.h>
#include <mex.h>
#include "libbladeRF.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    struct bladerf *dev;
	bladerf_sampling sp;
	int ret;
	long long *ip;

	if (nrhs < 2)
		return;

	ip = (long long *)mxGetPr(prhs[0]);

	dev = (struct bladerf *)*ip;
	sp = (bladerf_loopback)*(double *)mxGetData(prhs[1]);

	
	ret = bladerf_set_sampling(dev, sp);

	if (nlhs >= 1) {
		plhs[0] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
		ip = (long long *)mxGetData(plhs[0]);
		*ip = ret;
	}
}

