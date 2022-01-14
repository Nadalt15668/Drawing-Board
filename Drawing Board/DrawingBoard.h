#pragma once
#include "Brush.h"
class DrawingBoard
{
public:
	DrawingBoard();
	void Run();
	void CreateLine();
	void DrawLines();
private:
	RenderWindow* window;
	Brush brush;
	vector<RectangleShape> lines;
};

