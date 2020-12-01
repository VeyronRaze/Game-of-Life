#pragma once
#include "Graphics.h"
#include "Location.h"

class Cell{
public:
	Cell(Location loc);
	void Tick();
	void Draw(Graphics &gfx);
	void SetLoc(Location &src);
	Location GetLoc();
private:
	Location loc;
};

