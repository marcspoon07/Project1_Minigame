#pragma once
#include "../../headers/Video.h"
#include "../../headers/Input.h"

#include "../math/Vector2i.h"
#include "../math/Sizei.h"

#include "../Resources.h"
#include "../Renderer2D.h"

class Button
{
private:
	Uint32 m_ButtonSpriteSheet;
	Vector2i m_Position;
	Sizei m_Size;
	bool m_MouseOver;

	Resources* m_Resources;
	Renderer2D* m_Renderer2D;
	Input* m_Input;

	void CheckMouseOver();
public:
	Button(const char* sheet_path, int x, int y);
	~Button();

	enum ButtonState {
		BTNS_NORMAL,
		BTNS_HOVER,
		BTNS_FOCUS,
		BTNS_DISABLED
	};

	void setState(ButtonState st) { state = st; }
	int getState() { return state; }

	void Update();
	void Render();
protected:
	ButtonState state;

	virtual void OnClick() { /* VACIO */ }
};