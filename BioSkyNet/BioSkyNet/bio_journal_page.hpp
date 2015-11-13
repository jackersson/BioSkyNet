#pragma once

#ifndef Bio_Journal_Page_INCLUDED
#define Bio_Journal_Page_INCLUDED

#include "tab_page.hpp"

namespace SmartBio
{
	namespace View
	{

		
		class BioJournalPage : public TabPage
		{

		public:
			BioJournalPage( wxWindow* parent
				             , wxWindowID id = wxID_ANY);

			~BioJournalPage();

		private:
		
			void do_subscribe();
			void do_unsubscribe();
			void do_create();

		private:
			void onDeleteAllRecords  (wxCommandEvent& e);
			void onSelectedItemDelete(wxCommandEvent& e);
			
		private:
			wxDataViewListCtrl*  users_list_            ;	
			wxBitmapButton*      btn_journal_delete_    ;
			wxBitmapButton*      btn_journal_delete_all_;

			
			wxDataViewColumn*    person_                ; 
			wxDataViewColumn*    location_              ; 
			wxDataViewColumn*    time_                  ; 
			wxDataViewColumn*    photo_                 ; 
			wxDataViewColumn*    full_photo_            ; 
			wxDataViewColumn*	   status_                ; 
			wxDataViewColumn*	   detected_face_count_   ; 

			//TODO add wx_bio_face_view streamer to see the photo_

			//TODO make context menu;
			//Open Person
			//Delete Record
		};
	}
}

#endif


