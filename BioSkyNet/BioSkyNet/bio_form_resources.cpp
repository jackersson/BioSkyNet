#include "stdafx.h"
#include "bio_form_resources.hpp"
//#include "resources/logo.xpm"

#include "bio_resources.hpp"
#include "uinfo_item.hpp"

namespace SmartBio
{
	namespace View
	{
		BioFormResource::BioFormResource() { 
			initialize();
		}

		BioFormResource::~BioFormResource()	{}

		void BioFormResource::do_initialize()
		{			



			UInfoItem settings("Settings", "", "resources\\setting.png", "");


			insert(UIResources::ID_SETTINGS_TAB   , settings);

		}

	}
}