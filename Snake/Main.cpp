
#include "Tablero.h"
#include "Snake.h"
#include "Bolita.h"
#include "menu.h"
#include "controljuego.h"

#include <iostream>
#include <ncurses.h>
#include <thread>

#include <unistd.h>

void esperar(int* Tecla, Snake* s)
{
	while (s->GetVivo())
	{
		*Tecla = getch();
		if (*Tecla == 'q')
			break;
	}
}

void Juego(Snake s, Tablero tab, Bolita Bo, ControlJuego* control)
{
	tab.Print(*control);
	int Tecla = getch();

	std::thread thread1 (esperar, &Tecla, &s);

	while (s.GetVivo())
	{
		s.Mov(tab, Tecla);
		Bo.RevisarT(tab);
		tab.Print(*control);
		if (Tecla == 'q')
			break;
		
		usleep(199999);
	}

	thread1.detach();//elimina los threads
}

int main()
{
	initscr();
	start_color();
	clear();
	noecho();
	cbreak();
	curs_set(0);
	
	keypad(stdscr, TRUE); //Actiba las teclas

	int x=18;

	Menu menu;
	ControlJuego control; 

	Tablero tab(x, x);
	Snake s(tab);
	Bolita Bo(tab);

	while (true)
	{
		menu.usarMenu(control.getPantMenu());
		if (menu.getOpcion() == 0)
			Juego(s, tab, Bo, &control);
			tab.Restablecer();
			s.Restablecer(tab);
			wclear(control.getPantJuego());
			wrefresh(control.getPantJuego());			

		if (menu.getOpcion() == 1)
			menu.printControles(control.getPantMenu());
		if (menu.getOpcion() == 2)
			menu.printCreditos(control.getPantMenu());
		if (menu.getOpcion() == 3)
			break;	
	}



	endwin();
	return 0;
}                
