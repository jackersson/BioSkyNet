#include "stdafx.h"
#include "bio_personal_page.hpp"

//#include "bio_person.hpp"

//#include "bio_properties_utils.hpp"

namespace SmartBio
{
	namespace View
	{
		BioPersonalPage::BioPersonalPage(wxWindow* parent, wxWindowID id) : wxPanel(parent, id)
		{
			create();
		}

		BioPersonalPage::~BioPersonalPage()
		{

		}

		void BioPersonalPage::do_create()
		{
			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			wxBoxSizer* sizer_static_image = new wxBoxSizer(wxVERTICAL);
			main_sizer->Add(sizer_static_image, 0, wxALL | wxEXPAND, 5);

			person_photo_ = new wxStaticBitmap( this, wxID_ANY, wxArtProvider::GetBitmap( wxART_ERROR ), wxDefaultPosition, wxSize( 128, 128) );
			person_photo_->SetHelpText("Person photo");
			sizer_static_image->Add(person_photo_, 1, wxEXPAND, 5);
			//wxBoxSizer* sizer_personal_properties = new wxBoxSizer(wxVERTICAL);
			//main_sizer->Add( sizer_static_image, 2, wxALL | wxEXPAND, 5);


			//BioPropertiesUtils utils;

			person_information_ = new wxPropertyGrid( this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1)
				                                       , wxPG_TOOLBAR | wxPG_SPLITTER_AUTO_CENTER | wxPG_BOLD_MODIFIED );

			//utils.createEnumProperty()
			wxStringProperty* first_name    = new wxStringProperty("First name", wxPG_LABEL);
			wxStringProperty* last_name     = new wxStringProperty("Last name", wxPG_LABEL);
			wxDateProperty*   date_of_birth = new wxDateProperty  ("Date of birth", wxPG_LABEL, wxDateTime::Now() );

			wxPGChoices chs;
			//chs.Add("Male"     , Gender::Male);
			//chs.Add("Female"   , Gender::Female);
			//chs.Add("Undefined", Gender::Undefined);

			//wxEnumProperty*   gender = new wxEnumProperty( "Gender", wxPG_LABEL, chs, Gender::Male );

			wxStringProperty* country  = new wxStringProperty("Country", wxPG_LABEL);
			wxStringProperty* city     = new wxStringProperty("City", wxPG_LABEL);
			wxStringProperty* comments = new wxStringProperty("Comments", wxPG_LABEL);

			person_information_->Append(first_name   );
			person_information_->Append(last_name    );
			person_information_->Append(date_of_birth);
			//person_information_->Append(gender);
			person_information_->Append(country);
			person_information_->Append(city);
			person_information_->Append(comments);

			wxBoxSizer* sizer_personal_properties = new wxBoxSizer(wxVERTICAL);
			main_sizer->Add(sizer_personal_properties, 1, wxALL | wxEXPAND, 5);
			sizer_personal_properties->Add(person_information_, 1, wxEXPAND, 5);


			wxBoxSizer* sizer_tools = new wxBoxSizer(wxHORIZONTAL);
			sizer_personal_properties->Add(sizer_tools, 0, wxALIGN_RIGHT, 5);

			wxBitmapButton* btn_edit   = new wxBitmapButton(this, wxID_ANY, wxArtProvider::GetBitmap(wxART_FILE_OPEN));
			wxBitmapButton* btn_save   = new wxBitmapButton(this, wxID_ANY, wxArtProvider::GetBitmap(wxART_FILE_OPEN));
			wxBitmapButton* btn_delete = new wxBitmapButton(this, wxID_ANY, wxArtProvider::GetBitmap(wxART_FILE_OPEN));
			sizer_tools->Add( btn_edit, 0 );
			sizer_tools->Add( btn_save, 0);
			sizer_tools->Add( btn_delete, 0);
			this->Layout();
		}
	}
}