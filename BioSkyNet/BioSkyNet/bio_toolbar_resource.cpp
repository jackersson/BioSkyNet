#include "stdafx.h"
#include "bio_toolbar_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{

		BioToolBarResource::BioToolBarResource()
		{
			initialize();
		}

		BioToolBarResource::~BioToolBarResource()	{}


		void BioToolBarResource::do_initialize()
		{
			std::string tjournal      = "Journal";
			std::string tjournal_hint = "Journal";
			std::string tjournal_icon = "resources\\toolbar\\journalx48.png";

			std::string tsettings      = "Settings";
			std::string tsettings_hint = "Settings";
			std::string tsettings_icon = "resources\\toolbar\\settingsx48.png";

			std::string tpersonal      = "Personal information";
			std::string tpersonal_hint = "Personal information";
			std::string tpersonal_icon = "resources\\toolbar\\userx48.png";

			std::string tusers         = "Users";
			std::string tusers_hint    = "Users";
			std::string tusers_icon    = "resources\\toolbar\\usersx48.png";

			View::UInfoItem journal ( tjournal , tjournal_hint , tjournal_icon , "");
			View::UInfoItem settings( tsettings, tsettings_hint, tsettings_icon, "");
			View::UInfoItem personal( tpersonal, tpersonal_hint, tpersonal_icon, "");
			View::UInfoItem users   ( tusers   , tusers_hint   , tusers_icon   , "");

			insert(UIToolbar::ID_JOURNAL      , journal );
			insert(UIToolbar::ID_MAIN_SETTINGS, settings);
			insert(UIToolbar::ID_PERSONAL     , personal);
			insert(UIToolbar::ID_USERS        , users   );	
		}
	
	}
}