/*
	Hecho por Max Flores Saldaña , Usando la programación orientada a Objetos en C++.
	Si desea ver la documentacion de GLUT: https://www.opengl.org/resources/libraries/glut/spec3/spec3.html
*/

/// CODIGO REUTILIZADO DE https://github.com/MrAlexanderFS003/OpenGL-GLUT-Crear-varios-objetos-2D

#include "Punto.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

//Tamaño de la ventana
#define ANCHO 800
#define ALTO 600

//Tamaño de la Cuadricula
#define COLUMNAS 50
#define FILAS 50

//Objetos
Punto ptn;
vector<Punto>gen;

//Variables usadas para almacenar los calculos obtenidos
float objX = 0.0f, objY = 0.0f, MobjX = 0.0f, MobjY = 0.0f;
int valor = 0, cont = 0, val = 0, win = 0; 
bool bandera = false;

void Init() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNAS, 0.0, FILAS, -1.0, 1.0);
}

void Cuadricula() {
	glColor3ub(255, 255, 255);
	glLineWidth(1.0);
	for (int x = 0; x < COLUMNAS; x++) {
		for (int y = 0; y < FILAS; y++) {
			glBegin(GL_LINE_LOOP);
			glVertex2f(x, y);
			glVertex2f(x + 1, y);
			glVertex2f(x + 1, y + 1);
			glVertex2f(x, y + 1);
			glEnd();
		}
	}
}

//Esta funcion crea las acciones de las opciones que eligamos en el Menu
void Accion() {
	if (val == 1) {
		ptn.setRGB(255,0,0);
		gen.push_back(ptn);
	}

	if (val == 2) {
		ptn.setRGB(251, 255, 0);
		gen.push_back(ptn);
	}

	if (val == 3) {
		ptn.setRGB(0, 19, 255);
		gen.push_back(ptn);
	}

	if (val == 4) {
		bandera = true;
	}

	if (val == 5) {
		bandera = false;
	}
	
	if (val == 6) {
		gen.clear();
		val = NULL;
	}
	
	if (val == 7) {
		exit(0);
	}

}

void Dibuja() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	if (bandera == true) { Cuadricula(); }
	glPopMatrix();

	for (int i = 0; i < gen.size(); i++) { gen[i].Dibuja(); }

	Accion();

	glutSwapBuffers();
}

void Actualiza() {
	glutPostRedisplay();
}

//Posicion del raton
void Raton(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		objX = (x - (ANCHO / 2)) * 100 / ANCHO;
		objY = ((ALTO / 2) - y) * 100 / ALTO;

		ptn.setPosX(objX); // Objetenos la posicion en X del raton
		ptn.setPosY(objY); // Objetenos la posicion en Y del raton
		gen.push_back(ptn); // Guardamos los objetos creados 

		MobjX = objX;
		MobjY = objY;
		valor = state;
	}
}

void MoverRaton(int x, int y) {
	if (valor) {
		ptn.setPosX(MobjX);
		ptn.setPosY(MobjY);
	}
	MobjX = (x - (ANCHO / 2)) * 100 / ANCHO;
	MobjY = ((ALTO / 2) - y) * 100 / ALTO;
	// Ahora por cada vez que el raton se mueve en X,Y guardaremos los
	// objetos que se vayan creando 
	ptn.setPosX(MobjX);
	ptn.setPosY(MobjY);
	gen.push_back(ptn);
}

//Creamos una funcion "Menu" para comprobar cada valor 
void Menu(int value) {
	//Si al crear el menu el valor es 0 : destruye la ventana y la cierra 
	if (value == 0) { glutDestroyWindow(win); exit(0); }
	else { val = value; } // de otro modo el valor se agrega a otra variable 
	glutPostRedisplay();
}

/*
	glutAddMenuEntry(Nombre, Numero de orden);

	glutAddSubMenu(Nombre, Variable del menu Creado);
*/

void CrearMenu() {
	int OpcColor = glutCreateMenu(Menu); // Crea el Menu
	glutAddMenuEntry("Rojo",1); // En este caso SubMenu
	glutAddMenuEntry("Amarillo",2);
	glutAddMenuEntry("Azul",3);
	int OpcCuad = glutCreateMenu(Menu);
	glutAddMenuEntry("Mostrar Cuadricula",4);
	glutAddMenuEntry("Ocultar Cuadricula",5);
	glutAddMenuEntry("Limpiar Pantalla",6);
	glutAddMenuEntry("Salir",7);
	int subMenu = glutCreateMenu(Menu);// Crea el Menu
	glutAddSubMenu("Colores",OpcColor); // Aqui se crea el menu principal del submenu
	glutAddSubMenu("Ventana",OpcCuad);

	//Cada vez que hagamos click derecho saldra el submenu
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(ANCHO, ALTO);
	glutInitWindowPosition(50, 50);
	win = glutCreateWindow("SUBMENU-CUADRICULAS"); // El valor de la ventana creada se guarda en una variable

	Init();
	CrearMenu();
	glutDisplayFunc(Dibuja);
	glutIdleFunc(Actualiza);
	glutMouseFunc(Raton); // Posicion del raton
	glutMotionFunc(MoverRaton); // Movimiento del raton
	glutMainLoop();
	return 0;
}