#pragma once

namespace yen
{
	enum Flag
	{
		OK,
		ERROR_NOTHING_FOUND_ID,
		ERROR_THING_WITH_THIS_ID_IS_ALREADY_EXISTS,
		ERROR_COMPONENT_WITH_THIS_TYPE_HAS_BEEN_ADDED_ALREADY,
		ERROR_ENGINE_NOT_INITIALIZED,
		ERROR_CAN_NOT_LOAD_FILE
	};
}
