#pragma once

#ifndef BIO_FORM_INCLUDED
#define BIO_FORM_INCLUDED

#include "../SmartInterfaces/imodel.hpp"

//#include "log_control.hpp"

namespace SmartBio { namespace View
{
	class BioForm : public wxFrame
	{

		DECLARE_DYNAMIC_CLASS(BioForm);

	public:
		BioForm();
		BioForm( wxWindow* parent, const wxWindowID id = 1, const wxString& title = wxEmptyString);
		virtual ~BioForm();
		
// 
// 		void addItem( wxWindow* item, int proportion, int flag, int border )
// 		{
// 			sizer_panel_->Add(item, proportion, flag, border);
// 
// 			this->Layout();
// 		}

		//void onClose(wxCloseEvent& event);


		void setTop( wxApp& application )
		{
			application.SetTopWindow( this );
		}

	/*	Poco::SharedPtr<LogControl>& logControl()
		{
			return log_control_;
		}*/

	private: 
		void onAbout(wxCommandEvent& event);
		void onExit (wxCommandEvent& event);

		wxMenuBar*     createMainMenu();
		wxAuiToolBar*  createToolBar ();
		wxAuiNotebook* createNotebook();
	private:		
		static const std::size_t WINDOW_WIDTH = 1024;
		static const std::size_t WINDOW_HEIGHT = 640;
				
	private:
		//Poco::SharedPtr<LogControl>    log_control_;
		//Poco::SharedPtr<TabController> tab_control_;

	private: // UI elements
		wxStatusBar*    status_bar_   ;
		wxMenuBar*      menu_bar_     ;		
		wxToolBar*      tool_bar_     ;
		wxBoxSizer*     sizer_panel_  ;
		wxTextCtrl*     logg_control_  ;
		wxAuiManager    frame_manager_;
	private:
		void create();
		//void subscribe();


	private:
		wxDECLARE_EVENT_TABLE();

	};

}}

#endif
