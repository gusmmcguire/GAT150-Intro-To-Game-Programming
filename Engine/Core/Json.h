#pragma once
#include "Math/Color.h"
#include "Math/Vector2.h"
#include "document.h"
#include <string>

#define JSON_READ(value, data) gme::json::Get(value, #data, data);

namespace gme {
	namespace json {
		bool Load(const std::string& filename, rapidjson::Document& document);
		bool Get(const rapidjson::Value& value, const std::string& name, int& data);
		bool Get(const rapidjson::Value& value, const std::string& name, float& data);
		bool Get(const rapidjson::Value& value, const std::string& name, bool& data);
		bool Get(const rapidjson::Value& value, const std::string& name, std::string& data);
		bool Get(const rapidjson::Value& value, const std::string& name, Vector2& data);
		bool Get(const rapidjson::Value& value, const std::string& name, Color& data);

	}
}