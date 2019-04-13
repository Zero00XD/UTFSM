#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
int InsCur(alumno *A, int z, int id_curso){
    int i;
    for (i = 0; i < 50; i++){
        if (A[z].id_cursos_inscritos[i]==id_curso){
            return 1;
        }
    }
    return 0;
}

void reordenador(alumno *A, int n){
    int i, j;
    alumno aux;
    for (i = 0; i < n; i++){
        srand(time(NULL));
        j=rand()%n;
        aux=A[i];
        A[i]=A[j];
        A[j]=aux;
    }
}
//other weird shity curso reader

int main(void){
    int n,m,i,j,k,g,z,max,miembros,grupo;
    alumno *A;
    curso *C;
    FILE *fp,*fp2;
    fp = fopen("cursos.dat","r");
    if (fp==NULL){
        printf("Error al abrir el archivo");
        exit(1);
    }
    fread(&m,sizeof(int),1,fp); //con esto ya tengo la cantidad de structs que debo buscar
    C=(curso*)malloc(sizeof(curso)*m);
    for(i = 0;i<m;i++){
        fread(&C[i],sizeof(curso),m,fp);
    }
    fclose(fp);
    fp = fopen("alumnos.dat","r");
    if (fp==NULL){
        printf("Error al abrir el archivo");
        exit(1);
    }
    fread(&n,sizeof(int),1,fp);
    A=(alumno*)malloc(sizeof(alumno)*n);
    for (j = 0; j<n; j++){
        fread(&A[j],sizeof(alumno),n,fp);
    }
    fclose(fp);
    reordenador(A, n);
    char Narc[30] = "grupos-000000.txt";
    for (k = 0; k < m; k++){
        max=C[k].integrantes_por_grupo;
        if (max>0){
            for (g = 7; g < 13;g++){
                Narc[g] = C[k].sigla_curso[g-7];
            }
            fp2 = fopen(Narc, "w");
            fprintf(fp2, "%s - %s\n\n", C[k].sigla_curso,C[k].nombre_curso);
            miembros = 1;
            grupo = 1;
            fprintf(fp2, "Grupo %d:\n", grupo);
            for (z = 0; z < n; z++){
                if (InsCur(A, z, C[k].id_curso)==1){
                    if (miembros==max){
                        grupo++;
                        fprintf(fp2, "Grupo %d:\n", grupo);
                        miembros=1;
                    }
                    miembros++;
                    fprintf(fp2, "%s\n", A[z].nombre_completo);
                }
            }
            fclose(fp2);
        }
    }
    free((void*)C);
    free((void*)A);
    return 0;
}
