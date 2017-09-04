/*
*	Programa: Punteros.
*	Fecha: 27 - Agosto - 2017.
*	Elaborado por: Kelin Alejandra Arboleda - Camila Andrea Borja.
*/

//Librerias
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

//registros de estructuras
struct Alumno{
	char nombre[30];
	int edad;
	float promedio;
}alumno[3], *puntero_alumno = alumno;

struct Etapa{
	int horas, min, seg;
}etapa[3], *puntero_etapa = etapa;

struct competidor{
	char nombre[30], sexo, club[20];
	int edad;
}personal, *pCompetidor = &personal;

struct persona{
    char nombre[30];
    bool discapacidad;
}personas[100], pdiscapacidad[100], psdiscapacidad[100];




//Funciones
void menu();
void arreglos();
void matrices();
void punteros();
void estructuras();

//Funcion Arreglos
void numerosDecimales();
void dosValores();
void dimensionVector();

//Funcion Matrices
void matriz_teclado();
void matriz_automatica();
void matriz_auto_primos();

//Funciones de Punteros
void par_impar();
void numero_primo();
void numeros_pares();
void numero_menor();
void arreglo_dinamico();
void almacenar_numeros();
void vocales();
void cadena_caracteres();
void suma_dinamica();
void matriz_traspuesta();
void estructura_alumno(); 
void estructura_tiempo();

//Funciones de Estructuras
void estruc_competidor();
void estruc_estudiante();
void estruc_trabajadores();
void estruc_promedio();
void estruc_alumnos();
void estruc_representar();
void llenarDatos(int cantidad, persona *personita);
void validarDatos(int cantidad);
void imprimirDatodiscapacidad();
void imprimirDatosindiscapacidad();

persona *puntpersonas = personas;
persona *ppdiscapacidad = pdiscapacidad; 
persona *ppsdiscapacidad = psdiscapacidad;
int con = 0, sin = 0;

//Funcion principal 
int main(){
	
	menu();
	
	return 0;
}

//Menu principal
void menu(){
	int opcion;
	do{
		printf(".............................\n");
        printf(".       MENU PRINCIPAL      .\n");
        printf(".............................\n");
        printf(".                           .\n");
        printf(".  1. ARREGLOS              .\n");
        printf(".  2. MATRICES              .\n");
        printf(".  3. PUNTEROS              .\n");
        printf(".  4. ESTRUCTURAS           .\n");
        printf(".  0. SALIR                 .\n");
        printf(".............................\n");
        printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: arreglos();
				break;
			case 2: matrices();
				break;
			case 3: punteros();
				break;
			case 4: estructuras();
				break;
			case 0: exit(0);
				break;
			default: printf("Opcion no valida\n");
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}

void arreglos(){
	int opcion;
	do{
		printf("\n..............................");
		printf("\n.       ARREGLOS             .");
		printf("\n..............................");
		printf("\n.  1. Ver 4 Valores          .");
		printf("\n.  2. Ingresar dos valores   .");
		printf("\n.  3. Ingrese 4 Valores      .");
		printf("\n.  0. salir                  .");
		printf("\n..............................");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: numerosDecimales();
				break;
			case 2: dosValores();
				break;
			case 3: dimensionVector();
				break;
			case 0: menu();
				break;
			default: printf("Opcion no valida\n");
		}
		system("pause");
		system("cls");
    }while(opcion != 0);	
}

void numerosDecimales(){
	float arreglo[] = {32.583, 11.239, 45.781, 22.237};
	float* pArreglo = arreglo;
	for(int i = 0; i < 4; i++){
		printf("%.3f \n", *(pArreglo + i));
	}
}

void dosValores(){
	int matriz[100][100], fil, col, f, c;
	int *pMatriz = &matriz[0][0];
	
	printf("\nIngrese La Cantidad De Filas: ");
	scanf("%d", &fil);
	printf("\nIngrese La Cantidad De Columnas: ");
	scanf("%d", &col);
	for(f = 0; f < fil; f++){
		for(c = 0; c < col; c++){
			if(f == c){
				*(pMatriz + c + f * col) = 1;
			}else{
				*(pMatriz + c + f * col) = 0;
			}
		}
	}
	printf("\n");
	for(f = 0; f < fil; f++){
		for(c = 0; c < col; c++){
			printf("%d ", *(pMatriz + c + f * col));
		}
		printf("\n");
	}
}

