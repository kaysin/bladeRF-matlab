#include <math.h>
#include <matrix.h>
#include <mex.h>
#include "libbladeRF.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	struct bladerf *dev;
	int ret;
	long long *ip;
	unsigned int major, minor, patch;

	if (nrhs < 1)
		return;

	ip = (long long *)mxGetPr(prhs[0]);
	
	dev = *ip;
	ret = bladerf_version(dev, &major, &minor, &patch);
	
	if (nlhs >= 4) {
		plhs[3] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
		ip = (long long *)mxGetData(plhs[3]);
		*ip = patch;
	}

	if (nlhs >= 3) {
		plhs[2] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
		ip = (long long *)mxGetData(plhs[2]);
		*ip = minor;
	}

	if (nlhs >= 2) {
		plhs[1] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
		ip = (long long *)mxGetData(plhs[1]);
		*ip = major;
	}
	
	if (nlhs >= 1) {
		plhs[0] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
		ip = (long long *)mxGetData(plhs[0]);
		*ip = ret;
	}
}

