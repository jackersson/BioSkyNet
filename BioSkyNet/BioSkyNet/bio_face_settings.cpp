#include "stdafx.h"
#include "bio_face_settings.hpp"

#include "bio_face_settings_resource.hpp"

#include "bio_resources.hpp"

#include "bio_properties_utils.hpp"

namespace SmartBio
{
	namespace View
	{

		BioFaceSettings::BioFaceSettings() : wxPropertyGridPage()
		{
			do_initialize();
		}

		BioFaceSettings::~BioFaceSettings() {}
		
		void BioFaceSettings::do_initialize()
		{			
			Poco::SharedPtr<BioFaceSettingsResource> resource(new BioFaceSettingsResource());

			BioPropertiesUtils utils;

			age_treshold_				= utils.createEnumProperty(ID_FACE_AGE_TRESHOLD				, *this, *resource);
			face_confidence_		= utils.createEnumProperty(ID_FACE_FACE_CONFIDENCE		, *this, *resource);
			min_eye_distance_		= utils.createEnumProperty(ID_FACE_MIN_EYE_DISTANCE		, *this, *resource);
		  max_eye_distance_		= utils.createEnumProperty(ID_FACE_MAX_EYE_DISTANCE		, *this, *resource);
			matching_treshold_	= utils.createEnumProperty(ID_FACE_MATCHING_TRESHOLD	, *this, *resource);
		}
	}
}