#include "../../headers/entities/Conveyor.h"

Conveyor::Conveyor()
{
	m_Resources = Resources::getInstance();
	m_Renderer2D = Renderer2D::getInstance();
}

Conveyor::~Conveyor()
{

}

void Conveyor::Init(Vector2i position)
{
	m_Position = position;

	m_ConveyorSize.width = 198;
	m_ConveyorSize.height = 66;

	m_ConveyorCount = 4;

	m_ConveyorSheet = m_Resources->Load<Sprite>("Assets/Sprites/conveyor.png");

	m_ConveyorAnimation.Init("Assets/Sprites/conveyor.png", 3, 500, 0, m_ConveyorSize.width, m_ConveyorSize.height);
	m_ConveyorAnimation.setPosition(m_Position);
}

void Conveyor::Update()
{
	m_ConveyorAnimation.Update();
}

void Conveyor::Render()
{
	m_Renderer2D->RenderGraphic(m_ConveyorSheet, m_ConveyorSize.width, m_ConveyorSize.height, m_Position.x, m_Position.y, m_ConveyorSize.width, m_ConveyorSize.height);

	for (int i = 1; i < m_ConveyorCount; i++) {
		m_Renderer2D->RenderGraphic(m_ConveyorSheet, 0, m_ConveyorSize.height, m_Position.x + i * m_ConveyorSize.width, m_Position.y, m_ConveyorSize.width, m_ConveyorSize.height);
	}

	for (int i = 0; i < m_ConveyorCount; i++) {
		m_ConveyorAnimation.setPositionX(m_Position.x + i * m_ConveyorSize.width);
		m_ConveyorAnimation.Render();
	}
}