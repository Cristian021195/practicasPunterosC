#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct Tarea {
	int tareaID; //Numerado en ciclo iterativo
	char *desc; //
	int duracion; // entre 10 – 100
}Tarea;
char descripcion[5][12] = {"administrar","borrar","contar","deshacer","fijar"};


void cargarTareas(Tarea **tareasT, int cant);
void mostrarTareas(Tarea **tareasT, int cant);
void controlTareas(Tarea **tareasPendientes, Tarea **tareasRealizadas, int cant);
void cargarTareasVacias(Tarea **tareasTR, int cant);

int main(){
	srand(time(NULL));
	int cant;
	printf("Ingrese la cantidad de tareas: ");scanf("%d", &cant);fflush(stdin);
	Tarea **tareasPendientes = (Tarea **) malloc(sizeof(Tarea*)*cant);
	Tarea **tareasRealizadas = (Tarea **) malloc(sizeof(Tarea*)*cant);
	cargarTareas(tareasPendientes, cant);
	cargarTareasVacias(tareasRealizadas, cant);
	mostrarTareas(tareasPendientes, cant);
	controlTareas(tareasPendientes, tareasRealizadas, cant);
	printf("\n***************TAREAS REALIZADAS ***************\n");
	mostrarTareas(tareasRealizadas, cant);
	printf("\n***************TAREAS PENDIENTES ***************\n");
	mostrarTareas(tareasPendientes, cant);
}
void controlTareas(Tarea **tareasPendientes, Tarea **tareasRealizadas, int cant){
	int cond = 0;
	
	for(int i = 0; i < cant; i++){
		printf("Tarea: %s , ID: %d: se realizo?\n 1 si - 2 no\n", tareasPendientes[i]->desc, tareasPendientes[i]->tareaID);
		scanf("%d", &cond);fflush(stdin);
		
		while(cond != 1 && cond != 2){
			printf("Se realizo mal la entrada\n");
			printf("Tarea: %s , ID: %d: se realizo?\n 1 si - 2 no\n", tareasPendientes[i]->desc, tareasPendientes[i]->tareaID);
			scanf("%d", &cond);fflush(stdin);
		}
		if(cond == 1){
			//tareasTR[i] = (Tarea *)malloc(sizeof(Tarea));
			tareasRealizadas[i] = tareasPendientes[i];
			tareasPendientes[i] = NULL;
		}else {
			tareasRealizadas[i] = NULL;
		}
	}
}

void cargarTareasVacias(Tarea **tareasTR, int cant){
	for(int i = 0; i < cant; i++){
		tareasTR[i] = (Tarea *)malloc(sizeof(Tarea));
	}
}
void cargarTareas(Tarea **tareasT, int cant){
	for(int i = 0; i < cant; i++){
		tareasT[i] = (Tarea *)malloc(sizeof(Tarea));
		tareasT[i]->tareaID = i+1;
		tareasT[i]->duracion = (rand()%90 + 10);
		tareasT[i]->desc = descripcion[rand()%5];
	}
}
void mostrarTareas(Tarea **tareasT, int cant){
	for(int i = 0; i<cant; i++){
		printf("\nID: %d", tareasT[i]->tareaID);
		printf("\nDUR: %d", tareasT[i]->duracion);
		printf("\nDESC: %s", tareasT[i]->desc);
		printf("\n**************\n");
	}
}
