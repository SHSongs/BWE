#pragma once
#include "Object.h"
#include "WorldOutliner.h"
#include "SceneManager.h"
class MovingTrap : public Object {
private:
	
public:
	string Direction;
	string ID;
	MovingTrap()
	{

	}
	MovingTrap(FPosition Position, string Name, string Shape, string Direction) : Object(Position, Name, Shape, Direction)
	{
		ID = Name;
		this->Direction = Direction;
	}



	void Work() 
	{
		Move();
	}

	/*void OnCollision(Object* other) 
	{
		Object* o = WorldOutliner::FindObject(ID);
		if (o->getDirection() == "��") {
			o->setDirection("��");
		}
		if (o->getDirection() == "��") {
			o->setDirection("��");
		}

		if (o->getDirection() == "��") {
			Translate({ +5, 0 });
			o->setDirection("��");
			
		}
		if (o->getDirection() == "��") {
			o->setDirection("��");
		}
	}*/

	void OnCollision(Object* other)
	{
	//	Object* o = WorldOutliner::FindObject(ID);
		if (Direction == "��") {
			Direction = "��";
		}
		else if (Direction == "��") {
			Direction = "��";
		}

		if (Direction == "��") {
			Direction ="��";
		}
		else if (Direction == "��") {
			Direction = "��";
		}
	}
	void Move()
	{
	//	Object* o = WorldOutliner::FindObject(ID);
		if (Direction == "��") {
			Translate(Up);
		}
		else if (Direction == "��") {
			Translate(Down);
		}

		if (Direction == "��") {
			Translate(Left);
		}
		else if (Direction == "��") {
			Translate(Right);
		}
	}
};