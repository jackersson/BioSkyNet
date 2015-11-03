#include "stdafx.h"
#include "bio_general_settings.hpp"

#include "bio_resources.hpp"

#include "bio_properties_utils.hpp"

namespace SmartBio
{
	namespace View
	{

		BioGeneralSettings::BioGeneralSettings(): wxPropertyGridPage()
		{			
			do_initialize();  
		}

		BioGeneralSettings::~BioGeneralSettings() {}
		
		void BioGeneralSettings::do_initialize()
		{
			Poco::SharedPtr<BioGeneralSettingsResource> resource(new BioGeneralSettingsResource());

			BioPropertiesUtils utils;

			email_notification_ = utils.createBoolProperty(ID_EMAIL_NOTIFICATION, *this, *resource);		
		}


	}
}