#include<iostream>
#include "Utilities.h"
#include "CEngine.h"



int main(int argc, char* args[]) {

	CEngine Engine;


	if (Engine.Initialize()) {
		Engine.Run();
	}
	Engine.Shutdown();

	return 0;
}
