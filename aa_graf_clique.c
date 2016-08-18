#include <stdio.h>
#include <stdlib.h>

void clique( int **G, int Tam, int Ct);

void zeraList(int *list, int T);

int* grauVert(int *vet, int **G, int aux, int Tam);

int main()
{
	int mat[6][6],i ,j;
	int *l = (int*) malloc(sizeof(int)); 
	zeraList(l);
	for(i= 0; i < 6; i++)
		for(j=0; j<6;j++){
			mat[i][j]=0;
		}

	mat[0][1] = 1;
	mat[1][0] = 1;
	mat[0][3] = 1;
	mat[3][0] = 1;
	mat[1][5] = 1;
	mat[5][1] = 1;
	mat[3][5] = 1;
	mat[5][3] = 1;
	mat[3][2] = 1;
	mat[2][3] = 1;
	mat[4][5] = 1;	
	mat[5][4] = 1;
	mat[4][2] = 1;
	mat[3][4] = 1;

	l = clique(mat,6,3);

	for(i=0;i<6;i++)
	{
		if(l[i] != 0)
			printf("%d \t",l[i]);
	}

	return 0;
}

int* grauVert(int *vet, int **G, int aux, int Tam)
{
	int i,j;
	 for(i = 0; i < Tam; i++)
	 {
	   	for(j = 0; j < Tam; j++){
	   		if((i != j ) && (G[i][j] != 0))
	   			aux++;
	   	}
	   	vet[i] = aux;
	   	aux = 0;
	 }
	   return vet;
}

int maiorGrau(int *vet,int Tam)
{
	int aux = 0;
   for(i=1; i < Tam; i++)
   	if(vet[i] > vet[aux]){
   		aux = i; // armazenar o indice do vertice com grau maior	
  
   	}
  return aux;
}

void zeraList(int *list, int T)
{
	int i;

	for(i = 0; i< T; i++)
		list[i] = 0 ;
}

int* clique( int **G, int Tam, int Ct) 
{ 
   int grau, cont = Tam, i, j, aux=0, conL= 0;
   int *visitado;
   int *vet;
   int list[Tam]; //criar uma lista

      vet = (int*) malloc(Tam *sizeof(int));
      visitado = (int*) malloc(Tam *sizeof(int));
		//vetor para marcar os vertices visitados
	for(i =0; i < Tam; i++)
	{
		ant[i] = -1;
		vet = 0;
		visitado[i] = 0;
	}
  
 	vet = grauVert(vet, G, Tam);

   
	aux = maiorGrau(vet,Tam);  //aux recebe o vertice de maior grau  
	grau =  vet[aux];
	vet[aux] = -1; //colocar -1 para na proxima pesquisa não cair no mesmo vertice

   for (v = 0; v < G->V; v++)
      num[v] = -1; // marcar vertices com -1 para vertices nao visitados

  
   num[aux] = conta++;  // marca no vetor como visitado o vertice que ira iniciar a busca
   
   list [conL] =  aux ;     // inserir vertice inicial na lista 
   conL++;				//contador dos indices da lista
 

	while(cont > 0)
	{
		
        if(Ct > vet[aux])
        	{
        		break; // busca por um clique que não existe
        	}    

		visitado[aux] = 1;
		cont--;

		for(i =0; i < Tam; i++)
		{
			if(G[aux][i] == 1)
            {

                //pegar os vertices adjascentes
                list[conL] = i;
                conL++;

            	//verificar se existe algum clique igual ao numero armazenado na variavel Ct


                if(Ct == ) //Clique é de tamanho igual a Ct
                {
                	 // retorne o clique
                }
                else	//caso nao econtre o clique, fazer a busca em outro vertice
                {
                	zeraList(list);  
                	conL = Tam;

                }
			}
		}
   
}