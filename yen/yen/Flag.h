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
		ERROR_SCENE_NOT_INITIALIZED,
		ERROR_OBJECT_DONT_HAVE_COMPONENT_OF_THIS_TYPE,
		ERROR_SCENE_DONT_HAVE_CAMERA,
		ERROR_DEF_OBJECT_IS_NOT_FILLED_PROPERLY,
		ERROR_NO_BODY_FOUNDED,
		ERROR_LANGUAGE_WITH_THIS_CODE_ALREADY_EXISTS,
		ERROR_CAN_NOT_OPEN_FILE,
		ERROR_DIRECTORY_EMPTY,
		ERROR_CAN_NOT_READ_FILE,
		ERROR_BAD_PATH,
		ERROR_INDEX_OUT_OF_LIST_RANGE,
		ERROR_UNDEFINED,
		ERROR_CAN_NOT_FIND_STRING_WITH_SPECIFIC_NAME,
	};
}
