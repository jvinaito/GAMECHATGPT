#include <graphics.h>
#include <conio.h>
#include <iostream>
#include<vector>
#include <unistd.h>
#include <queue>   // Thu vi?n cho std::queue
#include <utility> // Thu vi?n cho std::pair
#include <windows.h>
#include <mmsystem.h>  // Thu vi?n h? tr? mciSendString
#pragma comment(lib, "winmm.lib")  // Li�n k?t thu vi?n
  // Thu vi?n cho delay
using namespace std;
bool isGameReset = false;
int MenuVolume=500;
int IngameVolume=500;
int pointColor=YELLOW;
int wallColor=BLUE;
int pacman1Color=RED;
int pacman2Color=GREEN;
const int SCREEN_WIDTH = 1680;
const int SCREEN_HEIGHT = 885;
const int gridSize = 30;
int x1=0;
int y1=0;
int x2=0;
int y2=0;
int initialmaze1[20][20];
int initialmaze2[20][20];
int maze1[20][20] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {3, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 3},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int maze2[20][20] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
	{1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void resetMaze() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            maze1[i][j] = initialmaze1[i][j];
            maze2[i][j] = initialmaze2[i][j]; 
        }
    }
}

void setVolume(int volume, const char* audioAlias) {
    // �?m b?o �m lu?ng n?m trong kho?ng t? 0 d?n 1000
    if (volume < 0) {
        volume = 0;
    } else if (volume > 1000) {
        volume = 1000;
    }

    int volumeValue = volume;  // Kh�ng c?n nh�n l�n n?a
    char command[100];
    sprintf(command, "setaudio %s volume to %d", audioAlias, volumeValue);  // Thay d?i th�nh setaudio
    mciSendString(command, NULL, 0, NULL);
}
int selectedMap = 1; 
int  selectedLevel=1;
void displayMapSelection() {
	while (true) {
		cleardevice();
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);

		outtextxy(200, 200, (char*)"Select Map:");
		outtextxy(200, 300, (char*)"1. Map 1");
		outtextxy(200, 400, (char*)"2. Map 2");
		outtextxy(200, 500, (char*)"3. Back to Main Menu");

		char choice = getch();  // Nh?p l?a ch?n c?a ngu?i choi
		if (choice == '1') {
			selectedMap = 1;  // Ch?n b?n d? 1
			return;  // Quay l?i menu chC-nh
		} else if (choice == '2') {
			selectedMap = 2;  // Ch?n b?n d? 2
			return;  // Quay l?i menu chC-nh
		} else if (choice == '3') {
			return;  // Quay l?i menu chC-nh
		}
	}
}

void drawMaze() {
	int (*maze)[20];  // Con tr? t?i m?ng 2D 20x20
	if (selectedMap == 1) {
		maze = maze1;
	}
	else if (selectedMap == 2) {
		maze = maze2;
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (maze[i][j] == 1) {  // Tu?ng
				setfillstyle(SOLID_FILL,wallColor);
				bar(j * gridSize, i * gridSize, (j + 1) * gridSize, (i + 1) * gridSize);
			} else if (maze[i][j] == 0) {  // KhC4ng cC3 gC,
				setfillstyle(SOLID_FILL, BLACK);
				bar(j * gridSize, i * gridSize, (j + 1) * gridSize, (i + 1) * gridSize);
			} else if (maze[i][j] == 2) {  // Ci?m vC ng
				setfillstyle(SOLID_FILL, pointColor);
				fillellipse(j * gridSize + gridSize / 2, i * gridSize + gridSize / 2, 5, 5);
			}
		}
	}
}

struct Pacman {
	int x, y;
	int dx, dy; // Hu?ng di chuy?n hi?n t?i
	int color;
	int angleStart, angleEnd;
	int score;
    int lives;
	Pacman(int posX, int posY, int c) {
		x = posX;
		y = posY;
		dx = 0;
		dy = 0;
		color = c;
		angleStart = 30;
		angleEnd = 330;
		score = 0;
		lives=3;
	}

	void move() {
		x += dx * gridSize;
		y += dy * gridSize;
	}

