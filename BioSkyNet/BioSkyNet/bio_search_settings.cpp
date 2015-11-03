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






			//date_time_								= utils.createPropertyCategory		(ID_SEARCH_SETTINGS_DATE_TIME				, *this, *resource);
			//date_from_ =  new wxEnumProperty("test1", wxPG_LABEL);
			//AppendIn(date_time_, date_from_);
				//utils.createEnumPropertyC	(ID_SEARCH_SETTINGS_DATE_FROM							, *this, *resource);
			//date_to_ 									= utils.createEnumPropertyC	(ID_SEARCH_SETTINGS_DATE_TO								, *this, *resource);
			//AppendIn(date_time_, date_to_);

			person_information_ = new wxPropertyCategory("test1", wxPG_LABEL);//utils.createPropertyCategory(ID_SEARCH_SETTINGS_PERSON_INFORMATION, *this, *resource);
			Append(person_information_);
			date_from_ =  new wxEnumProperty("test12", wxPG_LABEL);
			AppendIn(person_information_, date_from_);
			date_to_ = new wxEnumProperty("test13", wxPG_LABEL); //utils.createEnumPropertyC(ID_SEARCH_SETTINGS_DATE_TO, *this, *resource);
			AppendIn(person_information_, date_to_);
			//firs_name_ = utils.createEnumProperty(ID_SEARCH_SETTINGS_FIRST_NAME, *this, *resource);
			//last_name_ = utils.createEnumProperty(ID_SEARCH_SETTINGS_LAST_NAME, *this, *resource);
		/*	today_										= utils.createEnumPropertyC	(ID_SEARCH_SETTINGS_TODAY									, *this, *resource);
			yesterday_								= utils.createEnumPropertyC	(ID_SEARCH_SETTINGS_YESTERDAY							, *this, *resource);
			last_week_								= utils.createEnumPropertyC	(ID_SEARCH_SETTINGS_LAST_WEEK							, *this, *resource);
			last_month_								= utils.createEnumPropertyC	(ID_SEARCH_SETTINGS_LAST_MONTH						, *this, *resource);*/

			//this->AppendIn(date_from_,date_time_);
			//this->AppendIn(date_to_, date_time_);
			//this->AppendIn(1, date_from_);
			//this->AppendIn(2, date_to_);




																													 									
		/*	location_									= utils.createPropertyCategory(ID_SEARCH_SETTINGS_LOCATION, *this, *resource);
			locations_								= utils.createEnumProperty(ID_SEARCH_SETTINGS_LOCATIONS								, *this, *resource);
																													 									
			person_information_				= utils.createPropertyCategory(ID_SEARCH_SETTINGS_PERSON_INFORMATION	, *this, *resource);
			firs_name_								= utils.createEnumProperty(ID_SEARCH_SETTINGS_FIRST_NAME							, *this, *resource);
			last_name_								= utils.createEnumProperty(ID_SEARCH_SETTINGS_LAST_NAME								, *this, *resource);
																													 									
			by_face_									= utils.createPropertyCategory(ID_SEARCH_SETTINGS_BY_FACE							, *this, *resource);
			by_face_age_							= utils.createEnumProperty(ID_SEARCH_SETTINGS_BY_FACE_AGE							, *this, *resource);
			by_face_image_						= utils.createEnumProperty(ID_SEARCH_SETTINGS_BY_FACE_IMEAGE					, *this, *resource);
			by_face_face_confidence_	= utils.createEnumProperty(ID_SEARCH_SETTINGS_BY_FACE_FACE_CONFIDENCE	, *this, *resource);*/




			/*std::string matching_threshold = texts_->get(UIBioSettings::ID_MATCHING_THRESHOLD);
			std::string max_result_count = texts_->get(UIBioSettings::ID_MAXIMAL_RESULT_COUNT);
			std::string matching_details = texts_->get(UIBioSettings::ID_RETURN_MATCHING_DETAILS);
			std::string first_result_only = texts_->get(UIBioSettings::ID_MATCHING_FIRST_RESULT_ONLY);

			wxPGChoices chs;
			chs.Add("Normal", 99);
			chs.Add("Low", 9);
			chs.Add("Medium", 999);
			chs.Add("High", 9999);

			wxEnumProperty* p_matching_threshold = new wxEnumProperty(matching_threshold, wxPG_LABEL, chs, 99);
			p_matching_threshold->SetHelpString(texts_->get(UIBioSettings::ID_MATCHING_THRESHOLD_HINT));

			wxPGChoices chs22;

			chs22.Add("10", 10);
			chs22.Add("20", 20);
			chs22.Add("50", 50);
			chs22.Add("100", 100);
			chs22.Add("200", 200);
			chs22.Add("500", 500);
			chs22.Add("1000", 1000);

			wxEnumProperty* p_max_result_count = new wxEnumProperty(max_result_count, wxPG_LABEL, chs22, 50);
			p_max_result_count->SetHelpString(texts_->get(UIBioSettings::ID_MAXIMAL_RESULT_COUNT_HINT));

			wxSpinCtrl* sp;
			wxPGEditor* ed = new wxPGEditor();
			wxPropertyGrid::RegisterEditorClass(sp)

			wxBoolProperty* p_matching_details = new wxBoolProperty(matching_details, wxPG_LABEL, true);
			p_matching_details->SetEditor(wxPGEditor_CheckBox);
			p_matching_details->SetHelpString(texts_->get(UIBioSettings::ID_RETURN_MATCHING_DETAILS_HINT));

			wxBoolProperty* p_first_result_only = new wxBoolProperty(first_result_only, wxPG_LABEL, false);
			p_first_result_only->SetEditor(wxPGEditor_CheckBox);
			p_first_result_only->SetHelpString(texts_->get(UIBioSettings::ID_MATCHING_FIRST_RESULT_ONLY_HINT));

			Append(p_matching_threshold);*/
			//Append(p_max_result_count);
			//Append(p_matching_details);
			//Append(p_first_result_only);
		
		}


	}
}