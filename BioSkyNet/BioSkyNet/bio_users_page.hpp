#pragma once

#ifndef Bio_Users_Page_INCLUDED
#define Bio_Users_Page_INCLUDED

#include "tab_page.hpp"
#include "../BioSkyNetData/bio_person_binder.hpp"

namespace SmartBio
{
	namespace View
	{
		enum BioUsersContextMenuID
		{
			  ID_USER_OPEN_NEW_TAB
			, ID_USER_ADD_NEW_TAB
		};
				
		class BioUsersPage : public TabPage
		{

		public:
			BioUsersPage( wxWindow* parent
				          , wxWindowID id = wxID_ANY);

			~BioUsersPage();

		private:	
			void do_subscribe  ();
			void do_unsubscribe();
			void do_create     ();

		private:
			void onAddUser             (wxCommandEvent&  evt);
			void onOpenNewTab          (wxCommandEvent&  evt);
			void onContextMenuEvent    (wxCommandEvent&  evt);
			void onUserItemDoubleClick (wxMouseEvent&    evt);
			void onContextMenu         (wxDataViewEvent& evt);

			void createPersonTab(bool default_update);

		private:
			std::vector<Data::BioPerson> user_data_;		

			wxDataViewListCtrl*  users_list_  ;
			wxCommandLinkButton* btn_add_user_;
			
			wxDataViewColumn* first_name_    ;
			wxDataViewColumn* last_name_     ;
			wxDataViewColumn* date_if_birth_ ;
			wxDataViewColumn* gender_        ;
			wxDataViewColumn* country_       ;
			wxDataViewColumn* city_          ;
			wxDataViewColumn* avatar_        ;
			wxDataViewColumn* photo_         ;
			wxDataViewColumn* email_         ;
			wxDataViewColumn* comments_      ;
			wxDataViewColumn* rights_        ;			
		};
	}
}

#endif


