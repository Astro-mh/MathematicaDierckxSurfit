#include "wstp.h"
#include "stdlib.h"

int mymax(int a, int b) {
    
    return a > b ? a : b;
}

void surfit(int iopt, int m) {
    
    float *x;
    int xlen;
    float *y;
    int ylen;
    float *z;
    int zlen;
    float *w;
    int wlen;
    float xb;
    float xe;
    float yb;
    float ye;
    int kx;
    int ky;
    float s;
    int nxest;
    int nyest;
    int nmax;
    float eps;
    int nx;
    float * tx;
    int txlen;
    int ny;
    float * ty;
    int tylen;
    
    WSGetReal32List(stdlink,&x,&xlen);
    WSGetReal32List(stdlink,&y,&ylen);
    WSGetReal32List(stdlink,&z,&zlen);
    WSGetReal32List(stdlink,&w,&wlen);
    WSGetReal32(stdlink,&xb);
    WSGetReal32(stdlink,&xe);
    WSGetReal32(stdlink,&yb);
    WSGetReal32(stdlink,&ye);
    WSGetInteger32(stdlink,&kx);
    WSGetInteger32(stdlink,&ky);
    WSGetReal32(stdlink,&s);
    WSGetInteger32(stdlink,&nxest);
    WSGetInteger32(stdlink,&nyest);
    WSGetInteger32(stdlink,&nmax);
    WSGetReal32(stdlink,&eps);
    WSGetInteger32(stdlink,&nx);
    WSGetReal32List(stdlink,&tx,&txlen);
    WSGetInteger32(stdlink,&ny);
    WSGetReal32List(stdlink,&ty,&tylen);
    
    
    float * c;
    float fp;
    float * wrk1;
    int lwrk1;
    float * wrk2;
    int lwrk2;
    int * iwrk;
    int kwrk;
    int ier;
    
    int cwrk;

    int u;
    int v;
    int km;
    int ne;
    int bx;
    int by;
    int b1;
    int b2;

    
    
    cwrk = (nxest-kx-1)*(nyest-ky-1);
    
    c = (float *) malloc(sizeof(float)*cwrk);
    
    u = nxest-kx-1;
    v = nyest-ky-1;
    km = mymax(kx,ky)+1;
    ne = mymax(nxest,nyest);
    bx = kx*v+ky+1;
    by = ky*u+kx+1;
    
    if(bx <= by){
        b1 = bx;
        b2 = b1+v-ky;
    }
    
    if(bx > by){
        b1 = by;
        b2 = b1+u-kx;
    }
    
    lwrk1 = u*v*(2+b1+b2)+2*(u+v+km*(m+ne)+ne-kx-ky)+b2+1;
    
    wrk1= (float *) malloc(sizeof(float)*lwrk1);
    
    lwrk2 = u*v*(b2+1)+b2;
    
    wrk2= (float *) malloc(sizeof(float)*lwrk2);
    
    kwrk = m+(nxest-2*kx-1)*(nyest-2*ky-1);
    
    iwrk= (int *) malloc(sizeof(int)*kwrk);
   
    
    surfit_(&iopt,&m,x,y,z,w,&xb,&xe,&yb,&ye,&kx,&ky,&s,&nxest,&nyest,&nmax,&eps,&nx,tx,&ny,ty,c,&fp,wrk1,&lwrk1,wrk2,&lwrk2,iwrk,&kwrk,&ier);

    WSPutFunction(stdlink, "List", 7);
    WSPutInteger32(stdlink,nx);
    WSPutReal32List(stdlink,tx,nmax);
    WSPutInteger32(stdlink,ny);
    WSPutReal32List(stdlink,ty,nmax);
    WSPutReal32List(stdlink,c,cwrk);
    WSPutReal32(stdlink,fp);
    WSPutInteger32(stdlink,ier);
    
    WSReleaseReal32List(stdlink,x,xlen);
    WSReleaseReal32List(stdlink,y,ylen);
    WSReleaseReal32List(stdlink,z,zlen);
    WSReleaseReal32List(stdlink,w,wlen);
    WSReleaseReal32List(stdlink,tx,txlen);
    WSReleaseReal32List(stdlink,ty,tylen);
    
    free(c);
    free(wrk1);
    free(wrk2);
    free(iwrk);
    
    return;
}