void dimensionVector(){
	int matriz[4][4];
	int *p_matriz = &matriz[0][0];
	int f, c;
	int acum=1;

	for(f = 0; f < 4; f++){
        printf("Ingrese un numero: ");
		scanf("%d", &(*(p_matriz + f *4)));
		acum = *(p_matriz + f * 4);
		for(c = 1; c < 4; c++){
			acum = acum * *(p_matriz + f *4);
			*(p_matriz + c + f  * 4) = acum;
		}
	}
	for(f = 0; f < 4; f++){
        for(c = 0; c < 4; c++){
            printf("%d   ", *p_matriz++);
		}
		printf("\n");
	}
}

void matrices(){
	int opcion;
	do{
		printf("\n.............................................");
		printf("\n.                  MATRICES                 .");
		printf("\n.............................................");
		printf("\n.  1. Complete los valores de la matriz     .");
		printf("\n.  2. Matriz automatica                     .");
		printf("\n.  3. Matriz automatica con numeros primos  .");
		printf("\n.  0. salir                                 .");
		printf("\n.............................................");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: matriz_teclado();
				break;
			case 2: matriz_automatica();
				break;
			case 3: matriz_auto_primos();
				break;
			case 0: menu();
				break;
			default: printf("Opcion no valida\n");
		}
		system("pause");
		system("cls");
	}while(opcion !=0);
	
}
void matriz_teclado(){
	int l = 3, matriz[l][l], suma = 0, f, c;
	int *pMatriz = &matriz[0][0];
	
	//llenando matriz
	printf("\tLlene La Matriz \n");
	for(f = 0; f < l; f++){
		for(c = 0; c < l; c++){
			printf("Ingrese Un Numero En La Posicion %d %d: ", f, c);
			scanf("%d", &(*(pMatriz + c + f * l)));
		}
	}
	
	//sumando la matriz
	for(f = 0; f < l; f++){
		for(c = 0; c < l; c++){
			suma = suma + *(pMatriz + c + f + l);
		}
	}
	
	//mostrando matriz en pantalla
	printf("Matriz Llena\n");
	for(f = 0; f < l; f++){
		for(c = 0; c < l; c++){
			printf("%d ", *(pMatriz + c + f * l));
		}
		printf("\n");
	}
	printf("La Suma De Todas Las Posiciones Es: %d\n", suma);
}

void matriz_automatica(){
	int l = 3, matriz[l][l], f, c;
	int *pMatriz = &matriz[0][0];
	
	//Llenando matriz de numeros automaticos
	srand(time(0));
	for(f = 0; f < l; f++){
		for(c = 0; c < l; c++){
			*(pMatriz + c + f * l) = rand () % (50);
		}
	}
	
	//Imprimiendo la matriz
	for(f = 0; f < l; f++){
		for(c = 0; c < l; c++){
			printf("%d ", *(pMatriz + c + f * l));
		}
		printf("\n");
	}
}

void matriz_auto_primos(){
	int  l = 3;
	int filPrima = 0, colPrima = 0, matriz[l][l], i = 1, d = 0, numero;
	int *pMatriz = &matriz[0][0];
	
	printf("Ingrese El Numero Inicial: ");
	scanf("%d", &numero);
	
	while(filPrima < l){
		while(true){
			if(numero % i == 0){
				d += 1;
			}
			if(d > 2){
				break;
			}
			if(i >= numero){
				break;
			}
			i += 1;
		}
	
		if(d == 2){
			*(pMatriz + colPrima + filPrima * l) = numero;
			colPrima += 1;
			if(colPrima == 4){
				filPrima += 1;
				colPrima = 0;
			}
		}
		numero += 1;
		i = 1;
		d = 0;
	}
	
	//imprimiendo matriz
	for(int f = 0; f < l; f++){
		for(int c = 0; c < l; c++){
			printf("%d ", *(pMatriz + c + f * l));
		}
		printf("\n");
	}
}

