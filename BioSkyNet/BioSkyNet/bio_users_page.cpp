#include "stdafx.h"
#include "bio_users_page.hpp"

#include "bio_users_resource.hpp"
#include "bio_resources.hpp"

#include "common_utils.hpp"
#include "bio_properties_utils.hpp"

#include "../BioSkyNetData/bio_db_io.hpp"

#include "ui_notifications.hpp"

namespace SmartBio
{
	namespace View
	{
		
		BioUsersPage::BioUsersPage( wxWindow* parent
			                        , wxWindowID id ) :TabPage(parent, id)
		{
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

			users_list_ = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition
				                                  , wxSize(-1, -1), wxDV_ROW_LINES | wxDV_SINGLE);

			users_sizer->Add(users_list_, 1, wxALL | wxEXPAND, 5);
			
			std::string address = "D:\\Spark\\BioSkyNet\\BioSkyNet\\BioSkyNetData\\dataBase\\bioskynet.db";
			Poco::SharedPtr<Data::BioDbIO> db_io = new Data::BioDbIO(address);
			user_data_.clear();
			db_io->read<Data::BioPerson, Data::BioPersonTable>(user_data_, "");


			first_name_    = utils_property.createTextColumn(ID_BIO_USERS_FIRST_NAME   , *users_list_, *resource);
			last_name_     = utils_property.createTextColumn(ID_BIO_USERS_LAST_NAME    , *users_list_, *resource);
			date_if_birth_ = utils_property.createDateColumn(ID_BIO_USERS_DATE_OF_BIRTH, *users_list_, *resource);
			gender_        = utils_property.createTextColumn(ID_BIO_USERS_GENDER       , *users_list_, *resource);
			country_       = utils_property.createTextColumn(ID_BIO_USERS_COUNTRY      , *users_list_, *resource);
			city_          = utils_property.createTextColumn(ID_BIO_USERS_CITY         , *users_list_, *resource);
			avatar_        = utils_property.createTextColumn(ID_BIO_USERS_AVATAR       , *users_list_, *resource);
			photo_         = utils_property.createTextColumn(ID_BIO_USERS_PHOTO        , *users_list_, *resource);
			email_         = utils_property.createTextColumn(ID_BIO_USERS_EMAIL        , *users_list_, *resource);
			comments_      = utils_property.createTextColumn(ID_BIO_USERS_COMMENTS     , *users_list_, *resource);
			rights_        = utils_property.createTextColumn(ID_BIO_USERS_RIGHTS       , *users_list_, *resource);


			wxVector<wxVariant> data;
			for (auto it = user_data_.begin(); it != user_data_.end(); ++it)
			{
				Data::BioPerson person = (*it);
				//wxMessageBox((*it).firstName(), (*it).lastName());
				data.clear();

			//	wxVector<wxVariant> data;
				data.push_back(person.firstName());
				data.push_back(person.lastName());


				Poco::DateTime birthday = person.dateOfBirth();
				wxDateTime wx_date_time;
				wx_date_time.SetYear(birthday.year());
				wx_date_time.SetMonth((wxDateTime::Month)birthday.month());
				wx_date_time.SetDay(birthday.day());

				data.push_back(wx_date_time);
				data.push_back(person.gender()        );
				data.push_back(person.country()       );
				data.push_back(person.city()          );
				data.push_back(person.avatar()        );
				data.push_back(person.bioPhotoIndexs());
				data.push_back(person.email()         );
				data.push_back(person.comments()      );
				data.push_back(person.rights()        );

				users_list_->AppendItem(data);
			}		

//			users_list_->AppendItem()


			//**************************************************************************************
			wxBoxSizer* button_sizer = new wxBoxSizer(wxVERTICAL);
			main_sizer->Add(button_sizer);

			btn_add_user_ = utils.addCommandLinkButton(ID_BTN_ADD_USER, this, *resource, button_sizer);
			
			this->Layout();	

		}		




		void BioUsersPage::onContextMenu(wxDataViewEvent& evt)
		{
			wxMenu menu;
			
			if (menu.GetMenuItemCount() == 0) 
			{

				//TODO 'Open' and 'Add new' should be in resources
				wxMenuItem* menu_open_    = menu.Append(BioUsersContextMenuID::ID_USER_OPEN_NEW_TAB, "Open"   );
				/*wxMenuItem* menu_add_new_ = */menu.Append(BioUsersContextMenuID::ID_USER_ADD_NEW_TAB , "Add new");

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
			case BioUsersContextMenuID::ID_USER_OPEN_NEW_TAB:
				onOpenNewTab(evt);
				break;

			case BioUsersContextMenuID::ID_USER_ADD_NEW_TAB:				
				onAddUser(evt);
				break;

			default:
				break;
			}
		}

		void BioUsersPage::createPersonTab( bool default_update  )
		{		
			if (default_update)
			{
				this->postNotification(new CreatePersonTabNotification(default_update));
				return;
			}

			int i = users_list_->GetSelectedRow();
			if (i >= 0 && i < user_data_.size())
			{
				this->postNotification(new CreatePersonTabNotification(user_data_[i]));
			}
		}
			
	}
}


