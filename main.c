#include <stdio.h>
#include <stdio.h>
int main(void) {
  int n;
  printf("Quantas camadas da pirâmide você deseja criar? ");
  scanf("%i",&n);
  
  //Alocação da memória:
  int **skibidi = (int **)malloc(n * sizeof(int *));
  if(skibidi==NULL){
    fprintf(stderr,"Não foi possível alocar memória!\n");
    return 0;
  }
  unsigned int z;
  for(z = 0; z < n; z++){
    skibidi[z] = (int *)malloc((z+1) * sizeof(int));
    if(skibidi[z]==NULL){
      fprintf(stderr,"Não foi possível alocar memória!\n");
      return 0;
    }
  }
  if(z != n){
    for(z--; z>=0;z--){
      free(skibidi[z]);
    }
    free(skibidi);
    return 0;
  }

  //Os números da pirâmide são colocados na matriz aqui:
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      if(j == 0 || j == i) {
        skibidi[i][j] = 1;
      } else {
        skibidi[i][j] = skibidi[i-1][j-1] + skibidi[i-1][j];
      }
    }
  }

  //Os números da pirâmide são printados da matriz aqui:
  for(int i = 0; i < n; i++){
    printf("[");
    for(int j = 0; j <= i; j++){
      if(j == 0){printf("%i",skibidi[i][j]);}
      else{printf(",%i",skibidi[i][j]);}
    }
    printf("]\n");
  }
  printf("%i",skibidi[0][1]);
  
  return 0;
}