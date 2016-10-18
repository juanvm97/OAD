#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador
{
private:
	int* puntero;
	char img;
	int turnosPerdidos;
	bool ganar;
public:
	Jugador();
	bool GetGanar() { return ganar; }
	int GetPos() { return *puntero; }
	char GetImg() { return img; }
	void Inicio(int *tab);
	void Mover(int *tab);
	~Jugador();

	/* data */
};

#endif // JUGADOR_H