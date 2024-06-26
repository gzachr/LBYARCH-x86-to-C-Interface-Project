# MCO2-LBYARCH
Created by Bawa, Francis I. and Gomez, Zachary R. (S14)

## I. Intro
The project makes use of a C program that calls two kernels (C and assembly) to perform the same process ( *Z[i] = AX[i] + Y[i]* ) wherein A is a single-precision float and vectors X, Y, and Z are also single-precision floats. A variable *N* determines the length ( 2<sup>N</sup> ) of vectors X, Y, and Z. The program then compares the average execution time of both kernels over 30 different runs per size of N and determines if the output of both kernels is correct by cross-checking.

## II. Setup
![image](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97268058/726c26e3-d2e5-4ecd-9352-a1facbca39e8)

> Ensure that the command line path under the properties of asm file matches the location of the installed nasm.exe on the device for both debug and release mode.

Vector size can be adjusted by editing `const int N = 1 << 20;` in main.c wherein the second integer denotes N in ( 2<sup>N</sup> ).

### Debug Version for N = 20
![Debug 20](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/84b0a5f1-6157-4784-9d99-fd7ccaea4829)

### Release Version for N = 20
![Release 20](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/f2207aad-9c7d-4cd6-9d5b-ee5f4a74b684)

### Debug Version for N = 24
![Debug 24](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/b5f0537f-4365-41a9-8908-510c473afa16)

### Release Version for N = 24
![Release 24](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/bd48ca5e-216d-4c18-bad7-8ee1ace24103)

### N = 30 Error
![Error with 30](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/2512a7f1-5627-466c-b3a8-b2ad467ec464)

### Debug Version for N = 29
![Debug 29](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/27157e2c-5882-475a-b83c-2b8b2c13a9d4)

### Release Version for N = 29
![Release 29](https://github.com/gzachr/LBYARCH-x86-to-C-Interface-Project/assets/97230437/3d968078-f648-45e3-a719-11051b36d8aa)

## Comparative Execution and Analysis of the Kernels

The vector sizes (N) that were used for both versions of the kernel were: 20, 24, and 29. A size of N = 30 was attempted but it resulted in memory allocation failure because the machine could not support the large data size. As the size of N increases, it is apparent that the average time to finish the function for both kernels also increases thus indicating that they are directly proportional. 

For each size of N, the tests were run for both the Debug and Release versions. It is important to note that for all sizes of N, the release version is significantly faster than its debug counterpart. This is because the Debug version contains information in the compiled file used for easy debugging of the program. The Release version, on the other hand, has optimizations enabled that configure the program making it run faster (https://stackoverflow.com/questions/933739/what-is-the-difference-between-release-and-debug-modes-in-visual-studio). 

Lastly, it is important to highlight that the x86 Kernel is faster in all vector sizes of N in the Debug version but is sometimes slower than the C kernel in the Release versions. This is mainly because of the reason stated above that the Release version is optimized and significantly decreases the runtime of the C program.
