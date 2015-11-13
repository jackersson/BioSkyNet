#include "stdafx.h"
#include "bio_application.hpp"
#include "bio_form.hpp"

#include "bio_view.hpp"
//#include "../SmartBioModel/bio_model.hpp"


IMPLEMENT_APP( SmartBio::View::BioApplication )

namespace SmartBio { namespace View
{
	bool BioApplication::OnInit()
	{
		try
		{
			//Poco::SharedPtr<BioModel> model = BioModel::instance();
			wxImage::AddHandler(new wxPNGHandler);
			wxImage::AddHandler(new wxBMPHandler);
			Poco::SharedPtr<BioView> view = BioView::instance( NULL );

			view->setTopWindow( *this );	

		}		
		catch ( std::exception&  )
		{
			//wxExceptionDlg::Show(wxString(ex.what(), wxConvLibc));
			
			return false;
		}

		return true;
	}

	
	/*int BioApplication::OnExit()
	{
		try
		{
		  
		}
		catch (std::exception& ex)
		{
			//wxExceptionDlg::Show(wxString(ex.what(), wxConvLibc));
		}
		
		return wxApp::OnExit();
	}*/
	
}}
