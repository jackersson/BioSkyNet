#include "stdafx.h"
#include "bio_form.hpp"

//#include "bio_resources.hpp"
//#include "bio_view.hpp"

//#include "ui_texts.hpp"
//#include "bio_main_menu.hpp"
//#include "bio_toolbar.hpp"
//#include "tab_controller.hpp"
//#include "start_page.hpp"

//#include "main_bio_page.hpp"

//#include "sample.xpm"
//#include "bio_form_resources.hpp"

//#include "uapp_info_item.hpp"

//#include "bio_settings.hpp"
//#include "log_control.hpp"

#include <memory>

namespace SmartBio { namespace View
{
	IMPLEMENT_DYNAMIC_CLASS( BioForm, wxFrame );

	BEGIN_EVENT_TABLE(BioForm, wxFrame)
	
		EVT_MENU(wxID_EXIT , BioForm::onExit )
		EVT_MENU(wxID_ABOUT, BioForm::onAbout)

		
	END_EVENT_TABLE()

	BioForm::BioForm() { }
	
	BioForm::BioForm( wxWindow* parent
	                , wxWindowID const id, wxString const& title)
									: wxFrame(parent, id, title, wxDefaultPosition, wxSize( WINDOW_WIDTH, WINDOW_HEIGHT ) )
	{
		create();
	}

	BioForm::~BioForm()	{
	
		frame_manager_.UnInit();
	}

	void BioForm::onExit( wxCommandEvent&  )
	{
		Close();
	}

	void BioForm::onAbout(wxCommandEvent& )
	{
		//Texts::BioFormTexts app ;
		wxAboutDialogInfo   info;

		//info.SetName   ( app.tApplicationName() );
		//info.SetVersion( app.tVersion()         );
		//info.SetWebSite( app.tWebSite()         );

		wxAboutBox(info);
	}
	
	wxAuiNotebook* BioForm::createNotebook()
	{
		// create the notebook off-window to avoid flicker
		wxSize client_size = GetClientSize();
		long m_notebook_style;
		m_notebook_style = wxAUI_NB_DEFAULT_STYLE | wxAUI_NB_TAB_EXTERNAL_MOVE | wxNO_BORDER;
		wxAuiNotebook* ctrl = new wxAuiNotebook(this, wxID_ANY,
			wxPoint(client_size.x, client_size.y),
			wxSize(430, 200),
			m_notebook_style);
		ctrl->Freeze();

		wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16, 16));

		wxPanel* panel1 = new wxPanel(ctrl, wxID_ANY);
		ctrl->AddPage(panel1, wxT("Welcome to wxAUI"), false, page_bmp);
		ctrl->SetPageToolTip(0, "Welcome to wxAUI (this is a page tooltip)");


