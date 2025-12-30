#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) 
{
	int i,j;
	int pom = mat->r;
	
	if(pom != mat->c || pom != b->r || pom != x->r)
	{
		return 2; // zwracanie wartosci 2 jesli sa nieprawidlowe rozmiary
	}

	for(i = pom-1 ; i>=0;i--)
	{
		if(mat->data[i][i] ==0)
		{
			return 1; //zwracanie 1 jesli ma miejsce dzielenie przez 0
		}
	
		double s=0;
		for(j = i+1;j < pom;j++)
		{
			s+=mat->data[i][j] * x->data[j][0];
		}
		x-> data[i][0] = (b->data[i][0] -s) / (mat->data[i][i]);
	}
	return 0;
}


