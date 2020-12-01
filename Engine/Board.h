#pragma once

#include "Location.h"
#include "Graphics.h"

class Board{
public:
	Board();
	void Draw(Graphics &gfx);
	void InitSpawn();
	void DeleteCell();
	void Update();
private:
	class Cell{
	public:
		Cell() = default;
		Cell(Location loc);
		void Draw(Graphics &gfx);
		void SetLoc(Location &src);
		Cell& operator =(Cell &src);
		Location GetLoc();
		void Toggle();
		bool isAlive();
	private:
		Location loc = {-2, -2};
		bool alive = false;
	};
private:
	static constexpr int cellSize = 10;
	Cell board[Graphics::ScreenHeight / cellSize][Graphics::ScreenWidth / cellSize];
};

