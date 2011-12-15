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

#ifndef __GFX_H__
#define __GFX_H__

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>


class gfx{
public:
	gfx(){
		Font="/dev_hdd0/game/PS3PRINTF/Sans.ttf";
		font_size=10;
		x=60; y=20;
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();
		video = SDL_SetVideoMode(1280,720,32,SDL_FULLSCREEN|SDL_SWSURFACE);
	}
	gfx(int SW1,int SH1,int BPP1){
		Font="/dev_hdd0/game/PS3PRINTF/Sans.ttf";
		font_size=10;
		x=60; y=20;
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();
		video = SDL_SetVideoMode(SW,SH,BPP,SDL_FULLSCREEN|SDL_SWSURFACE);
	}
	gfx(int SW1,int SH1,int BPP1,int FontSize){
		Font="/dev_hdd0/game/PS3PRINTF/Sans.ttf";
		font_size=FontSize;
		x=60; y=20;
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();
		video = SDL_SetVideoMode(SW,SH,BPP,SDL_FULLSCREEN|SDL_SWSURFACE);
	}
	gfx(int SW1,int SH1,int BPP1,const char* Font_Path){
		Font=Font_Path;
		font_size=10;
		x=60; y=20;
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();
		video = SDL_SetVideoMode(SW,SH,BPP,SDL_FULLSCREEN|SDL_SWSURFACE);
	}
	gfx(int SW1,int SH1,int BPP1,int FontSize,const char* Font_Path){
		Font=Font_Path;
		font_size=FontSize;
		x=60; y=20;
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();
		video = SDL_SetVideoMode(SW,SH,BPP,SDL_FULLSCREEN|SDL_SWSURFACE);
	}
	~gfx(){
		TTF_Quit();
		SDL_Quit();
	}
	void Wait(int N){SDL_Delay(N*1000);}
	void uWait(int N){SDL_Delay(N);}
	void printf(const char *a, ...);
	void SetFontSize(int n){font_size=n;}


private:
	void Flip(){SDL_Flip(video);SDL_FreeSurface(video);}
	SDL_Surface *video;
	const char *Font;
	double x;
	double y;
	int font_size;
	int SW;
	int SH;
	int BPP;
};
#endif
