#pragma once

#include "Object.h"

class Wall : public Object {
private:

public:
	//WorldOutliner worldOutliner;
	Wall() {

	}
	Wall(string name) {
	}
	Wall(FPosition p, string name, string shape)
	{
		
	}
	Wall(FPosition p, string name, string shape, Area area) : Object(p, name, shape, area)
	{

	}

	void Work() // ���� �ȿ��� ���ư��� Work
	{
		Make();
	}

	void Make() {
		//SceneManager.worldOutliner.AddObject(new Wall(FPosition({ 5,5 }), "Wall_10,10", "��"));
	}
	void OnCollision(Object* other)
	{
		;
	}
	
	
	
	
	void Pause()
	{

	}
	~Wall()
	{

	}
};