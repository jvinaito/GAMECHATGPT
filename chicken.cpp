#include <graphics.h>
#include <conio.h>

void drawDuck() {
    // Body of the duck
    setcolor(BLACK); // Black outline for the body
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(300, 300, 100, 60); // Ellipse for the body
    ellipse(300, 300, 0, 360, 100, 60); // Outline for the body

    // Head of the duck
    setcolor(BLACK); // Black outline for the head
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(400, 220, 60, 60); // Circle for the head
    ellipse(400, 220, 0, 360, 60, 60); // Outline for the head

    // Eye of the duck
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(420, 210, 10, 10); // Eye

    // Beak of the duck
    setcolor(BLACK); // Black outline for the beak
    setfillstyle(SOLID_FILL, RED);
    ellipse(450, 230, 0, 180, 30, 20); // Upper part of the beak
    fillellipse(450, 230, 30, 20); // Fill the beak
    ellipse(450, 230, 0, 180, 30, 20); // Outline for the beak

    // Wing of the duck (Arc facing downwards)
    setcolor(BLACK);
    arc(320, 300, 180, 360, 40); // Arc for the wing facing downwards

    // Legs of the duck
    line(270, 350, 270, 400); // First leg
    line(330, 350, 330, 400); // Second leg

    // Claws for the first leg
    line(270, 400, 260, 420); // First claw
    line(270, 400, 270, 420); // Second claw
    line(270, 400, 280, 420); // Third claw

    // Claws for the second leg
    line(330, 400, 320, 420); // First claw
    line(330, 400, 330, 420); // Second claw
    line(330, 400, 340, 420); // Third claw
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setbkcolor(WHITE); // Set background color to white
    cleardevice(); // Clear the screen
    drawDuck(); // Draw the duck
    getch(); // Wait for user to press a key
    closegraph(); // Close the graphics mode
    return 0;
}


