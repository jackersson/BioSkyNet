#include "stdafx.h"
#include "bio_face_page.hpp"

#include "bio_face_resource.hpp"
#include "bio_resources.hpp"

#include "common_utils.hpp"

namespace SmartBio
{
	namespace View
	{
		BioFacePage::BioFacePage(wxWindow* parent, wxWindowID id) : wxPanel(parent, id)
		{
			create();
			subscribe();
		}

		BioFacePage::~BioFacePage()
		{
			unsubscribe();
		}

		void BioFacePage::onEnrollFromCamera(wxCommandEvent& )		
		{																									
			wxMessageBox("Enroll from camera");											
		}	

		void BioFacePage::onEnrollFromImage(wxCommandEvent& )
		{
			wxMessageBox("Enroll from image");
		}

		void BioFacePage::onSelectedFaceDelete(wxCommandEvent&)
		{
			wxMessageBox("Face delete");
		}
		
		//void do_initialize();
		void BioFacePage::do_subscribe()
		{
			btn_enroll_from_camera_->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::onEnrollFromCamera  , this);
			btn_enroll_from_image_ ->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::onEnrollFromImage   , this);
			btn_face_delete_       ->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::onSelectedFaceDelete, this);
		}

		void BioFacePage::do_unsubscribe()
		{
			btn_enroll_from_camera_->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::onEnrollFromCamera  , this);
			btn_enroll_from_image_ ->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::onEnrollFromImage   , this);
			btn_face_delete_       ->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::onSelectedFaceDelete, this);
		}

		void BioFacePage::do_create()
		{
			Poco::SharedPtr<BioFaceResource> resource(new BioFaceResource());
			CommonUtils utils;

			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			wxBoxSizer* enrollment_sizer = new wxBoxSizer(wxVERTICAL);
			main_sizer->Add(enrollment_sizer, 0, wxALL | wxEXPAND, 5);

			wxPanel* enrollment_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition
				                                     , wxSize(-1, -1), wxTAB_TRAVERSAL | wxBORDER_THEME);

			enrollment_sizer->Add(enrollment_panel, 1, wxEXPAND, 5);

			wxBoxSizer* enroll_panel_sizer = new wxBoxSizer(wxVERTICAL);
			enrollment_panel->SetSizer(enroll_panel_sizer);

			//**************************** Person Image ****************************
			wxBoxSizer* person_image_sizer = new wxBoxSizer(wxVERTICAL);
			enroll_panel_sizer->Add(person_image_sizer, 0, wxALL | wxEXPAND, 5);

			person_photo_ = utils.addImage( ID_PERSON_FACE_IMAGE, this, *resource
				                            , person_image_sizer, wxALL | wxEXPAND);

			//**********************************************************************


			//**************************** Enrollment status ****************************
			//TODO create resource file
			wxStaticBoxSizer* entollment_status_sizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY
				                                                                              , _("Status"))
				                                                                              , wxVERTICAL);

			enroll_panel_sizer->Add(entollment_status_sizer, 0, wxALL | wxEXPAND, 5);

			enroll_status_image_ = utils.addImage( ID_STATUS_IMAGE, this, *resource
				                                   , entollment_status_sizer, wxALL | wxALIGN_CENTER_HORIZONTAL);

			wxGauge* status_bar_ = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxSize(-1, -1), wxGA_HORIZONTAL);
			status_bar_->SetValue(0);

			entollment_status_sizer->Add(status_bar_, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

			//**************************************************************************************************

			//*********************************************** Enrollment Image Controls (Zoom, Fit) ********
			wxStaticBoxSizer* enrol_image_controls_sizer = new wxStaticBoxSizer(new wxStaticBox( this, wxID_ANY
				                                                                      , _("Controls"))
																																						  , wxHORIZONTAL);
			enroll_panel_sizer->Add(enrol_image_controls_sizer, 0, wxALL | wxEXPAND, 5);

			wxBoxSizer* slider_sizer = new wxBoxSizer(wxHORIZONTAL);
			enrol_image_controls_sizer->Add(slider_sizer, 1, wxALL | wxALIGN_LEFT, 5);

			wxSlider* slider_ = new wxSlider(this, wxID_ANY, 50, 0, 100);

			slider_sizer->Add(slider_, 1, wxALL, 5);

			wxStaticText* zoom_text = new wxStaticText(this, wxID_ANY, _("Zoom: 50%"));

			slider_sizer->Add(zoom_text, 1, wxALL, 5);
			
			wxBoxSizer* check_box_sizer = new wxBoxSizer(wxVERTICAL);
			enrol_image_controls_sizer->Add(check_box_sizer, 1, wxALL |  wxALIGN_RIGHT, 5);

			wxCheckBox* check_box = new wxCheckBox(this, wxID_ANY, _("Fit image"));
			check_box->SetValue(false);

			check_box_sizer->Add(check_box, 1, wxALL | wxALIGN_RIGHT, 5);

			//*******************************************************************************************

			//*********************************** Persons photo holder sizer ****************************

			wxBoxSizer* persons_photo_holder_sizer = new wxBoxSizer(wxHORIZONTAL);
			main_sizer->Add(persons_photo_holder_sizer, 1, wxEXPAND, 5);

			enrolled_photos_holder_ = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition
				                                              , wxSize(-1, -1), wxDV_ROW_LINES | wxDV_SINGLE);
			
			persons_photo_holder_sizer->Add(enrolled_photos_holder_, 12, wxRIGHT | wxTOP | wxEXPAND, 5);

			wxBoxSizer* sizer_tools = new wxBoxSizer(wxVERTICAL);

			persons_photo_holder_sizer->Add(sizer_tools, 0, wxTOP | wxALIGN_RIGHT, 5);

			btn_enroll_from_camera_ = utils.addButton(ID_BTN_ENROLL_FROM_CAMERA, this, *resource, sizer_tools);
			btn_enroll_from_image_  = utils.addButton(ID_BTN_ENROLL_FROM_IMAGE	, this, *resource, sizer_tools);
			btn_face_delete_        = utils.addButton(ID_BTN_FACE_DELETE, this, *resource, sizer_tools);

			this->Layout();
		}		
	}
}