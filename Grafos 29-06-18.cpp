//Marcos Martins De Souza

#include <stdlib.h>
#include <stdio.h>

void calculo(int x,int qtdVert);

char matriz [100][100];
int VetEul[100]={0};
int qtdVerticesVisitados = 0,QtdAresta=0,conexo = 1;


int main(){
	int escolha,medidamatriz,vertice,x=0,y=0,w=0,q=0;
	
	printf("\nDigite a quantidade de vertices: ");
	scanf("%d", &medidamatriz);
		medidamatriz=medidamatriz+1;
		for ( x=1; x<medidamatriz; x++ ){
    	for ( y=1; y<medidamatriz; y++ ){
			
		matriz[x][y]=NULL;
		
		if(x==y){
		matriz[x][y]='0';	
			}
		}
		}
		
	int z=medidamatriz;
	
	printf("\n");
  	do{
        printf("1 Adicionar Vertice\n");
        printf("2 Remover Vertice\n");
        printf("3 Arestas\n");
        printf("4 Contagem de Vertices\n");
        printf("5 Contagem de Arestas\n");
        printf("6 Grau dos Vertices\n");
        printf("7 Verificar Grafo Euleriano\n");
        printf("8 Exibir Matriz\n");
        printf("0 Sair\n\n");

        printf("Opção: ");
		scanf("%d", &escolha);
		 printf("\n");

		switch(escolha){
			case 1:
				printf("Digite o vertice para Adicionar: ");
				scanf("%d", &vertice);
				for ( y=1; y<=z; y++ ){
				matriz[vertice][y]= NULL;
				matriz[y][vertice]= NULL;}
				if(vertice==y){
				matriz[vertice][y]='0';
				}
				printf("\n");
				break;
			case 2:
				printf("Digite o vertice para remover: ");
				scanf("%d", &vertice);
				for ( y=1; y<z; y++ ){
				matriz[vertice][y]=NULL;
				matriz[y][vertice]=NULL;}
				printf("\n");
				break;
			case 3:
                printf ("\nDigite 1 ou 0\n\n");
 
				for ( x=1; x<z; x++ ){
					q=x;
				for ( y=q+1;y<z; y++){
      			 printf ("[%d][%d] = ", x, y);
      			 scanf (" %c",&matriz[ x ][ y ]);
       
    			if(matriz[ x ][ y ] == '0' || matriz[ x ][ y ] == '1'){
    			if(matriz[ x ][ y ] == '1'){
    				QtdAresta++;
				}
        		matriz[y] [x] = matriz[x] [y];	   
    			}
    			}
    			}
    			printf("\n");
                break;
            case 4:
                for ( x=1; x<z; x++ ){
    			for ( y=1; y<z; y++ ){
				if(x==y){
				if(matriz[ x ][ y ] == '0' || matriz[ x ][ y ] == '1')	{
				w++;
				 }
				}
				}
				}
				printf("O numero de vertices e: %d\n",w);
				printf("\n");
                break;
            case 5:
                for ( x=1; x<z; x++ ){
    			for ( y=x+1; y<z; y++ ){
				if(matriz[x][y]=='1'){
				w++;
				}
				}
				}
				printf("O numero de arestas e: %d\n",w);
				printf("\n");
                break;
            case 6:
                for ( x=1; x<z; x++ ){
				w=0;
		
    			for ( y=1; y<z; y++ ){
				if(matriz[x][y]=='1'){
				w++;
				}
				if(y==z-1 && matriz[x][y]!= NULL){
				printf ("Elemento[%d] = %d", x, w);
				}
				}
				printf("\n");
				}
				printf("\n");
                break;
            case 7:
	
    			for(x = 1; x < vertice; x++){
        		calculo(x, vertice);

       			 if(qtdVerticesVisitados+1 != vertice){ 
         		 conexo = 0;                              
                 }
                 }

    			if(conexo == 0){
        		printf("\n Grafo desconexo!");
    			}else{
   			     printf("\n Grafo conexo!");
				}
				printf("\n");
                break;
            case 8:
            	for ( x=1; x<z; x++ ){
    			for ( y=1; y<z; y++ ){
				if(matriz[x][y]=='0' || matriz[x][y]=='1'){
				printf("%d-%d %c ",x,y,matriz[x][y]);
				}
				}
				printf("\n");
				}
				printf("\n");
				break;
			case 0:
				break;
		}
	}while(escolha != 0);
}

void calculo(int x, int qtdVert){
    int y;
	VetEul[x] = 1;
    for(y = 1; y <= qtdVert; y++){
        if(VetEul[y]==0 && matriz[x][y] == '1'){
            qtdVerticesVisitados++;
            calculo(y,qtdVert);
        }
        
    }


}

