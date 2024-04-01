# MCO2-LBYARCH

### Debug Version for N = 20
![Debug 20](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/84b0a5f1-6157-4784-9d99-fd7ccaea4829)

### Release Version for N = 20
![Release 20](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/f2207aad-9c7d-4cd6-9d5b-ee5f4a74b684)

### Debug Version for N = 24
![Debug 24](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/b5f0537f-4365-41a9-8908-510c473afa16)

### Release Version for N = 24
![Release 24](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/166219fe-91dc-4c43-a4ff-cd1456704796)

### N = 30 Error
![Error with 30](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/2512a7f1-5627-466c-b3a8-b2ad467ec464)

### Debug Version for N = 29
![Debug 29](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/27157e2c-5882-475a-b83c-2b8b2c13a9d4)

### Release Version for N = 29
![Release 29](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/3d968078-f648-45e3-a719-11051b36d8aa)

## Comparative Execution and Analysis of the Kernels

The vector sizes (n) that were used for both versions of the kernel were: 20, 24, and 29. A size of N = 30 was attempted but it resulted in memory allocation failure because the machine could not support the large data size. As the size of N increases, it is apparent that the average time to finish the function for both kernels also increases thus indicating that they are directly proportional. 

For each size of N, the tests were run for both the Debug and Release versions. It is important to note that for all sizes of N, the release version is significantly faster than its debug counterpart. This is because the Debug version contains information in the compiled file used for easy debugging of the program. The Release version, on the other hand, has optimizations enabled that configure the program making it run faster (https://stackoverflow.com/questions/933739/what-is-the-difference-between-release-and-debug-modes-in-visual-studio). 

Lastly, it is important to highlight that the x86 Kernel is faster in all vector sizes of N in the Debug version but is sometimes slower than the C kernel in the Release versions. This is mainly because of the reason stated above that the Release version is optimized and significantly decreases the runtime of the C program.
