#include "stdafx.h"
#include "bio_users_page.hpp"

#include "bio_users_resource.hpp"
#include "bio_resources.hpp"

#include "common_utils.hpp"

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
			wxMessageBox("onAddUser");											
		}																									
		
		void BioUsersPage::do_subscribe()
		{		
			/*btn_add_user_->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioUsersPage::onAddUser, this);*/
		}

		void BioUsersPage::do_unsubscribe()
		{
			/*btn_add_user_->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioUsersPage::onAddUser, this);*/
		}

		void BioUsersPage::do_create()
		{
			Poco::SharedPtr<BioUsersResource> resource(new BioUsersResource());
			CommonUtils utils;

			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			users_list_ = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition
				                                  , wxSize(-1, -1), wxDV_ROW_LINES | wxDV_SINGLE);

			main_sizer->Add(users_list_, 1, wxALL | wxEXPAND, 5);

			btn_add_user_ = utils.addCommandLinkButton(ID_BTN_ADD_USER, this, *resource, main_sizer);
			
			this->Layout();	

		}		
	}
}