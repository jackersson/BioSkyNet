#include "stdafx.h"
#include "bio_surveillance_page.hpp"
#include "bio_resources.hpp"
#include "bio_location_resource.hpp"
#include "bio_location_view.hpp"
namespace SmartBio
{
	namespace View
	{

		BioSurveillancePage::BioSurveillancePage(wxWindow* parent
			, wxWindowID id) :TabPage(parent, id)
		{
			create();
		}

		BioSurveillancePage::~BioSurveillancePage()
		{

		}

		


		//void do_initialize();
		void BioSurveillancePage::do_subscribe()
		{

		}
		void BioSurveillancePage::do_unsubscribe()
		{

		}
		void BioSurveillancePage::do_create()
		{

			wxBoxSizer* main_surveillance_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_surveillance_sizer);

			wxGridSizer* grid_info_sizer = new wxGridSizer(0, 2, 0, 0);
			main_surveillance_sizer->Add(grid_info_sizer, 1, wxEXPAND, 5);

			BioLocationView* location = new BioLocationView(this, wxID_ANY);
			grid_info_sizer->Add(location, 1, wxEXPAND | wxALL, 5);

			BioLocationView* location2 = new BioLocationView(this, wxID_ANY);
			grid_info_sizer->Add(location2, 1, wxEXPAND | wxALL, 5);
			


			this->Layout();

			
		}

		

		wxStaticText* BioSurveillancePage::addText(int index, wxWindow* parent
			, BioControlResource<UInfoItem>& resource, wxSizer* sizer, int style)
		{
			bool flag(false);
			View::UInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxStaticText* txt = new wxStaticText(parent, wxID_ANY, item.text(), wxDefaultPosition, wxSize(-1, -1), 0);

				sizer->Add(txt, 1, style, 5);

				return txt;
			}
		}





		wxStaticBitmap* BioSurveillancePage::addImage( int index, wxWindow* parent
			, BioControlResource<UInfoItem>& resource, wxSizer* sizer, int style)
		{
			bool flag(false);
			View::UInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxStaticBitmap* img = new wxStaticBitmap(parent, wxID_ANY, item.bitmap(), wxDefaultPosition, wxSize(-1, -1), 0);

				sizer->Add(img, 1, style, 5);

				return img;
			}
		}




	}
}