	void draw() {
		setcolor(color);
		setfillstyle(SOLID_FILL, color);

		// Adjust the start and end angles based on movement direction
		if (dx == 1) { // Moving right
			angleStart = 35;
			angleEnd = 325;
		} else if (dx == -1) { // Moving left
			angleStart = 215;
			angleEnd = 145;
		} else if (dy == 1) { // Moving down
			angleEnd = 235;  // Rotated 90 degrees from right
			angleStart = 305;
		}
		 else if (dy == -1) { // Moving up
			angleEnd =55 ;   // Rotated -90 degrees from right
			angleStart =125 ;
		}

		// Draw Pacman using sector with adjusted angles
		sector(x + gridSize / 2, y + gridSize / 2, angleStart % 360, angleEnd % 360,
		       gridSize / 2 - 2, gridSize / 2 - 2);
	}

	void clear() {
		setfillstyle(SOLID_FILL, BLACK);
		bar(x, y, x + gridSize, y + gridSize);
	}

};
bool isWall(int x, int y) {
	int (*maze)[20];  // Con tr? t?i m?ng 2D 20x20

	// L?a ch?n b?n d? hi?n t?i d?a trC*n bi?n selectedMap
	if (selectedMap == 1) {
		maze = maze1;
	} else if (selectedMap == 2) {
		maze = maze2;
	}

	// Chuy?n d?i t?a d? pixel thC nh t?a d? trong m?ng (m?i C4 trong m?ng cC3 kC-ch thu?c gridSize)
	int gridX = x / gridSize;
	int gridY = y / gridSize;

	// Ki?m tra xem t?a d? cC3 n?m trong gi?i h?n c?a b?n d? khC4ng
	if (gridX >= 0 && gridX < 20 && gridY >= 0 && gridY < 20) {
		return maze[gridY][gridX] == 1;  // Tr? v? true n?u lC  tu?ng (giC! tr? 1)
	}
	return false;  // Tr? v? false n?u ngoC i gi?i h?n ho?c khC4ng ph?i lC  tu?ng
}
bool canMove(int x, int y, int dx, int dy) {
	int newX = x + dx * gridSize;
	int newY = y + dy * gridSize;
	return !isWall(newX, newY);
}
void eatPoint(Pacman &player) {  // Truy?n Pacman theo tham chi?u
	int (*maze)[20];  // Con tr? t?i m?ng 2D 20x20

	// L?a ch?n b?n d? hi?n t?i
	if (selectedMap == 1) {
		maze = maze1;
	}
	 else if (selectedMap == 2) {
		maze = maze2;
	}

	// TC-nh t?a d? trC*n m?ng 2D d?a trC*n v? trC- hi?n t?i c?a Pacman
	int gridX = player.x / gridSize;
	int gridY = player.y / gridSize;

	// Ki?m tra vC  an di?m theo mC u Pacman
	if (maze[gridY][gridX] == 2 ) {  //
		  mciSendString("open \"Eatpoint.mp3\" type mpegvideo alias myAudio", NULL, 0, NULL);
		maze[gridY][gridX] = 0;  // XC3a di?m vC ng
		player.score += 10;  // C?ng 10 di?m
	}

}
void teleportPacman(Pacman &player) {
    int (*maze)[20];  // Con tr? t?i m?ng 2D 20x20

    // L?a ch?n b?n d? hi?n t?i
    if (selectedMap == 1) {
        maze = maze1;
    } else if (selectedMap == 2) {
        maze = maze2;
    }

    // T�nh to�n t?a d? tr�n b?n d? d?a tr�n v? tr� c?a Pacman
    int gridX = player.x / gridSize;
    int gridY = player.y / gridSize;

    // Ki?m tra xem v? tr� hi?n t?i c� ph?i l� c?ng d?ch chuy?n kh�ng (gi� tr? 3)
    if (maze[gridY][gridX] == 3) {
        // N?u Pacman ch?m v�o c?ng d?ch chuy?n

        // Teleport theo h�ng
        // N?u di v�o c?ng d?ch chuy?n ? c?t d?u ti�n, di chuy?n d?n c?t cu?i c�ng c�ng h�ng
        if (gridX == 0) {
            player.x = (19 * gridSize);  // C?t 19 c�ng h�ng
        }
        // N?u di v�o c?ng d?ch chuy?n ? c?t cu?i c�ng, di chuy?n d?n c?t d?u ti�n c�ng h�ng
        else if (gridX == 19) {
            player.x = 0;  // C?t 0 c�ng h�ng
        }

        // Teleport theo c?t
        // N?u di v�o c?ng d?ch chuy?n ? h�ng d?u ti�n, di chuy?n d?n h�ng cu?i c�ng c�ng c?t
        else if (gridY == 0) {
            player.y = (19 * gridSize);  // H�ng 19 c�ng c?t
        }
        // N?u di v�o c?ng d?ch chuy?n ? h�ng cu?i c�ng, di chuy?n d?n h�ng d?u ti�n c�ng c?t
        else if (gridY == 19) {
            player.y = 0;  // H�ng 0 c�ng c?t
        }
    }
}
void updatePacman(Pacman &player) {
    if (canMove(player.x, player.y, player.dx, player.dy)) {
        player.move();  // C?p nh?t v? tr� m?i
        teleportPacman(player);  // Ki?m tra v� x? l� c?ng d?ch chuy?n n?u c�
    } else {
        // N?u kh�ng di chuy?n du?c, d?ng l?i
        player.dx = 0;
        player.dy = 0;
    }
}
struct Ghost {
    int x, y;
    int dx, dy;
    int color;
    int prevTile; 
    int targetX;
	int targetY;
	int chasing;
  int initialX, initialY;
     Ghost(int startX, int startY, int c, int chase) 
        : x(startX), y(startY), initialX(startX), initialY(startY), dx(0), dy(0), color(c), prevTile(0), targetX(0), targetY(0),chasing(chase) {
        setRandomDirection();
    }
    
