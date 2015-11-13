#include "stdafx.h"
#include "bio_form.hpp"

#include "bio_resources.hpp"
//#include "bio_view.hpp"

//#include "ui_texts.hpp"
#include "bio_main_menu.hpp"
#include "bio_toolbar.hpp"
#include "tab_controller.hpp"
//#include "start_page.hpp"

#include "main_bio_page.hpp"

#include "bio_form_resources.hpp"
#include "bio_application_resource.hpp"

#include "uapp_info_item.hpp"

#include "bio_settings.hpp"
//#include "log_control.hpp"
#include "bio_users_page.hpp"
#include "bio_surveillance_page.hpp"
#include "bio_journal_page.hpp"

#include <memory>

#include "Poco/AutoPtr.h"

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

	void BioForm::onCreatePersonTabNotification(const Poco::AutoPtr<CreatePersonTabNotification>& notif)
	{
		MainBioPage*  bio_page = new MainBioPage(this, wxID_ANY);
			
		if (!notif->isDefault())
		{
			Data::BioPerson data = notif->person();
			tab_controller_->AddPage(bio_page, data.firstName() + " " + data.lastName(), true, wxArtProvider::GetBitmap(wxART_OTHER));
			
			bio_page->updatePerson(data);
		}
		else
		{
			tab_controller_->AddPage(bio_page, "Add New User", true, wxArtProvider::GetBitmap(wxART_OTHER));
			bio_page->updatePerson(true);
		}



			
	}

	void BioForm::create()
	{

		SetMenuBar( new BioMainMenu() );


		//CreateStatusBar(2);
		logg_control_ = new wxTextCtrl(this, UIResources::ID_LOG_AUI, wxEmptyString, wxDefaultPosition
			, wxSize(250, 100), wxTE_MULTILINE | wxTE_READONLY | wxNO_BORDER);

		frame_manager_.SetManagedWindow(this);

		frame_manager_.AddPane(logg_control_, wxAuiPaneInfo().Bottom().Caption(_("Help Window")));
		
		wxSize client_size = GetClientSize();
		long m_notebook_style;
		m_notebook_style = wxAUI_NB_DEFAULT_STYLE | wxAUI_NB_TAB_EXTERNAL_MOVE | wxNO_BORDER;

		tab_controller_ = new TabController( this, wxID_ANY
			                    , wxPoint(client_size.x, client_size.y)
			                    , wxSize(430, 200)
			                    , m_notebook_style);
		//tb->Freeze();
		wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16, 16));

		//sizer->Add(m_tabbedPanel, 1, wxEXPAND | wxALL, 0);

		//StartPage*    start_page = new StartPage( this,  wxID_ANY);
		//tb->AddPage(start_page, "test", true, page_bmp);
		//tb->Thaw();

		/*MainBioPage*   bio_page = new MainBioPage(this, wxID_ANY);
		tab_controller_->AddPage(bio_page, "User Data", true, page_bmp);
		*/
		//tb->Thaw();

		BioUsersPage*   bio_users_page = new BioUsersPage(this, wxID_ANY);
		tab_controller_->AddPage(bio_users_page, "Users List", false, page_bmp);

		Poco::NObserver<BioForm, CreatePersonTabNotification> observer(*this, &BioForm::onCreatePersonTabNotification);
		bio_users_page->addObserver(observer);


		BioSurveillancePage*   bio_surveillance_page = new BioSurveillancePage(this, wxID_ANY);
		tab_controller_->AddPage(bio_surveillance_page, "Video Surveillance", false, page_bmp);

		BioJournalPage*   bio_journal_page = new BioJournalPage(this, wxID_ANY);
		tab_controller_->AddPage(bio_journal_page, "Journal", false, page_bmp);

		frame_manager_.AddPane(tab_controller_, wxAuiPaneInfo().CenterPane());

		BioToolBar* toolbar = new BioToolBar( this, UIResources::ID_TOOLBAR_MAIN, wxDefaultPosition, wxDefaultSize
			                                  , wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW | wxAUI_TB_VERTICAL );

		frame_manager_.AddPane(toolbar, wxAuiPaneInfo().Name(wxT("tb5")).Caption(wxT("Sample Vertical Toolbar")).
			ToolbarPane().Left().
			GripperTop());

		wxPanel* panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(250, 100));
		wxBoxSizer* boxSizer393 = new wxBoxSizer(wxVERTICAL);
		panel1->SetSizer(boxSizer393);

//		wxListbook* ls;
		

		//wxPropertyGridManager* pr_gris = new wxPropertyGridManager(panel1, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxPG_TOOLBAR|wxPG_DESCRIPTION | wxPG_SPLITTER_AUTO_CENTER | wxPG_BOLD_MODIFIED);
		//wxPGProperty* property1 = pr_gris->Append(new wxStringProperty(_("First Name"), wxPG_LABEL, wxT("")));
		//property1->SetHelpString(wxT(""));

		//pr_gris->AddPage("general", );
		//pr_gris->AddPage("face");

		

		BioSettings* settings = new BioSettings(this, wxID_ANY);

		//boxSizer393->Add(settings, 1, wxALL | wxEXPAND, 5);

		std::unique_ptr<BioFormResource> resource(new BioFormResource());

		bool flag;
		UInfoItem stgs = resource->get(UIResources::ID_SETTINGS_TAB, flag);
		if (flag)
		{

			frame_manager_.AddPane(settings, wxAuiPaneInfo().Caption(stgs.text())
				.Right());
		}

		
		
		this->Layout();

		std::unique_ptr<BioApplicationResource> resource_app(new BioApplicationResource());


		UAppInfoItem app = resource_app->get(UIResources::ID_APPLICATION, flag);
		if (flag)
		{			

			//wxIconBundle * icons = new wxIconBundle(wxIcon("resources\\logo_32x32.xpm"));
			//icons->AddIcon(wxIcon("resources\\logo_32x32.xpm"));
			//wxIcon image;
			//if (image.LoadFile("resources\\logo_32x32.xpm"))
				//SetIcon(image)/*app.icon()*/;
			//SetIcon(wxIcon(sample_xpm));
			SetIcon(wxIcon(app.icon()));
			
			SetTitle( app.text());
		}

		//this->SetTitle( resource->textById(UIResources::ID_APPLICATION) );
		this->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->Centre();

		frame_manager_.Update();
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