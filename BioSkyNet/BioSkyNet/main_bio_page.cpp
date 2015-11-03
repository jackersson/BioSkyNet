#include "stdafx.h"
#include "main_bio_page.hpp"

#include <memory>

//#include "wx/withimages.h"
#include "uinfo_item.hpp"
#include "bio_listbook_utils.hpp"
#include "bio_resources.hpp"
#include "bio_personal_page.hpp"
//#include "bio_info_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		MainBioPage::MainBioPage( wxWindow* parent
			                      , wxWindowID id) : TabPage( parent, id )
		{
			create();
		}

		MainBioPage::~MainBioPage()
		{

		}

		void MainBioPage::do_subscribe()
		{

		}

		void MainBioPage::do_unsubscribe()
		{

		}

		void MainBioPage::do_create()
		{
			Poco::SharedPtr<BioInfoResource> resource(new BioInfoResource());
			BioListbookUtils utils;

			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
			main_sizer->Add(sizer, 1, wxALL | wxEXPAND, 5);
						
			listbook_ = new wxListbook(this, wxID_ANY);
			
			wxImageList* image_list = new wxImageList(64, 64);
			listbook_->AssignImageList(image_list);

			wxPanel* panel = new wxPanel(listbook_, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL | wxBORDER_THEME);
		
			BioPersonalPage* personal_page = new BioPersonalPage(listbook_, wxID_ANY);

			utils.addPage(UIResources::ID_PERSON_INFO_PAGE     , personal_page, *listbook_, *resource, *image_list, true);
			utils.addPage(UIResources::ID_FACE_INFO_PAGE       , panel, *listbook_, *resource, *image_list, false);
			utils.addPage(UIResources::ID_FINGERPRINT_INFO_PAGE, panel, *listbook_, *resource, *image_list, false);
			utils.addPage(UIResources::ID_IRIS_INFO_PAGE       , panel, *listbook_, *resource, *image_list, false);
			
			sizer->Add(listbook_, 1, wxALL | wxEXPAND, 5);

			this->Layout();
		}


	}
}