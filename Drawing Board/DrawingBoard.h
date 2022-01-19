#pragma once
#include "Brush.h"
class DrawingBoard
{
public:
	DrawingBoard();
	void Run();
	void CreateLine();
	void DrawLines();
	void Capture(string filename);
private:
	RenderWindow* window;
	Brush brush;
	vector<RectangleShape> lines;
};

