/* Newton's backward differential interpolation */
#include <stdio.h>
#include <math.h>
#define N 5
int main(void){
    int i,j;
    float x[N],f[N][N],X,r,p,k;
    for(i=0;i<N;i++) {
        x[i]=2.0+0.1*i;
        f[0][i]=sqrt(x[i]);
    }
    for(i=1;i<N;i++)
        for(j=N-1;j>=i;j--)
            f[i][j]=f[i-1][j]-f[i-1][j-1];
    printf("input X:");
    scanf("%f",&X);
    r=(X-x[N-1])/(x[1]-x[0]);
    p=f[0][N-1];
    k=1.0;
    for(i=1;i<N;i++) {
        k*=(r+i-1)/i;
        p+=k*f[i][N-1];
        printf("p%1d=%f(%f)\n",i,p,sqrt(X)-p);
    }
}

/*
input X:9.2
p1=3.767239(-0.734088)
p2=2.085051(0.948100)
p3=4.806198(-1.773048)
p4=-0.637733(3.670883)
*/