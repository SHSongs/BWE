#pragma once

#include "Canon.h"
#include "SceneManager.h"
#include <optional>
#include "Player.h"
#include "Wall.h"
#include "PushTrap.h"
#include "MovingTrap.h"

class TestScene : public SceneManager
{
private:
public:
	
	int Size = 30;
	TestScene() : SceneManager()
	{
		mapPointer = new Map(30, 30);
	};
	void Create()
	{
		worldOutliner.AddObject(new Player(FPosition({ 2,28 }), "Player", "��", "Player"));
		worldOutliner.AddObject(new PushTrap(FPosition({ 15, 15 }), "PushTrap_1", "@@", "PushTrap"));
		worldOutliner.AddObject(new MovingTrap(FPosition({ 20, 20 }), "MovingTrap_1", "HH", "��", "MovingTrap"));
		worldOutliner.AddObject(new MovingTrap(FPosition({ 25, 20 }), "MovingTrap_2", "HH", "��", "MovingTrap"));
		worldOutliner.AddObject(new MovingTrap(FPosition({ 28, 28 }), "MovingTrap_3", "VV", "��", "MovingTrap"));
		worldOutliner.AddObject(new MovingTrap(FPosition({ 28, 14 }), "MovingTrap_4", "VV", "��", "MovingTrap"));
		worldOutliner.AddObject(new MovingTrap(FPosition({ 2, 2 }), "MovingTrap_5", "��", "��", "MovingTrap"));
		worldOutliner.AddObject(new MovingTrap(FPosition({ 6, 3 }), "MovingTrap_6", "��", "��", "MovingTrap"));


		worldOutliner.AddObject(new Wall(FPosition({ 3,4 }), "Hwall1", Area({10,1})));
		worldOutliner.AddObject(new Wall(FPosition({ 1,10 }), "Hwall2", Area({15,1})));
		worldOutliner.AddObject(new Wall(FPosition({ 1,20 }), "Hwall3", Area({10,1})));
		worldOutliner.AddObject(new Wall(FPosition({ 10,2}), "Vwall1", Area({1,7})));
		worldOutliner.AddObject(new Wall(FPosition({ 7,8}), "Vwall2", Area({1,7})));
		
		
		Map_Make();
	}

	void Render(float dt)
	{
	//		worldOutliner.FindObject("MovingTrap_1")->TryWork();
		
		//dynamic_cast<Player*>(worldOutliner.FindObject("canon1"))->getW();

		
		
		
	}
	void Resize(int x, int y)
	{

	}
	void Input(float dt)
	{
	
	}
	void Pause()
	{

	}
	~TestScene() 
	{

	}
	void Map_Make() 
	{
		worldOutliner.AddObject(new Wall(FPosition({ 0,0 }), "Wall_Top", "��", Area({ Size, 1 }), "Wall"));
		worldOutliner.AddObject(new Wall(FPosition({ 0,0 }), "Wall_Left", "��", Area({ 1, Size }), "Wall"));
		worldOutliner.AddObject(new Wall(FPosition({ (float) Size-1, 0 }), "Wall_Right", "��", Area({ 1, Size }), "Wall"));
		worldOutliner.AddObject(new Wall(FPosition({ 0, (float) Size-1 }), "Wall_Bottom", "��", Area({ Size, 1 }), "Wall"));
	}
	std::string getW()
	{
		worldOutliner.FindObject("Player")->GetShape();
	}
};