    void setRandomDirection() {
        int direction = rand() % 4;
        dx = (direction == 0) ? 1 : (direction == 1) ? -1 : 0;
        dy = (direction == 2) ? 1 : (direction == 3) ? -1 : 0;
    }
   void teleport() {
        int (*maze)[20];  // Con tr? t?i m?ng 2D 20x20

        // L?a ch?n b?n d? hi?n t?i
        if (selectedMap == 1) {
            maze = maze1;
        } else if (selectedMap == 2) {
            maze = maze2;
        }

        // T�nh to�n t?a d? tr�n b?n d?
        int gridX = x / gridSize;
        int gridY = y / gridSize;

        // Ki?m tra xem v? tr� hi?n t?i c� ph?i l� c?ng d?ch chuy?n kh�ng
        if (maze[gridY][gridX] == 3) {
            int newX, newY;

            // T?o v? tr� ng?u nhi�n cho d?n khi t�m du?c m?t v? tr� h?p l?
            do {
                newX = rand() % 20;  // Ch?n c?t ng?u nhi�n t? 0 d?n 19
                newY = rand() % 20;  // Ch?n h�ng ng?u nhi�n t? 0 d?n 19
            } while (maze[newY][newX] == 1 || maze[newY][newX] == 3);  // �?m b?o kh�ng ch?n tu?ng ho?c c?ng d?ch chuy?n

            // C?p nh?t v? tr� c?a ghost
            x = newX * gridSize;
            y = newY * gridSize;
        }
    }
    
