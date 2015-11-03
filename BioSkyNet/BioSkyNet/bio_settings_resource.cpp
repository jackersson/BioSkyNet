#include "stdafx.h"
#include "bio_settings_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{

		BioSettingsResource::BioSettingsResource()
		{
			initialize();
		}

		BioSettingsResource::~BioSettingsResource()	{}


		void BioSettingsResource::do_initialize()
		{
			

			View::USettingInfoItem apply						("", "", "Apply"						, "resources/settings/apply.png", "", "");
			View::USettingInfoItem ok								("", "", "Ok"								, "resources/settings/ok.png", "", "");
			View::USettingInfoItem reset_to_default	("", "", "Reset to default"	, "resources/settings/reset_to_default.png", "", "");



			insert(UIBioSettings::ID_SETTINGS_BTN_APPLY							, apply);
			insert(UIBioSettings::ID_SETTINGS_BTN_OK								, ok);
			insert(UIBioSettings::ID_SETTINGS_BTN_RESET_TO_DEFAULT	, reset_to_default);





		}

	}
}


