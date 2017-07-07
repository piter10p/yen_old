#pragma once
namespace yen
{
	class Resource
	{
		friend class ResourceEngine;

	protected:
		virtual bool load() = 0;

		int id;
	};
}
