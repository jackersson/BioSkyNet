#include "stdafx.h"

#include "tab_controller.hpp"
#include "tab_page.hpp"

namespace SmartBio { namespace View
{

	//Example add
	//FirstPage *firstPage = new FirstPage(this, wxID_ANY);
	//m_tabbedPanel->AddPage(firstPage, wxT("Start page"), true);

	// Add to control
	//m_tabbedPanel = new TabController(this, wxID_ANY);
	//sizer->Add(m_tabbedPanel, 1, wxEXPAND | wxALL, 0);

	TabController::TabController( wxWindow* parent
		                          , wxWindowID winid 
		                          , const wxPoint &pos
		                          , const wxSize &size
		                          , long style) 
															: wxAuiNotebook( parent, winid, pos, size, style )
	{
		subscribe();
	}

	TabController::~TabController()
	{
		unsubscribe();
	}

	void TabController::closeAllPages()
	{
		int count = GetPageCount();
		for (int i = 0; i < count; i++)
		{
			TabPage *currentPage = reinterpret_cast<TabPage *>(GetPage(i));
			currentPage->onCloseCallback();
		}
		DeleteAllPages();
	}

	void TabController::onPageClose(wxAuiNotebookEvent& event)
	{
		int selection = event.GetSelection();

		if (selection > -1)
		{
			TabPage *currentPage = reinterpret_cast<TabPage *>(GetPage(selection));
			currentPage->onCloseCallback();
		}
	}

	void TabController::onPageChange(wxAuiNotebookEvent& event)
	{
		int oldSelection = event.GetOldSelection();
		int selection = event.GetSelection();

		if (oldSelection > -1)
		{
			TabPage *oldPage = reinterpret_cast<TabPage *>(GetPage(oldSelection));
			oldPage->onLeavePageCallback();
		}

		if (selection > -1)
		{
			TabPage *currentPage = reinterpret_cast<TabPage *>(GetPage(selection));
			currentPage->onSelectPageCallback();
		}
	}

	void TabController::subscribe()
	{
		this->Bind(wxEVT_AUINOTEBOOK_PAGE_CHANGED, &TabController::onPageChange, this);
		this->Bind(wxEVT_AUINOTEBOOK_PAGE_CLOSE, &TabController::onPageClose, this);
	}

	void TabController::unsubscribe()
	{
		this->Unbind(wxEVT_AUINOTEBOOK_PAGE_CHANGED, &TabController::onPageChange, this);
		this->Unbind(wxEVT_AUINOTEBOOK_PAGE_CLOSE, &TabController::onPageClose, this);
	}


}}

