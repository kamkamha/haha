#include "Game.h"

vector<Game*> Game::vect;
//FrameTimer* Game::timer = new FrameTimer;
void Game::Update(int framestoupdate)
{

}

void Game::Initialize() {
	
}

void Game::GetInput()
{
	dInputMouseDevice->Acquire();
	dInputMouseDevice->GetDeviceState(sizeof(mouseState), &mouseState);
	currentXpos += mouseState.lX;
	// See how far in the Y direction the mouse has been moved
	currentYpos += mouseState.lY;
	mousepos.x = currentXpos;
	mousepos.y = currentYpos;

	dInputKeyboardDevice->Acquire();
	//	Get immediate Keyboard Data.
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	if (diKeys[DIK_UP] & 0x80)
	{
		upkeypress = true;
	}
	if (diKeys[DIK_DOWN] & 0x80)
	{
		downkeypress = true;
	}
	if (diKeys[DIK_LEFT] & 0x80)
	{
		leftkeypress = true;
	}
	if ((diKeys[DIK_RIGHT] & 0x80))
	{
		rightkeypress = true; 
	}
	//if (!(diKeys[DIK_RIGHT] & 0x80)) {
	//	rightkeypress = false;
	//}
	if (diKeys[DIK_SPACE] & 0x80)
	{
		shoot = true;
		stopper = false;
	}
	if (!(diKeys[DIK_SPACE] & 0x80) && !stopper) {
		shoot = false;
		go = true;
		stopper = true;
	}if (diKeys[DIK_ESCAPE] & 0x80)
	{
		PostQuitMessage(0);
	}
}

void Game::Render() {
	//	To Do:
//	Update.
//	Clear the back buffer.
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(red, green, blue), 1.0f, 0);

	//	Begin the scene
	d3dDevice->BeginScene();

	//	To Do:
	//	Drawing.
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXMATRIX mat;
	//player 1 draw
	for (Texture* texture : Texture::tex) {
			D3DXMatrixTransformation2D(&mat, NULL, 0.0, &texture->objectScaling, &texture->objectSpriteCentre, texture->objectDirection, &texture->objectPosition);
			sprite->SetTransform(&mat);
			sprite->Draw(texture->texture, &texture->objectAnimRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}
	//D3DXMatrixTransformation2D(&mat, NULL, 0.0, &Texture::tex.back()->objectScaling, &Texture::tex.back()->objectSpriteCentre, Texture::tex.back()->objectDirection, &Texture::tex.back()->objectPosition);
	//sprite->SetTransform(&mat);
	//sprite->Draw(Texture::tex.back()->texture, &Texture::tex.back()->objectAnimRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//player 2 draw
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &player2scaling, &player2spritecentre, player2Direction, &player2position);
	sprite->SetTransform(&mat);
	sprite->Draw(Texture::tex.back()->texture, &player2animrect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	if (mass1hp > 0) {
		//mass 1 draw
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, &mass1scaling, &mass1spritecentre, mass1Direction, &mass1position);
		sprite->SetTransform(&mat);
		sprite->Draw(masstexture, &mass1animrect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}
	if (mass2hp > 0) {
		//mass 2 draw
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, &mass2scaling, &mass2spritecentre, mass2Direction, &mass2position);
		sprite->SetTransform(&mat);
		sprite->Draw(masstexture, &mass2animrect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}

	//D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &spriteCentre, rotation, &position);
	//sprite->SetTransform(&mat);
	// Tell the sprite about the matrix
	//	Sprite rendering. Study the documentation.
	/*sprite->Draw(texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));*/
	//sprite->Draw(texture, &spriteRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	// 
	string force = " ";
	int a = (int)charge;
	while (a != 0)
	{
		int b = a % 10;
		a = a / 10;
		force = numchar[b]+force;
	}
	cout << force;
	cout << "||";
	//std::ostringstream ss;
	//ss << charge;
	//std::string s(ss.str());
	force = "Force:" + force;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, 0, 0, 0, 0);
	//string force = "Force" + ss.str();
	sprite->SetTransform(&mat);

	font->DrawText(sprite,force.c_str(), 9, &textRect, 0, D3DCOLOR_XRGB(255, 255, 255));
	std::string(force).swap(force);
	force.clear();
	force.shrink_to_fit();
	// 
	//D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &spriteCentre, rotation, &mousepos);

	sprite->End();
	//	End sprite drawing

	//	End the scene
	d3dDevice->EndScene();

	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

bool Game::CollisionDetection(RECT A, RECT B) {
	if (A.top > B.bottom) {
		return false;
	}
	if (A.bottom < B.top) {
		return false;
	}
	if (A.left > B.right) {
		return false;
	}
	if (A.right < B.left) {
		return false;
	}
	else {
		return true;
	}
}

bool Game::circlecollisiondetection(float radiusA, float radiusB, D3DXVECTOR2 positionA, D3DXVECTOR2 positionB) {
	D3DXVECTOR2 distance = positionA - positionB;
	if (radiusA + radiusB > D3DXVec2Length(&distance))
	{
		return true;
	}
	else {
		return false;
	}
}