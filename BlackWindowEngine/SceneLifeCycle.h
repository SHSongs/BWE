#pragma once


#include "Object.h"
#include "Map.h"
#include "SceneLifeCycle.h"

#include "Tools.h"
#include "WorldOutliner.h"


class SceneLifeCycle
{
protected:
public:
	WorldOutliner worldOutliner;
	Map* mapPointer;

	SceneLifeCycle()
	{
		worldOutliner = WorldOutliner();
	};
	
	virtual void Create() = 0;			//Called when the Application is first created.
	virtual void Render(float dt) = 0;
	virtual void Resize(int x, int y) = 0;
	virtual void Input(float dt) = 0;
	virtual void Pause() = 0;			//Stop Game
	virtual ~SceneLifeCycle() {};				//Called when this Game should release all resources.

	void UploadMap(Object o)
	{
		mapPointer->SetPartOfMap(o.GetPosition(), o.GetShape());
	}

	void UploadMap(vector<Object> obs)
	{
		for (auto o : obs)
		{
			try
			{
				mapPointer->SetPartOfMap(o.GetPosition(), o.GetShape());
			}
			catch (exception e)
			{
				Tools::cersorMoveTo(Position({ 0, mapPointer->GetYSIZE() + 2 }));
				cout << "ERROR : out of Map" << endl;
				Tools::backCersor();
			}
		}
	}

};