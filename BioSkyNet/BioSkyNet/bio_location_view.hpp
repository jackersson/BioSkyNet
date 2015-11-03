#ifndef Bio_Location_View_INCLUDED
#define Bio_Location_View_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

#include "bio_resources.hpp"

#include "bio_location_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioLocationView : public wxPanel
		{
		public:
			BioLocationView(wxWindow* parent, wxWindowID id);
			virtual ~BioLocationView();

			void setCameraPlayState(bool flag);
			void BioLocationView::setButtonPressedState(bool flag);
			void BioLocationView::setFaceCheckerState(bool flag);
			void BioLocationView::setDoorState(bool flag);
			void BioLocationView::setControllerState(bool flag);




		protected:
			void create()
			{
				do_create();
			}

		private:
			std::pair<wxBitmap, wxBitmap> icamera_on_air_;
			std::pair<wxBitmap, wxBitmap> icontroller_status_;


		private:
			virtual void do_create();

			void fillBitmap( int index, wxBitmap& parent
				             , BioControlResource<UInfoItem>& resource);



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

