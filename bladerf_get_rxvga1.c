#include <math.h>
#include <matrix.h>
#include <mex.h>
#include "libbladeRF.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    struct bladerf *dev;
    int gain;
    int ret;
    long long *ip;
    int *sp_ptr;

    if (nrhs < 1)
        return;

    ip = (long long *)mxGetPr(prhs[0]);
    dev = (struct bladerf *)*ip;

    ret = bladerf_get_rxvga1(dev, &gain);

    if (nlhs >= 2) {
        plhs[1] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
        ip = (long long *)mxGetData(plhs[1]);
        *ip = (long long)gain;
    }

    if (nlhs >= 1) {
        plhs[0] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
        ip = (long long *)mxGetData(plhs[0]);
        *ip = ret;
    }
}