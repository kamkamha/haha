#pragma once
#include "Global.h"

class Texture
{
public:
	//texture
	int object;
	LPDIRECT3DTEXTURE9 texture;
	int objectTextureWidth;
	int objectTextureHeight;
	int objectSpriteWidth;
	int objectSpriteHeight;
	int objectSpriteRow;
	int objectSpriteCol;
	int objectMaxFrame;
	RECT objectAnimRect;
	RECT objectColRect;
	int objectCurrentFrame;
	float objectDirection;
	int objectSpriteFPS;
	D3DXVECTOR2 objectPosition;
	D3DXVECTOR2 objectVelocity;
	D3DXVECTOR2 objectAcceleration;
	int objectNum;
	D3DXVECTOR2 objectScaling;
	D3DXVECTOR2 objectSpriteCentre;
	float objectMass;
	float objectEnginePower;
	float objectRotationSpeed;
	static std::vector<Texture*> tex;
	Texture(int object,LPDIRECT3DTEXTURE9 texture,int objectTextureWidth,int objectTextureHeight,int objectSpriteRow,int objectSpriteCol,int objectMaxFrame,int objectCurrentFrame,float objectDirection,int objectSpriteFPS,D3DXVECTOR2 objectPosition,D3DXVECTOR2 objectVelocity,D3DXVECTOR2 objectAcceleration,int objectNum,D3DXVECTOR2 objectScaling,float objectMass,float objectEnginePower, float objectRotationSpeed);
	Texture();

};

