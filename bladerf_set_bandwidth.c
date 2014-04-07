#include <math.h>
#include <matrix.h>
#include <mex.h>
#include "libbladeRF.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    struct bladerf *dev;
	bladerf_module mod;
	int ret, bw, actual;
	long long *ip;

	if (nrhs < 3)
		return;

	ip = (long long *)mxGetPr(prhs[0]);

	dev = (struct bladerf *)*ip;
	mod = (bladerf_module)*(double *)mxGetData(prhs[1]);
	bw = (int)*(double *)mxGetData(prhs[2]);

	
	ret = bladerf_set_bandwidth(dev, mod, bw, &actual);

	if (nlhs >= 2) {
		plhs[0] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
		ip = (long long *)mxGetData(plhs[0]);
		*ip = actual;
	}

	if (nlhs >= 1) {
		plhs[0] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
		ip = (long long *)mxGetData(plhs[0]);
		*ip = ret;
	}
}
