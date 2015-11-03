#include "stdafx.h"
#include "bio_face_settings_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{

		BioFaceSettingsResource::BioFaceSettingsResource()
		{
			initialize();
		}

		BioFaceSettingsResource::~BioFaceSettingsResource()	{}


		void BioFaceSettingsResource::do_initialize()
		{
			View::USettingInfoItem age_treshold			("Age treshold"			, "", "Age treshold"			, "", "", "");
			View::USettingInfoItem face_confidence	("Face confidence"	, "", "Face confidence"		, "", "", "");
			View::USettingInfoItem min_eye_distance	("Min eye distance"	, "", "Min eye distance"	, "", "", "");
			View::USettingInfoItem max_eye_distance	("Max eye distance"	, "", "Max eye distance"	, "", "", "");
			View::USettingInfoItem matching_treshold("Matching treshold", "", "Matching treshold"	, "", "", "");
			
			insert(UIBioFaceSettings::ID_FACE_AGE_TRESHOLD			, age_treshold     );
			insert(UIBioFaceSettings::ID_FACE_FACE_CONFIDENCE		, face_confidence  );
			insert(UIBioFaceSettings::ID_FACE_MIN_EYE_DISTANCE	, min_eye_distance );
			insert(UIBioFaceSettings::ID_FACE_MAX_EYE_DISTANCE	, max_eye_distance );
			insert(UIBioFaceSettings::ID_FACE_MATCHING_TRESHOLD	, matching_treshold);
		}

	}
}


