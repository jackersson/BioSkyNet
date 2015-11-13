#ifndef wx_Bio_Face_Streamer_Included
#define wx_Bio_Face_Streamer_Included

#include "wx_bio_face_view.hpp"
#include "wx_bio_view_zoom_slider.hpp"

/*
#include "../SmartFaceDetector/capture_frame_notification.hpp"
#include "../SmartFaceDetector/frsdk_client.hpp"*/
namespace SmartBio
{
	namespace View
	{
		wxDECLARE_EVENT(wxEVT_CAPTURE_FACE_THREAD, wxThreadEvent);


	  enum BioFaceStreamerEvent
		{
		   ID_EVENT_CAPTURE_FRAME_CHANGED
		};

		class wxBioFaceStreamer : public wxWindow
		{
		public:
			wxBioFaceStreamer(wxWindow* parent, wxWindowID id = wxID_ANY);
			~wxBioFaceStreamer();

			void create()
			{
				do_create();
			}
			
			void subscribe()
			{
				do_subscribe();				
			}

			void unsubscribe()
			{
				do_unsubscribe();				
			}
			void wxBioFaceStreamer::loadFromFile(wxString file_name);

			/*void updateDetector(Poco::SharedPtr<Detector::FRsdkClient> frsdk_client, const std::string& camera_name);*/

		private:
			//void onThreadEvent (wxThreadEvent& evt);
		/*	void onFrameChanged(Detector::CaptureFrameNotification* pnf );*/
		private:
			std::string detector_name_;
		/*	Poco::SharedPtr<Detector::FRsdkClient> frsdk_client_        ;*/
			Poco::SharedPtr<wxBioFaceView>         bio_face_view_       ;		
			Poco::SharedPtr<wxBioViewZoomSlider>   bio_face_zoom_slider_;

			Poco::Mutex mutex_;

			wxBioFaceStreamer(const wxBioFaceStreamer&);
			void operator=(const wxBioFaceStreamer&);
			
		private:
			virtual void do_create     ();
			virtual void do_subscribe  ();
			virtual void do_unsubscribe();
			

		};

	}
}
#endif