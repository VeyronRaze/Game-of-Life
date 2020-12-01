#include "Board.h"
#include <random>

Board::Cell::Cell(Location loc)
	:
	loc(loc){}

void Board::Cell::Draw(Graphics &gfx){
	gfx.DrawSquareWithPadding(loc.x*cellSize, loc.y*cellSize, cellSize, cellSize, Colors::Green);
}

void Board::Cell::SetLoc(Location &src){
	loc = src;
}

Board::Cell& Board::Cell::operator=(Cell &src){
	loc = src.GetLoc();
	return *this;
}

Location Board::Cell::GetLoc(){
	return loc;
}

void Board::Cell::Toggle(){
	alive = !alive;
}

bool Board::Cell::isAlive(){
	return alive;
}

Board::Board()
{
	InitSpawn();
}

void Board::Draw(Graphics &gfx){
	for(int y = 0; y < Graphics::ScreenHeight / cellSize; y++)
		for(int x = 0; x < Graphics::ScreenWidth / cellSize; x++)
			if(board[y][x].isAlive())
				board[y][x].Draw(gfx);
}

void Board::InitSpawn(){
	std::mt19937 rng = std::mt19937(std::random_device()());
	std::uniform_int_distribution<int> xuid(0, Graphics::ScreenWidth / cellSize);
	std::uniform_int_distribution<int> yuid(0, Graphics::ScreenHeight / cellSize);
	for(int i = 0; i < 100; i++){
		int x = xuid(rng);
		int y = yuid(rng);
		Location loc(x, y);
		board[y][x].SetLoc(loc);
		board[y][x].Toggle();
	}
}
