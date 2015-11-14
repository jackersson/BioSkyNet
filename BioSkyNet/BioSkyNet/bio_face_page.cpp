#include "stdafx.h"
#include "bio_face_page.hpp"

#include "bio_face_resource.hpp"
#include "bio_personal_resource.hpp"
#include "bio_resources.hpp"

#include "common_utils.hpp"
#include "bio_properties_utils.hpp"
#include "bio_list_model.hpp"

//#include "bio_profile_resource.hpp"



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

		void BioFacePage::onItemSelection(wxDataViewEvent& evt)
		{			
			/*int row = enrolled_photos_holder_->GetSelectedRow();

			auto pt = photo_items_.find(row);
			if (pt != photo_items_.end())
			{
				Data::BioPhotoItem item = pt->second;
				person_photo_->loadFromFile(item.photoPath());
			}*/

		}
	
		void BioFacePage::do_subscribe()
		{
			btn_enroll_from_camera_->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::onEnrollFromCamera  , this);
			btn_enroll_from_image_ ->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::onEnrollFromImage   , this);
			btn_face_delete_       ->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioFacePage::onSelectedFaceDelete, this);
			enrolled_photos_holder_->Bind(wxEVT_DATAVIEW_SELECTION_CHANGED, &BioFacePage::onItemSelection, this);
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
			Poco::SharedPtr<BioPersonalResource> settings_resource(new BioPersonalResource());


			CommonUtils utils;
			BioPropertiesUtils utils_property;

			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			wxBoxSizer* enrollment_sizer = new wxBoxSizer(wxVERTICAL);
			main_sizer->Add(enrollment_sizer, 2, wxALL | wxEXPAND, 5);

			wxPanel* enrollment_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition
				                                     , wxSize(-1, -1), wxTAB_TRAVERSAL | wxBORDER_THEME);

			enrollment_sizer->Add(enrollment_panel, 1, wxEXPAND, 5);

			wxBoxSizer* enroll_panel_sizer = new wxBoxSizer(wxVERTICAL);
			enrollment_panel->SetSizer(enroll_panel_sizer);

			wxBoxSizer* main_person_image_sizer = new wxBoxSizer(wxHORIZONTAL);
			enroll_panel_sizer->Add(main_person_image_sizer, 1, wxALL | wxEXPAND, 5);

			

			wxFlexGridSizer* grid_person_sizer = new wxFlexGridSizer(0,4,0,0);
			grid_person_sizer->AddGrowableCol(0, 2);
			grid_person_sizer->AddGrowableCol(1, 3);
			grid_person_sizer->AddGrowableCol(2, 2);
			grid_person_sizer->AddGrowableCol(3, 1);
			grid_person_sizer->AddGrowableRow(0, 2);

			main_person_image_sizer->Add(grid_person_sizer, 1, wxEXPAND, 5);

			//**************************** Person Image ****************************
			wxBoxSizer* left_person_image_sizer = new wxBoxSizer(wxVERTICAL);
			grid_person_sizer->Add(left_person_image_sizer, 1, wxALL | wxEXPAND, 5);
			
			wxBoxSizer* person_image_sizer = new wxBoxSizer(wxVERTICAL);
			grid_person_sizer->Add(person_image_sizer, 3, wxALL | wxEXPAND, 5);
			
			person_photo_ = utils.addFaceStreamer(ID_PERSON_FACE_IMAGE, *resource, this, person_image_sizer);


			wxBoxSizer* person_information_sizer = new wxBoxSizer(wxHORIZONTAL);
			grid_person_sizer->Add(person_information_sizer, 3, wxALL | wxEXPAND, 5);

			wxBoxSizer* right_person_image_sizer = new wxBoxSizer(wxVERTICAL);
			grid_person_sizer->Add(right_person_image_sizer, 0, wxALL | wxEXPAND, 5);

			wxPropertyGrid* person_information_ = new wxPropertyGrid(enrollment_panel, wxID_ANY, wxDefaultPosition, wxSize(-1, -1)
				, wxPG_SPLITTER_AUTO_CENTER | wxPG_BOLD_MODIFIED);

			person_information_sizer->Add(person_information_, 3, wxEXPAND, 5);

			
			natural_skin_color_  = utils_property.createProperty<wxBoolProperty>(ID_FACE_NATURAL_SKIN_COLOR
				                                                                  , *person_information_, *resource);											 
			gender_              = utils_property.createEnumPropertyWithChoises(ID_BIO_PERSON_GENDER
				                                                                 , *person_information_, *settings_resource);
			age_               	 = utils_property.createProperty<wxIntProperty>(ID_FACE_AGE
				                                                                 , *person_information_, *resource);											 
			glasses_          	 = utils_property.createProperty<wxBoolProperty>(ID_FACE_GLASSES
				                                                                  , *person_information_, *resource);											 
			resolution_        	 = utils_property.createProperty<wxStringProperty>(ID_FACE_RESOLURION
				                                                                    , *person_information_, *resource);
			ethnicity_         	 = utils_property.createEnumPropertyWithChoises(ID_BIO_PERSON_ETNICITY
				                                                                 , *person_information_, *settings_resource);
			sample_quality_      = utils_property.createProperty<wxFloatProperty>(ID_FACE_SAMPLE_QUALITY
				                                                                   , *person_information_, *resource);

			//*******************************************************************************************
		
			//*********************************** Persons photo holder sizer ****************************

			wxBoxSizer* persons_photo_holder_sizer = new wxBoxSizer(wxHORIZONTAL);
			main_sizer->Add(persons_photo_holder_sizer, 1, wxEXPAND, 5);

			enrolled_photos_holder_ = new wxDataViewCtrl( this, wxID_ANY, wxDefaultPosition
				                                              , wxSize(-1, -1), wxDV_ROW_LINES | wxDV_SINGLE);
