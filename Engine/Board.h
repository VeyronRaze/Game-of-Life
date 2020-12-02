#pragma once

#include "Location.h"
#include "Graphics.h"

class Board{
private:
	class Cell{
	public:
		Cell() = default;
		Cell(Location loc);
		void Draw(Graphics &gfx);
		void SetLoc(Location &src);
		Cell &operator =(Cell &src);
		Location GetLoc();
		void Toggle();
		bool isAlive();
		void AddToToggle();
		void Tick();
	private:
		Location loc = {-2, -2};
		bool alive = false;
		bool toToggle = false;
	};
public:
	Board();
	void Draw(Graphics &gfx);
	void InitSpawn();
	void KillCell(Cell &c);
	void KillCell(Location &loc);
	void SpawnCell(Cell &c);
	void SpawnCell(Location &loc);
	void Update();
	static constexpr int cellSize = 10;
private:
	Cell board[Graphics::ScreenHeight / cellSize][Graphics::ScreenWidth / cellSize];
};

