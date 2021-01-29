#include "StdAfx.h"
#include "StatusComponent.h"
#include <Components/Player/Player.h>

namespace
{
	static void RegisterStatusComponent(Schematyc::IEnvRegistrar& registrar)
	{
		Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
		{
			Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CStatusComponent));
		}
	}

	CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterStatusComponent);
}

void CStatusComponent::Initialize()
{
	m_isAlive = true;
}

Cry::Entity::EventFlags CStatusComponent::GetEventMask() const
{
	return Cry::Entity::EEvent::Update;
}

void CStatusComponent::ProcessEvent(const SEntityEvent& event)
{
	switch (event.event)
	{
	case Cry::Entity::EEvent::Update:
		const float frameTime = event.fParam[0];
		if (IsAlive())
			StatusUpdate(frameTime);
		break;
	}
}

void CStatusComponent::StatusUpdate(float frameTime)
{
	if (GetStatus().HealtMax <= GetStatus().HealtMed)
		CryLog("Warning Low Health");

	if (GetStatus().HealtMax <= 0)
	{
		CryLog("You are dead");
		m_isAlive = false;

		auto pPlayer = m_pEntity->GetComponent<CPlayerComponent>();
		pPlayer->OnReadyForGameplayOnServer();
	}
}
