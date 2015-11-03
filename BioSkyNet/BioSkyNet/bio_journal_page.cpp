#include "stdafx.h"
#include "bio_journal_page.hpp"

#include "bio_journal_resource.hpp"
#include "bio_resources.hpp"

#include "common_utils.hpp"

namespace SmartBio
{
	namespace View
	{

		BioJournalPage::BioJournalPage( wxWindow* parent
			                            , wxWindowID id) : TabPage(parent, id)
		{
			create();
			subscribe();
		}

		BioJournalPage::~BioJournalPage()
		{
			unsubscribe();
		}

		void BioJournalPage::onSelectedItemDelete(wxCommandEvent& )
		{
			wxMessageBox("Delete");
		}

		void BioJournalPage::onDeleteAllRecords(wxCommandEvent& )
		{
			wxMessageBox("Delete all");
		}


		void BioJournalPage::do_subscribe()
		{
			btn_journal_delete_			->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::onSelectedItemDelete	 , this);
			btn_journal_delete_all_	->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::onDeleteAllRecords	   , this);

		}
		void BioJournalPage::do_unsubscribe()
		{
			btn_journal_delete_			->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::onSelectedItemDelete	 , this);
			btn_journal_delete_all_	->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioJournalPage::onDeleteAllRecords	   , this);


		}
		void BioJournalPage::do_create()
		{
			Poco::SharedPtr<BioJournalResource> resource(new BioJournalResource());
			CommonUtils utils;

			wxBoxSizer* main_journal_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_journal_sizer);

			wxBoxSizer* tools_journal_sizer = new wxBoxSizer(wxHORIZONTAL);

			main_journal_sizer->Add(tools_journal_sizer, 1, wxALL | wxEXPAND, 5); 

			btn_journal_delete_     = utils.addButton(ID_BTN_JOURNAL_DELETE    , this, *resource, tools_journal_sizer);
			btn_journal_delete_all_ = utils.addButton(ID_BTN_JOURNAL_DELETE_ALL, this, *resource, tools_journal_sizer);

 
			wxDataViewListCtrl* journal_list = new wxDataViewListCtrl( this, wxID_ANY
				                                                       , wxDefaultPosition, wxSize(-1, -1)
								                                               , wxDV_ROW_LINES | wxDV_SINGLE);
 
			main_journal_sizer->Add(journal_list, 7, wxALL | wxEXPAND, 5);
 
			journal_list->AppendTextColumn(_("Time")      , wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
			journal_list->AppendTextColumn(_("First Name"), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
			journal_list->AppendTextColumn(_("Last Name") , wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
			journal_list->AppendTextColumn(_("Photo")     , wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
			journal_list->AppendTextColumn(_("Status")    , wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
			
			this->Layout();
		}
		
	}
}