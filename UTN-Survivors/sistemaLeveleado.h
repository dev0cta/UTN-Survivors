#pragma once
class sistemaNiveles
{
	public:
	sistemaNiveles()
	{
		nivelActual = 1;
		experienciaActual = 0;

	}
	void experienciaObtenida(int gana_exp)
	{
		experienciaActual += gana_exp;
		checkeoLeveleada();
	}
	
	
	private:
	const int EXP_PARA_LVL_2 = 10;
	int nivelActual;
	int experienciaActual;
	int expParaSigNivel;

	void checkeoLeveleada()
	{
		if (nivelActual == 1)
		{
			expParaSigNivel = EXP_PARA_LVL_2;
		}
		if (experienciaActual >= expParaSigNivel)
		{
			experienciaActual = 0;
			nivelActual++;
			expParaSigNivel = expParaSigNivel * 2;
		}
	}

};