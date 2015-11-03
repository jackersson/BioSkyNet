#include "stdafx.h"
#include "bio_users_page.hpp"

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
			unsubscribe();//
		}

		void BioUsersPage::onAddUser(wxCommandEvent& e)		//
		{																									//
			wxMessageBox("onAddUser");											//
		}																									//
			//void do_initialize();
		void BioUsersPage::do_subscribe()
		{		
			btn_add_user_->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioUsersPage::onAddUser, this);//
		}

		void BioUsersPage::do_unsubscribe()
		{
			btn_add_user_->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioUsersPage::onAddUser, this);//
		}

		void BioUsersPage::do_create()
		{

			Poco::SharedPtr<BioUsersResource> resource(new BioUsersResource());


			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			users_list_ = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxDV_ROW_LINES | wxDV_SINGLE);

			main_sizer->Add(users_list_, 1, wxALL | wxEXPAND, 5);

			//btn_add_user_ = new wxCommandLinkButton(this, wxID_ANY, _("Add"), _("Adding new person to Users List"), wxDefaultPosition, wxSize(-1, -1), 0);

			btn_add_user_ = addButton(ID_BTN_ADD_USER, this, *resource, main_sizer);

			//main_sizer->Add(btn_add_user_, 0, wxALL, 5);

			this->Layout();
			//btn_add_user_->Bind(wxEVT_KEY_DOWN, &BioUsersPage::onAddUser, this);
			//btn_add_user_->Bind(wxEVT_KEY_UP, &BioUsersPage::onAddUser, this);

		}


		wxCommandLinkButton* BioUsersPage::addButton(UIBioUsersPage index, wxWindow* parent, BioControlResource<UInfoItem>& resource, wxSizer* sizer)
		{
			bool flag(false);
			View::UInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxCommandLinkButton* btn = new wxCommandLinkButton(parent, wxID_ANY, item.text(), item.hint());

				sizer->Add(btn, 0);

				return btn;
			}

		}

	




		
	}
}