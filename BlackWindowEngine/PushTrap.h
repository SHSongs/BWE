#pragma once
#include "Object.h"
#include "WorldOutliner.h"
#include "SceneManager.h"
#include <string.h>
#include "Unit.h"
//#include "Player.h"

class PushTrap : public Object {
private:

public:
	string Direction;
	string ID;
	PushTrap() {

	}
	PushTrap(string name) {
		ID = name;
	}
	PushTrap(FPosition p, string name, string shape) : Object(p, name, shape)
	{
		ID = name;
	}
	PushTrap(FPosition p, string name, string shape, Area area) : Object(p, name, shape, area)
	{
		ID = name;
	}
	void Create()
	{
		
	}

	void Work() // ���� �ȿ��� ���ư��� Work
	{
		
	}

	void OnCollision(Object* other)
	{
		string Direction;
		static string back;

		Object* o = WorldOutliner::FindObject("Player");
		//Direction = o->GetShape();
		Object* Pushtrap = WorldOutliner::FindObject(ID);

		if (other->GetName() == "Player") {
			Direction = o->GetShape();

			if (Direction == "��") {
				Translate({ 0, -1 });
				back = Direction;
			}
			if (Direction == "��") {
				Translate({ -1, 0 });
				back = Direction;
			}
			if (Direction == "��") {
				Translate({ 0, +1 });
				back = Direction;
			}
			if (Direction == "��") {
				Translate({ +1, 0 });
				back = Direction;
			}
		}
		else {
			FPosition object_Position = o->GetPosition();
			FPosition Pushtrap_Position = Pushtrap->GetPosition();
			Direction = o->GetShape();	
			if (back == "��") {
				Translate({ 0, +1 });
				o->Translate({ 0, +1 });
			}
			if (back == "��") {
				Translate({ +1, 0 });
				o->Translate({ +1, 0 });
			}
			if (back == "��") {
				Translate({ 0, -1 });
				o->Translate({ 0, -1 });
			}
			if (back == "��") {
				Translate({ -1, 0 });
				o->Translate({ -1, 0 });
			}
		}

	}
	void Push(string w)
	{

	}
};