#include "stdafx.h"
#include "bio_personal_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{

		BioPersonalResource::BioPersonalResource()
		{
			initialize();
		}

		BioPersonalResource::~BioPersonalResource()	{}

		void BioPersonalResource::do_initialize()
		{
			View::USettingInfoItem gender_property   ("Gender"  , "Male,Female,Undefined"      );
			View::USettingInfoItem rights_property   ("Rights"  , "Manager,Superviser,Operator");
			View::USettingInfoItem ethnicity_property("Etnicity", "Black,Asian,White"          );



			insert(UIBioProfilePage::ID_BIO_PERSON_GENDER   , gender_property   );
			insert(UIBioProfilePage::ID_BIO_PERSON_RIGTS    , rights_property   );
			insert(UIBioProfilePage::ID_BIO_PERSON_ETNICITY , ethnicity_property);


	
		}

	}
}