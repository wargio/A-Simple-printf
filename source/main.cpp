/*
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 This program was created by Grazioli Giovanni Dante <wargio@libero.it>.
*/

#include <ppu-types.h>
#include <ppu-lv2.h>
#include <io/pad.h>
#include "gfx.h"



int main(int argc, char *argv[]){
	padData paddata;
	padInfo padinfo;
	ioPadInit (7);


	gfx *me=new gfx(); //init it as an object


	me->printf("This is a simple example of how my printf works.. "); //it will automatically use \n
	me->printf("It doesn't need a \\n");
	me->printf("If you need a \\r function i will write it");
	me->printf("You can use standard %%f or %%d, an example");
	me->printf("Sum of %d, %f is %f", 13,5.423131,13+5.423131);
	me->printf("you can use this as a normal printf() function");
	me->printf(" ");
	me->printf("What happen if i write too many things? let's find out:");
	me->printf("------------------------------------------------");
	for(int i=0;i<100;i++) me->printf("   %i",i);

	me->printf("Demo ended..");
	me->printf("Press start to return to the XMB..");

/* 
 * With my "lib" you can do:
 * it's possible to change SCREEN SIZE by calling gfx(int Screen_Width,int Screen_High, BPP)
 * you can change the FONT SIZE by calling gfx(int Screen_Width,int Screen_High, BPP, int FontSize) or SetFontSize(int size)
 * you can also change the path of the font: gfx(int Screen_Width,int Screen_High, BPP, int FontSize, const char* Font_Path)
 * You can also do not use any controller, and just call Wait(int seconds) or uWait(int milliseconds) before exit.
 */

	while(1){
		ioPadGetInfo (&padinfo);
		for(int i=0;i<MAX_PADS;i++){
			if(padinfo.status[i]){
				ioPadGetData(i, &paddata);
				if(paddata.BTN_START){
					goto end;
				}
			}
		}
	}
end:
	ioPadEnd();
	delete me;
	return 0;
}
