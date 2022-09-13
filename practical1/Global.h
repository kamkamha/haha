#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#include <Windowsx.h>
#include <dinput.h>
#include <vector>
#include "FrameTimer.h"
#include "Game.h"
#include "Texture.h"
#include <sstream>
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
//	Window handle
extern HWND g_hWnd;
//--------------------------------------------------------------------

//DX global
extern IDirect3DDevice9* d3dDevice;
extern WNDCLASS wndClass;
extern D3DPRESENT_PARAMETERS d3dPP;
extern LPD3DXSPRITE sprite ;
extern RECT textRect;
extern LPD3DXFONT font ;
extern LPD3DXLINE line;
extern LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;
extern LPDIRECTINPUTDEVICE8   dInputMouseDevice;
extern LPDIRECTINPUT8  dInput;
extern BYTE  diKeys[256];
extern LPDIRECTINPUT8  dInput2;
extern DIMOUSESTATE mouseState;
extern LONG currentXpos;
extern LONG currentYpos;

//mass
extern LPDIRECT3DTEXTURE9 masstexture;
extern int masstexturewidth ;
extern int masstextureheight ;
extern int massspritewidth ;
extern int massspriteheight ;
extern int massspriterow ;
extern int massspritecol ;
extern int massmaxframe ;

//mass 1 globals
extern RECT mass1animrect;
extern RECT mass1colrect;
extern int mass1currentframe ;
extern float mass1Direction;
extern int mass1spriteFPS ;
extern D3DXVECTOR2 mass1position;
extern D3DXVECTOR2 mass1velocity;
extern D3DXVECTOR2 mass1acceleration;
extern int mass1num ;
extern D3DXVECTOR2 mass1scaling;
extern D3DXVECTOR2 mass1spritecentre;
extern float mass1mass;
extern float mass1enginepower;
extern float mass1rotationspeed;
extern int mass1hp;

//mass 2 globals
extern RECT mass2animrect;
extern RECT mass2colrect;
extern int mass2currentframe ;
extern float mass2Direction;
extern  int mass2spriteFPS ;
extern  D3DXVECTOR2 mass2position;
extern  D3DXVECTOR2 mass2velocity;
extern  int mass2num ;
extern  D3DXVECTOR2 mass2scaling;
extern  D3DXVECTOR2 mass2spritecentre;
extern  D3DXVECTOR2 mass2acceleration;
extern  float mass2mass;
extern  float mass2enginepower;
extern  float mass2rotationspeed;
extern  int mass2hp;
//texture
extern  LPDIRECT3DTEXTURE9 texture[20];
extern  int playertexturewidth ;
extern  int playertextureheight ;
extern  int playerspritewidth ;
extern  int playerspriteheight ;
extern int playerspriterow ;
extern int playerspritecol ;
extern int playermaxframe ;

//player 1 globals
extern RECT player1animrect;
extern RECT player1colrect;
extern int player1currentframe;
extern float player1Direction;
extern int player1spriteFPS;
extern D3DXVECTOR2 player1position;
extern D3DXVECTOR2 player1velocity;
extern D3DXVECTOR2 player1acceleration;
extern int player1num ;
extern D3DXVECTOR2 player1scaling;
extern D3DXVECTOR2 player1spritecentre;
extern float player1mass;
extern float player1enginepower;
extern float player1rotationspeed;

//player 2 globals
extern RECT player2animrect;
extern RECT player2colrect;
extern int player2currentframe ;
extern float player2Direction;
extern int player2spriteFPS  ;
extern D3DXVECTOR2 player2position;
extern D3DXVECTOR2 player2velocity;
extern int player2num ;
extern D3DXVECTOR2 player2scaling;
extern D3DXVECTOR2 player2spritecentre;
extern D3DXVECTOR2 player2acceleration;
extern float player2mass;
extern float player2enginepower;
extern float player2rotationspeed;
//global variable

extern D3DXVECTOR2 position, mousepos;
extern int blue , red , green ;
extern int haha ;
extern int hehe ;
extern boolean adding ;
extern boolean leftkeypress ;
extern boolean downkeypress ;
extern boolean upkeypress ;
extern boolean rightkeypress ;
extern boolean shoot ;
extern float charge;
extern boolean chargemax;
extern boolean go;
extern boolean end1;
extern boolean stopper;
extern boolean launcher;
extern D3DXVECTOR2 positionbefore;
extern D3DXVECTOR2 distancechanged;
////enum charactermovement {movedown, moveleft, moveright, moveup};
//int movement = 0;
extern int counter;
extern float gravity;
extern float friction;

extern D3DXVECTOR2 startpoint;
extern D3DXVECTOR2 endpoint;
extern D3DXVECTOR2 lineVertices[];
extern FrameTimer* timer;
extern char numchar[10];




