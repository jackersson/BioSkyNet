#include "stdafx.h"
#include "bio_profile_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{

		BioProfileResource::BioProfileResource()
		{
			initialize();
		}		

		BioProfileResource::~BioProfileResource()	{}

		void BioProfileResource::do_initialize()
		{
			View::UInfoItem btn_edit  ("", "You can edit properties", "resources\\profile\\edit.png"  , "");
			View::UInfoItem btn_open  ("", "You can edit properties", "resources\\profile\\open.png"  , "");
			View::UInfoItem btn_save  ("", "You can edit properties", "resources\\profile\\save.png"  , "");
			View::UInfoItem btn_delete("", "You can edit properties", "resources\\profile\\delete.png", "");
			View::UInfoItem avatar    ("", "You can edit properties", "resources\\profile\\avatar.png", "");
			
			insert(UIBioProfilePage::ID_BTN_EDIT  , btn_edit   );
			insert(UIBioProfilePage::ID_BTN_OPEN  , btn_open   );
			insert(UIBioProfilePage::ID_BTN_SAVE  , btn_save   );
			insert(UIBioProfilePage::ID_BTN_DELETE, btn_delete );
			insert(UIBioProfilePage::ID_AVATAR    , avatar     );
		}

	}
}