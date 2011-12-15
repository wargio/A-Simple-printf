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

#include "gfx.h"

void gfx::printf( const char *a, ...){
	SDL_Color WHITE = {255,255,255};
	TTF_Font *FONT = TTF_OpenFont(Font,font_size);
	char msg[1024];
	va_list va;
	va_start(va, a);
	vsnprintf(msg, sizeof msg, a, va);

	SDL_Surface *txt = TTF_RenderText_Blended(FONT, msg, WHITE);
	SDL_Rect offset;
	if(y>=SH-20){ x+=400; y=20;}
	offset.x = (int)(1*x);
	offset.y = (int)(1*y);
	SDL_BlitSurface(txt,NULL,video,&offset);
	SDL_FreeSurface(txt);
	y+=10;
	TTF_CloseFont(FONT);
	Flip();
}
