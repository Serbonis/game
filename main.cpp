//========================================
// main.cpp
//========================================
#include <Opal.hpp>
#include "game.hpp"

using namespace opal;

int main(){

	OPAL::PROJECT( GAME::PROJECT );
	OPAL::BGCOLOR( BLACK );

	return Opal( new GAME );
}

// End Of File
