#include "Cell.h"

Cell::Cell(Location loc)
	:
	loc(loc)
{}

void Cell::Draw(Graphics &gfx){
	gfx.DrawSquareWithPadding(loc.x*10, loc.y*10, 10, 10, Colors::Green);
}

void Cell::SetLoc(Location &src)
{
	loc = src;
}

Location Cell::GetLoc(){
	return loc;
}
