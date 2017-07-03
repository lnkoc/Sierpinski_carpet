/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lukasz
 *
 * Created on 23 października 2016, 16:27
 */

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

typedef float point2[2];

using namespace std;

// argumenty funkcji to lewy dolny i prawy dolny bok kwadratu oraz stopień deformacji kwadratu
int rysuj2 (point2 ld, point2 pd, int licznik) {

	float bok = pd[0] - ld[0];
	float bok_maly = bok / 3;
	// licznik = 1 wypelnij boki i szary kwardat w srodku
	if (licznik == 1) {

		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {

				point2 new_ld = {ld[0] + (bok_maly * i), ld[1] + (bok_maly * j)};
				point2 new_lg = {ld[0] + (bok_maly * i), ld[1] + bok_maly + (bok_maly * j)};
				point2 new_pg = {ld[0] + bok_maly + (bok_maly * i), ld[1] + bok_maly + (bok_maly * j)};
				point2 new_pd = {ld[0] + bok_maly + (bok_maly * i), ld[1] + (bok_maly * j)};

				if ((i != 1) || (j != 1)) {
					// kwadrat wypelniony
					glBegin(GL_POLYGON);
					glColor3f(float (rand() % 1000) / 1000, float (rand() % 1000) / 1000, float (rand() % 1000) / 1000);
						glVertex2fv(new_ld);
						glColor3f(float (rand() % 1000) / 1000, float (rand() % 1000) / 1000, float (rand() % 1000) / 1000);
						glVertex2fv(new_lg);
						glColor3f(float (rand() % 1000) / 1000, float (rand() % 1000) / 1000, float (rand() % 1000) / 1000);
						glVertex2fv(new_pg);
						glColor3f(float (rand() % 1000) / 1000, float (rand() % 1000) / 1000, float (rand() % 1000) / 1000);
						glVertex2fv(new_pd);
					glEnd();
				}
				else {
					//kwadrat pusty
					glBegin(GL_POLYGON);
						glColor3f(0.0f, 0.0f, 0.0f); // wierzchołek pusty
						glVertex2fv(new_ld);
						glVertex2fv(new_lg);
						glVertex2fv(new_pg);
						glVertex2fv(new_pd);
					glEnd();
				}

			}
		}
		return 0;
	}
	// licznik > 1

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3 ; j++) {

			point2 new_ld = {ld[0] + (bok_maly * i), ld[1] + (bok_maly * j)};
			point2 new_lg = {ld[0] + (bok_maly * i), ld[1] + bok_maly + (bok_maly * j)};
			point2 new_pg = {ld[0] + bok_maly + (bok_maly * i), ld[1] + bok_maly + (bok_maly * j)};
			point2 new_pd = {ld[0] + bok_maly + (bok_maly * i), ld[1] + (bok_maly * j)};

			if ((i != 1) || (j != 1)) {
				//rysuj w nowych wspolrzednych, licznik--
				rysuj2(new_ld, new_pd, licznik - 1);
			}
			else {
				//rysuj szary kwadrat w srodku
				glBegin(GL_POLYGON);
					glColor3f(0.0f, 0.0f, 0.0f); // wierzchołek pusty
					glVertex2fv(new_ld);
					glVertex2fv(new_lg);
					glVertex2fv(new_pg);
					glVertex2fv(new_pd);
				glEnd();
			}
		}
	}
	return 0;
}

//void rysuj (double a, double b, int licznik) {
//
//	double bok = b;
//	double c = b / 3;
////	double poczatek = a;
//
//	for (int i = 0; i < 3; i++) {
//
//		for (int j = 0; j < 3 ; j++) {
//
//			if ((i != 1) || (j != 1)) {
//
//				for (int k = 0; k < 3; k++) {
//
//					for (int l = 0; l < 3 ; l++) {
//
//						licznik--;
//
//						if ((k != 1) || (l != 1)) {
//							glBegin(GL_POLYGON);
//								glColor3f(1.0f, 0.0f, 0.0f); // wierzchołek czerwony
//								glVertex2f(-a + (c*j) + (k * bok), -a + (c*i) + (l * bok));
//							//	glColor3f(0.0f, 1.0f, 0.0f); // wierzchołek zielony
//								glVertex2f(-a + (c*j) + (k * bok), -a + c +(c*i) + (l * bok));
//							//	glColor3f(0.0f, 0.0f, 1.0f); // wierzchołek niebieski
//								glVertex2f(-a + c + (c*j) + (k * bok), -a + c + (c*i) + (l * bok));
//							//	glColor3f(1.0f, 1.0f, 1.0f); // wierzchołek biały
//								glVertex2f(-a + c + (c*j) + (k * bok), -a + (c*i) + (l * bok));
//							glEnd();
//						}
//						else {
//							glBegin(GL_POLYGON);
//								glColor3f(0.5f, 0.5f, 0.5f);
//								glVertex2f(-a + (c*j) + (k * bok), -a + (c*i) + (l * bok));
//								glVertex2f(-a + (c*j) + (k * bok), -a + c +(c*i) + (l * bok));
//								glVertex2f(-a + c + (c*j) + (k * bok), -a + c + (c*i) + (l * bok));
//								glVertex2f(-a + c + (c*j) + (k * bok), -a + (c*i) + (l * bok));
//							glEnd();
//						}
//					}
//				}
//			}
//			else {
//				glBegin(GL_POLYGON);
//					glColor3f(0.5f, 0.5f, 0.5f);
//					glVertex2f(-a + (b*j), -a + (b*i));
//					glVertex2f(-a + (b*j), -a + b +(b*i));
//					glVertex2f(-a + b + (b*j), -a + b + (b*i));
//					glVertex2f(-a + b + (b*j), -a + (b*i));
//				glEnd();
//			}
//		}
//	}
//}

