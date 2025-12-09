#include "PlayerController.h"
#include "Entity.h"
#include "Sprite.h"
#include "Spawner.h"

PlayerController::PlayerController(Entity* ent): Component(ent),m_Spawner(nullptr)
{
	//a faire dans le start
	m_Spawner = m_Entity->GetComponent<Spawner>();
	m_BulletSfx = Engine::Get().Audio()->LoadSound("Shoot.mp3");
}

PlayerController::PlayerController(const PlayerController& other, Entity* newParent) : Component(newParent),m_Spawner(other.m_Spawner)
{

}

static float _x = 400.0f;
static float _y = 500.0f;

void PlayerController::Start()
{
	m_Spawner = m_Entity->GetComponent<Spawner>();
}

void PlayerController::Update(float dt) {

	_x = m_Entity->GetX();
	if (_x < 750 && Engine::Get().Input()->IsKeyDown(EKEY_D)){
		_x += 5.0f * dt;
	}
	if (_x > 0 && Engine::Get().Input()->IsKeyDown(EKEY_A)) {
		_x -= 5.0f * dt;
	}
	m_Entity->SetX(_x);

	if (Engine::Get().Input()->IsSpaceUp())
	{
		
		Engine::Get().Audio()->PlaySFX(m_BulletSfx);

		Entity* bullet = m_Spawner->Spawn("baseBullet");
		bullet->SetX(this->m_Entity->GetX() + 15);
		bullet->SetY(this->m_Entity->GetY());
	}
}

void PlayerController::Draw() {
	
}

Component* PlayerController::Clone(Entity* newParent) const
{
	return new PlayerController(*this,newParent);
}


