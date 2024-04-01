void saxpy_c(int n, float a, float* x, float* y, float* z) {
    int i;
    for (i = 0; i < n; i++) {
        z[i] = a * x[i] + y[i];
    }
}