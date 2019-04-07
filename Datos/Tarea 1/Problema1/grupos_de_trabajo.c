#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int id_curso;
    char sigla_curso[7];
    char nombre_curso[30];
    int integrantes_por_grupo;
} curso;
typedef struct{
    char rol_estudiante[12];
    char carrera[4];
    char nombre_completo[41];
    int numero_cursos;
    int id_cursos_inscritos[50];
} alumno;

//int random_number_generator


//other weird shity curso reader

int main(void){
    FILE*fp=fopen("cursos.dat","r");
    int n,m,i,j;
    fread(&n,sizeof(int),1,fp); //con esto ya tengo la cantidad de structs que debo buscar
    curso C[n];
    for(i=0;i<n;i++){
        fread(&C[i],sizeof(curso),1,fp);
    }

    return C;


    return 0;
}