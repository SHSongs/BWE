#pragma once

#include "Object.h"

class Wall : public Object {
private:

public:
	
	//WorldOutliner worldOutliner;
	Wall();

	Wall(FPosition p, std::string name, Area area);

	Wall(FPosition p, std::string name, std::string shape, std::string Type);

	Wall(FPosition p, std::string name, std::string shape, Area area, std::string Type);

	void Work() // ���� �ȿ��� ���ư��� Work
	;

	void Make();

	void OnCollision(Object* other);


	void Pause();

	~Wall();
};