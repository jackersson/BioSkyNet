#include "stdafx.h"
#include "bio_general_settings_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{
		
		BioGeneralSettingsResource::BioGeneralSettingsResource()
		{
			initialize();
		}

		BioGeneralSettingsResource::~BioGeneralSettingsResource()	{}


		void BioGeneralSettingsResource::do_initialize()
		{		
			View::USettingInfoItem memail_notification( "Email Notification", "", "Email Notification", "", "", "" );

			insert(UIBioSettings::ID_EMAIL_NOTIFICATION, memail_notification);
		}

	}
}


