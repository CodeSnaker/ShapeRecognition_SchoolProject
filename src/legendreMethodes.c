#include <stdio.h>
#include <stdlib.h>
#include "legendreMethodes.h"
#include "myBmpGris.h"
#include <math.h>

int pixelValue( BmpImg img, int x, int y ) {

    if ( img.img[x][y] ) {

        return 1;

    }

    return 0;
}


double sommeMoment( BmpImg img, int p, int q ) {
    double sum1 = 0, sum2 = 0;

    for ( int i = 0; i < img.dimX ; i++ ) {

        for ( int j = 0; j < img.dimY; j++ ) {

            sum1 += pow( i, p ) * pow( j, q ) * pixelValue( img, i, j ); //on utilise pixelValue() pour convertir les pixels a 255 a 1

        }
        sum2 += sum1;

        sum1 = 0;
    }

    return sum2;
}

double** momentGeometrique(  BmpImg img, int n ) {
    
    double** res;

    res = malloc( n * sizeof( double* ) );

    if ( res == NULL ) {

        printf("Error : couldn't assign memory to res in momentGeometrique\n");
        return res;

    }

    for( int i = 0; i < n; i++ ) {
        res[i] = calloc( n-i, sizeof( double ) );
    }


    for ( int p = 0; p <= n; p++ ) {
        
        for( int q = 0; p + q <= n; q++ ) {

            res[p][q] = sommeMoment(  img, p, q ); 

        }

    }
    
    return res;

}