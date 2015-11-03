#pragma once

#ifndef Bio_Surveillance_Page_INCLUDED
#define Bio_Surveillance_Page_INCLUDED

#include "tab_page.hpp"

#include "uinfo_item.hpp"

#include "bio_control_resource.hpp"


namespace SmartBio
{
	namespace View
	{
		class BioSurveillancePage : public TabPage
		{

		public:
			BioSurveillancePage(wxWindow* parent
				                 , wxWindowID id = wxID_ANY);

			~BioSurveillancePage();

		private:
			//void do_initialize();
			void do_subscribe();
			void do_unsubscribe();
			void do_create();

		private:
			wxDataViewListCtrl*  users_list_;
			wxCommandLinkButton* btn_add_user_;

			wxStaticBitmap* img_door_;
			wxStaticBitmap* img_controller_status_;
			wxStaticBitmap* img_face_checker_;
			wxStaticBitmap* img_controll_button_;
			wxStaticBitmap* img_on_air_;
			wxStaticBitmap* stream_;

			wxStaticText* txt_location_name_;
			wxStaticText* txt_camera_info_;
			wxStaticText* txt_time_;


			wxStaticBitmap* addImage(int index, wxWindow* parent
				, BioControlResource<UInfoItem>& resource, wxSizer* sizer, int style);
			wxStaticText* addText(int index, wxWindow* parent, BioControlResource<UInfoItem>& resource, wxSizer* sizer, int style);



		};
	}
}

#endif


