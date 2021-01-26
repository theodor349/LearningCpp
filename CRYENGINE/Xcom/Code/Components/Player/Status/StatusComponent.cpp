#include "StdAfx.h"
#include "StatusComponent.h"

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
		StatusUpdate(frameTime);
		break;
	}
}

void CStatusComponent::StatusUpdate(float frameTime)
{
}
