#include <math.h>
#include <matrix.h>
#include <mex.h>
#include "libbladeRF.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    struct bladerf *dev;
    char path[255*3];
    int gain;
    int ret;
    long long *ip;
    int *sp_ptr;

    if (nrhs < 2)
        return;

    ip = (long long *)mxGetPr(prhs[0]);
    mxGetString(prhs[1], path, sizeof(path) - 1);
	dev = (struct bladerf *)*ip;

    ret = bladerf_load_fpga(dev, path);

    if (nlhs >= 1) {
        plhs[0] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
        ip = (long long *)mxGetData(plhs[0]);
        *ip = ret;
    }
}