 void move() {
        if(	selectedLevel==1){
		if (canMove(x, y, dx, dy)) {
            x += dx * gridSize;
            y += dy * gridSize;
        } else {
             setRandomDirection(); }
        
        teleport();
        
		}
        
		else if(selectedLevel==2){
        for (int i = 0; i < 2; i++) {  // Di chuy?n t?i da 2 bu?c
            if (canMove(x, y,dx,dy)) {
                x += dx * gridSize;
                y += dy * gridSize;
            } else {
                setRandomDirection();  // �?i hu?ng n?u va ch?m
            }
            teleport();
		}}
       else if (selectedLevel == 3) {
            if (chasing == 1) {
                // �u?i theo ngu?i choi 1 (x1, y1)
                chasePlayer(x1, y1);
            } 
			else if (chasing == 2) {
                // �u?i theo ngu?i choi 2 (x2, y2)
                chasePlayer(x2, y2);
            } 
			else if(chasing==0) {
                if (canMove(x, y, dx, dy)) {
            x += dx * gridSize;
            y += dy * gridSize;
        } else {
             setRandomDirection(); }
        
        teleport();
            }
        }  
       
    }
void chasePlayer(int targetX, int targetY) {
    // �?u ti�n, t�nh to�n kho?ng c�ch gi?a Ghost v� Pacman
    int distX = targetX - x;
    int distY = targetY - y;

    // Di chuy?n theo hu?ng g?n nh?t, uu ti�n di chuy?n theo chi?u ngang n?u g?n hon
    if (abs(distX) > abs(distY)) {  
        // Di chuy?n sang tr�i ho?c ph?i
        if (canMove(x, y, (distX > 0) ? 1 : -1, 0)) {
            dx = (distX > 0) ? 1 : -1;
            dy = 0;  
        } else {
            // N?u kh�ng th? di chuy?n theo hu?ng ngang, th? theo chi?u d?c
            if (canMove(x, y, 0, (distY > 0) ? 1 : -1)) {
                dx = 0;
                dy = (distY > 0) ? 1 : -1;
            } else {
                // N?u c? hai hu?ng d?u kh�ng th?, ch?n hu?ng ng?u nhi�n
                setRandomDirection();
            }
        }
    } else {  
        // Di chuy?n l�n ho?c xu?ng
        if (canMove(x, y, 0, (distY > 0) ? 1 : -1)) {
            dx = 0;
            dy = (distY > 0) ? 1 : -1;
        } else {
            // N?u kh�ng th? di chuy?n theo hu?ng d?c, th? theo chi?u ngang
            if (canMove(x, y, (distX > 0) ? 1 : -1, 0)) {
                dx = (distX > 0) ? 1 : -1;
                dy = 0;  
            } else {
                // N?u c? hai hu?ng d?u kh�ng th?, ch?n hu?ng ng?u nhi�n
                setRandomDirection();
            }
        }
    }

    // C?p nh?t v? tr� n?u c� th? di chuy?n
    if (canMove(x, y, dx, dy)) {
        x += dx * gridSize;
        y += dy * gridSize;
    }
}
    void draw() {
        setfillstyle(SOLID_FILL, color);
        fillellipse(x + gridSize / 2, y + gridSize / 2, gridSize / 2 - 2, gridSize / 2 - 2);
    }

    void clear() {
    	int (*maze)[20];  // Con tr? t?i m?ng 2D 20x20

	// L?a ch?n b?n d? hi?n t?i d?a trC*n bi?n selectedMap
	if (selectedMap == 1) {
		maze = maze1;
	} else if (selectedMap == 2) {
		maze = maze2;
	}
    // Ki?m tra gi� tr? c?a � hi?n t?i trong m?ng maze
    if (maze[y / gridSize][x / gridSize] == 2) {
        // N?u � l� di?m, h�y v? l?i n�
    int gridX = x / gridSize;
    int gridY = y / gridSize;

        // X�a � hi?n t?i
        setfillstyle(SOLID_FILL, BLACK);
        bar(x, y, x + gridSize, y + gridSize);

        // V? l?i di?m
        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(gridY * gridSize + gridSize / 2, gridX * gridSize + gridSize / 2, 5, 5);
    } else {
        // N?u � kh�ng ph?i l� di?m, ch? c?n x�a
        setfillstyle(SOLID_FILL, BLACK);
        bar(x, y, x + gridSize, y + gridSize);
    }
}
};

void updateGhost(Ghost &ghost) {
    ghost.move();
}

