#include "../../headers/ui/Button.h"

void Button::CheckMouseOver()
{
	m_MouseOver = false;

	Vector2i mousePos = m_Input->getMousePos();

	if (mousePos.x > m_Position.x && mousePos.x < m_Position.x + m_Size.width) {
		if (mousePos.y > m_Position.y && mousePos.y < m_Position.y + m_Size.height) {
			m_MouseOver = true;
		}
	}
}

Button::Button(const char* sheet_path, int x, int y)
{
	m_Resources = Resources::getInstance();
	m_Renderer2D = Renderer2D::getInstance();
	m_Input = Input::getInstance();

	m_ButtonSpriteSheet = m_Resources->Load<Sprite>(sheet_path);

	Sprite* sprite = m_Resources->GetResourceById<Sprite>(m_ButtonSpriteSheet);

	m_Size.width = sprite->getWidth() / 3;
	m_Size.height = sprite->getHeight();
	state = BTNS_NORMAL;
	m_Position.x = x;
	m_Position.y = y;
}

Button::~Button()
{
}

void Button::Update()
{
	CheckMouseOver();

	switch (state) {
		case BTNS_NORMAL:
			if (m_MouseOver) {
				state = BTNS_HOVER;
			}
			break;
		case BTNS_HOVER:
			if (!m_MouseOver) {
				state = BTNS_NORMAL;
			}
			else {
				if (m_Input->getMousePress()) {
					state = BTNS_FOCUS;
				}
			}
			
			break;
		case BTNS_FOCUS:
			if (!m_Input->getMousePress()) {
				if (m_MouseOver) {
					OnClick();
				}

				state = BTNS_HOVER;
			}
			break;
		default:
			break;
	}
}

void Button::Render()
{
	m_Renderer2D->RenderGraphic(m_ButtonSpriteSheet, state * m_Size.width, 0, m_Position.x, m_Position.y, m_Size.width, m_Size.height);
}