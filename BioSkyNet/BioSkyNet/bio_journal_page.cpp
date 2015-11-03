#include "stdafx.h"
#include "bio_journal_page.hpp"

namespace SmartBio
{
	namespace View
	{

		BioJournalPage::BioJournalPage(wxWindow* parent
			, wxWindowID id) :TabPage(parent, id)
		{
			create();
			subscribe();
		}

		BioJournalPage::~BioJournalPage()
		{
			unsubscribe();
		}

		void BioJournalPage::btDelete(wxCommandEvent& e)
		{
			wxMessageBox("Delete");
		}

		void BioJournalPage::btDeleteAll(wxCommandEvent& e)
		{
			wxMessageBox("Delete all");
		}



		//void do_initialize();
		void BioJournalPage::do_subscribe()
		{
			btn_journal_delete_			->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::btDelete			, this);
			btn_journal_delete_all_	->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::btDeleteAll	, this);

		}
		void BioJournalPage::do_unsubscribe()
		{
			btn_journal_delete_			->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::btDelete			, this);
			btn_journal_delete_all_	->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::btDeleteAll	, this);


		}
		void BioJournalPage::do_create()
		{


			Poco::SharedPtr<BioJournalResource> resource(new BioJournalResource());


			wxBoxSizer* main_journal_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_journal_sizer);

			wxBoxSizer* button_journal_sizer = new wxBoxSizer(wxHORIZONTAL);

			main_journal_sizer->Add(button_journal_sizer, 1, wxALL | wxEXPAND, 5);
 

			btn_journal_delete_ = addButton(ID_BTN_JOURNAL_DELETE, this, *resource, button_journal_sizer);			
 
			btn_journal_delete_all_ = addButton(ID_BTN_JOURNAL_DELETE_ALL, this, *resource, button_journal_sizer);

 
			wxDataViewListCtrl* journal_list = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxDV_ROW_LINES | wxDV_SINGLE);
 
			main_journal_sizer->Add(journal_list, 7, wxALL | wxEXPAND, 5);
 
			journal_list->AppendTextColumn(_("Time"), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
			journal_list->AppendTextColumn(_("First Name"), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
			journal_list->AppendTextColumn(_("Last Name"), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
			journal_list->AppendTextColumn(_("Photo"), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
			journal_list->AppendTextColumn(_("Status"), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
			







/*
			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			users_list_ = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxDV_ROW_LINES | wxDV_SINGLE);

			main_sizer->Add(users_list_, 1, wxALL | wxEXPAND, 5);

			btn_add_user_ = new wxCommandLinkButton(this, wxID_ANY, _("Add"), _("Adding new person to Users List"), wxDefaultPosition, wxSize(-1, -1), 0);

			main_sizer->Add(btn_add_user_, 0, wxALL, 5);
*/

			this->Layout();


		}

		wxBitmapButton* BioJournalPage::addButton(UIBioJournalPage index, wxWindow* parent, BioJournalResource& resource, wxBoxSizer* sizer)
		{
			bool flag(false);
			View::UInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxBitmapButton* btn = new wxBitmapButton(parent, wxID_ANY, item.bitmap());

				sizer->Add(btn, 0);

				return btn;
			}



		}






	}
}