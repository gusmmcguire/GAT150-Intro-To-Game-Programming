#include "Actor.h"
#include "Math/MathUtils.h"
#include "Math/Random.h"
#include "Graphics/Renderer.h"
#include <algorithm>

namespace gme {
	void Actor::Update(float dt) {
		transform.Update();
		std::for_each(children.begin(), children.end(), [](auto& child) {child->transform.Update(child->parent->transform.matrix); });
	}

	void Actor::Draw(Renderer* renderer) {
		if (texture) renderer->Draw(texture, transform);
		std::for_each(children.begin(), children.end(), [renderer](auto& child) {child->Draw(renderer); });
	}

	void Actor::addChild(std::unique_ptr<Actor> actor) {
		actor->parent = this;
		children.push_back(std::move(actor));
	}

	float Actor::GetRadius() {
		return (texture) ? texture->GetSize().Length() * .5f * transform.scale.x : 0;
	}
}