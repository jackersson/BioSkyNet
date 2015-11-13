#include "stdafx.h"
#include "bio_settings.hpp"


#include "bio_resources.hpp"
#include "bio_settings_resource.hpp"


#include "bio_grid_settings.hpp"

#include "common_utils.hpp"

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

		void BioSettings::onBtnApplyClick(wxCommandEvent& )
		{
			wxMessageBox("Apply");
		}

		void BioSettings::onBtnOkClick(wxCommandEvent& )
		{
			wxMessageBox("Ok");
		}

		void BioSettings::onBtnResetToDefaultClick(wxCommandEvent& )
		{
			wxMessageBox("Delete");
		}

		void BioSettings::do_subscribe()
		{
			btn_apply_						->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::onBtnApplyClick         , this);
			btn_ok_								->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::onBtnOkClick		         , this);
			btn_reset_to_default_	->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::onBtnResetToDefaultClick, this);

		}
		void BioSettings::do_unsubscribe()
		{
			btn_apply_					 ->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::onBtnApplyClick         , this);
			btn_ok_							 ->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::onBtnOkClick		          , this);
			btn_reset_to_default_->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioSettings::onBtnResetToDefaultClick, this);
		}


		void BioSettings::do_create()
		{	
			Poco::SharedPtr<BioSettingsResource> resource(new BioSettingsResource());
			CommonUtils utils;

			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);			

			BioGridSettings* settings = new BioGridSettings( this, wxID_ANY, wxDefaultPosition, wxSize(100, 100)
				                                             , wxPG_TOOLBAR | wxPG_DESCRIPTION 
																										 | wxPG_SPLITTER_AUTO_CENTER | wxPG_BOLD_MODIFIED);

			settings->Init();

			main_sizer->Add(settings, 7, wxALL | wxEXPAND, 5);

			wxBoxSizer* tools_sizer = new wxBoxSizer(wxHORIZONTAL);
			main_sizer->Add(tools_sizer, 1, wxALL | wxEXPAND, 5);

			
			btn_apply_							= utils.addButton(ID_SETTINGS_BTN_APPLY						, this, *resource, tools_sizer, 0);
			btn_ok_									= utils.addButton(ID_SETTINGS_BTN_OK							, this, *resource, tools_sizer, 0);
			btn_reset_to_default_		= utils.addButton(ID_SETTINGS_BTN_RESET_TO_DEFAULT, this, *resource, tools_sizer, 0);
						

			this->Layout();
		};		

	}
}