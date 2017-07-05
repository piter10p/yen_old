#pragma once
namespace yen
{
	enum ResourceType
	{
		AnimationResource
	};

	class Resource
	{
		friend class ResourceEngine;

	protected:
		virtual bool load() = 0;

		const ResourceType resource;
	};
}