void punteros(){
		int opcion;
	do{
		printf("\n.......................................");
		printf("\n.              PUNTEROS               .");
		printf("\n.......................................");
		printf("\n.  1. Numero Par o Impar              .");
		printf("\n.  2. Numero Primo                    .");
		printf("\n.  3. Arreglo De 10 Numeros           .");
		printf("\n.  4. Numero Menor.                   .");
		printf("\n.  5. Ordenando Numeros               .");
		printf("\n.  6. Buscar Numero                   .");
		printf("\n.  7. Cantidad De Vocales             .");
		printf("\n.  8. Cadena De Caracteres            .");
		printf("\n.  9. Suma De Matrices                .");
		printf("\n.  10. Matriz Traspuesta              .");
		printf("\n.  11. Estructura Alumno              .");
		printf("\n.  12. Tiempo Empleado                .");
		printf("\n.  0. salir                           .");
		printf("\n.......................................");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: par_impar();
				break;
			case 2: numero_primo();
				break;
			case 3: numeros_pares();
				break;
			case 4: numero_menor();
				break;
			case 5: arreglo_dinamico();
				break;
			case 6: almacenar_numeros();
				break;
			case 7: vocales();
				break;
			case 8: cadena_caracteres();
				break;
			case 9: suma_dinamica();
				break;
			case 10: matriz_traspuesta();
				break;
			case 11: estructura_alumno();
				break;
			case 12: estructura_tiempo();
				break;
			case 0: menu();
				break;
			default: printf("Opcion no valida\n");
		}
		system("pause");
		system("cls");
	}while(opcion !=0);
	
}
void par_impar(){
	int numero;
	int* pNum = &numero;
	printf("Ingrese Un Numero ");
	scanf("%d", &numero);
	if(*pNum % 2 == 0){
		printf("El Numero %d Es Par \n", *pNum);
	}else{
		printf("El Numero %d Es Impar \n", *pNum);
	}
	printf("Posicion De Memoria: %p \n", *(&pNum));
}

void numero_primo(){
	int j = 0, i, num;
	int *pNum = &num;
	
    printf("Ingrese Un Numero: ");
    scanf("%d", &num);
    for(i = 1; i < (num + 1); i++){
    	if(num % i == 0){
        	j++;
        }
    }
    
    if(j != 2){
    	printf("El Numero %d No Es Primo\n", *pNum);
    }else{
    	printf("El Numero %d Es Primo\n", *pNum);
    }
    
	printf("%p \n", *(&pNum));
}

void numeros_pares(){
	int arreglo[10];
	int* pArreglo = arreglo;
	
	for(int i = 0; i < 10; i++){
		printf("Ingrese Un numero En La Posicion %d: ", i + 1);
		scanf("%d", &arreglo[i]);
		if(pArreglo[i] %2 == 0){
			printf("\n");
			printf("El Numero Es Par \n");
			printf("Direccion De Memoria: %p \n", *(&pArreglo + i));
			printf("\n");
		}
	}
}

void numero_menor(){
	int numero;
	printf("Ingrese La Longitud Del Arreglo: ");
	scanf("%d", &numero);
	int arreglo[numero], i, num_menor;
	int* pArreglo = arreglo;
	for(i = 0; i < numero; i++){
		printf("Ingrese Un Numero En La Posicion %d: ", i + 1);
		scanf("%d", &arreglo[i]);
	}
	num_menor = *pArreglo;
	for(i = 0; i < numero; i++){
		if(num_menor > pArreglo[i]){
			num_menor = pArreglo[i];
		}
	}
	printf("El Numero Menor Es: %d \n", num_menor);
}

void arreglo_dinamico(){
	int lon, i, j, aux;
	
	printf("Ingrese La Longitud Del Vector: ");
	scanf("%d", &lon);
	int arreglo[lon], *pArreglo = arreglo;
	
	for(i = 0; i < lon; i++){
		printf("Ingrese Un Numero En La Posicion %d: ", i);
		scanf("%d", &arreglo[i]);
	}

	for(i = 1; i < lon; i++) { 
        j = i; 
        aux = pArreglo[i]; 
        while(j > 0 && aux < pArreglo[j-1]){ 
            pArreglo[j] = pArreglo[j-1]; 
            j--; 
        } 
        pArreglo[j] = aux; 
    } 
    for(i = 0; i < lon; i++) { 
        printf("%d  ", pArreglo[i]); 
    }
}

