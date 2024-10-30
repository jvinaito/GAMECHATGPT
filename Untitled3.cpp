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

const int SCREEN_WIDTH = 1680;
const int SCREEN_HEIGHT = 885;
const int gridSize = 30;
int x1=0;
int y1=0;
int x2=0;
int y2=0;
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
				setfillstyle(SOLID_FILL, BLUE);
				bar(j * gridSize, i * gridSize, (j + 1) * gridSize, (i + 1) * gridSize);
			} else if (maze[i][j] == 0) {  // KhC4ng cC3 gC,
				setfillstyle(SOLID_FILL, BLACK);
				bar(j * gridSize, i * gridSize, (j + 1) * gridSize, (i + 1) * gridSize);
			} else if (maze[i][j] == 2) {  // Ci?m vC ng
				setfillstyle(SOLID_FILL, YELLOW);
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
                 playsound
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


void displayHelp() {
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
void displayMenu() {
	   mciSendString("open \"Menu.mp3\" type mpegvideo alias myAudio", NULL, 0, NULL);
	      mciSendString("play myAudio repeat", NULL, 0, NULL);
	while (true) {
		cleardevice();
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);

		outtextxy(200, 200, (char*)"1. Start Game");
		outtextxy(200, 300, (char*)"2. Select Map");
		outtextxy(200, 400, (char*)"3. Select Level");
		outtextxy(200, 500, (char*)"4. Help");
		outtextxy(200, 600, (char*)"5. Exit");

		char choice = getch();  // Wait for user input
	
		if (choice == '1') {
			   stopAudio();
			cleardevice();  // Start the game by clearing the screen
			return;  // Exit menu loop and start the game
		} else if (choice == '2') {
		
			displayMapSelection();  // Chuy?n t?i menu ch?n b?n d?
		} else if(choice=='3'){
			displayLevelselection();
		}
		else if (choice == '4') {
			displayHelp();  // Show the help screen
		} else if (choice == '5') {
			exit(0);  // Exit the game
		}
	}
	 PlaySound(NULL, 0, 0);
}

void displayGameOver() {
     stopAudio();
	cleardevice();
   mciSendString("open \"Defeat.mp3\" type mpegvideo alias myAudio", NULL, 0, NULL);
    settextstyle(3, 0, 6);
    delay(2000);
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
	// Ki?m tra xem c�n di?m n�o b?ng 2 kh�ng
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (maze[i][j] == 2) {
                return; // N?u c�n di?m, kh�ng th?ng
            }
        }
    }
    cleardevice(); // X�a m�n h�nh
    settextstyle(3, 0, 6); // Thi?t l?p ki?u ch?
      
    stopAudio();  // D?ng nh?c cu
    mciSendString("open \"Victory.mp3\" type mpegvideo alias myAudio", NULL, 0, NULL);
    mciSendString("play myAudio", NULL, 0, NULL);  // Ph�t nh?c chi?n th?ng
    delay(1500);
    outtextxy(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 50, "VICTORY"); // Hi?n th? th�ng b�o
    getch(); // �?i ngu?i choi nh?n ph�m
}
void drawLargePacman(int x,int y) {
    int size = 100;  // Tang k�ch thu?c Pacman (to hon)
    int angleStart = 35;
    int angleEnd = 325;

    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);

    // V? Pacman l?n hon
    sector(x, y, angleStart % 360, angleEnd % 360, size, size);
}
void loading(){
	drawLargePacman(300,250);
	rectangle(310,330,390,340);

setcolor(CYAN);

for(int i=0;i<=76;i++){

rectangle(310+i,332,310+i,338);

delay(100);
}
cleardevice();
	
}
int main() {
     int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
   loading();
	initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pacman Maze");
	displayMenu();
	// V? mC* cung
	drawMaze();
	Pacman player1(1 * gridSize, 1 * gridSize, YELLOW);// Starting at (1,1)
	Pacman player2(18 * gridSize, 18 * gridSize, GREEN); // Starting at (18,18)
      vector<Ghost> ghosts;
    ghosts.push_back(Ghost(10 * gridSize, 2 * gridSize, RED,1));
    ghosts.push_back(Ghost(10 * gridSize, 5 * gridSize, RED,0));
    ghosts.push_back(Ghost(10 * gridSize, 6 * gridSize, RED,2));
    ghosts.push_back(Ghost(10 * gridSize, 8 * gridSize, RED,0));
	  mciSendString("open \"Ingame.mp3\" type mpegvideo alias myAudio", NULL, 0, NULL);
	      mciSendString("play myAudio repeat", NULL, 0, NULL);
while (true) {
		 
	x1=player1.x;
	x2=player2.x;
	y2=player2.y;
	y1=player1.y;
	   if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cleardevice();   // XC3a mC n hC,nh trC2 choi
		drawMaze();
	Pacman player1(1 * gridSize, 1 * gridSize, YELLOW);  // Starting at (1,1)
	Pacman player2(18 * gridSize, 18 * gridSize, GREEN); // Starting at (18,18)
      vector<Ghost> ghosts;
    ghosts.push_back(Ghost(10 * gridSize, 2 * gridSize, RED,1));
    ghosts.push_back(Ghost(10 * gridSize, 5 * gridSize, RED,0));
    ghosts.push_back(Ghost(10 * gridSize, 6 * gridSize, RED,2));
    ghosts.push_back(Ghost(10 * gridSize, 8 * gridSize, RED,0));     // V? l?i mC* cung sau khi quay l?i trC2 choi
		}
		if (GetAsyncKeyState(VK_F1) & 0x8000) {
    cleardevice();   // X�a m�n h�nh
    displayMenu();   // Quay l?i menu ch�nh
    drawMaze();      // V? l?i m� cung sau khi quay l?i tr� choi
}
	    player1.clear();
	    player2.clear();
        for (size_t i = 0; i < ghosts.size(); ++i) {
            ghosts[i].clear();
        }
		// Ki?m t
         if (player1.lives > 0) {
            if (GetAsyncKeyState(VK_UP) & 0x8000) { player1.dx = 0; player1.dy = -1; }
            if (GetAsyncKeyState(VK_DOWN) & 0x8000) { player1.dx = 0; player1.dy = 1; }
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) { player1.dx = -1; player1.dy = 0; }
            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { player1.dx = 1; player1.dy = 0; }
        }
		
		 //n?u player2 c�n m?ng th� cho ph�p di chuy?n
        if (player2.lives > 0) {
            if (GetAsyncKeyState(0x57) & 0x8000) { player2.dx = 0; player2.dy = -1; } // W
            if (GetAsyncKeyState(0x53) & 0x8000) { player2.dx = 0; player2.dy = 1; }  // S
            if (GetAsyncKeyState(0x41) & 0x8000) { player2.dx = -1; player2.dy = 0; } // A
            if (GetAsyncKeyState(0x44) & 0x8000) { player2.dx = 1; player2.dy = 0; }  // D
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
         
}

	getch();
	closegraph();
	return 0;}
