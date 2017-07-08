#pragma once
namespace yen
{
	class Object
	{
	public:
		Object();
		~Object();

		friend class ObjectsManager;

	protected:
		int id;
	};
}
