#include "stdafx.h"
#include "bio_search_settings_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{

		BioSearchSettingsResource::BioSearchSettingsResource()
		{
			initialize();
		}

		BioSearchSettingsResource::~BioSearchSettingsResource()	{}


		void BioSearchSettingsResource::do_initialize()
		{

			View::USettingInfoItem date_time							("Date time"		      , "", "Date time"		      , "", "", "");
			View::USettingInfoItem date_from							("Date from"		      , "", "Date from"		      , "", "", "");
			View::USettingInfoItem date_to								("Date to"			      , "", "Date to"			      , "", "", "");
			View::USettingInfoItem today									("Today"				      , "", "Today"				      , "", "", "");
			View::USettingInfoItem yesterday							("Yesterday"		      , "", "Yesterday"		      , "", "", "");
			View::USettingInfoItem last_week							("Last week"		      , "", "Last week"		      , "", "", "");
			View::USettingInfoItem last_month							("Last month"		      , "", "Last month"		    , "", "", "");
																																		      										      
			View::USettingInfoItem location								("Location"			      , "", "Location"			    , "", "", "");
			View::USettingInfoItem locations							("Locations"		      , "", "Locations"		      , "", "", "");

			View::USettingInfoItem person_information			("Person_information"	, "", "Person_information", "", "", "");
			View::USettingInfoItem firs_name							("First name"					, "", "First name"				, "", "", "");
			View::USettingInfoItem last_name							("Last name"					, "", "Last name"					, "", "", "");

			View::USettingInfoItem by_face								("By face"					  , "", "By face"					  , "", "", "");
			View::USettingInfoItem by_face_age						("Age"							  , "", "Age"							  , "", "", "");
			View::USettingInfoItem by_face_image					("Image"						  , "", "Image"						  , "", "", "");
			View::USettingInfoItem by_face_face_confidence("Face confidence"	  , "", "Face confidence"	  , "", "", "");

			





			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_DATE_TIME							, date_time);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_DATE_FROM							, date_from);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_DATE_TO								, date_to);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_TODAY									, today);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_YESTERDAY							, yesterday);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_LAST_WEEK							, last_week);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_LAST_MONTH							, last_month);
																										
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_LOCATION								, location);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_LOCATIONS							, locations);
																										
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_PERSON_INFORMATION			, person_information);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_FIRST_NAME							, firs_name);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_LAST_NAME							, last_name);
																										
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_BY_FACE								, by_face);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_BY_FACE_AGE						, by_face_age);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_BY_FACE_IMEAGE					, by_face_image);
			insert(UIBioSearchSettings::ID_SEARCH_SETTINGS_BY_FACE_FACE_CONFIDENCE, by_face_face_confidence);




		}

	}
}


