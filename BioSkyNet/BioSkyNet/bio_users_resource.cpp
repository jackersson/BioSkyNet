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
			View::UInfoItem btn_add_user("Add" , "Adding new person", "", "");
			View::UInfoItem item_image  (""    , "Adding new person", "resources//face//avatar.png", "");
			View::UInfoItem text        ("Name", "Adding new person", "", "");


			View::UInfoItem first_name   ("First Name"   , "", "", "");
			View::UInfoItem last_name    ("Last Name"    , "", "", "");
			View::UInfoItem date_of_birth("Date of birth", "", "", "");
			View::UInfoItem gender       ("Gender"       , "", "", "");
			View::UInfoItem country      ("Country"      , "", "", "");
			View::UInfoItem city         ("City"         , "", "", "");
			View::UInfoItem avatar       ("Avatar"       , "", "", "");
			View::UInfoItem photo        ("Photo"        , "", "", "");
			View::UInfoItem email        ("Email"        , "", "", "");
			View::UInfoItem comments     ("Comments"     , "", "", "");
			View::UInfoItem rights       ("Rights"       , "", "", "");

			View::UInfoItem menu_open   ("Open"   , "", "", "");
			View::UInfoItem menu_add_new("Add new", "", "", "");




			insert(UIBioLocation::ID_TXT_LOCATION_NAME, text);
			insert(UIBioUsersPage::ID_BTN_ADD_USER, btn_add_user);
			insert(UIBioFacePage::ID_PERSON_FACE_IMAGE, item_image);

			insert(UIBioUsersPage::ID_BIO_USERS_FIRST_NAME   , first_name   );
			insert(UIBioUsersPage::ID_BIO_USERS_LAST_NAME    , last_name    );
			insert(UIBioUsersPage::ID_BIO_USERS_DATE_OF_BIRTH, date_of_birth);
			insert(UIBioUsersPage::ID_BIO_USERS_GENDER       , gender       );
			insert(UIBioUsersPage::ID_BIO_USERS_COUNTRY      , country      );
			insert(UIBioUsersPage::ID_BIO_USERS_CITY         , city         );
			insert(UIBioUsersPage::ID_BIO_USERS_AVATAR       , avatar       );
			insert(UIBioUsersPage::ID_BIO_USERS_PHOTO        , photo        );
			insert(UIBioUsersPage::ID_BIO_USERS_EMAIL        , email        );
			insert(UIBioUsersPage::ID_BIO_USERS_COMMENTS     , comments     );
			insert(UIBioUsersPage::ID_BIO_USERS_RIGHTS       , rights       );

			insert(UIBioUsersPage::ID_BIO_USERS_MENU_OPEN   , menu_open     );
			insert(UIBioUsersPage::ID_BIO_USERS_MENU_ADD_NEW, menu_add_new  );

		}

	}
}