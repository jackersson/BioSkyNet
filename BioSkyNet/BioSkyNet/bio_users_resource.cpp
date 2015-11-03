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
			View::UInfoItem btn_add_user("Add", "Adding new person", "", "");

			insert(UIBioUsersPage::ID_BTN_ADD_USER, btn_add_user);
		}

	}
}