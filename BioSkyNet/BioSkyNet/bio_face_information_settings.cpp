#include "stdafx.h"
#include "bio_face_information_settings.hpp"

#include "bio_face_information_settings_resource.hpp"

#include "bio_resources.hpp"

#include "bio_properties_utils.hpp"

namespace SmartBio
{
	namespace View
	{

		BioFaceInformationSettings::BioFaceInformationSettings() : wxPropertyGridPage()
		{
			do_initialize();
		}

		BioFaceInformationSettings::~BioFaceInformationSettings() {}

		void BioFaceInformationSettings::do_initialize()
		{
			Poco::SharedPtr<BioFaceInformationSettingsResource> resource(new BioFaceInformationSettingsResource());
			
			BioPropertiesUtils utils;

			number_of_faces_		= utils.createEnumProperty(ID_FACE_INFORMATION_NUMBER_OF_FACES		, *this, *resource);
			natural_skin_color_ = utils.createEnumProperty(ID_FACE_INFORMATION_NATURAL_SKIN_COLOR	, *this, *resource);
			gender_							= utils.createEnumProperty(ID_FACE_INFORMATION_GENDER							, *this, *resource);
			age_								= utils.createEnumProperty(ID_FACE_INFORMATION_AGE								, *this, *resource);
			glasses_						= utils.createEnumProperty(ID_FACE_INFORMATION_GLASSES						, *this, *resource);
			image_resolution_		= utils.createEnumProperty(ID_FACE_INFORMATION_RESOLURION					, *this, *resource);
			ethnicity_					= utils.createEnumProperty(ID_FACE_INFORMATION_ETHNICITY					, *this, *resource);					
		}


	}
}