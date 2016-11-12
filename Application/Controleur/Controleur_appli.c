#include "controleur_appli.h"

int appuye_menu(uint16_t x, uint16_t y){
	if(y> 93 && y<=93+66){
		if(x>=31 && x<=31+66)return 1;
		if(x>=127 && x<=127+66)return 2;
		if(x>=223 && x<=223+66)return 3;
	}
	return 0;
}
