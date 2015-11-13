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
			View::UInfoItem btn_add_user ("", "Add user" , "resources\\profile\\add_user.png" , "");
			View::UInfoItem btn_refresh  ("", "Refresh"  , "resources\\profile\\refresh.png"  , "");
			View::UInfoItem btn_open     ("", "Open"     , "resources\\profile\\open.png"     , "");
			View::UInfoItem btn_save     ("", "Save"     , "resources\\profile\\save.png"     , "");
			View::UInfoItem btn_delete   ("", "Delete"   , "resources\\profile\\delete.png"   , "");
			View::UInfoItem avatar       ("", "Avatar"   , "resources\\profile\\avatar.png"   , "");
			View::UInfoItem first_name   ("First Name *", "", "", "")	;
			View::UInfoItem last_name    ("Last Name *", "", "", "")	;
			View::UInfoItem date_of_birth("Date of birth *", "", "", "")	;
			View::UInfoItem country      ("Country *", "", "", "")	;
			View::UInfoItem city         ("City *", "", "", "")	;
			View::UInfoItem comments     ("Comments", "", "", "")	;
			View::UInfoItem email        ("Email", "", "", "")	;

			
			insert(UIBioProfilePage::ID_BTN_PROFILE_ADD_USER    , btn_add_user );
			insert(UIBioProfilePage::ID_BTN_REFRESH             , btn_refresh  );
			insert(UIBioProfilePage::ID_BTN_OPEN                , btn_open     );
			insert(UIBioProfilePage::ID_BTN_SAVE                , btn_save     );
			insert(UIBioProfilePage::ID_BTN_DELETE              , btn_delete   );
			insert(UIBioProfilePage::ID_AVATAR                  , avatar       );
			insert(UIBioProfilePage::ID_BIO_PERSON_FIRST_NAME   , first_name   );
			insert(UIBioProfilePage::ID_BIO_PERSON_LAST_NAME    , last_name    );
			insert(UIBioProfilePage::ID_BIO_PERSON_DATE_OF_BIRTH, date_of_birth);
			insert(UIBioProfilePage::ID_BIO_PERSON_COUNTRY      , country      );
			insert(UIBioProfilePage::ID_BIO_PERSON_CITY         , city         );
			insert(UIBioProfilePage::ID_BIO_PERSON_COMMENTS     , comments     );
			insert(UIBioProfilePage::ID_BIO_PERSON_EMAIL        , email        );


		}

	}
}