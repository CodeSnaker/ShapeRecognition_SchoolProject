#include <stdio.h>
#include <stdlib.h>

#include "legendreMethodes.h"
#include "myBmpGris.h"

int main() {
    
    BmpImg img = readBmpImage("dataBase/Pentagone.bmp", "Pentagone.bmp");

    int* or = malloc( 3*sizeof(int));
    double** mat = momentGeometrique( img, 1 );

    printf("%lf\t%lf\t%lf\n\n", mat[0][0], mat[1][0], mat[0][1] );

    double a, b , c;
    a = sommeMoment( img, 0, 0);
    b = sommeMoment( img, 1, 0);
    c = sommeMoment( img, 0, 1);



    printf("%lf\t%lf\t %lf\n", a,b/a, c/a);

    for( int i = 0; i <= 1; i++ ) {
        free( mat[i] );
    }

    free( mat );
    free( or );

    return 0;
}