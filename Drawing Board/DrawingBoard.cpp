#include "DrawingBoard.h"

// Checks if current mouse position is in window borders
#define CheckBorders(worldPos) (worldPos.x > 0 && worldPos.x < WIDTH && worldPos.y > 0 && worldPos.y < HEIGHT)

DrawingBoard::DrawingBoard()
{
    window = new RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    window->setFramerateLimit(200);
}

//---------------------------------------------------------------
//                              Run
//                              ---
// 
// Responsible on the whole program.
// Checks for mouse presses and releases, keyboard input for
// clearing the screen and draws the lines.
//---------------------------------------------------------------
void DrawingBoard::Run()
{
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();
            else if (event.type == Event::MouseButtonReleased)
                brush.ResetPositions();
        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
            lines.clear();
        Vector2i pixelPos = sf::Mouse::getPosition(*window);
        Vector2f worldPos = window->mapPixelToCoords(pixelPos); // Current position of mouse in our window

        if (Mouse::isButtonPressed(Mouse::Left) &&
            (brush.curPos.x == NULL || brush.curPos.y == NULL) &&
            CheckBorders(worldPos))
        {
            brush.curPos.x = worldPos.x;
            brush.curPos.y = worldPos.y;
        }
        else if (Mouse::isButtonPressed(Mouse::Left) &&
            (worldPos.x != brush.curPos.x || worldPos.y != brush.curPos.y) &&
            CheckBorders(worldPos))
        {
            brush.NewPosition(worldPos);
            CreateLine();
        }

        window->clear(Color::White);
        DrawLines();
        window->display();
    }
}

//---------------------------------------------------------------
//                          Create Line
//                          -----------
// 
// Calculates the length and angle between the previous position
// and the current position and creates a rectangle between the
// two points.
//---------------------------------------------------------------
void DrawingBoard::CreateLine()
{
    float length = brush.CalculateLength() + 4;
    float angle = brush.CalculateAngle();
    RectangleShape newLine;
    newLine.setOrigin(Vector2f(0, THICKNESS / 2));
    newLine.setRotation(angle);
    newLine.setFillColor(Color::Black);
    newLine.setPosition(brush.prevPos);
    newLine.setSize(Vector2f(THICKNESS, length));
    lines.push_back(newLine);
}

//---------------------------------------------------------------
//                           Draw Line
//                           ---------
// 
// Draws all the lines in the 'lines' vector.
//---------------------------------------------------------------
void DrawingBoard::DrawLines()
{
    for (int i = 0; i < lines.size(); i++)
        window->draw(lines[i]);

}
