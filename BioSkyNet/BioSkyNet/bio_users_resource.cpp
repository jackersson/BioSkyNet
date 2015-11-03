#include "stdafx.h"
#include "bio_users_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{

		BioUsersResource::BioUsersResource()
		{
			initialize();
		}


		BioUsersResource::~BioUsersResource()	{}


		void BioUsersResource::do_initialize()
		{


			// 			std::string tjournal = "Journal";
			// 			std::string tjournal_hint = "Journal";
			// 			std::string tjournal_icon = "resources\\toolbar\\journalx48.png";

			View::UInfoItem btn_add_user("Add", "Adding new person", "", "");




			/*View::UInfoItem journal(tjournal, tjournal_hint, tjournal_icon, "");*/

			insert(UIBioUsersPage::ID_BTN_ADD_USER, btn_add_user);




		}

	}
}