void almacenar_numeros(){
	int lon, i, dato;
	bool estado = false;
	
	printf("\nIngrese La Longitud Del Vector: ");
	scanf("%d", &lon);
	int arreglo[lon], *pArreglo = arreglo;
	
	for(i = 0; i < lon; i++){
		printf("Ingrese Un Numero En La Posicion %d: ", i);
		scanf("%d", &arreglo[i]);
	}
 
   printf("\nIngrese Un Numero Para Sber Si Se Encuentra En El Arreglo: ");
   scanf("%d", &dato);
   
   for(i = 0; i < lon; i++){
       if(pArreglo[i] == dato){
           estado = true;
           break;
       }
   }
   if(estado == true){
       printf("\n\tDato Encontrado \n");
   } else {
       printf("\n\tDato No Encontrado \n");
   }
}

void vocales(){
	char nombreUsuario[30];
	char* pNombre = nombreUsuario;
	int cont = 0;
	fflush(stdin);
	printf("Ingrese Su Nombre: ");
	fgets(nombreUsuario, 30, stdin);
	strupr(nombreUsuario);
	
	while(*pNombre){
		switch(*pNombre){
			case 'A':  
			case 'E':  
			case 'I':  
			case 'O':  
			case 'U': cont++; 
		}
		*pNombre++;
	}
	
	printf("La Cantidad De Vocales Es: %d \n", cont);
}

void cadena_caracteres(){
	char cadena[30];
	int i = 0, u = 0, o = 0, a = 0, e = 0;
	char* pCadena = cadena;
	fflush(stdin);
	printf("Ingrese La Cadena Deseada: ");
	fgets(cadena, 30, stdin);
	strupr(cadena);
	
	while(*pCadena){
		switch(*pCadena){
			case 'A': a++; 
				break;
			case 'E': e++;
				break; 
			case 'I': i++; 
				break;
			case 'O': o++; 
				break;
			case 'U': u++; 
				break;
		}
		*pCadena++;
	}
	printf("La Cantidad De Vocales a: %d \n", a);
	printf("La Cantidad De Vocales e: %d \n", e);
	printf("La Cantidad De Vocales i: %d \n", i);
	printf("La Cantidad De Vocales o: %d \n", o);
	printf("La Cantidad De Vocales u: %d \n", u);
}

void suma_dinamica(){
	int l = 3, matriz1[l][l], matriz2[l][l], i, j, sumaMatriz[l][l];
	int *pMatriz1 = &matriz1[0][0], *pMatriz2 = &matriz2[0][0], *pSumaMatriz = &sumaMatriz[0][0];
	
	//llenar las matrices
	printf("\tLlene La Matriz 1\n");
	for(i = 0; i < l; i++){
		for(j = 0; j < l; j++){
			printf("Ingrese Numero En La Posicion %d %d: ", i, j);
			scanf("%d", &matriz1[i][j]);
		}
	}
	printf("\n\tLlene La Matriz 2\n");
	for(i = 0; i < l; i++){
		for(j = 0; j < l; j++){
			printf("Ingrese Numero En La Posicion %d %d: ", i, j);
			scanf("%d", &matriz2[i][j]);
		}
	}
	
	//imprimir matrices
	printf("\n\tMatriz 1\n");
	for(i = 0; i < l; i++){
		for(j = 0; j < l; j++){
			printf("%d ", *(pMatriz1 + j + i * l));
		}
		printf("\n");
	}
	printf("\n\tMatriz 2\n");
	for(i = 0; i < l; i++){
		for(j = 0; j < l; j++){
			printf("%d ", *(pMatriz2 + j + i * l));
		}
		printf("\n");
	}
	
	//sumo las dos matrices
	printf("\n\tLa Suma De Las Dos Matrices\n");
	for(i = 0; i < l; i++){
		for(j = 0; j < l; j++){
			sumaMatriz[i][j] = *(pMatriz1 + j + i * l) + *(pMatriz2 + j + i * l);
			printf("%d ", *(pSumaMatriz + j + i * l));
		}
		printf("\n");
	}
}