/*

			wxListCtrl* lv = new wxListCtrl(this, wxID_ANY);*/

			//MyListModel* m_list_model = new MyListModel();
			//wxObjectDataPtr<MyListModel> m_list_model;
			//enrolled_photos_holder_->AssociateModel(m_list_model);



			// the various columns
		/*	enrolled_photos_holder_->AppendTextColumn("Photo pathway",		MyListModel::Col_EditableText, wxDATAVIEW_CELL_EDITABLE
			                                       	,	wxCOL_WIDTH_AUTOSIZE);*/

			/*enrolled_photos_holder_->AppendBitmapColumn( "bitmap", 	MyListModel::Col_IconText, wxDATAVIEW_CELL_EDITABLE
				                                           ,	wxCOL_WIDTH_AUTOSIZE);*/
		//	new wxDataViewTextRenderer
				//new wxDataViewDateRenderer
			//enrolled_photos_holder_->AppendColumn(new wxDataViewColumn("bitmap",  new wxDataViewBitmapRenderer
				//, MyListModel::Col_IconText));

			/*wxDataViewColumn* m_attributes = new wxDataViewColumn( "attributes",	new wxDataViewTextRenderer
				                                                   , MyListModel::Col_TextWithAttr, wxCOL_WIDTH_AUTOSIZE
																													 , wxALIGN_RIGHT,	wxDATAVIEW_COL_REORDERABLE | wxDATAVIEW_COL_RESIZABLE);
			enrolled_photos_holder_->AppendColumn(m_attributes);

			enrolled_photos_holder_->AppendColumn( new wxDataViewColumn("custom renderer", new MyCustomRenderer
				                                   , MyListModel::Col_Custom) );*/
				
		



			enrolled_photos_holder_->SetRowHeight(130);

			
			//first_name_ = utils_property.createTextColumn(ID_FACE_PAGE_NAME      , *enrolled_photos_holder_, *resource);
			//photo_path_ = utils_property.createTextColumn(ID_FACE_PAGE_PHOTO_PATH, *enrolled_photos_holder_, *resource);

			/*enrolled_photos_holder_->AppendBitmapColumn("Image", wxID_ANY, wxDATAVIEW_CELL_INERT, -1,	wxALIGN_CENTER);*/

		

			persons_photo_holder_sizer->Add(enrolled_photos_holder_, 12, wxRIGHT | wxTOP | wxEXPAND, 5);
			//persons_photo_holder_sizer->Add(lv, 12, wxRIGHT | wxTOP | wxEXPAND, 5);

	/*		wxImageList* ls = new wxImageList(128, 128, true);
			persons_photo_holder_sizer->Add(lv, 12, wxRIGHT | wxTOP | wxEXPAND, 5);
			wxImage im("1.bmp");
			if (im.IsOk())
			{
				im.Rescale(128, 128);
				wxBitmap bitmap(im, wxIMAGE_LIST_NORMAL);
				ls->Add(bitmap);		
			}
		
			lv->SetImageList(ls, 0);

			wxListItem itemCol;
			itemCol.SetText(wxT("Column 1"));
			itemCol.SetImage(-1);
			lv->InsertColumn(0, itemCol);

			wxListItem info;
			info.SetImage(0);
			info.SetId(0);
			info.SetColumn(0);
			lv->SetItem(info);

			lv->Show();*/
		

			wxBoxSizer* sizer_tools = new wxBoxSizer(wxVERTICAL);

			persons_photo_holder_sizer->Add(sizer_tools, 0, wxTOP | wxALIGN_RIGHT, 5);

			btn_enroll_from_camera_ = utils.addButton(ID_BTN_ENROLL_FROM_CAMERA , this, *resource, sizer_tools, 0);
			btn_enroll_from_image_  = utils.addButton(ID_BTN_ENROLL_FROM_IMAGE	, this, *resource, sizer_tools, 0);
			btn_face_delete_        = utils.addButton(ID_BTN_FACE_DELETE        , this, *resource, sizer_tools, 0);
						
			btn_face_delete_->Disable();

			this->Layout();
		}

		void BioFacePage::update(const  Data::BioPhotoItem& photo_item)
		{			
			natural_skin_color_  ->SetValue(photo_item.naturalSkinColor());
			gender_							 ->SetValue(photo_item.gender()          );
			age_								 ->SetValue(photo_item.age()             );
			glasses_						 ->SetValue(photo_item.glasses()         );
			resolution_					 ->SetValue(photo_item.resolution()      );
			ethnicity_					 ->SetValue(photo_item.etnicity()        );
		}




	}
}