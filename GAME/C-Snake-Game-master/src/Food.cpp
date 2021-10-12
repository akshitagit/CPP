#include "Food.h"

void Food::gen_food()
{
    pos.X = (rand() % WIDTH - 3) + 1;
    pos.Y = (rand() % HEIGHT - 3) + 1;
}

COORD Food::get_pos() { return pos; }
