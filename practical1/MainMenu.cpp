#include "MainMenu.h"
void MainMenu::Update(int framestoupdate)
{
	
	//if (shoot) {
	//	delete Texture::tex.back();
	//	Texture::tex.pop_back();
	//	Texture::tex.push_back(new Texture(0, texture, 64, 64, 2, 2, 1, 0, 0.0f, 10, D3DXVECTOR2(100.0f, 500.0f), D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f), 0, D3DXVECTOR2(1.0f, 1.0f), 0.1, 1, 0.1));
	//}
	Texture* player = NULL;
	for (Texture* texture : Texture::tex) {
		if (texture->object == 0) {
			player = texture;
		}
	}
	if (!launcher) {
		if (shoot) {
			if (charge < 100 && !chargemax) {
				charge += 0.3;
				chargemax = false;
			}
			else if (charge >= 100 || chargemax) {
				chargemax = true;
				charge -= 0.3;
				if (charge <= 0) {
					chargemax = false;
				}
			}
		}

	}
	for (int i = 0; i < framestoupdate; i++) {
		if (leftkeypress) {
			player->objectDirection -= player->objectRotationSpeed;
		}
		if (rightkeypress) {
			player->objectDirection += player->objectRotationSpeed;
		}
		if (upkeypress) {
			player->objectAcceleration.x = sin(player->objectDirection) * player->objectEnginePower / player->objectMass;
			player->objectAcceleration.y = -cos(player->objectDirection) * player->objectEnginePower / player->objectMass;
		}

		//collision check
		if (circlecollisiondetection(player->objectSpriteWidth / 2, player->objectSpriteWidth / 2, player->objectPosition + player->objectSpriteCentre, player2position + player2spritecentre)) {
			cout << "haha";
			D3DXVECTOR2 normalvector = player2position - player->objectPosition;
			D3DXVECTOR2 finalNormal;
			D3DXVec2Normalize(&finalNormal, &normalvector);
			D3DXVECTOR2 veln = finalNormal * D3DXVec2Dot(&player->objectVelocity, &finalNormal);
			D3DXVECTOR2 velt = player->objectVelocity - veln;
			D3DXVECTOR2 reflectedvel = velt - veln;

			float totalForce = ((player->objectMass * D3DXVec2Length(&player->objectAcceleration)) + (player2mass * D3DXVec2Length(&player2acceleration))) / player2num;

			player->objectVelocity = reflectedvel;

			player->objectVelocity += player->objectAcceleration * totalForce;
		}
		if (go) {
			if (!launcher)
			{
				player->objectAcceleration.x = sin(player->objectDirection) * charge / player->objectMass;
				player->objectAcceleration.y = -cos(player->objectDirection) * charge / player->objectMass;
				player->objectAcceleration.x += 10;
				charge = 0;
				launcher = true;
			}

		}
		positionbefore = player->objectPosition;
		player->objectVelocity += player->objectAcceleration;
		player->objectVelocity *= 1 - friction;
		player->objectPosition += player->objectVelocity;
		distancechanged = player->objectPosition - positionbefore;
		if (go) {
			if (D3DXVec2Length(&distancechanged) < 0.0001) {
				end1 = true;
				go = false;
			}
		}
		if (end1) {
			int count = 0;
			for (Texture* texture : Texture::tex) {
				if (texture->object == 0) {
					break;
				}
				count++;
			}
			Texture::tex.erase(Texture::tex.begin()+count);
			Texture::tex.push_back(new Texture(0, texture[0], 64, 64, 2, 2, 1, 0, 0.0f, 10, D3DXVECTOR2(haha / 2, hehe - 64), D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f), 0, D3DXVECTOR2(1.0f, 1.0f), 1.7, 1, 0.1));
			launcher = false;
		}
		//collision check
		if (mass1hp > 0) {
			if (circlecollisiondetection(player->objectSpriteWidth / 2, massspritewidth*3 / 2, player->objectPosition + player->objectSpriteCentre, mass1position + mass1spritecentre)) {
				mass1hp--;
				player->objectMass += mass1mass;
				cout << player->objectMass;
				/*mass1scaling = D3DXVECTOR2(0.0f, 0.0f);*/
			}
		}
		//collision check
		if (mass2hp > 0) {
			if (circlecollisiondetection(player->objectSpriteWidth / 2, massspritewidth*3 / 2, player->objectPosition + player->objectSpriteCentre, mass2position + mass2spritecentre)) {
				mass2hp--;
				player->objectMass += mass1mass;
				cout << player->objectMass;
				/*mass2scaling = D3DXVECTOR2(0.0f, 0.0f);*/
			}
		}
		//boundarycheck,bounce
		if (player->objectPosition.x<0 || player->objectPosition.x>haha - player->objectSpriteWidth) {
			if (player->objectPosition.x < 0)
			{
				player->objectPosition.x = 0;
			}
			if (player->objectPosition.x > haha - player->objectSpriteWidth)
			{
				player->objectPosition.x = haha - player->objectSpriteWidth;
			}
			player->objectVelocity.x *= -1;
		}
		if (player->objectPosition.y<0 || player->objectPosition.y>hehe - player->objectSpriteHeight) {
			player->objectVelocity.y *= -1;
		}

		//boundarycheck,bounce
		if (player2position.x<0 || player2position.x>haha - playerspritewidth) {
			if (player2position.x < 0)
			{
				player2position.x = 0;
			}
			if (player2position.x > haha - playerspritewidth)
			{
				player2position.x = haha - playerspritewidth;
			}
			player2velocity.x *= -1;
		}
		if (player2position.y<0 || player2position.y>hehe - playerspriteheight) {
			player2velocity.y *= -1;
		}

		//animation
		counter++;
		if (counter % (timer->GetFPS() / player->objectSpriteFPS) == 0) {
			player->objectCurrentFrame++;
			if (player->objectCurrentFrame > player->objectMaxFrame) {
				player->objectCurrentFrame = 0;
			}
			player2currentframe++;
			if (player2currentframe > playermaxframe) {
				player2currentframe = 0;
			}
		}

		player->objectAnimRect.top = player->objectCurrentFrame * player->objectSpriteHeight;
		player->objectAnimRect.bottom = player->objectAnimRect.top + player->objectSpriteHeight;
		player->objectAnimRect.left = 0 * player->objectSpriteWidth;
		player->objectAnimRect.right = player->objectAnimRect.left + player->objectSpriteWidth;

		player2animrect.top = player2currentframe * playerspriteheight;
		player2animrect.bottom = player2animrect.top + playerspriteheight;
		player2animrect.left = (player2num - 1) * playerspritewidth;
		player2animrect.right = player2animrect.left + playerspritewidth;
	}
	end1 = false;
	leftkeypress = false;
	rightkeypress = false;
	upkeypress = false;
	downkeypress = false;

	player->objectAcceleration = D3DXVECTOR2(0, 0);
	player2acceleration = D3DXVECTOR2(0, 0);
}

