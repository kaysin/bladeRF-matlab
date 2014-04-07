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

    if (nrhs < 2)
        return;

    ip = (long long *)mxGetPr(prhs[0]);

    dev = (struct bladerf *)*ip;
    gain = (int)*(double *)mxGetData(prhs[1]);

    ret = bladerf_set_rxvga2(dev, gain);

    if (nlhs >= 1) {
        plhs[0] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
        ip = (long long *)mxGetData(plhs[0]);
        *ip = ret;
    }
}