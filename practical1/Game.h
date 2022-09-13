#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>
#include <dinput.h>
#include <string>
#include <Windowsx.h>
#include <stdio.h>
#include "Global.h"
#include "Texture.h"
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
using namespace std;
class Game
{
public:
	virtual void Update(int framestoupdate);
	virtual void Initialize();
	void GetInput();
	void Render();
	void CleanUp();
	bool CollisionDetection(RECT A, RECT B);
	bool circlecollisiondetection(float radiusA, float radiusB, D3DXVECTOR2 positionA, D3DXVECTOR2 positionB);
	static std::vector<Game*> vect;
	

};


