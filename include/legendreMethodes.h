#ifndef _LEGENDREMETHODES_H_

#define _LEGENDREMETHODES_H_

#include <stdio.h>
#include <stdlib.h>
#include "myBmpGris.h"
#include <math.h>


/**
 * @brief Renvoie 1 si le pixel n'est pas de valeur 0
 * 
 * @param img 
 * @param x 
 * @param y 
 * @return int 
 */
int pixelValue( BmpImg img, int x, int y );

/**
 * @brief calcule le moment geometrique M(p,q) 
 * 
 * @param img Une image format Bmp sur laquelle on utilise readBmpImg() de 'myBmpGris.h'
 * @param p 
 * @param q p et q sont les coefficients de puissance utilises dans la formule
 * @return double : le moment geometrique M(p,q) 
 */
double sommeMoment( BmpImg img, int p, int q );


/**
 * @brief calcule les moments geometriques d'une image Bmp et les stocke dans une matrice
 * 
 * @param img Une image format Bmp sur laquelle on utilise readBmpImg() de 'myBmpGris.h'
 * @param n est le parametre dans la formule, ou on a p+q <= n
 * @return double** : matrice qui contient les moments M(p,q)
 * les moments correspondants se trouvent aux coordonnees (p, q) de la matrice
 * ! Il faut noter que la matrice retournee est une matrice triangulaire inversee
 */
double** momentGeometrique(  BmpImg img, int n );



#endif