#include "stdafx.h"
#include "bio_face_settings.hpp"

#include "bio_resources.hpp"
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