void RenderScene(void) {
    
    glClear(GL_COLOR_BUFFER_BIT);
    // Czyszczenie okna aktualnym kolorem czyszczącym

    point2 ld = {-50, -50};
    point2 pd = {50, -50};

	int licznik = 6;

	rysuj2(ld, pd, licznik);

    glFlush();
    // Przekazanie poleceń rysujących do wykonania
}
/*************************************************************************************/

// Funkcja ustalająca stan renderowania


void MyInit(void) {
    
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   // Kolor okna wnętrza okna - ustawiono na czarny
}
/*************************************************************************************/

// Funkcja służąca do kontroli zachowania proporcji rysowanych obiektów
// niezależnie od rozmiarów okna graficznego


void ChangeSize(GLsizei horizontal, GLsizei vertical) {
// Parametry horizontal i vertical (szerokość i wysokość okna) są
// przekazywane do funkcji za każdym razem, gdy zmieni się rozmiar okna

     GLfloat AspectRatio;
    // Deklaracja zmiennej AspectRatio określającej proporcję wymiarów okna

    if(vertical==0)
    // Zabezpieczenie pzred dzieleniem przez 0
        vertical = 1;

    glViewport(0, 0, horizontal, vertical);
    // Ustawienie wielkościokna okna urządzenia (Viewport)
    // W tym przypadku od (0,0) do (horizontal, vertical)

    glMatrixMode(GL_PROJECTION);
    // Określenie układu współrzędnych obserwatora
    glLoadIdentity();
    // Określenie przestrzeni ograniczającej
    AspectRatio = (GLfloat)horizontal / (GLfloat)vertical;
    // Wyznaczenie współczynnika proporcji okna
    // Gdy okno na ekranie nie jest kwadratem wymagane jest
    // określenie okna obserwatora.
    // Pozwala to zachować właściwe proporcje rysowanego obiektu
    // Do okreslenia okna obserwatora służy funkcja glOrtho(...)

    if(horizontal <= vertical)
        glOrtho(-100.0, 100.0, -100.0 / AspectRatio,100.0 / AspectRatio, 1.0, -1.0);
    else
        glOrtho(-100.0 * AspectRatio, 100.0 * AspectRatio, -100.0 ,100.0, 1.0, -1.0);

    glMatrixMode(GL_MODELVIEW);
    // Określenie układu współrzędnych
    glLoadIdentity();
}
/*************************************************************************************/

/*************************************************************************************/

// Główny punkt wejścia programu. Program działa w trybie konsoli


int main(int argc, char **argv) {

    // start randomizowania
    srand( time( NULL ) );

    // This is init function
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    // Ustawienie trybu wyświetlania
    // GLUT_SINGLE - pojedynczy bufor wyświetlania
    // GLUT_RGBA - model kolorów RGB

    glutCreateWindow("Dywan Sierpinskiego");
    // Utworzenie okna i określenie treści napisu w nagłówku okna

    glutDisplayFunc(RenderScene);
    // Określenie, że funkcja RenderScene będzie funkcją zwrotną (callback)
    // Biblioteka GLUT będzie wywoływała tą funkcję za każdym razem, gdy
    // trzeba będzie przerysować okno


    glutReshapeFunc(ChangeSize);
    // Dla aktualnego okna ustala funkcję zwrotną odpowiedzialną za
    // zmiany rozmiaru okna

    MyInit();
    // Funkcja MyInit (zdefiniowana powyżej) wykonuje wszelkie
    // inicjalizacje konieczneprzed przystąpieniem do renderowania

    glutMainLoop();
    // Funkcja uruchamia szkielet biblioteki GLUT

   return (0);
}
/**************************************************************************************/
