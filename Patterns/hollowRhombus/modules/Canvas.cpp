#include <iostream>
#include <string>
#include <cstring>

#include "../headers/Canvas.hpp"

using std::cout;
using std::strcat;
using std::string;

bool diamonRule(PointerPosition, CanvasSize);

Canvas::Canvas(CanvasSize size, Pixel pixelType)
{
	this->size = size;
	this->block = pixelType;
	this->calcContentSize();
}

void Canvas::calcContentSize()
{
	this->conSize = {
		this->size.width - 2,
		this->size.height - 2,
	};
}

void Canvas::draw()
{
	string lines = this->generate();
	std::cout << lines << std::endl;
}

string Canvas::generate()
{
	string canvas = "\n";
	for (int y = 0; y < this->size.height; y++)
		for (int x = 0; x < this->size.width; x++)
		{
			bool isInContent = this->isInContent({x, y});
			canvas += isInContent ? this->addShape({x - 1, y - 1}) : this->addFrame({x, y});
		}
	return canvas;
}

bool Canvas::isInContent(PointerPosition p)
{
	bool top = p.y >= 1;
	bool left = p.x >= 1;
	bool right = p.x <= this->conSize.width;
	bool bottom = p.y <= this->conSize.height;
	return left && right && top && bottom;
}

string Canvas::addFrame(PointerPosition p)
{
	bool isTop = p.y == 0;
	bool isRight = p.x == 0;
	bool isBottom = p.y + 1 == this->size.height;
	bool isLeft = p.x + 1 == this->size.width;

	if (isTop && isLeft || isLeft)
		return this->addBlock(this->block.solid, '\n');
	else if (isTop || isRight || isBottom)
		return this->addBlock(this->block.solid);

	return "";
}

string Canvas::addShape(PointerPosition conPos)
{
	bool isInDiamonShape = diamonRule(conPos, this->conSize);
	if (isInDiamonShape)
		return this->addBlock(this->block.hollow);
	return this->addBlock(this->block.solid);
}

string Canvas::addBlock(char block)
{
	return this->addBlock(block, ' ');
}

string Canvas::addBlock(char block, char padding)
{
	return string(1, block) + string(1, padding);
}