void handleCollision(Pacman &player, vector<Ghost> &ghosts) {
    for (size_t i = 0; i < ghosts.size(); ++i) {
        Ghost& ghost = ghosts[i];  // Thay d?i t? const sang kh�ng const
        if (player.x == ghost.x && player.y == ghost.y) {
            if (player.lives > 0) {
                  mciSendString("open \"Ghost.mp3\" type mpegvideo alias myAudio", NULL, 0, NULL);
				player.lives--;  // Tr? m?ng
                // �?t l?i v? tr� Pacman sau va ch?m
               

                // �?t l?i t?t c? ma v? v? tr� kh?i d?u
                ghost.x = 10 * gridSize; // V? tr� kh?i d?u c?a ma (c� th? thay d?i theo y�u c?u)
                ghost.y = (i + 2) * gridSize; // V� d?: �?t l?i v? tr� kh�c nhau cho t?ng ma

                break;  // Tho�t v�ng l?p sau khi x? l� va ch?m

                break;  // Tho�t v�ng l?p sau khi x? l� va ch?m
            }
        }
    }
}
void displayLives(Pacman &player1, Pacman &player2) {
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    char livesText1[50], livesText2[50];
    sprintf(livesText1, "Lives: %d", player1.lives);
    sprintf(livesText2, "Lives: %d", player2.lives);
    outtextxy(10, 10, livesText1);   // Hi?n th? s? m?ng c?a ngu?i choi 1
    outtextxy(100, 10, livesText2);  // Hi?n th? s? m?ng c?a ngu?i choi 2
}
void displayLevelselection() {
    while (true) {
        cleardevice();
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
        outtextxy(200, 200, (char*)"Select Level:");
        outtextxy(200, 300, (char*)"1. Normal");
        outtextxy(200, 400, (char*)"2. Medium");
         outtextxy(200, 500, (char*)"3. Hard"); 
        outtextxy(200, 600, (char*)"4. Back to Main Menu"); // Th�m d?u ch?m ph?y ? d�y

        char choice = getch();  // Nh?p l?a ch?n c?a ngu?i choi

        if (choice == '1') {
            selectedLevel = 1;  // Ch?n b?n d? 1
            return;  // Quay l?i menu ch�nh
        } else if (choice == '2') {
            selectedLevel = 2;  // Ch?n b?n d? 2
            return;  // Quay l?i menu ch�nh
        } 
         else if (choice == '3') {
             selectedLevel = 3; // Ch?n b?n d? 3 n?u c?n
           return;
	     }
        else if (choice == '4') {
            return;  // Quay l?i menu ch�nh
        }
    }
}
void stopAudio() {
    mciSendString("close myAudio", NULL, 0, NULL); // D?ng v� d�ng nh?c dang ph�t
}
void adjustVolume() { 
    while (true) { 
        cleardevice(); 
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);

        // C?t 1
        outtextxy(400, 200, (char*)"Adjust Volume:");
        outtextxy(400, 300, (char*)"1. Menu Volume"); 
        outtextxy(400, 400, (char*)"2. Ingame Volume "); 
        outtextxy(400, 500, (char*)"3. Back to menu"); 

        char choice = getch();

        if (choice >= '1' && choice <= '2') { 
            // Hi?n th? �m lu?ng hi?n t?i
            outtextxy(400, 550, (char*)"Enter new volume (0-1000):");

            char volumeInput[6] = ""; // D�ng 6 d? ch?a t?i da 5 k� t? + null terminator
            int index = 0;

            while (true) {
                char ch = getch(); // Nh?n t?ng k� t? nh?p
                if (ch == '\r') break; // D?ng nh?p khi nh?n Enter
                if (ch == '\b') { // H? tr? x�a k� t?
                    if (index > 0) {
                        index--; 
                        volumeInput[index] = '\0'; // X�a k� t? cu?i c�ng
                        // Hi?n th? �m lu?ng dang nh?p
                        outtextxy(400, 750, volumeInput); 
                    }
                } else if (isdigit(ch) && index < 5) { // Ch?p nh?n k� t? s?, t?i da 5 k� t?
                    volumeInput[index++] = ch;
                    volumeInput[index] = '\0'; // K?t th�c chu?i
                    outtextxy(400, 750, volumeInput); // Hi?n th? �m lu?ng dang nh?p
                }
            }

            int newVolume = atoi(volumeInput); 
            newVolume = (newVolume < 0) ? 0 : (newVolume > 1000 ? 1000 : newVolume); // Gi?i h?n t? 0 d?n 1000

            switch (choice) { 
                case '1': 
                    MenuVolume = newVolume; 
                    setVolume(MenuVolume, "music1"); 
                    break; 
                case '2': 
                    IngameVolume = newVolume; 
                    setVolume(IngameVolume, "music2"); 
                    break;             
            } 

            // Hi?n th? l?i c�c th�ng tin giao di?n
            cleardevice(); 
            settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
            outtextxy(400, 200, (char*)"Adjust Volume:");
            outtextxy(400, 300, (char*)"1. Menu Volume"); 
            outtextxy(400, 400, (char*)"2. Ingame Volume"); 
            
            // Hi?n th? �m lu?ng hi?n t?i sau khi di?u ch?nh
            char currentVolume[10]; // Tang k�ch thu?c d? ch?a gi� tr? d?n 1000
            sprintf(currentVolume, "%d", newVolume);
            outtextxy(400, 550, currentVolume); // Hi?n th? �m lu?ng d� di?u ch?nh

        } else if (choice == '3') { 
            return; // Quay l?i menu ch�nh 
        } 
    } 
}
int getColorSelection() {
    while (true) {
        cleardevice();
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
        outtextxy(600, 200, (char*)"Select a Color:");

        // Hi?n th? c�c t�y ch?n m�u theo h�ng ngang
        outtextxy(100, 300, (char*)"1. YELLOW  ");
        outtextxy(100, 300 + 50, (char*)"2. GREEN   ");
        outtextxy(100, 300 + 100, (char*)"3. BLUE    ");
        outtextxy(100, 300 + 150, (char*)"4. RED     ");
        outtextxy(100, 300 + 200, (char*)"5. WHITE   ");
        outtextxy(100, 300 + 250, (char*)"6. CYAN    ");
        outtextxy(100, 300 + 300, (char*)"7. MAGENTA ");
        outtextxy(100, 300 + 350, (char*)"8. LIGHTGRAY "); // Thay ORANGE b?ng LIGHTGRAY
        outtextxy(100, 300 + 400, (char*)"9. BACK    ");

        char choice = getch();  // Nh?p l?a ch?n c?a ngu?i choi

        switch (choice) {
            case '1':
                return YELLOW;  // Tr? v? m�u v�ng
            case '2':
                return GREEN;   // Tr? v? m�u xanh l�
            case '3':
                return BLUE;    // Tr? v? m�u xanh duong
            case '4':
                return RED;     // Tr? v? m�u d?
            case '5':
                return WHITE;   // Tr? v? m�u tr?ng
            case '6':
                return CYAN;    // Tr? v? m�u xanh lam nh?t
            case '7':
                return MAGENTA; // Tr? v? m�u t�m
            case '8':
                return LIGHTGRAY; // Tr? v? m�u x�m s�ng
            case '9':
                return -1;      // Quay l?i menu tru?c
            default:
                break; // N?u kh�ng h?p l?, quay l?i v�ng l?p
        }
    }
}
void changecolor() {
    while (true) {
        cleardevice();
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
        outtextxy(600, 200, (char*)"Select Colors:");

        outtextxy(600, 300, (char*)"1. Point Color");
        outtextxy(600, 400, (char*)"2. Wall Color");
        outtextxy(600, 500, (char*)"3. Pacman 1 Color");
        outtextxy(600, 600, (char*)"4. Pacman 2 Color");
        outtextxy(600, 700, (char*)"5. Back to Main Menu");

        char choice = getch();  // Nh?p l?a ch?n c?a ngu?i choi

        if (choice == '1') {
            pointColor = getColorSelection();  // H�m ch?n m�u cho di?m
        } else if (choice == '2') {
            wallColor = getColorSelection();  // H�m ch?n m�u cho tu?ng
        } else if (choice == '3') {
            pacman1Color = getColorSelection();  // H�m ch?n m�u cho Pacman 1
        } else if (choice == '4') {
            pacman2Color = getColorSelection();  // H�m ch?n m�u cho Pacman 2
        } else if (choice == '5') {
            return;  // Quay l?i menu ch?nh
        }
    }
}
void stopAllMusic() {
    // D?ng �m thanh menu
    mciSendString("stop music1", NULL, 0, NULL);
    mciSendString("close music1", NULL, 0, NULL);

    // D?ng �m thanh trong tr� choi
    mciSendString("stop music2", NULL, 0, NULL);
    mciSendString("close music2", NULL, 0, NULL);
}void displayHelp() {
	cleardevice();
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
	outtextxy(100, 100, (char*)"Instructions:");  // Cast to (char*)
	outtextxy(100, 150, (char*)"Player 1: Arrow keys to move.");
	outtextxy(100, 200, (char*)"Player 2: W, A, S, D keys to move.");
	outtextxy(100, 250, (char*)"Collect all the points to win!");
	outtextxy(100, 350, (char*)"Press any key to return to the menu...");
	getch();  // Wait for user to press any key before returning
	cleardevice();
}


