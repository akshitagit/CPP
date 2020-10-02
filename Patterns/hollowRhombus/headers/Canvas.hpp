#ifndef CANVAS_H
#define CANVAS_H

#include <string>
#include "Struct.hpp"

using std::string;

class Canvas
{
private:
	CanvasSize conSize;
	Pixel block;

protected:
	void calcContentSize();
	bool isInContent(PointerPosition);
	string addFrame(PointerPosition);
	string addShape(PointerPosition);
	string addBlock(char);
	string addBlock(char, char);

public:
	CanvasSize size;

	Canvas(CanvasSize, Pixel);
	void draw();
	std::string generate();
};

#endif