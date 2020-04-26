#include "MovingTrap.h"

MovingTrap::MovingTrap()
{
}

MovingTrap::
MovingTrap(FPosition Position, std::string Name, std::string Shape, std::string Direction, std::string Type): Object(
	Position, Name, Shape, Direction, Type)
{
	ID = Name;
	this->Direction = Direction;
}

void MovingTrap::Work()
{
	Move();
}

void MovingTrap::OnCollision(Object* other)
{
	Object* o = WorldOutliner::FindObject(ID);
	if (o->getDirection() == "��")
	{
		o->setDirection("��");
	}
	else if (o->getDirection() == "��")
	{
		o->setDirection("��");
	}

	if (o->getDirection() == "��")
	{
		o->setDirection("��");
	}
	else if (o->getDirection() == "��")
	{
		o->setDirection("��");
	}
}

void MovingTrap::Move()
{
	Object* o = WorldOutliner::FindObject(ID);
	if (o->getDirection() == "��")
	{
		Translate(Up);
	}
	else if (o->getDirection() == "��")
	{
		Translate(Down);
	}

	if (o->getDirection() == "��")
	{
		Translate(Left);
	}
	else if (o->getDirection() == "��")
	{
		Translate(Right);
	}
}
