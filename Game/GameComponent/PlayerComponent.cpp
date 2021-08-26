#include "PlayerComponent.h"
#include "Engine.h"

using namespace gme;

void PlayerComponent::Update() {
	Vector2 force = Vector2::zero;
	if (IsButtonHeld(SDL_SCANCODE_A,owner->scene->engine)) {
		force.x -= speed;
	}
	if (IsButtonHeld(SDL_SCANCODE_D, owner->scene->engine)) {
		force.x += speed;
	}

	/*if (IsButtonPressed(SDL_SCANCODE_SPACE, owner->scene->engine)) {
		force.y += jumpSpeed;
	}*/
	PhysicsComponent* physicsComponent = owner->GetComponent<PhysicsComponent>();
	assert(physicsComponent);

	physicsComponent->ApplyForce(force);
}

bool PlayerComponent::Write(const rapidjson::Value& value) const {
	return false;
}

bool PlayerComponent::Read(const rapidjson::Value& value) {
	JSON_READ(value, speed);
	JSON_READ(value, jumpSpeed);
	return true;
}

