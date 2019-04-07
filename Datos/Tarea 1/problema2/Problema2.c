#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int compare_function(const void * a, const void * b ) {
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;
    return strcmp(pa,pb);
}


int pCML(char**S,int n){
    qsort(S,n,sizeof(S),compare_function);
    char anterior=S[0][0];
    int prefix=0;
    int realPrefix=0;
    if(n<=2){
        if(anterior==(S[1][0])){
            int i=0;
            while((S[0][i])==(S[1][i])&&(S[1][i]!='\n')){
                prefix++;
                i++;
            }if(prefix>realPrefix){realPrefix=prefix;}
        }

    }else{

        for(int i=1;i<n;i++){ //recorremos el arreglo S
            char actual=(S[i][0]);
            if(anterior==actual&&actual!=EOF){
                int j=0;
                prefix=0;
                while(S[i-1][j]==(S[i][j])&&(S[i][j]!='\n')){
                    prefix++;
                    j++;
                }
                if((S[i][j+1])=='\n'){prefix--;}
                if(prefix>realPrefix){realPrefix=prefix;}
            }
            anterior=actual;
            prefix=0;

        }
    }
    return realPrefix;
}


int main(){
    clock_t t; 
    t = clock(); 
    int contador=0;
    FILE*fp=fopen("string.txt","r");
    char*palabra=(char*) malloc(202*sizeof(char));
    char**arreglo=(char**)malloc(100000000*sizeof(palabra));
    free(palabra);
    if(fp!=NULL){
        while(!feof(fp)){
            char*palabra=(char*) malloc(202*sizeof(char));
            fgets(palabra,202,fp);
            arreglo[contador]=palabra;
            contador++; 
            }
        }
    int comun = pCML(arreglo,contador);
    fclose(fp);
    FILE*output=fopen("salida-1.txt","w");
    fprintf(output,"%d",comun);
    fclose(output);
    free(arreglo);
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("EL programa tardo %f segundos",time_taken);

    return 0;
}

