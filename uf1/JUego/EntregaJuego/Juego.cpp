
#include <iostream>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>
#include <mmsystem.h>
using namespace std;


//atributos del Enemigo1
double enemy1HP = 750;
double enemy1Damage;
string enemy1Name = "Joker";
bool enemy1IsAlive = true;


//atributos del Enemigo2
double enemy2HP = 500;
double enemy2Damage;
string enemy2Name = "Harley Queen";
bool enemy2IsAlive = true;


//Atributos del héroe
string heroName;
double heroDamage = 1;
double heroHP = 1000;
bool heroIsAlive = true;
int numAtaque;
int numEnemigo;
double numPociones = 3;

//Ataques
double ataqueFuerte = 200;
double ataqueFlojo = 120;

int main()
{
	int instrucciones = 0;
	cout << "Estas en gotam\n";
	Sleep(1000);
	cout << "Hay un ataque de unos villanos\n";
	Sleep(1000);
	cout << "El enemigo " << enemy1Name << " acaba de aparecer y tiene " << enemy1HP << " de vida\n";
	Sleep(1000);
	cout << "Y viene acompañado de " << enemy2Name << " que tiene " << enemy2HP << " de vida\n";
	Sleep(1000);
	cout << "Inserta el nombre del heroe que lo va a derrotar\n";
	cin >> heroName;
	cout << "el nombre del heroe es " << heroName << "\n";
	while(instrucciones!=2){
		cout << "Que quieres hacer?\n[1]Ver las instrucciones\n[2]Empezar Juego\n";

		cin >> instrucciones;
		switch (instrucciones) {
		case 1:
			cout << "Tienes 4 ataques.\n";
			Sleep(1000);
			cout << "[1] Patada Ninja - Hace Daño directo al rival.\n";
			Sleep(1000);
			
			cout << "[2] Puñetazo de fuego - Hace Daño directo al rival.\n";
			Sleep(1000);
			cout << "\n";
			cout << "Uno de los ataques directos es mas efectivo con un rival y el otro con el otro.\n";
			cout << "\n";
			Sleep(1000);
			cout << "[3] Concentración mística - Sube tu daño un 50% (es incremental).\n";
			Sleep(1000);
			cout << "[4] Pocion de Vida - Te sube la vida 200 puntos de vida, solo tendras 3 pociones.\n";
			Sleep(1000);
			break;
		default: 
			continue;
			break;



		}
	}
	
	

	while (enemy1IsAlive && enemy2IsAlive && heroIsAlive)
	{
		cout << "\n";
		Sleep(1000);
		cout << "\n";
		Sleep(1000);
		cout << "A que enemigo quieres atacar?\n[1] Joker\n[2] Harley Queen\n";
		cin >> numEnemigo;
		switch (numEnemigo) {
		case 1: //Ataco a Joker
			cout << "Que ataque quieres hacer al Joker?\n";
			cout << "[1] Patada Ninja \n[2] Puñetazo de fuego\n[3] Concentración mística \n[4] Pocion de Vida(" << numPociones << ")\n";
			cin >> numAtaque;

			switch (numAtaque) { //switch ataque
			case 1:
				enemy1HP = enemy1HP - ataqueFlojo * heroDamage;
				cout << "El ataque Patada Ninja de " << heroName << " ha hecho " << ataqueFlojo * heroDamage << " puntos de daño a Joker\n";
				Sleep(1000);
				break;
			case 2:
				enemy1HP = enemy1HP - ataqueFuerte * heroDamage;
				cout << "El ataque Puñetazo de Fuego de " << heroName << " ha hecho " << ataqueFuerte * heroDamage << " puntos de daño a Joker\n";
				Sleep(1000);
				break;
			case 3:
				cout << "Te estas concentrando...\n";
				heroDamage = heroDamage * 1.5;
				cout << "Tu concentración ha subido un 50%!!\n";
				Sleep(1000);
				break;
			case 4:
				if (numPociones >= 0) {
					cout << "Te tomas la poción de vida\n";
					numPociones = numPociones - 1;
					heroHP = heroHP + 200;
					cout << "Te quedan " << numPociones << " pociones\n";
					Sleep(1000);
					cout << "Te quedaban " << heroHP - 200 << " puntos de vida y ahora te quedan " << heroHP << " puntos de vida\n";
				}
				else {
					cout << "No te quedan pociones";
				}
				break;
			default:
				cout << "Introduce una opcion correcta\n";
				Sleep(1000);
				continue;
			}
			if (enemy1HP <= 0) { //muerte Joker
				enemy1HP = 0;
				enemy1IsAlive = false;
				cout << "Has derrotado al Joker\n";
				Sleep(1000);
				cout << "Harley se esta sumiendo en la locura\n";
				Sleep(1000);
				cout << "Harley recibe un x2 en vida y en daño a causa de su rabia\n";
				Sleep(1000);
				enemy2HP = 2 * enemy2HP;
			}
			else {
				cout << "Al Joker le quedan " << enemy1HP << " puntos de vida\n"; Sleep(1000);
			}

			if (enemy1IsAlive == true) {  //ataque Joker
				cout << "El Joker se dispone a atacar\n";
				Beep(330, 100); Sleep(100);
				Beep(330, 100);
				Sleep(1000);
				enemy1Damage = (rand() % 200) * 2;
				if (enemy1Damage > 150) {
					enemy1Damage = 150;
					cout << "Golpe Critico!!\n";
				}
				heroHP = heroHP - enemy1Damage;
				if (heroHP <= 0) {
					heroHP = 0;
					heroIsAlive = false;
					cout << "El Joker te ha hecho " << enemy1Damage << " puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
					Sleep(1000);
				}
				else {
					cout << "El Joker te ha hecho " << enemy1Damage << " puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
					Sleep(1000);
				}
				if (heroHP <= 0) {  //muerte heroe
					heroHP = 0;
					heroIsAlive = false;
				}
				

			}
			if (enemy2IsAlive == true) {  //ataque Harley
				cout << "Harley se dispone a atacar\n";
				Beep(330, 100); Sleep(100);
				Beep(330, 100);
				Sleep(1000);
				enemy2Damage = rand() % 200;
				if (enemy2Damage > 150) {
					enemy2Damage = 150;
					cout << "Golpe Critico!!\n";
				}
				heroHP = heroHP - enemy2Damage;
				if (heroHP < 0) {
					heroHP = 0;
					heroIsAlive = false;
					cout << "Harley te ha hecho " << enemy2Damage << "puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
					Sleep(1000);
				}
				else {
					cout << "Harley te ha hecho " << enemy2Damage << "puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
					Sleep(1000);
				}
			}
			if (heroHP <= 0) {  //muerte heroe
				heroHP = 0;
				heroIsAlive = false;

			}
			break;
		case 2: //Ataque a Harley Queen
			cout << "Que ataque quieres hacer a Harley Queen?\n";
			cout << "[1] Patada Ninja\n[2] Puñetazo de fuego\n[3] Concentración mística \n[4] Pocion de Vida(" << numPociones << ")\n";
			cin >> numAtaque;

			switch (numAtaque) {
			case 1:
				enemy2HP = enemy2HP - ataqueFuerte * heroDamage;
				cout << "El ataque Patada Ninja de " << heroName << " ha hecho " << ataqueFuerte * heroDamage << "  puntos de daño a Harley Queen\n";
				Sleep(1000);
				break;
			case 2:
				enemy2HP = enemy2HP - ataqueFlojo * heroDamage;
				cout << "El ataque Puñetazo de Fuego de " << heroName << " ha hecho " << ataqueFlojo * heroDamage << " puntos de daño a Harley Queen\n";
				Sleep(1000);
				break;
			case 3:
				cout << "Te estas concentrando...\n";
				Sleep(1000);
				heroDamage = heroDamage * 1.5;
				cout << "Tu concentración ha subido un 50%!!\n";
				Sleep(1000);
				break;
			case 4:
				if (numPociones >= 0) {
					cout << "Te tomas la poción de vida\n";
					numPociones = numPociones - 1;
					heroHP = heroHP + 200;
					cout << "Te quedan " << numPociones << " pociones\n";
					Sleep(1000);
					cout << "Te quedaban " << heroHP - 200 << " puntos de vida y ahora te quedan " << heroHP << " puntos de vida\n";
				}
				else {
					cout << "No te quedan pociones";
				}
				break;
			default:
				cout << "Introduce una opcion correcta\n";
				continue;
			}
			if (enemy2HP <= 0) { //muerte Harley
				enemy2HP = 0;
				enemy2IsAlive = false;
				cout << "Has derrotado al Harley Queen\n";
				Sleep(1000);
				cout << "Joker se esta sumiendo en la locura\n";
				Sleep(1000);
				cout << "Joker recibe un x2 en vida y en daño a causa de su rabia\n";
				Sleep(1000);
				enemy1HP = 2 * enemy1HP;
			}
			else {
				cout << "A Harley Queen le quedan " << enemy2HP << " puntos de vida\n";
			}

			if (enemy2IsAlive == true) {  //ataque Harley
				cout << "Harley se dispone a atacar\n";
				Beep(330, 100); Sleep(100);
				Beep(330, 100);
				Sleep(1000);
				enemy2Damage = rand() % 200;
				if (enemy2Damage > 150) {
					enemy2Damage = 150;
					cout << "Golpe Critico!!\n";
				}
				heroHP = heroHP - enemy2Damage;
				if (heroHP < 0) {
					heroHP = 0;
					heroIsAlive = false;
					cout << "Harley te ha hecho " << enemy2Damage << "puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
					Sleep(1000);
				}
				else {
					cout << "Harley te ha hecho " << enemy2Damage << "puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
					Sleep(1000);
				}
			}
			if (heroHP <= 0) {  //muerte heroe
				heroHP = 0;
				heroIsAlive = false;

			}
			if (enemy1IsAlive == true) {  //ataque Joker
				cout << "El Joker se dispone a atacar\n";
				Beep(330, 100); Sleep(100);
				Beep(330, 100);
				Sleep(1000);
				enemy1Damage = (rand() % 200) * 2;
				if (enemy1Damage > 150) {
					enemy1Damage = 150;
					cout << "Golpe Critico!!\n";
				}
				heroHP = heroHP - enemy1Damage;
				if (heroHP <= 0) {
					heroHP = 0;
					heroIsAlive = false;
					cout << "El Joker te ha hecho " << enemy1Damage << " puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
					Sleep(1000);
				}
				else {
					cout << "El Joker te ha hecho " << enemy1Damage << " puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
					Sleep(1000);
				}
				if (heroHP <= 0) {  //muerte heroe
					heroHP = 0;
					heroIsAlive = false;
				}


			}
			break;
		default:
			cout << "Introduce una opcion correcta\n";
			continue;



		}
	}
	while (enemy1IsAlive && enemy2IsAlive == false && heroIsAlive)
	{


		//Ataque a Joker
		cout << "Que ataque quieres hacer al Joker?\n";
		cout << "[1] Patada Ninja \n[2] Puñetazo de fuego\n[3] Concentración mística \n[4] Pocion de Vida(" << numPociones << ")\n";
		cin >> numAtaque;

		switch (numAtaque) {
		case 1:
			enemy1HP = enemy1HP - ataqueFlojo * heroDamage;
			cout << "El ataque Patada Ninja  de " << heroName << " ha hecho " << ataqueFlojo * heroDamage << " puntos de daño a Joker\n";
			Sleep(1000);
			break;
		case 2:
			enemy1HP = enemy1HP - ataqueFuerte * heroDamage;
			cout << "El ataque Puñetazo de Fuego de " << heroName << " ha hecho " << ataqueFuerte * heroDamage << " puntos de daño a Joker\n";
			Sleep(1000);
			break;
		case 3:
			cout << "Te estas concentrando...\n";
			heroDamage = heroDamage * 1.5;
			cout << "Tu concentración ha subido un 50%!!\n";
			Sleep(1000);
			break;
		case 4:
			if (numPociones >= 0) {
				cout << "Te tomas la poción de vida\n";
				numPociones = numPociones - 1;
				heroHP = heroHP + 200;
				cout << "Te quedan " << numPociones << " pociones\n";
				Sleep(1000);
				cout << "Te quedaban " << heroHP - 200 << " puntos de vida y ahora te quedan " << heroHP << " puntos de vida\n";
			}
			else {
				cout << "No te quedan pociones";
			}
			break;
		default:
			cout << "Introduce una opcion correcta\n";
			Sleep(1000);
			continue;
		}
		if (enemy1HP <= 0) { //muerte Joker
			enemy1HP = 0;
			enemy1IsAlive = false;
			cout << "Has derrotado al Joker\n";
			Sleep(1000);

		}
		else {
			cout << "Al Joker le quedan " << enemy1HP << " puntos de vida\n"; Sleep(1000);
		}

		if (enemy1IsAlive == true) {  //ataque Joker
			cout << "El Joker se dispone a atacar\n";
			Beep(330, 100); Sleep(100);
			Beep(330, 100);
			Sleep(1000);
			enemy1Damage = (rand() % 200) * 2;
			if (enemy1Damage > 150) {
				enemy1Damage = 150;
				cout << "Golpe Critico!!\n";
			}
			heroHP = heroHP - enemy1Damage;
			if (heroHP <= 0) {
				heroHP = 0;
				heroIsAlive = false;
				cout << "El Joker te ha hecho " << enemy1Damage << " puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
				Sleep(1000);
			}
			else {
				cout << "El Joker te ha hecho " << enemy1Damage << " puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
				Sleep(1000);
			}
			if (heroHP <= 0) {  //muerte heroe
				heroHP = 0;
				heroIsAlive = false;
			}
		}

	}
	while (enemy1IsAlive == false && enemy2IsAlive && heroIsAlive)
	{

		cout << "Que ataque quieres hacer a Harley Queen?\n";
		cout << "[1] Patada Ninja\n[2] Puñetazo de fuego\n[3] Concentración mística \n[4] Pocion de Vida(" << numPociones << ")\n";
		cin >> numAtaque;

		switch (numAtaque) {
		case 1:
			enemy2HP = enemy2HP - ataqueFuerte * heroDamage;
			cout << "El ataque Patada Ninja de " << heroName << " ha hecho " << ataqueFuerte * heroDamage << "  puntos de daño a Harley Queen\n";
			Sleep(1000);
			break;
		case 2:
			enemy2HP = enemy2HP - ataqueFlojo * heroDamage;
			cout << "El ataque Puñetazo de Fuego de " << heroName << " ha hecho " << ataqueFlojo * heroDamage << " puntos de daño a Harley Queen\n";
			Sleep(1000);
			break;
		case 3:
			cout << "Te estas concentrando...\n";
			Sleep(1000);
			heroDamage = heroDamage * 1.5;
			cout << "Tu concentración ha subido un 50%!!\n";
			Sleep(1000);
			break;
		case 4:
			if (numPociones >= 0) {
				cout << "Te tomas la poción de vida\n";
				numPociones = numPociones - 1;
				heroHP = heroHP + 200;
				cout << "Te quedan " << numPociones << " pociones\n";
				Sleep(1000);
				cout << "Te quedaban " << heroHP - 200 << " puntos de vida y ahora te quedan " << heroHP << " puntos de vida\n";
			}
			else {
				cout << "No te quedan pociones";
			}
			break;
		default:
			cout << "Introduce una opcion correcta\n";
			continue;
		}
		if (enemy2HP <= 0) { //muerte Harley
			enemy2HP = 0;
			enemy2IsAlive = false;

		}
		else {
			cout << "A Harley Queen le quedan " << enemy2HP << " puntos de vida\n";
		}

		if (enemy2IsAlive == true) {  //ataque Harley
			cout << "Harley se dispone a atacar\n";
			Beep(330, 100); Sleep(100);
			Beep(330, 100);
			Sleep(1000);
			enemy2Damage = (rand() % 200) * 2;
			if (enemy2Damage > 150) {
				enemy2Damage = 150;
				cout << "Golpe Critico!!\n";
			}
			heroHP = heroHP - enemy2Damage;
			if (heroHP < 0) {
				heroHP = 0;
				heroIsAlive = false;
				cout << "Harley te ha hecho " << enemy2Damage << "puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
				Sleep(1000);
			}
			else {
				cout << "Harley te ha hecho " << enemy2Damage << "puntos de daños  y te quedan " << heroHP << " puntos de vida.\n";
				Sleep(1000);
			}
		}

	}
	if (heroIsAlive == false) {
		cout << "Los enemigos te han derrotado\n";
		Sleep(1000);
		cout << "Gotam nunca olvidara este dia\n";
		Sleep(1000);
		cout << "El dia que empezo el reinado de terror\n";
		Sleep(1000);
		cout << "El mundo se ha vuelto un lugar oscuro\n";
		Sleep(1000);
		cout << "G"; Sleep(500);
		cout << "A"; Sleep(500);
		cout << "M"; Sleep(500);
		cout << "E"; Sleep(500);
		cout << " "; Sleep(500);
		cout << "O"; Sleep(500);
		cout << "V"; Sleep(500);
		cout << "E"; Sleep(500);
		cout << "R"; Sleep(500);
	}
	if (enemy1IsAlive == false && enemy2IsAlive == false && heroIsAlive) {
		cout << heroName + " has derrotado a los enemigos\n";
		Sleep(1000);
		cout << "Gotam nunca olvidara este dia,";
		Sleep(1000);
		cout << "el dia que empezo el reinado de paz\n";
		Sleep(1000);
		cout << "El mundo se ha vuelto un lugar mas bonito gracias a ti "+heroName+"\n";
		/*Intro*/
		Beep(330, 100); Sleep(100);
		Beep(330, 100); Sleep(300);
		Beep(330, 100); Sleep(300);
		Beep(262, 100); Sleep(100);
		Beep(330, 100); Sleep(300);
		Beep(392, 100); Sleep(700);
		Beep(196, 100); Sleep(700);
		Beep(196, 100); Sleep(125);
		Beep(262, 100); Sleep(125);
		Beep(330, 100); Sleep(125);
		Beep(392, 100); Sleep(125);
		Beep(523, 100); Sleep(125);
		Beep(660, 100); Sleep(125);
		Beep(784, 100); Sleep(575);
		Beep(660, 100); Sleep(575);
		Beep(207, 100); Sleep(125);
		Beep(262, 100); Sleep(125);
		Beep(311, 100); Sleep(125);
		Beep(415, 100); Sleep(125);
		Beep(523, 100); Sleep(125);
		Beep(622, 100); Sleep(125);
		Beep(830, 100); Sleep(575);
		Beep(622, 100); Sleep(575);
		Beep(233, 100); Sleep(125);
		Beep(294, 100); Sleep(125);
		Beep(349, 100); Sleep(125);
		Beep(466, 100); Sleep(125);
		Beep(587, 100); Sleep(125);
		Beep(698, 100); Sleep(125);
		Beep(932, 100); Sleep(575);
		Beep(932, 100); Sleep(125);
		Beep(932, 100); Sleep(125);
		Beep(932, 100); Sleep(125);
		Beep(1046, 675);
		cout << "G"; Sleep(500);
		cout << "R"; Sleep(500);
		cout << "A"; Sleep(500);
		cout << "C"; Sleep(500);
		cout << "I"; Sleep(500);
		cout << "A"; Sleep(500);
		cout << "S"; Sleep(500);
		cout << " "; Sleep(500);
		cout << "P"; Sleep(500);
		cout << "O"; Sleep(500);
		cout << "R"; Sleep(500);
		cout << " "; Sleep(500);
		cout << "J"; Sleep(500);
		cout << "U"; Sleep(500);
		cout << "G"; Sleep(500);
		cout << "A"; Sleep(500);
		cout << "R"; Sleep(500);

		system("pause");
		return 0;
	
	}
}

