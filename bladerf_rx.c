#include <math.h>
#include <matrix.h>
#include <mex.h>
#include "libbladeRF.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    long long *ip;
    struct bladerf *dev;
    int n, fmt;
    int i, ret;
    double *out;
    unsigned long *ptr;
    unsigned short val;
    int dims[] = {0, 2};

    if (nrhs < 3 || nlhs < 2)
        return;

    ip = (long long *)mxGetPr(prhs[0]);

	dev = (struct bladerf *)*ip;
    fmt = (int)*(double *)mxGetData(prhs[1]);
    n = (int)*(double *)mxGetData(prhs[2]);

    if (n % 1024)
        return;

    dims[0] = n;

    ptr = (unsigned long *)malloc(sizeof(unsigned long) * n);
    ret = bladerf_rx(dev, BLADERF_FORMAT_SC16_Q12, ptr, n, NULL);

    plhs[0] = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
    ip = (long long *)mxGetData(plhs[0]);
    *ip = ret;
    
    plhs[1] = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
    out = (double *)mxGetPr(plhs[1]);

    for (i = 0; i < n; i++) {
        val = (ptr[i]>>16)&0xffff;
        if ((val & 0xf000) == 0x3000) {
            val &= ~0xf000;
            if (val & 0x800)
                val |= 0xf000;
        }
        out[n + i] = val;

        val = ptr[i]&0xffff;
        if ((val & 0xf000) == 0xb000) {
            val &= ~0xf000;
            if (val & 0x800)
                val |= 0xf000;
        }
        out[i] = val + 2;
    }
    free(ptr);
}