void displayMenu() {
	  mciSendString("open \"Menu.mp3\" type mpegvideo alias music1", NULL, 0, NULL);
	  mciSendString("play music1 repeat", NULL, 0, NULL);
      setVolume(MenuVolume, "music1");
	while (true) {
		cleardevice();
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);

		outtextxy(200, 200, (char*)"1. Start Game");
		outtextxy(200, 300, (char*)"2. Select Map");
		outtextxy(200, 400, (char*)"3. Select Level");
		outtextxy(200, 500, (char*)"4. Color");
		outtextxy(200, 600, (char*)"5. Music");
		outtextxy(200, 700, (char*)"6. Help");
		outtextxy(200, 800, (char*)"7. Exit");

		char choice = getch();  // Wait for user input
	
		if (choice == '1') {
stopAllMusic();
PlaySound(NULL, 0, 0);
			cleardevice();  // Start the game by clearing the screen
			return;  // Exit menu loop and start the game
		} else if (choice == '2') {
		
			displayMapSelection();  // Chuy?n t?i menu ch?n b?n d?
		} else if(choice=='3'){
			displayLevelselection();
		}
		else if (choice == '4') {
		changecolor();
		}
		else if (choice == '5') {
		adjustVolume();
		}
		else if (choice == '6') {
		  displayHelp();  // Show the help screen
		} else if (choice == '7') {
			exit(0);  // Exit the game
		}
	}
	 
}

