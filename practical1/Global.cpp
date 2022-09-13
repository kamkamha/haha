#include "Global.h"

//	Window handle
HWND g_hWnd = NULL;
//--------------------------------------------------------------------

//DX global
IDirect3DDevice9* d3dDevice;
WNDCLASS wndClass;
D3DPRESENT_PARAMETERS d3dPP;
LPD3DXSPRITE sprite = NULL;
RECT textRect;
LPD3DXFONT font = NULL;
LPD3DXLINE line = NULL;
LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;
LPDIRECTINPUTDEVICE8  dInputMouseDevice;
LPDIRECTINPUT8 dInput;
BYTE  diKeys[256];
LPDIRECTINPUT8 dInput2;
DIMOUSESTATE mouseState;
LONG currentXpos;
LONG currentYpos;

//mass
LPDIRECT3DTEXTURE9 masstexture = NULL;
int masstexturewidth = 0;
int masstextureheight = 0;
int massspritewidth = 0;
int massspriteheight = 0;
int massspriterow = 0;
int massspritecol = 0;
int massmaxframe = 1;

//mass 1 globals
RECT mass1animrect;
RECT mass1colrect;
int mass1currentframe = 0;
float mass1Direction;
int mass1spriteFPS = 0;
D3DXVECTOR2 mass1position;
D3DXVECTOR2 mass1velocity;
D3DXVECTOR2 mass1acceleration;
int mass1num = 1;
D3DXVECTOR2 mass1scaling;
D3DXVECTOR2 mass1spritecentre;
float mass1mass;
float mass1enginepower;
float mass1rotationspeed;
int mass1hp;

//mass 2 globals
RECT mass2animrect;
RECT mass2colrect;
int mass2currentframe = 0;
float mass2Direction;
int mass2spriteFPS = 0;
D3DXVECTOR2 mass2position;
D3DXVECTOR2 mass2velocity;
int mass2num = 2;
D3DXVECTOR2 mass2scaling;
D3DXVECTOR2 mass2spritecentre;
D3DXVECTOR2 mass2acceleration;
float mass2mass;
float mass2enginepower;
float mass2rotationspeed;
int mass2hp;
//texture
LPDIRECT3DTEXTURE9 texture[20];
int playertexturewidth = 0;
int playertextureheight = 0;
int playerspritewidth = 0;
int playerspriteheight = 0;
int playerspriterow = 0;
int playerspritecol = 0;
int playermaxframe = 1;

//player 1 globals
RECT player1animrect;
RECT player1colrect;
int player1currentframe = 0;
float player1Direction;
int player1spriteFPS = 0;
D3DXVECTOR2 player1position;
D3DXVECTOR2 player1velocity;
D3DXVECTOR2 player1acceleration;
int player1num = 1;
D3DXVECTOR2 player1scaling;
D3DXVECTOR2 player1spritecentre;
float player1mass;
float player1enginepower;
float player1rotationspeed;

//player 2 globals
RECT player2animrect;
RECT player2colrect;
int player2currentframe = 0;
float player2Direction;
int player2spriteFPS = 0;
D3DXVECTOR2 player2position;
D3DXVECTOR2 player2velocity;
int player2num = 2;
D3DXVECTOR2 player2scaling;
D3DXVECTOR2 player2spritecentre;
D3DXVECTOR2 player2acceleration;
float player2mass;
float player2enginepower;
float player2rotationspeed;
//global variable

D3DXVECTOR2 position, mousepos;
int blue = 0, red = 0, green = 0;
int haha = GetSystemMetrics(SM_CXSCREEN);
int hehe = GetSystemMetrics(SM_CYSCREEN);
boolean adding = true;
boolean leftkeypress = false;
boolean downkeypress = false;
boolean upkeypress = false;
boolean rightkeypress = false;
boolean shoot = false;

////enum charactermovement {movedown, moveleft, moveright, moveup};
//int movement = 0;
int counter = 0;
float gravity;
float friction = 0.03;
float charge = 0;
boolean chargemax = false;
boolean go = false;
boolean end1 = false;
boolean stopper = true;
boolean launcher = false;
D3DXVECTOR2 positionbefore;
D3DXVECTOR2 distancechanged;
D3DXVECTOR2 startpoint = D3DXVECTOR2(400, 250);
D3DXVECTOR2 endpoint = D3DXVECTOR2(200, 200);
D3DXVECTOR2 lineVertices[] = { startpoint,endpoint };
FrameTimer* timer = new FrameTimer;
char numchar[10] = {'0','1','2','3','4','5','6','7','8','9'};
