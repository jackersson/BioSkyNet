#include "stdafx.h"
#include "bio_face_page.hpp"

#include "bio_face_resource.hpp"
#include "bio_resources.hpp"

#include "common_utils.hpp"
#include "bio_properties_utils.hpp"

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

			person_photo_ = new wxBioFaceStreamer(this, ID_PERSON_FACE_IMAGE);

			person_image_sizer->Add(person_photo_, 1, wxALL | wxEXPAND, 5);



			wxBoxSizer* person_information_sizer = new wxBoxSizer(wxHORIZONTAL);
			grid_person_sizer->Add(person_information_sizer, 3, wxALL | wxEXPAND, 5);

			wxBoxSizer* right_person_image_sizer = new wxBoxSizer(wxVERTICAL);
			grid_person_sizer->Add(right_person_image_sizer, 0, wxALL | wxEXPAND, 5);

			wxPropertyGrid* person_information_ = new wxPropertyGrid(enrollment_panel, wxID_ANY, wxDefaultPosition, wxSize(-1, -1)
				, wxPG_SPLITTER_AUTO_CENTER | wxPG_BOLD_MODIFIED);

			person_information_sizer->Add(person_information_, 3, wxEXPAND, 5);

			
			natural_skin_color_  = utils_property.createProperty<wxStringProperty>(ID_FACE_NATURAL_SKIN_COLOR
				                                                        , *person_information_, *resource);											 
			gender_            	 = utils_property.createProperty<wxStringProperty>(ID_FACE_GENDER
				                                                        , *person_information_, *resource);											 
			age_               	 = utils_property.createProperty<wxStringProperty>(ID_FACE_AGE
				                                                        , *person_information_, *resource);											 
			glasses_          	 = utils_property.createProperty<wxStringProperty>(ID_FACE_GLASSES
				                                                        , *person_information_, *resource);											 
			resolution_        	 = utils_property.createProperty<wxStringProperty>(ID_FACE_RESOLURION
				                                                        , *person_information_, *resource);
			ethnicity_         	 = utils_property.createProperty<wxStringProperty>(ID_FACE_ETHNICITY
				                                                        , *person_information_, *resource);

			//*******************************************************************************************
		
			//*********************************** Persons photo holder sizer ****************************

			wxBoxSizer* persons_photo_holder_sizer = new wxBoxSizer(wxHORIZONTAL);
			main_sizer->Add(persons_photo_holder_sizer, 1, wxEXPAND, 5);

			enrolled_photos_holder_ = new wxDataViewCtrl( this, wxID_ANY, wxDefaultPosition
				                                              , wxSize(-1, -1), wxDV_ROW_LINES | wxDV_SINGLE);
/*

			wxListCtrl* lv = new wxListCtrl(this, wxID_ANY);*/

			MyListModel* m_list_model = new MyListModel();
			//wxObjectDataPtr<MyListModel> m_list_model;
			enrolled_photos_holder_->AssociateModel(m_list_model);



			// the various columns
		/*	enrolled_photos_holder_->AppendTextColumn("Photo pathway",		MyListModel::Col_EditableText, wxDATAVIEW_CELL_EDITABLE
			                                       	,	wxCOL_WIDTH_AUTOSIZE);*/

			enrolled_photos_holder_->AppendBitmapColumn( "bitmap", 	MyListModel::Col_IconText, wxDATAVIEW_CELL_EDITABLE
				                                           ,	wxCOL_WIDTH_AUTOSIZE);

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



		static int my_sort_reverse(int *v1, int *v2)
		{
			return *v2 - *v1;
		}

		static int my_sort(int *v1, int *v2)
		{
			return *v1 - *v2;
		}

