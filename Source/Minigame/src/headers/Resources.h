#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

#include "../simple_types.h"

#include <string>
#include <vector>

#include "Debug.h"

#include "Singleton.h"

// Resources
#include "utilities/Sprite.h"

typedef uint32 ResourceId;

typedef Mix_Chunk AudioClip;

class Resources : public Singleton<Resources>
{
	friend class Singleton<Resources>;
private:
	// Enum that indicates all the resources that can be loaded by the engine
	enum ResourceType {
		RT_SPRITE,
		RT_AUDIOCLIP,
		RT_LAST
	};

	struct Resource {
		// Path to resource
		std::string filePath;

		// Any type
		void* resource;
	};

	std::vector<Resource*> m_Resources[RT_LAST];

	Resources();

	uint32 getResourcePosition(ResourceType rt, const char* file);
public:
	~Resources();

	template<class T> ResourceId Load(const char* file);
	template<class T> T* GetResourceById(ResourceId id);
};

//SPECIALIZATION FOR SPRITE
template<>
inline uint32 Resources::Load<Sprite>(const char * file)
{
	size_t size = m_Resources[ResourceType::RT_SPRITE].size();
	size_t i;

	Uint32 resourceId = -1;

	for (i = 0; i < size; i++) {
		if (m_Resources[RT_SPRITE][i]->filePath == file) {
			resourceId = static_cast<Uint32>(i);
			break;
		}
	}

	if (i == size) {
		SDL_Surface* srfc = IMG_Load(file);

		if (!srfc) {
			Debug::getInstance()->LogError("RESOURCES", IMG_GetError());
		}
		else {
			Resource* resource = new Resource();

			resource->filePath = file;

			resource->resource = new Sprite(srfc, srfc->w, srfc->h);

			resourceId = static_cast<uint32>(size);

			m_Resources[RT_SPRITE].push_back(resource);

			std::string message = "LOADED SPRITE: ";
			message += file;

			Debug::getInstance()->Log("RESOURCES", message.c_str());
		}
	}

	return resourceId;
}

template<>
inline Sprite* Resources::GetResourceById<Sprite>(ResourceId id)
{
	Sprite* sprite = NULL;

	if (id >= 0 && id < m_Resources[RT_SPRITE].size()) {
		sprite = static_cast<Sprite*>(m_Resources[RT_SPRITE][id]->resource);
	}

	return sprite;
}

// SPECIALIZATION FOR MIX_CHUNK
template<>
inline ResourceId Resources::Load<AudioClip>(const char * file)
{
	Uint32 size = static_cast<Uint32>(m_Resources[ResourceType::RT_AUDIOCLIP].size());
	Uint32 i;

	Uint32 resourceId = -1;

	for (i = 0; i < size; i++) {
		if (m_Resources[RT_AUDIOCLIP][i]->filePath == file) {
			resourceId = static_cast<Uint32>(i);
			break;
		}
	}

	if (i == size) {
		Mix_Chunk* audioclip = Mix_LoadWAV(file);

		if (!audioclip) {
			Debug::getInstance()->LogError("Resources", Mix_GetError());
		}
		else {
			Resource* resource = new Resource();

			resource->resource = audioclip;

			resource->filePath = file;

			resourceId = static_cast<Uint32>(size);

			m_Resources[RT_AUDIOCLIP].push_back(resource);

			std::string message = "LOADED AUDIO: ";
			message += file;

			Debug::getInstance()->Log("RESOURCES", message.c_str());
		}
	}

	return resourceId;
}

template<>
inline AudioClip* Resources::GetResourceById<AudioClip>(ResourceId id)
{
	AudioClip* audioclip = NULL;

	if (id >= 0 && id < m_Resources[RT_AUDIOCLIP].size()) {
		audioclip = static_cast<AudioClip*>(m_Resources[RT_AUDIOCLIP][id]->resource);
	}

	return audioclip;
}

// BOMBERMAN

// SPECIALIZATION FOR MAP

//template<>
//inline ResourceId Resources::Load<Map>(const char* file) {
//	Uint32 size = static_cast<Uint32>(mResources[ResourceType::RT_MAP].size());
//	Uint32 i;
//
//	Uint32 resourceId = -1;
//
//	for (i = 0; i < size; i++) {
//		if (mResources[RT_MAP][i]->filePath == file) {
//			resourceId = static_cast<Uint32>(i);
//			break;
//		}
//	}
//
//	if (i == size) {
//		Map* map = new Map();
//		map->LoadMap(file);
//
//		Resource* resource = new Resource();
//
//		resource->resource = map;
//
//		resource->filePath = file;
//
//		resourceId = static_cast<Uint32>(size);
//
//		mResources[RT_MAP].push_back(resource);
//
//		std::cout << "RESOURCES: Loaded " << file << std::endl;
//	}
//
//	return resourceId;
//}
//
//template<>
//inline Map* Resources::GetResourceById<Map>(ResourceId resource) {
//	Map* map = NULL;
//
//	if (resource >= 0 && resource < mResources[RT_MAP].size()) {
//		map = static_cast<Map*>(mResources[RT_MAP][resource]->resource);
//	}
//
//	return map;
//}