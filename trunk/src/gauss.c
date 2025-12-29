#include "gauss.h"
#include <math.h>
 
/**
* Zwraca 0 - elimnacja zakonczona sukcesem
* Zwraca 1 - macierz osobliwa - dzielenie przez 0
*/
int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->r;
    int i, j, k;
 
    if (mat->r != mat->c || mat->r != b->r) return 1; 
 
    for (k = 0; k < n - 1; k++) {
 
        // e +-= 0, m.osobliwa
        if (fabs(mat->data[k][k]) < 1e-12) return 1; 
 
        // gaus
        for (i = k + 1; i < n; i++) {
            double factor = mat->data[i][k] / mat->data[k][k];
            mat->data[i][k] = 0;
            for (j = k + 1; j < n; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }
	
    if (fabs(mat->data[n-1][n-1]) < 1e-12) return 1;
 
    return 0;
}