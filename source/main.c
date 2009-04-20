#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>

#include "soundbank.h"
#include "soundbank_bin.h"

int main()
{
	consoleDemoInit();

	consoleClear();

	mmInitDefaultMem( (mm_addr)soundbank_bin );
	
	// load the MOD_SONG000 module
	mmLoad( MOD_SONG000 );

	// Start looping MOD_SONG000
	mmStart( MOD_SONG000, MM_PLAY_LOOP );

	// ansi escape sequence to set print co-ordinates
	// /x1b[line;columnH
	iprintf( "\x1b[6;10HJohn's Game" );
	iprintf( "\x1b[16;9H<Press Start>" );
	
	uint32 keys_pressed;
	uint32 keys_released;

	do {		
		swiWaitForVBlank();

		scanKeys();
		keys_pressed = keysDown();
		keys_released = keysUp();

		if ( keys_pressed & KEY_START )
		{
			iprintf( "\x1b[17;11HYou Wish!" );
		}

		if ( keys_released & KEY_START )
		{
			iprintf( "\x1b[17;11H         " );
		}
	} while( 1 );
}
