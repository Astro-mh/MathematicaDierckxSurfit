# Mathematica Diercx surfit link

This is a package to link the netlib DIERCX surfit routines to Mathematica using Mathematica's WSTP mechanism.

It is still at a very early stage of development, and is missing a build phase and error checking.

The original code can be found at [netlib](http://www.netlib.org/dierckx/)

It includes two slightly altered routines, bispevSA and fpbispSA which return the fitted points only at the positions specified by the arrays x and yorig, as opposed to the original which returned a grid specified by x and y.

On a Cent OS 7 machine with a standard Mathematica install this has been successfully compiled with the following commands:
```
gfortran -c bispev.f -o bispev.o
gfortran -c bispevSA.f -o bispevSA.o
gfortran -c fpback.f -o fpback.o
gfortran -c fpbisp.f -o fpbisp.o
gfortran -c fpbispSA.f -o fpbispSA.o
gfortran -c fpbspl.f -o fpbspl.o
gfortran -c fpdisc.f -o fpdisc.o
gfortran -c fpgivs.f -o fpgivs.o
gfortran -c fporde.f -o fporde.o
gfortran -c fprank.f -o fprank.o
gfortran -c fprati.f -o fprati.o
gfortran -c fprota.f -o fprota.o
gfortran -c fpsurf.f -o fpsurf.o
gfortran -c surfit.f -o surfit.o

/usr/local/Wolfram/Mathematica/11.0/SystemFiles/Links/WSTP/DeveloperKit/Linux-x86-64/CompilerAdditions/wsprep dierckxWSTPlinkTemplate.tm -o dierckxWSTPlinkTemplate.c
gcc -I/usr/local/Wolfram/Mathematica/11.0/SystemFiles/Links/WSTP/DeveloperKit/Linux-x86-64/CompilerAdditions/ -g -c dierckxWSTPlinkTemplate.c -o dierckxWSTPlinkTemplate.o
gcc dierckxWSTPlinkTemplate.o dierckxWSTPlink.o bispev.o bispevSA.o fpback.o fpbisp.o fpbispSA.o fpbspl.o fpdisc.o fpgivs.o fporde.o fprank.o fprati.o fprota.o fpsurf.o surfit.o /usr/local/Wolfram/Mathematica/11.0/SystemFiles/Links/WSTP/DeveloperKit/Linux-x86-64/CompilerAdditions/libWSTP64i4.a -lstdc++ -lm -pthread -ldl -lrt -luuid  -o dierckxWSTPlink
```

Refer to the Mathematica documentation to see how to run the resulting code using the Install[] command.
