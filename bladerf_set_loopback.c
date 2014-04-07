#include <math.h>
#include <matrix.h>
#include <mex.h>
#include "libbladeRF.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    struct bladerf *dev;
	bladerf_loopback lp;
	int ret;
	long long *ip;
	int *lp_ptr;

	if (nrhs < 2)
		return;

	ip = (long long *)mxGetPr(prhs[0]);
	lp_ptr = (int *)mxGetPr(prhs[1]);

	dev = (struct bladerf *)*ip;
	lp = (bladerf_loopback)*(double *)mxGetData(prhs[1]);

	
	ret = bladerf_set_loopback(dev, lp);

	if (nlhs >= 1) {
		plhs[0] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
		ip = (long long *)mxGetData(plhs[0]);
		*ip = ret;
	}
}

