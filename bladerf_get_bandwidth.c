#include <math.h>
#include <matrix.h>
#include <mex.h>
#include "libbladeRF.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    struct bladerf *dev;
	bladerf_module mod;
	int ret, bw;
	long long *ip;
	int *m_ptr;

	if (nrhs < 2)
		return;

	ip = (long long *)mxGetPr(prhs[0]);
	m_ptr = (int *)mxGetPr(prhs[1]);

	dev = (struct bladerf *)*ip;
	mod = (bladerf_module)(*m_ptr);

	
	ret = bladerf_get_bandwidth(dev, mod, &bw);

	if (nlhs >= 2) {
		plhs[1] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
		ip = (long long *)mxGetData(plhs[1]);
		*ip = bw;
	}

	if (nlhs >= 1) {
		plhs[0] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
		ip = (long long *)mxGetData(plhs[0]);
		*ip = ret;
	}
}

