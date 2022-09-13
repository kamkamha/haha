//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN
#pragma warning(disable 4996)
#include "Global.h"
#include "MainMenu.h"

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

		//	The message is post when we destroy the window.
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
void createWindow() {

	ZeroMemory(&wndClass, sizeof(wndClass));

	//	Filling wndClass. You are to refer to MSDN for each of the members details.
	//	These are the fundamental structure members to be specify, in order to create your window.
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hInstance = GetModuleHandle(NULL);
	wndClass.lpfnWndProc = WindowProcedure;
	wndClass.lpszClassName = "My Window";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	ShowCursor(FALSE);
	RegisterClass(&wndClass);
	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "My Window's Name", WS_OVERLAPPEDWINDOW, 0, 100, 800, 600, NULL, NULL, wndClass.hInstance, NULL);
	ShowWindow(g_hWnd, 1);

}
bool windowIsRunning()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		//	Receive a quit message
		if (msg.message == WM_QUIT) {
			return false;
		}
		//	Translate the message 
		TranslateMessage(&msg);
		//	Send message to your window procedure
		DispatchMessage(&msg);
	}
	return true;
}
void CleanUpWindow() {
	//	Free up the memory.
	UnregisterClass(wndClass.lpszClassName, wndClass.hInstance);
}
int createMyDx() {
	IDirect3D9* direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	//	Define how the screen presents.

	ZeroMemory(&d3dPP, sizeof(d3dPP));

	//	Refer to Direct3D 9 documentation for the meaning of the members.
	d3dPP.Windowed = true;
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dPP.BackBufferCount = 1;
	d3dPP.BackBufferWidth = haha;
	d3dPP.BackBufferHeight = hehe;
	d3dPP.hDeviceWindow = g_hWnd;

	//	Create a Direct3D 9 device.
	HRESULT hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);

	//	To Do: Cout out the message to indicate the failure.
	if (FAILED(hr))
		return 0;


	hr = D3DXCreateSprite(d3dDevice, &sprite);
	if (FAILED(hr))
		return 0;

	hr = D3DXCreateFont(d3dDevice, 25, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &font);
	if (FAILED(hr))
		return 0;

	hr = D3DXCreateLine(d3dDevice, &line);
	if (FAILED(hr))
		return 0;
}
void CreateInput() {

	//	Create the Direct Input object.
	HRESULT hr = DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput, NULL);
	hr = DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput2, NULL);
	//	Direct Input keyboard device.

	//	Create the keyboard device.
	hr = dInput->CreateDevice(GUID_SysKeyboard, &dInputKeyboardDevice, NULL);
	hr = dInput2->CreateDevice(GUID_SysMouse, &dInputMouseDevice, NULL);

	//	Set the input data format.
	dInputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	dInputKeyboardDevice->SetCooperativeLevel(g_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	dInputMouseDevice->SetDataFormat(&c_dfDIMouse);
	dInputMouseDevice->SetCooperativeLevel(g_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
}
void cleanUpMyDx() {
	sprite->Release();
	sprite = NULL;
	for (LPDIRECT3DTEXTURE9 texture : texture) {
		if (texture != nullptr) {
			texture->Release();
			texture = NULL;
		}
	}
	Texture::tex.clear();
	Game::vect.clear();
	masstexture->Release();
	masstexture = NULL;
	d3dDevice->Release();
	//	Reset pointer to NULL, a good practice.
	d3dDevice = NULL;
	font->Release();
	font = NULL;

	line->Release();
	line = NULL;
}
void cleanupmyinput() {
	dInputKeyboardDevice->Unacquire();
	dInputKeyboardDevice->Release();
	dInputKeyboardDevice = NULL;

	//	Release DirectInput.
	dInput->Release();
	dInput = NULL;

	dInputMouseDevice->Unacquire();
	dInputMouseDevice->Release();
	dInputMouseDevice = NULL;

	//	Release DirectInput.
	dInput2->Release();
	dInput2 = NULL;
}

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Game::vect.push_back(new MainMenu);
	createWindow();
	createMyDx();
	Game::vect.back()->Initialize();
	CreateInput();
	timer->init(60);
	//	Define Direct3D 9.
	while (windowIsRunning())
	{
		Game::vect.back()->GetInput();
		Game::vect.back()->Update(timer->FramesToUpdate());
		Game::vect.back()->Render();
	}
	cleanupmyinput();
	cleanUpMyDx();
	CleanUpWindow();

	return 0;
}