void displayGameOver() {
      PlaySound(NULL, NULL, SND_PURGE);
    stopAllMusic();
   cleardevice();
  PlaySound(TEXT("Defeat.wav"), NULL, SND_FILENAME | SND_ASYNC);
    settextstyle(3, 0, 6);
    outtextxy(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 50, "GAME OVER");
    getch(); // �?i ngu?i choi nh?n ph�m
}
void checkWinCondition() {
   
   int (*maze)[20];  // Con tr? t?i m?ng 2D 20x20
	if (selectedMap == 1) {
		maze = maze1;
	}
	else if (selectedMap == 2) {
		maze = maze2;
	}
    if (selectedMap == 1) {
        maze = maze1;
    } else if (selectedMap == 2) {
        maze = maze2;
    }

    // Ki?m tra xem c?n �i?m n�o kh�ng
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (maze[i][j] == 2) {
                return;  // C?n �i?m -> ch�a th?ng
            }
        }
    }


    PlaySound(NULL, NULL, SND_PURGE);
    stopAllMusic();
    cleardevice();
    settextstyle(3, 0, 6);
    PlaySound(TEXT("Victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
    outtextxy(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 50, "VICTORY");
   getch();
}

void drawPacman(int x, int y, int radius) {
    setcolor(YELLOW);  // �?t m�u vi?n
    setfillstyle(SOLID_FILL, YELLOW);  // �?t m�u n?n

    // Pac-Man quay mi?ng sang ph?i (G�c t? 30 d?n 330 d?)
    pieslice(x, y, 30, 330, radius);  
}

// H�m v? thanh loading ngang qua Pac-Man
void drawLoadingBar() {
    int screenWidth = getmaxx(); // L?y chi?u r?ng m�n h�nh
    int x_start = (screenWidth - 400) / 2; // Can gi?a thanh loading (chi?u r?ng 400px)
    int y = 650; // V? tr� theo tr?c Y

    setcolor(WHITE); // M�u vi?n thanh loading
    rectangle(x_start, y, x_start + 400, y + 20); // V? khung ngo�i thanh loading

    for (int i = 0; i <= 400; i++) { 
        setfillstyle(SOLID_FILL, YELLOW); // M�u v�ng cho thanh
        bar(x_start, y, x_start + i, y + 20); // V? ph?n thanh d� t?i

        delay(100); // Gi?m th?i gian tr? d? mu?t hon
    }
} 
void showTitleWithEffect(const char* title, int x, int y, int delayTime) {
    
    settextstyle(TRIPLEX_FONT, 0, 6); 

    // T?o b�ng ch? b?ng c�ch v? ch? ? v? tr� l?ch m?t ch�t
    setcolor(DARKGRAY);
    outtextxy(x + 2, y + 2, (char*)title); 
 setcolor(CYAN);
     

    char buffer[100] = "";  

    for (int i = 0; i < strlen(title); ++i) {
        buffer[i] = title[i];   
        buffer[i + 1] = '\0';  

        outtextxy(x, y, buffer); 
        delay(delayTime);        
    }
}

void drawTitle() {
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);  // �?t ki?u v� k�ch thu?c ph�ng Gothic
    setcolor(CYAN);  // M�u ch? d?

    // V? ch? PACMAN ? v? tr� gi?a m�n h�nh, ph�a tr�n c�ng
    int screenWidth = getmaxx();
    outtextxy((screenWidth - textwidth("P A C M A N")) / 2, 50, (char*)"P A C M A N");
}

