
#ifndef CONTROLJUEGO_H
#define CONTROLJUEGO_H

#include <ncurses.h>

class ControlJuego
{
	int puntuacion;
	int vidas;
	int nivel;
	int maxNiveles;
	
	int velocidad;
	
	WINDOW *pantallaJuego; //ESTAS PANTALLAS LAS TENGO QUE MOVER A SUS RESPECTIVAS CLASES
	WINDOW *pantallaMenu;
	WINDOW *pantallaDatos;
	
public:
	ControlJuego();
	void ganar();
	void perder();
	void printDatos();
	
	void reiniciar();
	void aumentarPuntuacion(int p) { puntuacion += p; }
	
	int getVidas() { return vidas; }
	bool pasarNivel();
	
	int getVelocidad() { return velocidad; }

	void aumentarVida() { vidas++; };
	
	WINDOW *getPantJuego() { return pantallaJuego; }
	WINDOW *getPantMenu() { return pantallaMenu;  }
	WINDOW *getPantDatos() { return pantallaDatos;  }
};

#endif // CONTROLJUEGO_H
