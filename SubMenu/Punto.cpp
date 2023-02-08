#include "Punto.h"
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void Punto::Dibuja() {
	Actualiza();
	glColor3ub(r,g,b);
	glRectd(posX, posY, posX + 1, posY + 1);
}

void Punto::Actualiza() { glutPostRedisplay(); }