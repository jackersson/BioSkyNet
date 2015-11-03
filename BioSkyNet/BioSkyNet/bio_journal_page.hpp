#pragma once

#ifndef Bio_Journal_Page_INCLUDED
#define Bio_Journal_Page_INCLUDED

#include "tab_page.hpp"
#include "bio_resources.hpp"
#include "bio_journal_resource.hpp"
#include "iui_subscrible.hpp"


namespace SmartBio
{
	namespace View
	{
		class BioJournalPage : public TabPage
		{

		public:
			BioJournalPage(wxWindow* parent
				, wxWindowID id = wxID_ANY);

			~BioJournalPage();

		private:
			//void do_initialize();
			void do_subscribe();
			void do_unsubscribe();
			void do_create();

		private:
			void btDeleteAll(wxCommandEvent& e);
			void btDelete(wxCommandEvent& e);



		private:
			wxDataViewListCtrl*  users_list_;
			wxCommandLinkButton* btn_add_user_;
			wxBitmapButton* btn_journal_delete_;
			wxBitmapButton* btn_journal_delete_all_;

			wxBitmapButton* BioJournalPage::addButton(UIBioJournalPage index, wxWindow* parent, BioJournalResource& resource, wxBoxSizer* sizer);





		};
	}
}

#endif


