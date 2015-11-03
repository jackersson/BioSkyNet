#include "stdafx.h"
#include "bio_settings.hpp"


/*
#include "bio_general_settings.hpp"

#include "bio_face_settings.hpp"*/

#include "bio_grid_settings.hpp"

namespace SmartBio
{
	namespace View
	{
		BioSettings::BioSettings( wxWindow* parent, wxWindowID id )			                      
														: wxPanel(parent, id, wxDefaultPosition, wxSize(350, -1) )
		{
			create();
			subscribe();
		}

		BioSettings::~BioSettings()
		{
			unsubscribe();
		}

		void BioSettings::btApply(wxCommandEvent& e)
		{
			wxMessageBox("Apply");
		}

		void BioSettings::btOk(wxCommandEvent& e)
		{
			wxMessageBox("Ok");
		}

		void BioSettings::btResetToDefault(wxCommandEvent& e)
		{
			wxMessageBox("Delete");
		}

		void BioSettings::do_subscribe()
		{
			btn_apply_						->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::btApply, this);
			btn_ok_								->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::btOk		, this);
			btn_reset_to_default_	->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::btResetToDefault		, this);

		}
		void BioSettings::do_unsubscribe()
		{
			btn_apply_						->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::btApply, this);
			btn_ok_								->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::btOk		, this);
			btn_reset_to_default_->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::btResetToDefault, this);
		}


		void BioSettings::do_create()
		{	
			Poco::SharedPtr<BioSettingsResource> resource(new BioSettingsResource());


			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);			

			BioGridSettings* settings = new BioGridSettings(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxPG_TOOLBAR | wxPG_DESCRIPTION | wxPG_SPLITTER_AUTO_CENTER | wxPG_BOLD_MODIFIED);

			main_sizer->Add(settings, 7, wxALL | wxEXPAND, 5);

			wxBoxSizer* buttons_sizer = new wxBoxSizer(wxHORIZONTAL);
			main_sizer->Add(buttons_sizer, 1, wxALL | wxEXPAND, 5);

			
			btn_apply_							= addButton(ID_SETTINGS_BTN_APPLY						, this, *resource, buttons_sizer);
			btn_ok_									= addButton(ID_SETTINGS_BTN_OK							, this, *resource, buttons_sizer);
			btn_reset_to_default_		= addButton(ID_SETTINGS_BTN_RESET_TO_DEFAULT, this, *resource, buttons_sizer);
			
			/*//texts = new Texts::BioSettingsTexts();
			//wxInfoBar* infobar = new wxInfoBar()


			

			AddPage("General settings", wxArtProvider::GetBitmap(wxART_QUESTION), new BioGeneralSettings(  ));
			AddPage("Face settings", wxArtProvider::GetBitmap(wxART_FILE_OPEN), new BioFaceSettings());*/

			this->Layout();
		};

		wxBitmapButton* BioSettings::addButton(UIBioSettings index, wxWindow* parent, BioSettingsResource& resource, wxBoxSizer* sizer)
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


		wxStaticBitmap* BioSettings::addImage(int index, wxWindow* parent
			, BioControlResource<UInfoItem>& resource, wxSizer* sizer, int style)
		{
			bool flag(false);
			View::UInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxStaticBitmap* img = new wxStaticBitmap(parent, wxID_ANY, item.bitmap(), wxDefaultPosition, wxSize(-1, -1), 0);

				sizer->Add(img, 1, style, 5);

				return img;
			}
		}

	}
}