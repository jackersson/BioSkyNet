#include "stdafx.h"

#include "tab_page.hpp"
#include "tab_controller.hpp"

namespace SmartBio { namespace View
{

	TabPage::TabPage( wxWindow *parent, wxWindowID winid ) 
		             : wxScrolledWindow(static_cast<wxWindow *>(parent), winid)
	{
		state_ = NULL;
		current_state_ = OPEN;

		SetScrollRate(1, 1);	
	}

	TabPage::~TabPage(){}

	void TabPage::setStateMonitorVariable(State *state)
	{
		state_ = state;

		if (state_ != NULL)
			*state_ = current_state_;
	}

	void TabPage::close()
	{
		current_state_ = CLOSED;

		if (state_ != NULL)
			*state_ = CLOSED;

		TabController *parent = dynamic_cast<TabController *>(this->GetParent());
		parent->DeletePage(parent->GetPageIndex(this));
	}

	void TabPage::onCloseCallback()
	{
		current_state_ = CLOSED;

		if (state_ != NULL)
			*state_ = CLOSED;

		onClose();
	}

	void TabPage::onLeavePageCallback()
	{
		current_state_ = OPEN;

		if (state_ != NULL)
			*state_ = OPEN;

		onLeavePage();
	}

	void TabPage::onSelectPageCallback()
	{
		current_state_ = ACTIVE;

		if (state_ != NULL)
			*state_ = ACTIVE;

		onSelectPage();
	}

	void TabPage::onClose(){}
	void TabPage::onLeavePage(){}

	void TabPage::onSelectPage(){}

	void TabPage::setLabel(const wxString& label)
	{
		TabController *parent = dynamic_cast<TabController *>(this->GetParent());
		parent->SetPageText(parent->GetPageIndex(this), label);
	}


	void TabPage::subscribe()
	{
		do_subscribe();
	}

	void TabPage::unsubscribe()
	{
		do_unsubscribe();
	}

	void TabPage::create()
	{
		do_create();
	}

}}

