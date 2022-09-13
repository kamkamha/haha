#include "Texture.h"
vector<Texture*> Texture::tex;



Texture::Texture(int object, LPDIRECT3DTEXTURE9 texture, int objectTextureWidth, int objectTextureHeight, int objectSpriteRow, int objectSpriteCol, int objectMaxFrame, int objectCurrentFrame, float objectDirection, int objectSpriteFPS, D3DXVECTOR2 objectPosition, D3DXVECTOR2 objectVelocity, D3DXVECTOR2 objectAcceleration, int objectNum, D3DXVECTOR2 objectScaling, float objectMass, float objectEnginePower, float objectRotationSpeed)
{
	//texture
	this->object = object;
	this->texture = texture;
	//texture information
	this->objectTextureWidth = objectTextureWidth;
	this->objectTextureHeight = objectTextureHeight;
	this->objectSpriteRow = objectSpriteRow;
	this->objectSpriteCol = objectSpriteCol;
	this->objectSpriteWidth = objectTextureWidth/ objectSpriteCol;
	this->objectSpriteHeight = objectTextureHeight/ objectSpriteRow;
	this->objectMaxFrame = objectMaxFrame;
	this->objectCurrentFrame = objectCurrentFrame;
	//texture animation rect
	this->objectAnimRect.top = objectCurrentFrame * this->objectSpriteHeight;
	this->objectAnimRect.bottom = this->objectAnimRect.top + this->objectSpriteHeight;
	this->objectAnimRect.left = 0 * this->objectSpriteWidth;
	this->objectAnimRect.right = this->objectAnimRect.left + this->objectSpriteWidth;
	//texture position and rect
	this->objectPosition = objectPosition;
	objectColRect.top = objectPosition.y;
	objectColRect.bottom = this->objectColRect.top + this->objectSpriteHeight;
	objectColRect.left = objectPosition.x;
	objectColRect.right = this->objectColRect.left + this->objectSpriteWidth;

	//texture status
	this->objectSpriteFPS = objectSpriteFPS;
	this->objectVelocity = objectVelocity;
	this->objectAcceleration = objectAcceleration;
	this->objectNum = objectNum;
	this->objectScaling = objectScaling;
	this->objectSpriteCentre = D3DXVECTOR2(this->objectSpriteWidth / 2, this->objectSpriteHeight / 2);;
	this->objectMass = objectMass;
	this->objectEnginePower = objectEnginePower;
	this->objectRotationSpeed = objectRotationSpeed;
}


