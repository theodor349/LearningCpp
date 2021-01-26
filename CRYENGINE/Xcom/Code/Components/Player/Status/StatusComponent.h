#pragma once

#include <CryEntitySystem/IEntityComponent.h>
#include <CrySchematyc/CoreAPI.h>

class CStatusComponent : public IEntityComponent 
{
	struct SStatus
	{
		inline bool operator == (const SStatus& rhs) const { return 0 == memcmp(this, &rhs, sizeof(rhs)); }
		inline bool operator != (const SStatus& rhs) const { return 0 == memcmp(this, &rhs, sizeof(rhs)); }

		Schematyc::Range<0, 1000, 0, 1000, float>HealtMax = 1000.0f;
		Schematyc::Range<0, 3000, 0, 3000, float>StaminaMax = 3000.0f;

		static void ReflectType(Schematyc::CTypeDesc<SStatus>& desc) {
			desc.SetGUID("{2B2C783E-591B-4DAC-BB26-6A7EE9558962}"_cry_guid);
			desc.SetLabel("Status Params");
			desc.SetDescription("Set the default values of status to this Entity");

			desc.AddMember(&SStatus::HealtMax, 'heal', "HealthMax", "Health Max", "Set this entity's maximum health", 1000.0f);
			desc.AddMember(&SStatus::StaminaMax, 'stam', "StaminaMax", "Stamina Max", "Set this entity's maximum stamina", 3000.0f);
		}
	};

protected:
	// IEntityComponent
	virtual void Initialize() override;

	virtual Cry::Entity::EventFlags GetEventMask() const override;
	virtual void ProcessEvent(const SEntityEvent& event) override;
	// ~IEntityComponent

public:
	CStatusComponent() = default;
 	virtual ~CStatusComponent() = default;

	// Reflect type to set a unique identifier for this component
	static void ReflectType(Schematyc::CTypeDesc<CStatusComponent>& desc)
	{
		desc.SetGUID("{CF2612FE-5212-4675-A464-A538F92C260E}"_cry_guid);

		desc.AddMember(&CStatusComponent::m_StatusParams, 'stat', "StatusParams", "StatusParams", nullptr, SStatus());
	}

	SStatus m_StatusParams;

protected:
	void StatusUpdate(float frameTime);

};