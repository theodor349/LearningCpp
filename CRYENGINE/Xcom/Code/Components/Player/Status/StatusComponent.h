#pragma once

#include <CryEntitySystem/IEntityComponent.h>
#include <CrySchematyc/CoreAPI.h>

enum class ECharacterStatusState {
	ECS_Alive = 0,
	ECS_Injured,
	ECS_Dead,
};

enum class ECharacterState {
	ECS_Patrol = 0,
	ECS_Alerted,
};

static void ReflectType(Schematyc::CTypeDesc<ECharacterState>& desc) {
	desc.SetGUID("{7BDF5845-6B6C-4B3C-962F-72E68BAA147B}"_cry_guid);
	desc.SetLabel("Character State");
	desc.SetDescription("Set the start state of this entity");
	desc.SetDefaultValue(ECharacterState::ECS_Patrol);
	desc.AddConstant(ECharacterState::ECS_Patrol, "Patrol", "Patrol");
	desc.AddConstant(ECharacterState::ECS_Alerted, "Alerted", "Alerted");
}

class CStatusComponent : public IEntityComponent 
{
	struct SStatus
	{
		inline bool operator == (const SStatus& rhs) const { return 0 == memcmp(this, &rhs, sizeof(rhs)); }
		inline bool operator != (const SStatus& rhs) const { return 0 == memcmp(this, &rhs, sizeof(rhs)); }

		Schematyc::Range<0, 1000, 0, 1000, float>HealtMax = 1000.0f;
		Schematyc::Range<0, 1000, 0, 1000, float>HealtMed = 500.0f;

		Schematyc::Range<0, 3000, 0, 3000, float>StaminaMax = 3000.0f;
		Schematyc::Range<0, 3000, 0, 3000, float>StaminaMed = 1500.0f;

		static void ReflectType(Schematyc::CTypeDesc<SStatus>& desc) {
			desc.SetGUID("{2B2C783E-591B-4DAC-BB26-6A7EE9558962}"_cry_guid);
			desc.SetLabel("Status Params");
			desc.SetDescription("Set the default values of status to this Entity");

			desc.AddMember(&SStatus::HealtMax, 'heal', "HealthMax", "Health Max", "Set this entity's maximum health", 1000.0f);
			desc.AddMember(&SStatus::HealtMed, 'heam', "HealthMedium", "Health Medium", "Set this entity's medium health", 500.0f);

			desc.AddMember(&SStatus::StaminaMax, 'stam', "StaminaMax", "Stamina Max", "Set this entity's maximum stamina", 3000.0f);
			desc.AddMember(&SStatus::StaminaMed, 'stmd', "StaminaMedium", "Stamina Medium", "Set this entity's medium stamina", 1500.0f);
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
		desc.SetLabel("Status Component");
		desc.SetDescription("Our awesome status component");
		desc.SetEditorCategory("Game");
		desc.SetComponentFlags({ IEntityComponent::EFlags::Socket, IEntityComponent::EFlags::Attach });

		desc.AddMember(&CStatusComponent::m_StatusParams, 'stat', "StatusParams", "StatusParams", nullptr, SStatus());
		desc.AddMember(&CStatusComponent::m_CharacterState, 'csta', "CharacterState", "Character State", nullptr, ECharacterState::ECS_Patrol);
	}

	SStatus& GetStatus() { return m_StatusParams; }
	bool IsAlive() { return m_isAlive; }
	void Alive(bool changeIsAlive) { m_isAlive = changeIsAlive; }
	void SetHealth(float newHealth) { GetStatus().HealtMax = newHealth; }
	void SetStamina(float newStamina) { GetStatus().StaminaMax = newStamina; }
	void SetDamage(float damage) { GetStatus().HealtMax -= damage; }

protected:
	bool m_isAlive = false;
	SStatus m_StatusParams;
	void StatusUpdate(float frameTime);

	ECharacterState m_CharacterState;
};