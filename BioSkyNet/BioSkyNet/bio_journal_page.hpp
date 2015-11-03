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
		};
	}
}

#endif


