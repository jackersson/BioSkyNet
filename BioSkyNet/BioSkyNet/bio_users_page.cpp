#include "stdafx.h"
#include "bio_users_page.hpp"

#include "bio_users_resource.hpp"
#include "bio_resources.hpp"

#include "common_utils.hpp"
#include "bio_properties_utils.hpp"

#include "../BioSkyNetData/bio_db_io.hpp"

#include "ui_notifications.hpp"

#include "bio_list_model.hpp"

namespace SmartBio
{
	namespace View
	{
		
		BioUsersPage::BioUsersPage( wxWindow* parent
			                        , wxWindowID id ) :TabPage(parent, id)
		{

			resource = new BioUsersResource;
			create();
			subscribe();
		}

		BioUsersPage::~BioUsersPage()
		{
			unsubscribe();
		}

		void BioUsersPage::onAddUser(wxCommandEvent& )		
		{				
			createPersonTab(true);
		}		

		void BioUsersPage::onOpenNewTab(wxCommandEvent&) 
		{			
			createPersonTab(false);
		}

		void BioUsersPage::onUserItemDoubleClick(wxMouseEvent&) 
		{
			createPersonTab(false);
		}
		
		
		void BioUsersPage::do_subscribe()
		{		
			btn_add_user_->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioUsersPage::onAddUser, this);

			users_list_->Connect(this->users_list_->GetId(), wxEVT_DATAVIEW_ITEM_ACTIVATED, wxMouseEventHandler(BioUsersPage::onUserItemDoubleClick), NULL, this);
			users_list_->Bind(wxEVT_DATAVIEW_SELECTION_CHANGED        , &BioUsersPage::onContextMenuEvent, this);
			users_list_->Bind(wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU, &BioUsersPage::onContextMenu, this);

		}

		void BioUsersPage::do_unsubscribe()
		{
			btn_add_user_->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioUsersPage::onAddUser, this);

			users_list_->Disconnect(this->users_list_->GetId(), wxEVT_DATAVIEW_ITEM_ACTIVATED, wxMouseEventHandler(BioUsersPage::onUserItemDoubleClick), NULL, this);
			users_list_->Unbind(wxEVT_DATAVIEW_SELECTION_CHANGED        , &BioUsersPage::onContextMenuEvent, this);
			users_list_->Unbind(wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU, &BioUsersPage::onContextMenu, this);
		}

		void BioUsersPage::do_create()
		{
			Poco::SharedPtr<BioUsersResource> resource(new BioUsersResource());
			CommonUtils utils;
			BioPropertiesUtils utils_property;


			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			wxBoxSizer* users_sizer = new wxBoxSizer(wxVERTICAL);
			main_sizer->Add(users_sizer, 1, wxEXPAND, 5);

			users_list_ = new wxDataViewCtrl( this, wxID_ANY, wxDefaultPosition
				                                  , wxSize(-1, -1), wxDV_ROW_LINES | wxDV_SINGLE);

		

			

			users_sizer->Add(users_list_, 1, wxALL | wxEXPAND, 5);
			
			std::string address = "D:\\Spark\\BioSkyNet\\BioSkyNet\\BioSkyNetData\\dataBase\\bioskynet.db";
			Poco::SharedPtr<Data::BioDbIO> db_io = new Data::BioDbIO(address);
			user_data_.clear();
			db_io->read<Data::BioPerson, Data::BioPersonTable>(user_data_, "");

			MyListModel* m_list_model = new MyListModel(user_data_);

			users_list_->AssociateModel(m_list_model);

			users_list_->SetRowHeight(130);

			utils_property.createColumn(ID_BIO_USERS_AVATAR, *users_list_, MyListModel::Col_Avatar
				                         , *resource, new wxDataViewBitmapRenderer);

			utils_property.createColumn(ID_BIO_USERS_FIRST_NAME, *users_list_, MyListModel::Col_FirstName
				                         , *resource, new wxDataViewTextRenderer);

			utils_property.createColumn(ID_BIO_USERS_LAST_NAME, *users_list_, MyListModel::Col_LastName
				                         , *resource, new wxDataViewTextRenderer);

			utils_property.createColumn(ID_BIO_USERS_DATE_OF_BIRTH, *users_list_, MyListModel::Col_DateOfBirth
				, *resource, new wxDataViewDateRenderer);

			utils_property.createColumn(ID_BIO_USERS_GENDER, *users_list_, MyListModel::Col_Gender
				, *resource, new wxDataViewTextRenderer);

			utils_property.createColumn(ID_BIO_USERS_COUNTRY, *users_list_, MyListModel::Col_Country
				, *resource, new wxDataViewTextRenderer);

			utils_property.createColumn(ID_BIO_USERS_CITY, *users_list_, MyListModel::Col_City
				, *resource, new wxDataViewTextRenderer);

			utils_property.createColumn(ID_BIO_USERS_EMAIL, *users_list_, MyListModel::Col_Email
				, *resource, new wxDataViewTextRenderer);

			utils_property.createColumn(ID_BIO_USERS_COMMENTS, *users_list_, MyListModel::Col_Comments
				, *resource, new wxDataViewTextRenderer);

			utils_property.createColumn(ID_BIO_USERS_RIGHTS, *users_list_, MyListModel::Col_Rights
				, *resource, new wxDataViewTextRenderer);


			//**************************************************************************************
			wxBoxSizer* button_sizer = new wxBoxSizer(wxVERTICAL);
			main_sizer->Add(button_sizer);

			btn_add_user_ = utils.addCommandLinkButton(ID_BTN_ADD_USER, this, *resource, button_sizer);
			
			this->Layout();	

		}		


		void BioUsersPage::onContextMenu(wxDataViewEvent& evt)
		{		

			wxMenu menu;
			CommonUtils utils;
			
			if (menu.GetMenuItemCount() == 0) 
			{

				wxMenuItem* menu_open_    = utils.addMenuItem(ID_BIO_USERS_MENU_OPEN   , *resource, menu);
				wxMenuItem* menu_add_new_ = utils.addMenuItem(ID_BIO_USERS_MENU_ADD_NEW, *resource, menu);


				menu.Bind(wxEVT_COMMAND_MENU_SELECTED, &BioUsersPage::onContextMenuEvent, this);
									
				bool enable = (evt.GetItem() == NULL);

				menu_open_->Enable(!enable);
				PopupMenu(&menu);
			}		
		}	

		void BioUsersPage::onContextMenuEvent(wxCommandEvent& evt)
		{
			switch (evt.GetId()) 
			{
			case ID_BIO_USERS_MENU_OPEN:
				onOpenNewTab(evt);
				break;

			case ID_BIO_USERS_MENU_ADD_NEW:
				onAddUser(evt);
				break;

			default:
				break;
			}
		}

		void BioUsersPage::createPersonTab( bool default_update  )
		{
		/*	if (default_update)
			{
				this->postNotification(new CreatePersonTabNotification(default_update));
				return;
			}

			int i = users_list_->GetSelectedRow();
			if (i >= 0 && i < user_data_.size())
			{
				this->postNotification(new CreatePersonTabNotification(user_data_[i]));
			}*/
		}
			
	}
}