void bispev() {
    
    
    float * tx;
    int nx;
    float * ty;
    int ny;
    float * c;
    int clen;
    int kx;
    int ky;
    float *x;
    int mx;
    float *y;
    int my;
    
    
    WSGetReal32List(stdlink,&tx,&nx);
    WSGetReal32List(stdlink,&ty,&ny);
    WSGetReal32List(stdlink,&c,&clen);
    WSGetInteger32(stdlink,&kx);
    WSGetInteger32(stdlink,&ky);
    WSGetReal32List(stdlink,&x,&mx);
    WSGetReal32List(stdlink,&y,&my);

    float * wrk;
    int lwrk;
    int * iwrk;
    int kwrk;
    
    float *z;
    int ier;
    
    lwrk = mx*(kx+1)+my*(ky+1);
    wrk = (float *) malloc(sizeof(float)*lwrk);
    
    kwrk = mx+my;
    iwrk = (int *) malloc(sizeof(int)*kwrk);
    
    z = (float *) malloc(sizeof(float)*mx*my);
    
    bispev_(tx,&nx,ty,&ny,c,&kx,&ky,x,&mx,y,&my,z,wrk,&lwrk,iwrk,&kwrk,&ier);
    
    WSPutFunction(stdlink, "List", 2);
    WSPutReal32List(stdlink,z,mx*my);
    WSPutInteger32(stdlink,ier);
    
    
    WSReleaseReal32List(stdlink,tx,nx);
    WSReleaseReal32List(stdlink,ty,ny);
    WSReleaseReal32List(stdlink,c,clen);
    WSReleaseReal32List(stdlink,x,mx);
    WSReleaseReal32List(stdlink,y,my);
    
    free(wrk);
    free(iwrk);
    free(z);
    
    return;
}

void bispevSA() {
    
    
    float * tx;
    int nx;
    float * ty;
    int ny;
    float * c;
    int clen;
    int kx;
    int ky;
    float *x;
    int mx;
    float *y;
    int my;
    int *yorig;
    int yoriglen;
    
    
    WSGetReal32List(stdlink,&tx,&nx);
    WSGetReal32List(stdlink,&ty,&ny);
    WSGetReal32List(stdlink,&c,&clen);
    WSGetInteger32(stdlink,&kx);
    WSGetInteger32(stdlink,&ky);
    WSGetReal32List(stdlink,&x,&mx);
    WSGetReal32List(stdlink,&y,&my);
    WSGetInteger32List(stdlink,&yorig,&yoriglen);
    
    float * wrk;
    int lwrk;
    int * iwrk;
    int kwrk;
    
    float *z;
    int ier;
    
    lwrk = mx*(kx+1)+my*(ky+1);
    wrk = (float *) malloc(sizeof(float)*lwrk);
    
    kwrk = mx+my;
    iwrk = (int *) malloc(sizeof(int)*kwrk);
    
    z = (float *) malloc(sizeof(float)*mx);
    
    bispevsa_(tx,&nx,ty,&ny,c,&kx,&ky,x,&mx,y,&my,yorig,z,wrk,&lwrk,iwrk,&kwrk,&ier);
    
    WSPutFunction(stdlink, "List", 2);
    WSPutReal32List(stdlink,z,mx);
    WSPutInteger32(stdlink,ier);
    
    
    WSReleaseReal32List(stdlink,tx,nx);
    WSReleaseReal32List(stdlink,ty,ny);
    WSReleaseReal32List(stdlink,c,clen);
    WSReleaseReal32List(stdlink,x,mx);
    WSReleaseReal32List(stdlink,y,my);
    WSReleaseInteger32List(stdlink,yorig,yoriglen);
    
    free(wrk);
    free(iwrk);
    free(z);
    
    return;
}

int main(int argc, char *argv[]) {
    return WSMain(argc, argv);
}