int main() {
	initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pacman Maze");
	/*showTitleWithEffect("Nguyen Hoang Hai",425, 350, 100);
	mciSendString("open \"loading.mp3\" type mpegvideo alias myMusic", NULL, 0, NULL);
	mciSendString("play myMusic", NULL, 0, NULL);
	cleardevice();
	drawTitle();
	drawPacman(765,350,150);
	drawLoadingBar();
	stopAllMusic();
	PlaySound(NULL, 0, 0);*/
	
	cleardevice();
	
	displayMenu();

	drawMaze();
	Pacman player1(1 * gridSize, 1 * gridSize, pacman1Color);
    Pacman player2(18 * gridSize, 18 * gridSize, pacman2Color);
	vector<Ghost> ghosts;
	ghosts.push_back(Ghost(10 * gridSize, 2 * gridSize, RED,1));
	ghosts.push_back(Ghost(10 * gridSize, 5 * gridSize, RED,0));
	ghosts.push_back(Ghost(10 * gridSize, 6 * gridSize, RED,2));
	ghosts.push_back(Ghost(10 * gridSize, 8 * gridSize, RED,0));
 
	while (true) {
	 mciSendString("open \"Ingame.mp3\" type mpegvideo alias music2", NULL, 0, NULL);
        mciSendString("play music2 repeat", NULL, 0, NULL);
        setVolume(IngameVolume, "music2"); // �?m b?o r?ng �m lu?ng trong tr� choi du?c thi?t l?p


		x1=player1.x;
		x2=player2.x;
		y2=player2.y;
		y1=player1.y;
		player1.clear();
		player2.clear();
		for (size_t i = 0; i < ghosts.size(); ++i) {
			ghosts[i].clear();
		}
		// Ki?m t
		if (player1.lives > 0) {
			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				player1.dx = 0;
				player1.dy = -1;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				player1.dx = 0;
				player1.dy = 1;
			}
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
				player1.dx = -1;
				player1.dy = 0;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
				player1.dx = 1;
				player1.dy = 0;
			}
		}

		//n?u player2 c?n m?ng th? cho ph?p di chuy?n
		if (player2.lives > 0) {
			if (GetAsyncKeyState(0x57) & 0x8000) {
				player2.dx = 0;    // W
				player2.dy = -1;
			}
			if (GetAsyncKeyState(0x53) & 0x8000) {
				player2.dx = 0;    // S
				player2.dy = 1;
			}
			if (GetAsyncKeyState(0x41) & 0x8000) {
				player2.dx = -1;    // A
				player2.dy = 0;
			}
			if (GetAsyncKeyState(0x44) & 0x8000) {
				player2.dx = 1;    // D
				player2.dy = 0;
			}
		}

		displayLives(player1, player2);

		if (player1.lives > 0) updatePacman(player1);
		if (player2.lives > 0) updatePacman(player2);

		handleCollision(player1, ghosts);    // Player 1 v? t?a d? (1,1)
		handleCollision(player2, ghosts);

		// Ki?m tra n?u Pacman an di?m
		eatPoint(player1);
		eatPoint(player2);
		for (size_t i = 0; i < ghosts.size(); ++i) {
			ghosts[i].move();
		}
		// V? Pacman ? v? trC- m?i
		if (player1.lives > 0) 	player1.draw();
		if (player2.lives > 0) 	player2.draw();
		for (size_t i = 0; i < ghosts.size(); ++i) {
			ghosts[i].draw();
		}
		delay(100);

      
            if (player1.lives <= 0 && player2.lives <= 0) {
                displayGameOver();
               
            }
            checkWinCondition();
        
        
     if (GetAsyncKeyState(VK_F1) & 0x8000) {
    stopAllMusic();
	PlaySound(NULL, 0, 0);
    cleardevice();
    displayMenu(); // Hi?n th? menu
    drawMaze();// Ch?y l?i v�ng l?p tr� choi
    } // Tho�t v�ng l?p d? quay l?i menu
    }
	getch();
	closegraph();
	return 0;
}              
		 

