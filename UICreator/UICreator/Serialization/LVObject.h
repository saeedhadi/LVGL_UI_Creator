#pragma once

#include <string>

#include "../../3rdParty/JSON/json.hpp"
#include "lvgl/lvgl.h"

#include "Style.h"
#include "Area.h"
#include "Realign.h"

using json = nlohmann::json;

namespace Serialization
{
	class LVObject
	{
	public:
		static json ToJSON(lv_obj_t* obj);
		static lv_obj_t* FromJSON(json j, lv_obj_t* widget = nullptr);

	};


}