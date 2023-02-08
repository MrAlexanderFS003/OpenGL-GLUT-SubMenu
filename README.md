# SUBMENU

En el anterior repositorio ( https://github.com/MrAlexanderFS003/OpenGL-GLUT-Crear-varios-objetos-2D ) vimos como podemos crear varios objetos y poder hacer un 
paint sencillo aunque puede ser aun mejor. En este proyecto crearemos un menu de opciones con el ratón (Mouse), ya sea para cambiar el color o borrar todo lo que se 
a pintado, con esto nos evitamos de tener la funcion "Teclado" y tan solo con el raton poder hacer tantas acciones que deseemos.

Para la creacion de el menu de opciones, solo necesitaremos dos funciones, "void Menu(int value)" y "void CrearMenu()" es muy sensillo de entender:
- void Menu(int value): Esta funcion lo que hará es evaluar, si el menu da un 0 entonces lo que hace es destruir la ventana y cerrarla, de otro modo es valido.
- void CrearMenu(): Aqui crearemos el menu y todas las opciones que se desee, tambien configuramos que boton del raton sera lo que active este menu.
A continuacion un ejemplo:

```C++
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//Esta funcion crea las acciones de las opciones que eligamos en el Menu
void Accion() {
  if (val == 1) {
  glColor3ub(255,0,0);
  }
}

void Dibuja() {
  glClear(GL_COLOR_BUFFER_BIT);

  Accion();

  glutSwapBuffers();
}

void Actualiza() {
  glutPostRedisplay();
}

//Creamos una funcion "Menu" para comprobar cada valor 
void Menu(int value) {
  //Si al crear el menu el valor es 0 : destruye la ventana y la cierra 
  if (value == 0) { glutDestroyWindow(win); exit(0); }
  else { val = value; } // de otro modo el valor se agrega a otra variable 
  glutPostRedisplay();
}

void CrearMenu() {
  int OpcColor = glutCreateMenu(Menu); // Crea el Menu
  glutAddMenuEntry("Rojo",1); // En este caso SubMenu
  int subMenu = glutCreateMenu(Menu);// Crea el Menu
  glutAddSubMenu("Color",OpcColor); // Aqui se crea el menu principal del submenu

  //Cada vez que hagamos click derecho saldra el menu
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main() {
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(ANCHO, ALTO);
  glutInitWindowPosition(50, 50);
  win = glutCreateWindow("SUBMENU-CUADRICULAS"); // El valor de la ventana creada se guarda en una variable

  CrearMenu();
  glutDisplayFunc(Dibuja);
  glutIdleFunc(Actualiza);
  glutMainLoop();
  return 0;
}
```

## GLORTHO

Es una función de proyección en OpenGL GLUT que permite definir una proyección ortográfica para la escena 3D. 
La proyección ortográfica es un tipo de proyección en la que los objetos aparecen en un tamaño constante independientemente 
de su distancia a la cámara.

La función glOrtho toma seis argumentos: left, right, bottom, top, near, y far, que especifican los límites de la ventana de 
proyección en el eje x, y y z. Cualquier objeto en la escena que se encuentre dentro de estos límites será visible en la proyección. Por ejemplo :

```C++
 // Definir una proyección ortográfica con límites en x de -100 a 100, 
 // y de -100 a 100, y de -100 a 100 en z
glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
```

## GLRECTD

Es una función en OpenGL GLUT que permite dibujar un rectángulo en la escena 3D. Esta función toma dos pares de coordenadas 
(x1, y1, x2, y2) que especifican las posiciones de los vértices opuestos del rectángulo en el plano 2D. Después de establecer 
el color y otros atributos de dibujo, puede llamar a glRectd para dibujar el rectángulo en la escena. Por ejemplo :

```C++
glColor3f(1.0, 0.0, 0.0); // Establecer el color rojo
glRectd(0.0, 0.0, 100.0, 50.0); // Dibujar un rectángulo de 100x50 a partir del punto (0, 0)
```

# PROGRAMA EN EJECUCIÓN

![4-EC](https://user-images.githubusercontent.com/96871746/217643147-b9cf854c-a2ed-42f6-a83c-405201dd3310.gif)