void MainMenu::Initialize() {
	srand(time(0));
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "practical9.png", &texture[0]);
	if (FAILED(hr)) {
		cout << "Texture failed to load";
	}
	hr = D3DXCreateTextureFromFile(d3dDevice, "ocean.png", &texture[1]);
	if (FAILED(hr)) {
		cout << "Texture failed to load";
	}
	hr = D3DXCreateTextureFromFile(d3dDevice, "mass.png", &masstexture);
	if (FAILED(hr)) {
		cout << "Texture failed to load";
	}
	Texture::tex.emplace_back(new Texture(1, texture[1], 1920, 1080, 1, 1, 1, 0, 0.0f, 0, D3DXVECTOR2(0, 0), D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f), 0, D3DXVECTOR2(1.0f, 1.0f), 0, 0, 0));
	Texture::tex.emplace_back(new Texture(0, texture[0], 64, 64, 2, 2, 1, 0, 0.0f, 10, D3DXVECTOR2(haha / 2, hehe - 64), D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f), 0, D3DXVECTOR2(1.0f, 1.0f), 1.7, 1, 0.1));
	//texture
	playertexturewidth = 64;
	playertextureheight = 64;
	playerspriterow = 2;
	playerspritecol = 2;
	playerspritewidth = playertexturewidth / playerspritecol;
	playerspriteheight = playertextureheight / playerspriterow;
	playermaxframe = 1;
	////player 1 globals
	//player1currentframe = 0;
	//player1animrect.top = player1currentframe * playerspriteheight;
	//player1animrect.bottom = player1animrect.left + playerspriteheight;
	//player1animrect.left = (player1num - 1) * playerspritewidth;
	//player1animrect.right = player1animrect.left + playerspritewidth;

	//player1position = D3DXVECTOR2(100.0f, 300.0f);

	//player1colrect.top = player1position.y;
	//player1colrect.bottom = player1colrect.top + playerspriteheight;
	//player1colrect.left = player1position.x;
	//player1colrect.right = player1colrect.left + playerspritewidth;

	//player1velocity = D3DXVECTOR2(0.0f, 0.0f);

	//player1Direction = 0.0f;
	//player1spriteFPS = 10;
	//player1scaling = D3DXVECTOR2(1.0f, 1.0f);
	//player1spritecentre = D3DXVECTOR2(playerspritewidth / 2, playerspriteheight / 2);

	//player1enginepower = 1;
	//player1rotationspeed = 0.1;
	//player1mass = 0.1;

	//player1acceleration = D3DXVECTOR2(0.0f, 0.0f);

	//player 2 globals
	player2currentframe = 0;
	player2animrect.top = player2currentframe * playerspriteheight;
	player2animrect.bottom = player2animrect.top + playerspriteheight;
	player2animrect.left = (player2num - 1) * playerspritewidth;;
	player2animrect.right = player2animrect.left + playerspritewidth;

	player2position = D3DXVECTOR2(500.0f, 300.0f);

	player2colrect.top = player2position.y;
	player2colrect.bottom = player2colrect.left + playerspriteheight;
	player2colrect.left = player2position.x;
	player2colrect.right = player2colrect.left + playerspritewidth;

	player2velocity = D3DXVECTOR2(0.0f, 0.0f);;

	player2Direction = 0.0f;
	player2spriteFPS = 10;
	player2scaling = D3DXVECTOR2(1.0f, 1.0f);
	player2spritecentre = D3DXVECTOR2(playerspritewidth / 2, playerspriteheight / 2);

	player2enginepower = 1;
	player2rotationspeed = 0.1;
	player2mass = 1;

	player2acceleration = D3DXVECTOR2(0.0f, 0.0f);

	//MASS INIT
	//texture
	LPDIRECT3DTEXTURE9 masstexture = NULL;
	masstexturewidth = 32;
	masstextureheight = 32;
	massspriterow = 0;
	massspritecol = 0;
	massspritewidth = 9;
	massspriteheight = 9;
	massmaxframe = 0;

	//mass 1 globals
	mass1currentframe = 0;
	mass1animrect.top = 0;
	mass1animrect.bottom = mass1animrect.left + massspriteheight;
	mass1animrect.left = 0;
	mass1animrect.right = mass1animrect.left + massspritewidth;

	//GENERATE A NUMBER BETWEEN 0 - HAHA - SPRITEWIDTH
	mass1position = D3DXVECTOR2(rand() % (haha - massspritewidth), rand() % (hehe - massspriteheight));

	mass1colrect.top = mass1position.y;
	mass1colrect.bottom = mass1colrect.top + massspriteheight;
	mass1colrect.left = mass1position.x;
	mass1colrect.right = mass1colrect.left + massspritewidth;

	mass1velocity = D3DXVECTOR2(0.0f, 0.0f);

	mass1Direction = 0.0f;
	mass1spriteFPS = 10;
	mass1scaling = D3DXVECTOR2(3.0f, 3.0f);
	mass1spritecentre = D3DXVECTOR2(massspritewidth*3 / 2, massspriteheight*3 / 2);

	mass1enginepower = 1;
	mass1rotationspeed = 0.1;
	mass1mass = 1;
	mass1hp = 1;
	mass1acceleration = D3DXVECTOR2(0.0f, 0.0f);

	//mass 2 globals
	mass2currentframe = 0;
	mass2animrect.top = 0;
	mass2animrect.bottom = mass2animrect.top + massspriteheight;
	mass2animrect.left = 0;
	mass2animrect.right = mass2animrect.left + massspritewidth;

	mass2position = D3DXVECTOR2(rand() % (haha - massspritewidth), rand() % (hehe - massspriteheight));

	mass2colrect.top = mass2position.y;
	mass2colrect.bottom = mass2colrect.left + massspriteheight;
	mass2colrect.left = mass2position.x;
	mass2colrect.right = mass2colrect.left + massspritewidth;

	mass2velocity = D3DXVECTOR2(0.0f, 0.0f);;

	mass2Direction = 0.0f;
	mass2spriteFPS = 10;
	mass2scaling = D3DXVECTOR2(3.0f, 3.0f);
	mass2spritecentre = D3DXVECTOR2(massspritewidth*3 / 2, massspriteheight*3 / 2);

	mass2enginepower = 1;
	mass2rotationspeed = 0.1;
	mass2mass = 1;
	mass2hp = 1;
	mass2acceleration = D3DXVECTOR2(0.0f, 0.0f);

	textRect.top = 0;
	textRect.bottom = 50;
	textRect.left = 0;
	textRect.right = 170;
}