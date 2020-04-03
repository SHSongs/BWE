#pragma once

#include "WorldOutliner.h"
#include "Object.h"
#include "MovingTrap.h"
class Canon : public Object
{
private:
	bool ch = true;
	string Direction;
	float speed = 0.05;
public:
	
	string shape2;
	Canon(FPosition p, string name, string shape, string shape2, Area area, string Direction) : Object(p,name,shape,area)
	{
		this->shape2 = shape2;
		this->Direction = Direction;
	}

	virtual void Work()
	{
		Move(Direction);
		SwapShape();
	}
	void Move(string D)
	{
		if (D == "��")
		{
			Translate(FPosition({ 0,(float)(-speed) }));
		}
		else if (D == "��")
		{ 
			Translate(FPosition({ 0,(float)(speed) }));
		}
		else if (D == "��")
		{
			Translate(FPosition({ (float)(-speed), 0 }));
		}
		else if (D == "��")
		{
			Translate(FPosition({ (float)(+speed), 0 }));
		}
		else if (D == "��")
		{
			Translate(FPosition({ 0, 0 }));
		}
	}
	void SwapShape()
	{
		string tmp = shape;
		shape = shape2; 
		shape2 = tmp;
	}
	void DoNothing()
	{
		
	}
	virtual void OnCollision(Object* other)
	{
		shape2 = shape;

		WorldOutliner::Destroy(this);

		if(dynamic_cast<MovingTrap*>(other))
		{
			WorldOutliner::Destroy(this);
		}
	}
	
};