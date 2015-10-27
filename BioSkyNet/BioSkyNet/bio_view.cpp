#include "stdafx.h"
#include "bio_view.hpp"

//#include "notifications.h"

#include "bio_form.hpp"

//#include "start_page.hpp"
///#include "subject_page.hpp"
//#include "settings_page.hpp"
//#include "ui_texts.hpp"


namespace SmartBio { namespace View 
{
	//using namespace Interfaces;

	BioView::BioView( Poco::SharedPtr<Interfaces::IModel>& model ) 
		              : IView(model)
	{		
		initialize(); 
	}


	BioView::~BioView()
	{
		
	}	

	BioForm const& BioView::getForm() const
	{
		return *bio_form_;
	}

	void BioView::do_initialize()
	{
		
		bio_form_ = new BioForm( NULL );			
		bio_form_->Show(true);
		//bio_form_->Refresh();
		//bio_form_->Update();		

/**		Texts::PagesNames pages_names;*/

		//log_control_ = LogControl::instance( bio_form_ );

		//tab_control_ = new TabController( bio_form_, wxID_ANY );
		//bio_form_->addItem(tab_control_, 1, wxEXPAND | wxALL, 0);

		//StartPage*    start_page = new StartPage( bio_form_, bio_form_->logControl(),  wxID_ANY);
		//ab_control_->AddPage(start_page, pages_names.tStartPage(), true);
	/*
		BioModel* model = BioModel::instance();*/

		//SettingsPage* settings_page = new SettingsPage(tab_control_, log_control_);
		//tab_control_->AddPage( settings_page, pages_names.tSettingsPage(), true );

		//SubjectPage*  subject_page = new SubjectPage(log_control_, tab_control_);
		//tab_control_->AddPage(subject_page, pages_names.tSubjectPage(), true);

		//SettingsPage* settings_page = new SettingsPage( tab_control_, log_control_ );
		//tab_control_->AddPage( settings_page, pages_names.tSettingsPage(), true );

		//BioModel* model = BioModel::instance();
		//settings_page->initialize( model->biomericClient() );

		//subscribe();
		
		//postNotification( new LicenseNotification() );
	}

	void BioView::subscribe()
	{/*
		try 
		{ 
			BioModel* model = BioModel::instance();
			model->logger()->addObserver(*bio_form_->logControl());
		}
		catch (std::exception& ex)
		{
			wxMessageBox(wxString::Format(wxT("Reason: %s"),
				((wxString)ex.what()).c_str()));
		}*/
	}

}}