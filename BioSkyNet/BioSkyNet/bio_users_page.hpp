#pragma once

#ifndef Bio_Users_Page_INCLUDED
#define Bio_Users_Page_INCLUDED

#include "tab_page.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioUsersPage : public TabPage
		{

		public:
			BioUsersPage( wxWindow* parent
				          , wxWindowID id = wxID_ANY);

			~BioUsersPage();

		private:	
			void do_subscribe();
			void do_unsubscribe();
			void do_create();

		private:
			void onAddUser(wxCommandEvent& e);

		private:
			wxDataViewListCtrl*  users_list_  ;
			wxCommandLinkButton* btn_add_user_;
		
		};
	}
}

#endif


