#ifndef STRUCT_H
#define STRUCT_H

struct PointerPosition
{
	int x;
	int y;
};

struct Area
{
	int start;
	int end;
};

struct Range
{
	int min;
	int max;
};

struct CanvasSize
{
	int width;
	int height;
};

struct Pixel
{
	char solid;
	char hollow;
};

#endif