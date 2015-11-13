#include "stdafx.h"
#include "bio_grid_settings_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{
		BioGridSettingsResource::BioGridSettingsResource() 
		{
			initialize();
		}

		BioGridSettingsResource::~BioGridSettingsResource()	{}

		void BioGridSettingsResource::do_initialize()
		{
			UInfoItem device_settings		("Device Settings"	, "", "resources\\settings\\device.png"						, "");
			UInfoItem general_settings	("General settings" , "", "resources\\settings\\general.png"					, "");
			UInfoItem face_settings			("Face settings"		, "", "resources\\settings\\face.png"							, "");
			UInfoItem search_settings		("Search settings"	, "", "resources\\settings\\search.png"						, "");
			
			
			insert(UIResources_::ID_DEVICE_SETTINGS	  , device_settings  );
			insert(UIResources_::ID_GENERAL_SETTINGS  , general_settings );
			insert(UIResources_::ID_FACE_SETTINGS		  , face_settings    );
			insert(UIResources_::ID_SEARCH_SETTINGS	  , search_settings  );
	
		}
	}
}