#include "stdafx.h"
#include "bio_journal_page.hpp"

#include "bio_journal_resource.hpp"
#include "bio_resources.hpp"

#include "common_utils.hpp"
#include "bio_properties_utils.hpp"

namespace SmartBio
{
	namespace View
	{

		BioJournalPage::BioJournalPage( wxWindow* parent
			                            , wxWindowID id) : TabPage(parent, id)
		{
			resource = new BioJournalResource;
			create();
			subscribe();
		}

		BioJournalPage::~BioJournalPage()
		{
			unsubscribe();
		}

		void BioJournalPage::onSelectedItemDelete(wxCommandEvent& )
		{
			wxMessageBox("Delete");
		}

		void BioJournalPage::onDeleteAllRecords(wxCommandEvent& )
		{
			wxMessageBox("Delete all");
		}


		void BioJournalPage::do_subscribe()
		{
			btn_journal_delete_			->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::onSelectedItemDelete	 , this);
			btn_journal_delete_all_	->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::onDeleteAllRecords	   , this);

			journal_list_           ->Bind(wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU, &BioJournalPage::onContextMenu, this);

		}

		void BioJournalPage::do_unsubscribe()
		{
			btn_journal_delete_			->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::onSelectedItemDelete	 , this);
			btn_journal_delete_all_	->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::onDeleteAllRecords	   , this);

			journal_list_           ->Unbind(wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU, &BioJournalPage::onContextMenu, this);

		}

		void BioJournalPage::do_create()
		{
			Poco::SharedPtr<BioJournalResource> resource(new BioJournalResource());
			CommonUtils utils;
			BioPropertiesUtils property_utils;

			wxBoxSizer* main_journal_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_journal_sizer);

			wxBoxSizer* tools_journal_sizer = new wxBoxSizer(wxHORIZONTAL);

			main_journal_sizer->Add(tools_journal_sizer, 1, wxALL | wxEXPAND, 5); 

			btn_journal_delete_     = utils.addButton(ID_BTN_JOURNAL_DELETE    , this, *resource, tools_journal_sizer);
			btn_journal_delete_all_ = utils.addButton(ID_BTN_JOURNAL_DELETE_ALL, this, *resource, tools_journal_sizer);


			wxBoxSizer* main_journal_list_sizer = new wxBoxSizer(wxHORIZONTAL);

			main_journal_sizer->Add(main_journal_list_sizer, 7, wxALL | wxEXPAND, 5);

			

			wxBoxSizer* avatar_sizer = new wxBoxSizer(wxVERTICAL);

			main_journal_list_sizer->Add(avatar_sizer, 1, wxALL | wxEXPAND, 5);

		/*	wxFlexGridSizer* grid_avatar_sizer = new wxFlexGridSizer(3, 0, 0, 0);

			grid_avatar_sizer->AddGrowableRow(0, 2);
			grid_avatar_sizer->AddGrowableRow(1, 3);
			grid_avatar_sizer->AddGrowableRow(2, 1);


			avatar_sizer->Add(grid_avatar_sizer, 1, wxEXPAND, 5);

			wxBoxSizer* top_avatar_sizer = new wxBoxSizer(wxVERTICAL);

			grid_avatar_sizer->Add(top_avatar_sizer, 1, wxALL | wxEXPAND, 5);*/


			utils.addFaceStreamer(ID_BTN_JOURNAL_AVATAR, *resource, this, avatar_sizer);


		/*	wxBoxSizer* both_avatar_sizer = new wxBoxSizer(wxVERTICAL);

			grid_avatar_sizer->Add(both_avatar_sizer, 1, wxALL | wxEXPAND, 5);*/


//************************************************Journal List*********************************************************************
 
			wxBoxSizer* journal_list_sizer = new wxBoxSizer(wxHORIZONTAL);

			main_journal_list_sizer->Add(journal_list_sizer, 3, wxALL | wxEXPAND, 5);

		 journal_list_ = new wxDataViewListCtrl( this, wxID_ANY
				                                   , wxDefaultPosition, wxSize(-1, -1)
								                           , wxDV_ROW_LINES | wxDV_SINGLE);

 
		 journal_list_sizer->Add(journal_list_, 7, wxALL | wxEXPAND, 5);
			
			person_              = property_utils.createTextColumn  (ID_JOURNAL_PERSON_NAME        , *journal_list_, *resource);
			photo_               = property_utils.createBitmapColumn(ID_JOURNAL_PHOTO              , *journal_list_, *resource);	
			full_photo_          = property_utils.createBitmapColumn(ID_JOURNAL_FULL_PHOTO         , *journal_list_, *resource);
			time_                = property_utils.createDateColumn  (ID_JOURNAL_TIME               , *journal_list_, *resource);
			location_            = property_utils.createTextColumn  (ID_JOURNAL_LOCATION           , *journal_list_, *resource);
			detected_face_count_ = property_utils.createBitmapColumn(ID_JOURNAL_DETECTED_FACE_COUNT, *journal_list_, *resource);
			status_              = property_utils.createBitmapColumn(ID_JOURNAL_STATUS             , *journal_list_, *resource);
					
			this->Layout();
		}


		void BioJournalPage::onContextMenu(wxDataViewEvent& evt)
		{
			wxMenu menu;

			CommonUtils utils;

			if (menu.GetMenuItemCount() == 0)
			{

				
				wxMenuItem* open_person_   = utils.addMenuItem(ID_JOURNAL_MENU_OPEN_PERSON  , *resource, menu);
				wxMenuItem* delete_record_ = utils.addMenuItem(ID_JOURNAL_MENU_DELETE_RECORD, *resource, menu);

				menu.Bind(wxEVT_COMMAND_MENU_SELECTED, &BioJournalPage::onContextMenuEvent, this);

				bool enable = (evt.GetItem() == NULL);

				open_person_  ->Enable(!enable);
				delete_record_->Enable(!enable);
				PopupMenu(&menu);
			}
		}

		void BioJournalPage::onContextMenuEvent(wxCommandEvent& evt)
		{
			switch (evt.GetId())
			{
			case ID_JOURNAL_MENU_OPEN_PERSON:
				//onOpenNewTab(evt);
				break;

			case ID_JOURNAL_MENU_DELETE_RECORD:
				//onAddUser(evt);
				break;

			default:
				break;
			}
		}
		
	}
}