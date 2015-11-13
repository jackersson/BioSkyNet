#include "stdafx.h"
#include "bio_application_resource.hpp"
//#include "resources/logo.xpm"

#include "bio_resources.hpp"
#include "uapp_info_item.hpp"

namespace SmartBio
{
	namespace View
	{
		BioApplicationResource::BioApplicationResource() {
			initialize();
		}

		BioApplicationResource::~BioApplicationResource()	{}

		void BioApplicationResource::do_initialize()
		{
			std::string app_name = "Smart Biometrics";
			std::string app_version = "v0.1";
			std::string app_website = "http://bioskynet.com";
			//std::string app_icon    = "resources\\logo.xpm";
			std::string app_hint = "Smart Biometrics v0.1";

			UAppInfoItem app(app_name, app_hint, "", "", app_website, app_version);
			
			insert(UIResources::ID_APPLICATION, app);


		}

	}
}