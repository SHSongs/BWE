#include "Player.h"

Player::Player()
{
}

Player::Player(FPosition p, std::string name, std::string shape, std::string Type): Object(p, name, shape, Type)
{
}

void Player::Work()
{
	Control();
}

void Player::Control()
{
	static int start = 0;
	int pressed_key; // ���� Ű�� ���ȴ���


	if (start == 0)
	{
		// ó�� �����Ҷ��� �������ֱ� ���ؼ�

		Move("��", false);
		start = 1; // ó�� �����Ҷ��� �������ֱ� ���ؼ�
	}

	else if (_kbhit())
	{
		// ���� Ű�� ���ȴٸ� 
		pressed_key = _getch(); //���� Ű���� �Է�
		if (pressed_key == 72 || pressed_key == 119)
		{
			// ��(W)

			Move("��", true);
		}

		if (pressed_key == 75 || pressed_key == 97)
		{
			// ��(A)

			Move("��", true);
		}

		if (pressed_key == 80 || pressed_key == 115)
		{
			// ��(S)

			Move("��", true);
		}

		if (pressed_key == 77 || pressed_key == 100)
		{
			// ��(D)

			Move("��", true);
		}


		if (pressed_key == 32)
		{
			Object* o = WorldOutliner::FindObject("Player");

			Shot(o->GetShape());
			//WorldOutliner::AddObject(new Canon(GetPosition(), "canon2", "��", "��", Area({ 1,1 }), "��"));			}
		}
	}
}

void Player::Move(std::string w, bool ifGo)
{
	this->w = w;
	if (ifGo == true)
	{
		if (w == "��")
			Translate({0, -1}, w);
		if (w == "��")
			Translate({-1, 0}, w);
		if (w == "��")
			Translate({0, +1}, w);
		if (w == "��")
			Translate({+1, 0}, w);
	}
	else
	{
		Translate({0, 0}, w);
	}
}

void Player::Shot(std::string D)
{
	if (D == "��")
	{
		WorldOutliner::AddObject(new Canon({GetPosition().x, GetPosition().y - 1}, "canon2", "��", "��", Area({1, 1}),
		                                   "��", "Canon"));
	}
	if (D == "��")
	{
		WorldOutliner::AddObject(new Canon({GetPosition().x, GetPosition().y + 1}, "canon2", "��", "��", Area({1, 1}),
		                                   "��", "Canon"));
	}

	if (D == "��")
	{
		WorldOutliner::AddObject(new Canon({GetPosition().x - 1, GetPosition().y}, "canon2", "��", "��", Area({1, 1}),
		                                   "��", "Canon"));
	}
	if (D == "��")
	{
		WorldOutliner::AddObject(new Canon({GetPosition().x + 1, GetPosition().y}, "canon2", "��", "��", Area({1, 1}),
		                                   "��", "Canon"));
	}
}

void Player::OnCollision(Object* other)
{
	/*Object* o = WorldOutliner::FindObject("canon1");
	o->SetShape("ac");*/


	/*if (dynamic_cast<Canon*>(other))
		other->SetShape("ac");*/

	//if (dynamic_cast<PushTrap*>(other))
	//Move(w, true);
	if (other->getType() == "Wall")
	{
		if (w == "��")
			Translate({0, +1}, w);
		else if (w == "��")
			Translate({+1, 0}, w);
		else if (w == "��")
			Translate({0, -1}, w);
		else if (w == "��")
			Translate({-1, 0}, w);
	}
	else
	{
		std::string D = other->getDirection();
		if (D == "��")
			Translate({0, -1}, D);
		else if (D == "��")
			Translate({-1, 0}, D);
		else if (D == "��")
			Translate({0, +1}, D);
		else if (D == "��")
			Translate({+1, 0}, D);
	}
}

std::string Player::getW()
{
	return w;
}