#define INITIAL_NUMBER_OF_ITEMS 10000

		MyListModel::MyListModel() :
			wxDataViewVirtualListModel(INITIAL_NUMBER_OF_ITEMS)
		{
			// the first 100 items are really stored in this model;
			// all the others are synthesized on request
			static const unsigned NUMBER_REAL_ITEMS = 100;

			m_textColValues.reserve(NUMBER_REAL_ITEMS);
			m_textColValues.push_back("first row with long label to test ellipsization");
			for (unsigned int i = 1; i < NUMBER_REAL_ITEMS; i++)
			{
				m_textColValues.push_back(wxString::Format("real row %d", i));
			}

		/*	m_iconColValues.assign(NUMBER_REAL_ITEMS, "test");*/

		/*	m_icon[0] = wxIcon(null_xpm);
			m_icon[1] = wxIcon(wx_small_xpm);*/
		}

		void MyListModel::Prepend(const wxString &text)
		{
			m_textColValues.Insert(text, 0);
			RowPrepended();
		}

		void MyListModel::DeleteItem(const wxDataViewItem &item)
		{
			unsigned int row = GetRow(item);

			if (row >= m_textColValues.GetCount())
				return;

			m_textColValues.RemoveAt(row);
			RowDeleted(row);
		}

		void MyListModel::DeleteItems(const wxDataViewItemArray &items)
		{
			unsigned i;
			wxArrayInt rows;
			for (i = 0; i < items.GetCount(); i++)
			{
				unsigned int row = GetRow(items[i]);
				if (row < m_textColValues.GetCount())
					rows.Add(row);
			}

			if (rows.GetCount() == 0)
			{
				// none of the selected items were in the range of the items
				// which we store... for simplicity, don't allow removing them
				wxLogError("Cannot remove rows with an index greater than %d", m_textColValues.GetCount());
				return;
			}

			// Sort in descending order so that the last
			// row will be deleted first. Otherwise the
			// remaining indeces would all be wrong.
			rows.Sort(my_sort_reverse);
			for (i = 0; i < rows.GetCount(); i++)
				m_textColValues.RemoveAt(rows[i]);

			// This is just to test if wxDataViewCtrl can
			// cope with removing rows not sorted in
			// descending order
			rows.Sort(my_sort);
			RowsDeleted(rows);
		}

		void MyListModel::AddMany()
		{
			Reset(GetCount() + 1000);
		}

		void MyListModel::GetValueByRow(wxVariant &variant,
			unsigned int row, unsigned int col) const
		{
			switch (col)
			{
		/*	case Col_EditableText:
				if (row >= m_textColValues.GetCount())
					variant = wxString::Format("virtual row %d", row);
				else
					variant = m_textColValues[row];
				break;*/

			case Col_IconText:
			{
				/*wxString text;
				if (row >= m_iconColValues.GetCount())
					text = "virtual icon";
				else
					text = m_iconColValues[row];*/
				wxImage im("1.bmp");
				if (im.IsOk())
				{
					im.Rescale(128, 128);
					wxBitmap bitmap(im, wxBITMAP_TYPE_BMP);
					variant << bitmap;
				}
	/*				wxBitmap bitmap(im, wxBITMAP_TYPE_BMP);
				bitmap.SetSize(wxSize(32, 32));
				variant << bitmap;
*/

				//variant << wxDataViewIconText(text, m_icon[row % 2]);
			}
			break;

			/*case Col_TextWithAttr:
			{
				static const char *labels[5] =
				{
					"blue", "green", "red", "bold cyan", "default",
				};

				variant = labels[row % 5];
			}
			break;

			case Col_Custom:
				variant = wxString::Format("%d", row % 100);
				break;
*/

			case Col_Max:
				wxFAIL_MSG("invalid column");
			}
		}

		bool MyListModel::GetAttrByRow(unsigned int row, unsigned int col,
			wxDataViewItemAttr &attr) const
		{
			switch (col)
			{
			/*case Col_EditableText:
				return false;*/

			case Col_IconText:
				if (!(row % 2))
					return false;
				attr.SetColour(*wxLIGHT_GREY);
				break;

		/*	case Col_TextWithAttr:
			case Col_Custom:
				// do what the labels defined in GetValueByRow() hint at
				switch (row % 5)
				{
				case 0:
					attr.SetColour(*wxBLUE);
					break;

				case 1:
					attr.SetColour(*wxGREEN);
					break;

				case 2:
					attr.SetColour(*wxRED);
					break;

				case 3:
					attr.SetColour(*wxCYAN);
					attr.SetBold(true);
					break;

				case 4:
					return false;
				}
				break;*/

			case Col_Max:
				wxFAIL_MSG("invalid column");
			}

			return true;
		}

		bool MyListModel::SetValueByRow(const wxVariant &variant,
			unsigned int row, unsigned int col)
		{
			switch (col)
			{
			//case Col_EditableText:
			case Col_IconText:
				if (row >= m_textColValues.GetCount())
				{
					// the item is not in the range of the items
					// which we store... for simplicity, don't allow editing it
					wxLogError("Cannot edit rows with an index greater than %d",
						m_textColValues.GetCount());
					return false;
				}

			/*	if (col == Col_EditableText)
				{
					m_textColValues[row] = variant.GetString();
				}
				else // col == Col_IconText
				{
					wxDataViewIconText iconText;
					iconText << variant;
					m_iconColValues[row] = iconText.GetText();
				}*/
				return true;

			/*case Col_TextWithAttr:
			case Col_Custom:
				wxLogError("Cannot edit the column %d", col);
				break;
*/

			case Col_Max:
				wxFAIL_MSG("invalid column");
			}

			return false;
		}


	}
}