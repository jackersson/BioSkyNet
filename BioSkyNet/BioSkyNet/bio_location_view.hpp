#ifndef Bio_Location_View_INCLUDED
#define Bio_Location_View_INCLUDED

namespace SmartBio
{
	namespace View
	{
		class BioLocationView : public wxPanel
		{
		public:
			BioLocationView(wxWindow* parent, wxWindowID id);
			virtual ~BioLocationView();

			void setCameraPlayState   (bool flag);
			void setButtonPressedState(bool flag);
			void setFaceCheckerState  (bool flag);
			void setDoorState         (bool flag);
			void setControllerState   (bool flag);
			
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

		private:
			wxStaticBitmap* img_door_status_          ;
			wxStaticBitmap* img_controller_status_    ;
			wxStaticBitmap* img_face_checker_         ;
			wxStaticBitmap* img_device_button_pressed_;
			wxStaticBitmap* camera_on_air_            ;
			wxStaticBitmap* video_stream_             ;

			wxStaticText* txt_location_name_;
			wxStaticText* camera_fps_       ;
			wxStaticText* txt_current_time_ ;		
		};
	}
}

#endif

