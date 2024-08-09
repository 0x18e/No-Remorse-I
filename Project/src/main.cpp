#include<iostream>
#include "Utilities.h"
#include "CEngine.h"
#include "hello.h"



int main(int argc, char* args[]) {

	CEngine Engine;


	if (Engine.Initialize()) {
		Engine.Run();
	}
	Engine.Shutdown();
	// SDL Requires a return code
	return 0;
}
