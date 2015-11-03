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
			subscribe();
		}
		

		BioPersonalPage::~BioPersonalPage()
		{
			unsubscribe();
		}

		void BioPersonalPage::edit(wxCommandEvent& e)
		{
			wxMessageBox("Edit");
		}

		void BioPersonalPage::open(wxCommandEvent& e)
		{
			wxMessageBox("Open");
		}

		void BioPersonalPage::save(wxCommandEvent& e)
		{
			wxMessageBox("Save");
		}

		void BioPersonalPage::btn_delete(wxCommandEvent& e)
		{
			wxMessageBox("Delete");
		}

		//void do_initialize();
		void BioPersonalPage::do_subscribe()
		{
			btn_edit_		->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::edit, this);
			btn_open_		->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::open, this);
			btn_save_		->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::save, this);
			btn_delete_	->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::btn_delete, this);
		}

		void BioPersonalPage::do_unsubscribe()
		{
			btn_edit_		->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::edit, this);
			btn_open_		->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::open, this);
			btn_save_		->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::save, this);
			btn_delete_	->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::btn_delete, this);
		}							 



		void BioPersonalPage::do_create()
		{
			Poco::SharedPtr<BioProfileResource> resource(new BioProfileResource());

			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			wxBoxSizer* sizer_static_image = new wxBoxSizer(wxVERTICAL);
			main_sizer->Add(sizer_static_image, 0, wxALL | wxEXPAND, 5);

			bool flag(false);
			View::UInfoItem item = resource->get(UIBioProfilePage::ID_AVATAR, flag);

			person_photo_ = new wxStaticBitmap( this, wxID_ANY, item.bitmap(), wxDefaultPosition, wxSize( 128, 128) );
			person_photo_->SetHelpText("Person photo");
			sizer_static_image->Add(person_photo_, 1, wxEXPAND, 5);
			//wxBoxSizer* sizer_personal_properties = new wxBoxSizer(wxVERTICAL);
			//main_sizer->Add( sizer_static_image, 2, wxALL | wxEXPAND, 5);


			//BioPropertiesUtils utils;

			person_information_ = new wxPropertyGrid( this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1)
				                                       , wxPG_TOOLBAR | wxPG_SPLITTER_AUTO_CENTER | wxPG_BOLD_MODIFIED );

			//utils.createEnumProperty()
			wxStringProperty* first_name    = new wxStringProperty("First name");
			wxStringProperty* last_name     = new wxStringProperty("Last name", wxPG_LABEL);
			wxDateProperty*   date_of_birth = new wxDateProperty  ("Date of birth", wxPG_LABEL, wxDateTime::Now() );

			wxPGChoices chs;
			chs.Add("Male"     , 0);
			chs.Add("Female"   , 1);
			chs.Add("Undefined", 2);

			wxEnumProperty*   gender = new wxEnumProperty( "Gender", wxPG_LABEL, chs, 0 );

			wxStringProperty* country  = new wxStringProperty("Country", wxPG_LABEL);
			wxStringProperty* city     = new wxStringProperty("City", wxPG_LABEL);
			wxStringProperty* comments = new wxStringProperty("Comments", wxPG_LABEL);

			person_information_->Append(first_name   );
			person_information_->Append(last_name    );
			person_information_->Append(date_of_birth);
			person_information_->Append(gender);
			person_information_->Append(country);
			person_information_->Append(city);
			person_information_->Append(comments);

			wxBoxSizer* sizer_personal_properties = new wxBoxSizer(wxHORIZONTAL);
			main_sizer->Add(sizer_personal_properties, 1, wxALL | wxEXPAND, 5);
			sizer_personal_properties->Add(person_information_, 1, wxEXPAND, 5);


			wxBoxSizer* sizer_tools = new wxBoxSizer(wxVERTICAL);
			sizer_personal_properties->Add(sizer_tools, 0, wxALIGN_RIGHT, 5);


			btn_edit_		= addButton(ID_BTN_EDIT, this, *resource, sizer_tools);
			btn_open_		= addButton(ID_BTN_OPEN, this, *resource, sizer_tools);
			btn_save_		= addButton(ID_BTN_SAVE, this, *resource, sizer_tools);
			btn_delete_ = addButton(ID_BTN_DELETE, this, *resource, sizer_tools);


				this->Layout();
		}

		wxBitmapButton* BioPersonalPage::addButton(UIBioProfilePage index, wxWindow* parent, BioProfileResource& resource, wxBoxSizer* sizer)
		{
			bool flag(false);
			View::UInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxBitmapButton* btn = new wxBitmapButton(parent, wxID_ANY, item.bitmap());

				sizer->Add(btn, 0);

				return btn;
			}



		}
	}
}