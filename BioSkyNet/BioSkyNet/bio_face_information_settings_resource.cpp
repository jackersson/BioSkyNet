#include "stdafx.h"
#include "bio_face_information_settings_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{

		BioFaceInformationSettingsResource::BioFaceInformationSettingsResource()
		{
			initialize();
		}

		BioFaceInformationSettingsResource::~BioFaceInformationSettingsResource()	{}


		void BioFaceInformationSettingsResource::do_initialize()
		{

			View::USettingInfoItem number_of_faces		("Number of faces"			, "", "Number of faces"		, "", "", "");
			View::USettingInfoItem natural_skin_color	("Natural skin color"		, "", "Natural skin color", "", "", "");
			View::USettingInfoItem gender							("Gender"								, "", "Gender"						, "", "", "");
			View::USettingInfoItem age								("Age"									, "", "Age"								, "", "", "");
			View::USettingInfoItem glasses						("Glasses"							, "", "Glasses"						, "", "", "");
			View::USettingInfoItem resolution					("Resolution"						, "", "Resolution"				, "", "", "");
			View::USettingInfoItem ethnicity					("Ethnicity"						, "", "Ethnicity"					, "", "", "");













			insert(UIBioFaceInformationSettings::ID_FACE_INFORMATION_NUMBER_OF_FACES		, number_of_faces);
			insert(UIBioFaceInformationSettings::ID_FACE_INFORMATION_NATURAL_SKIN_COLOR	, natural_skin_color);
			insert(UIBioFaceInformationSettings::ID_FACE_INFORMATION_GENDER							, gender);
			insert(UIBioFaceInformationSettings::ID_FACE_INFORMATION_AGE								, age);
			insert(UIBioFaceInformationSettings::ID_FACE_INFORMATION_GLASSES						, glasses);
			insert(UIBioFaceInformationSettings::ID_FACE_INFORMATION_RESOLURION					, resolution);
			insert(UIBioFaceInformationSettings::ID_FACE_INFORMATION_ETHNICITY					, ethnicity);
																									






		}

	}
}


