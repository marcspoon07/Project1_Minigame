#pragma once

#include "../utilities/Animation.h"

class Portal {
private:
	Animation m_PortalAnimation;

	bool m_IsActive;
	Vector2i m_Position;
public:
	Portal();
	~Portal();

	void Activate(Vector2i position);
	void Deactivate();
};