		ctrl->Thaw();
		return ctrl;
	}

	void BioForm::create()
	{
		/*SetMenuBar( new BioMainMenu() );
		CreateStatusBar(2);
		logg_control_ = new wxTextCtrl(this, UIResources::ID_LOG_AUI, wxEmptyString, wxDefaultPosition
			, wxSize(250, 100), wxTE_MULTILINE | wxTE_READONLY | wxNO_BORDER);

		frame_manager_.SetManagedWindow(this);

		frame_manager_.AddPane(logg_control_, wxAuiPaneInfo().Bottom().Name(wxT("Help")).Caption(_("Help Window")));
		
		wxSize client_size = GetClientSize();
		long m_notebook_style;
		m_notebook_style = wxAUI_NB_DEFAULT_STYLE | wxAUI_NB_TAB_EXTERNAL_MOVE | wxNO_BORDER;

		TabController* tb = new TabController(this, wxID_ANY,
			wxPoint(client_size.x, client_size.y),
			wxSize(430, 200),
			m_notebook_style);
		//tb->Freeze();
		wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16, 16));

		//sizer->Add(m_tabbedPanel, 1, wxEXPAND | wxALL, 0);

		StartPage*    start_page = new StartPage( this,  wxID_ANY);
		tb->AddPage(start_page, "test", true, page_bmp);
		//tb->Thaw();

		MainBioPage*    bio_page = new MainBioPage(this, wxID_ANY);
		tb->AddPage(bio_page, "main", true, page_bmp);
		//tb->Thaw();

		frame_manager_.AddPane(tb, wxAuiPaneInfo().CenterPane());

		BioToolBar* toolbar = new BioToolBar( this, UIResources::ID_TOOLBAR_MAIN, wxDefaultPosition, wxDefaultSize
			                                  , wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW | wxAUI_TB_VERTICAL );

		frame_manager_.AddPane(toolbar, wxAuiPaneInfo().Name(wxT("tb5")).Caption(wxT("Sample Vertical Toolbar")).
			ToolbarPane().Left().
			GripperTop());

		wxPanel* panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(250, 100));
		wxBoxSizer* boxSizer393 = new wxBoxSizer(wxVERTICAL);
		panel1->SetSizer(boxSizer393);*/

//		wxListbook* ls;
		

		//wxPropertyGridManager* pr_gris = new wxPropertyGridManager(panel1, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxPG_TOOLBAR|wxPG_DESCRIPTION | wxPG_SPLITTER_AUTO_CENTER | wxPG_BOLD_MODIFIED);
		//wxPGProperty* property1 = pr_gris->Append(new wxStringProperty(_("First Name"), wxPG_LABEL, wxT("")));
		//property1->SetHelpString(wxT(""));

		//pr_gris->AddPage("general", );
		//pr_gris->AddPage("face");
		/*BioSettings* settings = new BioSettings(panel1, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxPG_TOOLBAR | wxPG_DESCRIPTION | wxPG_SPLITTER_AUTO_CENTER | wxPG_BOLD_MODIFIED);

		boxSizer393->Add(settings, 1, wxALL | wxEXPAND, 5);

		frame_manager_.AddPane(panel1, wxAuiPaneInfo().
			Name(wxT("test10")).Caption(wxT("Text Pane with Hide Prompt")).
			Right().Icon(wxArtProvider::GetBitmap(wxART_WARNING,
			wxART_OTHER,
			wxSize(16, 16))));


		std::unique_ptr<BioFormResource> resource(new BioFormResource());
		
		this->Layout();

		bool flag;
		UAppInfoItem app = resource->get(UIResources::ID_APPLICATION, flag);
		if (flag)
		{			
			SetIcon ( app.icon());
			SetTitle( app.text());
		}

		//this->SetTitle( resource->textById(UIResources::ID_APPLICATION) );
		this->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->Centre();

		frame_manager_.Update();*/
	}
	
	/*void BioForm::create()
	{		
		wxBoxSizer* sizer;
		sizer = new wxBoxSizer( wxVERTICAL );	

		status_bar_ = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );

		menu_bar_ = new wxMenuBar( 0 );

		wxMenu* menu_file_  = new wxMenu();
		wxMenu* menu_exit_  = new wxMenu();

		wxMenuItem* menu_item_exit_ = new wxMenuItem( menu_file_, wxID_ANY, text_holder_.tMenuItemExit()
			                                          , wxEmptyString, wxITEM_NORMAL, menu_exit_ );
		menu_file_->Append( menu_item_exit_ );


		wxMenu* menu_about_ = new wxMenu();

		menu_bar_->Append( menu_file_ , text_holder_.tMenuItemFile()  );
		menu_bar_->Append( menu_about_, text_holder_.tMenuItemAbout() ); 


		this->SetMenuBar( menu_bar_ );

		tool_bar_ = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
		tool_bar_->Realize(); 


		//wxBoxSizer* sizer_panel;
		sizer_panel_ = new wxBoxSizer( wxVERTICAL );

		//wxPanel* panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
		//sizer_panel->Add( panel, 1, wxEXPAND | wxALL, 5 );
		
		sizer->Add( sizer_panel_, 3, wxEXPAND, 5 );

		this->SetSizer( sizer );

		log_control_ = LogControl::instance( this );

		//tab_control_ = new TabController( this, wxID_ANY );
		//sizer_panel_->Add(tab_control_, 1, wxEXPAND | wxALL, 0);

		//StartPage* start_page = new StartPage( this, wxID_ANY );
		//tab_control_->AddPage( start_page, "Start page", true );

		//SubjectPage* subject_page = new SubjectPage( tab_control_, wxID_ANY );
		//tab_control_->AddPage( subject_page, "Subject page", true );

		//SettingsPage* settings_page = new SettingsPage( tab_control_);

		//settings_page->update( model->biomericClient() );

		//tab_control_->AddPage( settings_page, "Settings page", true);
		//settings_page->SetStateMonitorVariable( )

		this->Layout();	
		//this->SetIcon( Neurotechnology_XPM );
		this->SetTitle( text_holder_.tApplicationName() );
		this->SetSize( WINDOW_WIDTH, WINDOW_HEIGHT );
		this->Centre();
	}
*/

	

}}