void matriz_traspuesta(){
	int l = 3, matriz[l][l], i, j;
	int *pMatriz = &matriz[0][0];
	
	printf("\tLlene La Matriz\n");
	for(i = 0; i < l; i++){
		for(j = 0; j < l; j++){
			printf("Ingrese Numero En La Posicion %d %d: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	//matriz original
	printf("\tMatriz Llena\n");
	for(i = 0; i < l; i++){
		for(j = 0; j < l; j++){
			printf("%d ", *(pMatriz + j + i * l));
		}
		printf("\n");
	}
	
	//matriz transpuesta
	printf("\tMatriz Traspuesta\n");
	for(i = 0; i < l; i++){
		for(j = 0; j < l; j++){
			printf("%d ", *(pMatriz + i + j * l));
		}
		printf("\n");
	}
}

void estructura_alumno(){
	float mayor = 0.0;
	int posicion = 0;
	
	for(int i = 0; i < 3; i++){
		printf("\n\tIngrese Datos Del Estudiante\n");
		fflush(stdin); 
		printf("\nIngrese Nombre Del Estudiante: ");
		fgets((puntero_alumno + i) -> nombre, 30, stdin);
		printf("Ingrese La Edad: ");
		scanf("%d", &((puntero_alumno + i) -> edad));
		printf("Ingrese El Promedio: ");
		scanf("%f", &((puntero_alumno + i) -> promedio));
		fflush(stdin); 
	}
	
	for(int i = 0; i < 3; i++){
		if((puntero_alumno + i) -> promedio > mayor){
			mayor = (puntero_alumno + i) -> promedio;
			posicion = i;
		}
	}
	
	printf("\n\tAlumno Con El Mejor Promedio\n");
	printf("\nNombre: %s", ((puntero_alumno + posicion) -> nombre));
	printf("Edad: %d\n", ((puntero_alumno + posicion) -> edad));
	printf("Promedio: %0.1f", ((puntero_alumno + posicion) -> promedio));
	
}

void estructura_tiempo(){
	int horasT = 0, minutosT = 0, segundosT = 0;
	
	printf("\tDigite Los Tiempos Empleados: \n");	
	for(int i = 0; i < 3; i++){
		printf("\nHoras: "), 
		scanf("%d", &((puntero_etapa + i) -> horas));
		printf("Minutos: "); 
		scanf("%d", &((puntero_etapa + i) -> min));
		printf("Segundos: "); 
		scanf("%d", &((puntero_etapa + i) -> seg));
		printf("\n");
	}
	
	for(int i = 0; i < 3; i++){
		horasT += (puntero_etapa + i) -> horas; 
		minutosT += (puntero_etapa + i) -> min;
		if(minutosT >= 60){
			minutosT -= 60;
			horasT++;
		}
		segundosT += (puntero_etapa + i) -> seg;
		if(segundosT >= 60){
			segundosT -= 60;
			minutosT++; 
		}
	}
	
	printf("\n\tEl Tiempo Total Es\n");
	printf("\nHoras: %d", horasT);
	printf("\nMinutos: %d", minutosT);
	printf("\nSegundos: %d", segundosT);

}

void estructuras(){
	int opcion;
	do{
		printf("......................................\n");
        printf(".            ESTRUCTURAS             .\n");
        printf("......................................\n");
        printf(".                                    .\n");
        printf(".  1. Competidor                     .\n");
        printf(".  2. Estudiantes                    .\n");
        printf(".  3. Trabajadores De Una Empresa    .\n");
        printf(".  4. Promedio De Notas              .\n");
        printf(".  5. Mejor y Menor Promedio         .\n");
        printf(".  6. Representacion De Una Persona  .\n");
        printf(".  0. Salir                          .\n");
        printf("......................................\n");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: estruc_competidor();
				break;
			case 2: estruc_estudiante();
				break;
			case 3: estruc_trabajadores();
				break;
			case 4: estruc_promedio();
				break;
			case 5: estruc_alumnos();
				break;
			case 6: estruc_representar();
				break;
			case 0: menu();
				break;
			default: printf("Opcion no valida\n");
		}
		system("pause");
		system("cls");
    }while(opcion != 0);	
}
void estruc_competidor(){
	//pidiendo datos al usuario
	fflush(stdin);
	printf("\nIngrese Su Nombre: ");
	fgets((pCompetidor) -> nombre, 30, stdin);
	printf("\nIngrese (F) Si Es Femenino o (M) Si Es Masculino: ");
	scanf("%c", &(pCompetidor) -> sexo);
	fflush(stdin);
	printf("\nIngrese El Nombre Del Club: ");
	fgets((pCompetidor) -> club, 20, stdin);
	fflush(stdin);
	printf("\nIngrese Su Edad: ");
	scanf("%d", &(pCompetidor) -> edad);
	system("cls");
	
	//imprimiendo datos
	printf("\n\tDatos Del Competidor\n");
	printf("Nombre: %s", pCompetidor -> nombre);
	printf("Sexo: %c\n", pCompetidor -> sexo);
	printf("Club: %s", pCompetidor -> club);
	printf("Edad: %d", pCompetidor -> edad);
	if(pCompetidor -> edad >= 1 && pCompetidor -> edad <= 15){
		printf("\nCategoria: Infantil");
	}else if(pCompetidor -> edad > 15 && pCompetidor -> edad <= 30){
		printf("\nCategoria: Joven");
	}else{
		printf("\nCategoria: Mayor");
	}
}

void estruc_estudiante(){
		float mayor = 0.0;
	int posicion = 0;
	
	for(int i = 0; i < 3; i++){
		printf("\n\tIngrese Datos Del Estudiante\n");
		fflush(stdin); 
		printf("\nIngrese Nombre Del Estudiante: ");
		fgets((puntero_alumno + i) -> nombre, 30, stdin);
		printf("Ingrese La Edad: ");
		scanf("%d", &((puntero_alumno + i) -> edad));
		printf("Ingrese El Promedio: ");
		scanf("%f", &((puntero_alumno + i) -> promedio));
		fflush(stdin); 
	}
	
	for(int i = 0; i < 3; i++){
		if((puntero_alumno + i) -> promedio > mayor){
			mayor = (puntero_alumno + i) -> promedio;
			posicion = i;
		}
	}
	
	printf("\n\tAlumno Con El Mejor Promedio\n");
	printf("\nNombre: %s", ((puntero_alumno + posicion) -> nombre));
	printf("Edad: %d\n", ((puntero_alumno + posicion) -> edad));
	printf("Promedio: %0.1f\n", ((puntero_alumno + posicion) -> promedio));
	
}

void estruc_trabajadores(){
	printf("Profe Estas Muy Bueno, No La Hicimos Por Falta De Tiempo LOVE YOU");
	
}

void estruc_promedio(){
	printf("Profe Estas Muy Bueno, No La Hicimos Por Falta De Tiempo LOVE YOU");
}

void estruc_alumnos(){
	printf("Profe Estas Muy Bueno, No La Hicimos Por Falta De Tiempo LOVE YOU");
}

void estruc_representar(){
	int cantidad;
    printf("Ingrese Cantidad: ");
    scanf("%d", &cantidad);
    llenarDatos(cantidad, puntpersonas);
    validarDatos(cantidad);
    imprimirDatodiscapacidad();
    imprimirDatosindiscapacidad();
}

void llenarDatos(int cantidad, persona *personita)
{
    char opcion;
    for(int i = 0; i < cantidad; i++)
    {
        fflush(stdin);
        printf("Ingrese Nombre: ");
        fgets((personita + i) -> nombre, 30, stdin);
        printf("Ingrese s para discapacitado y n para no discapacitado: ");
        scanf("%c", &opcion);
        if(opcion == 's'){
            (personita + i) -> discapacidad = true;
        }else{
            (personita + i) -> discapacidad = false;
        }
    }
}

void validarDatos(int cantidad){
    int i;
    for(i = 0; i < cantidad; i++){
        if((puntpersonas + i) -> discapacidad == true){
            strcpy((puntpersonas + i) -> nombre, (ppdiscapacidad + con) ->nombre);
            (ppdiscapacidad + con) -> discapacidad = true;
            con += 1;
        }
        else
        {
            strcpy((puntpersonas + i) -> nombre, (ppsdiscapacidad + sin) -> nombre);
            (ppsdiscapacidad + sin) -> discapacidad = false;
            sin += 1;
        }
    }
}

void imprimirDatodiscapacidad(){
    int i;
    printf("Personas con discapacidad: \n");
    for(i = 0; i < con; i++){
        printf("%s \n", (ppdiscapacidad + i) -> nombre);
    }
}

void imprimirDatosindiscapacidad(){
    int i;
    printf("Personas sin discapacidad: \n");
    for(i = 0; i < sin; i++){
        printf("%s \n", (ppsdiscapacidad + i) -> nombre);
    }
}
