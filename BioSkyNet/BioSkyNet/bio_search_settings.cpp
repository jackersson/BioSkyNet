#include "stdafx.h"
#include "bio_search_settings.hpp"

#include "bio_search_settings_resource.hpp"

#include "bio_resources.hpp"

#include "bio_properties_utils.hpp"

namespace SmartBio
{
	namespace View
	{

		BioSearchSettings::BioSearchSettings() : wxPropertyGridPage()
		{
			do_initialize();
		}

		BioSearchSettings::~BioSearchSettings() {}

		void BioSearchSettings::do_initialize()
		{
			Poco::SharedPtr<BioSearchSettingsResource> resource(new BioSearchSettingsResource());
			BioPropertiesUtils utils;

			//TODO test view 
			category_person_information_ = new wxPropertyCategory("test1", wxPG_LABEL);//utils.createPropertyCategory(ID_SEARCH_SETTINGS_PERSON_INFORMATION, *this, *resource);
			Append(category_person_information_);
			property_date_from_ =  new wxEnumProperty("test12", wxPG_LABEL);
			AppendIn(category_person_information_, property_date_from_);
			property_date_to_ = new wxEnumProperty("test13", wxPG_LABEL); //utils.createEnumPropertyC(ID_SEARCH_SETTINGS_DATE_TO, *this, *resource);
			AppendIn(category_person_information_, property_date_to_);
			//firs_name_ = utils.createEnumProperty(ID_SEARCH_SETTINGS_FIRST_NAME, *this, *resource);
			//last_name_ = utils.createEnumProperty(ID_SEARCH_SETTINGS_LAST_NAME, *this, *resource);
		/*	today_										= utils.createEnumPropertyC	(ID_SEARCH_SETTINGS_TODAY									, *this, *resource);
			yesterday_								= utils.createEnumPropertyC	(ID_SEARCH_SETTINGS_YESTERDAY							, *this, *resource);
			last_week_								= utils.createEnumPropertyC	(ID_SEARCH_SETTINGS_LAST_WEEK							, *this, *resource);
			last_month_								= utils.createEnumPropertyC	(ID_SEARCH_SETTINGS_LAST_MONTH						, *this, *resource);*/

	




																													 									
		/*	location_									= utils.createPropertyCategory(ID_SEARCH_SETTINGS_LOCATION, *this, *resource);
			locations_								= utils.createEnumProperty(ID_SEARCH_SETTINGS_LOCATIONS								, *this, *resource);
																													 									
			person_information_				= utils.createPropertyCategory(ID_SEARCH_SETTINGS_PERSON_INFORMATION	, *this, *resource);
			firs_name_								= utils.createEnumProperty(ID_SEARCH_SETTINGS_FIRST_NAME							, *this, *resource);
			last_name_								= utils.createEnumProperty(ID_SEARCH_SETTINGS_LAST_NAME								, *this, *resource);
																													 									
			by_face_									= utils.createPropertyCategory(ID_SEARCH_SETTINGS_BY_FACE							, *this, *resource);
			by_face_age_							= utils.createEnumProperty(ID_SEARCH_SETTINGS_BY_FACE_AGE							, *this, *resource);
			by_face_image_						= utils.createEnumProperty(ID_SEARCH_SETTINGS_BY_FACE_IMEAGE					, *this, *resource);
			by_face_face_confidence_	= utils.createEnumProperty(ID_SEARCH_SETTINGS_BY_FACE_FACE_CONFIDENCE	, *this, *resource);*/




			
		
		}


	}
}