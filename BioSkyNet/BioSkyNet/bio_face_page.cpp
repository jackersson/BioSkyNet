#include "stdafx.h"
#include "bio_face_page.hpp"






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

		void BioFacePage::enrollFromCamera(wxCommandEvent& e)		
		{																									
			wxMessageBox("Enroll from camera");											
		}	

		void BioFacePage::enrollFromImage(wxCommandEvent& e)
		{
			wxMessageBox("Enroll from image");
		}

		void BioFacePage::faceDelete(wxCommandEvent& e)
		{
			wxMessageBox("Face delete");
		}
		
		//void do_initialize();
		void BioFacePage::do_subscribe()
		{
			btn_enroll_from_camera_->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::enrollFromCamera, this);
			btn_enroll_from_image_->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::enrollFromImage, this);
			btn_face_delete_->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::faceDelete, this);
		}

		void BioFacePage::do_unsubscribe()
		{
			btn_enroll_from_camera_->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::enrollFromCamera, this);
			btn_enroll_from_image_->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::enrollFromImage, this);
			btn_face_delete_->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::faceDelete, this);
		}



		void BioFacePage::do_create()
		{
			Poco::SharedPtr<BioFaceResource> resource(new BioFaceResource());

			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			wxBoxSizer* main_status_sizer = new wxBoxSizer(wxVERTICAL);
			main_sizer->Add(main_status_sizer, 0, wxALL | wxEXPAND, 5);

			wxPanel* status_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL | wxBORDER_THEME);

			main_status_sizer->Add(status_panel, 1, wxEXPAND, 5);

			wxBoxSizer* m_status_sizer = new wxBoxSizer(wxVERTICAL);
			status_panel->SetSizer(m_status_sizer);



			wxBoxSizer* sizer_static_image = new wxBoxSizer(wxVERTICAL);
			m_status_sizer->Add(sizer_static_image, 0, wxALL | wxEXPAND, 5);

			bool flag(false);

			person_photo_ = addImage(ID_FACE_AVATAR, this, *resource, sizer_static_image, wxALL | wxEXPAND);







			wxStaticBoxSizer* status_sizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Status")), wxVERTICAL);
			m_status_sizer->Add(status_sizer, 0, wxALL | wxEXPAND, 5);

			status_image_ = addImage(ID_STATUS_IMAGE, this, *resource, status_sizer, wxALL | wxALIGN_CENTER_HORIZONTAL);

			wxGauge* status_bar_ = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxSize(-1, -1), wxGA_HORIZONTAL);
			status_bar_->SetValue(10);

			status_sizer->Add(status_bar_, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);




			wxStaticBoxSizer* controll_sizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Controls")), wxHORIZONTAL);
			m_status_sizer->Add(controll_sizer, 0, wxALL | wxEXPAND, 5);

			wxBoxSizer* slider_sizer = new wxBoxSizer(wxHORIZONTAL);
			controll_sizer->Add(slider_sizer, 1, wxALL | wxALIGN_LEFT, 5);

			wxSlider* slider_ = new wxSlider(this, wxID_ANY, 50, 0, 100);

			slider_sizer->Add(slider_, 1, wxALL, 5);

			
			wxStaticText* zoom_text = new wxStaticText(this, wxID_ANY, _("Zoom: 50%"));

			slider_sizer->Add(zoom_text, 1, wxALL, 5);



			wxBoxSizer* check_box_sizer = new wxBoxSizer(wxVERTICAL);
			controll_sizer->Add(check_box_sizer, 1, wxALL |  wxALIGN_RIGHT, 5);

			wxCheckBox* check_box = new wxCheckBox(this, wxID_ANY, _("Fit image"));
			check_box->SetValue(false);

			check_box_sizer->Add(check_box, 1, wxALL | wxALIGN_RIGHT, 5);


















			wxBoxSizer* sizaer_photo_list = new wxBoxSizer(wxHORIZONTAL);
			main_sizer->Add(sizaer_photo_list, 1, wxEXPAND, 5);

			photo_holder_ = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxDV_ROW_LINES | wxDV_SINGLE);
			
			sizaer_photo_list->Add(photo_holder_, 12, wxRIGHT | wxTOP | wxEXPAND, 5);

			wxBoxSizer* sizer_tools = new wxBoxSizer(wxVERTICAL);

			sizaer_photo_list->Add(sizer_tools, 0, wxTOP | wxALIGN_RIGHT, 5);




			btn_enroll_from_camera_ = addButton(ID_BTN_ENROLL_FROM_CAMERA	, this, *resource, sizer_tools);
			btn_enroll_from_image_  = addButton(ID_BTN_ENROLL_FROM_IMAGE	, this, *resource, sizer_tools);
			btn_face_delete_        = addButton(ID_BTN_FACE_DELETE				, this, *resource, sizer_tools);


			this->Layout();
		}

		wxBitmapButton* BioFacePage::addButton(UIBioFacePage index, wxWindow* parent, BioFaceResource& resource, wxBoxSizer* sizer)
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

		wxStaticBitmap* BioFacePage::addImage(int index, wxWindow* parent
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