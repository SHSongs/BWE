#pragma once
#include "Object.h"
#include "WorldOutliner.h"


class MovingTrap : public Object {
private:
	
public:
	std::string Direction;
	std::string ID;
	MovingTrap();

	MovingTrap(FPosition Position, std::string Name, std::string Shape, std::string Direction, std::string Type);


	void Work();

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

	void OnCollision(Object* other);

	void Move();
};