#include "../headers/Canvas.hpp"
#include "../headers/Struct.hpp"

bool diamonRule(PointerPosition pos, CanvasSize size)
{
	int axis = 1;
	int increasingVerticalParam = pos.y <= size.height / 2 ? pos.y : size.height - 1 - pos.y;
	int shapeSize = axis + (increasingVerticalParam * 2);
	int emptySize = size.width - shapeSize;
	Area shapeArea{
		emptySize / 2 - 1, // -1 due to pos start from 0
		shapeSize + emptySize / 2,
	};
	return (pos.x > shapeArea.start && pos.x < shapeArea.end);
}