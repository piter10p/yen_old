#pragma once
#include "Flag.h"
#include "Id.h"

namespace yen
{
	class Resource :public Id
	{
	public:
		void loadOperations()
		{
			if (isUsed && !loaded)
			{
				load();
				loaded = true;
			}
				
			else if (!isUsed && loaded)
			{
				unLoad();
				loaded = false;
			}
		}

		void used()
		{
			isUsed = true;
		}

		void resetUsed()
		{
			isUsed = false;
		}

	protected:
		virtual void load() = 0;
		virtual void unLoad() = 0;

	private:
		bool isUsed = false;
		bool loaded = false;
	};
}
