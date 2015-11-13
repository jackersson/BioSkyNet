#include "stdafx.h"
#include "wx_bio_face_streamer.hpp"

#include "Poco/Observer.h"

#include "Poco/ScopedLock.h"
#include "Poco/Mutex.h"

namespace SmartBio
{
	namespace View
	{
		wxDEFINE_EVENT(wxEVT_CAPTURE_FACE_THREAD, wxThreadEvent);

		wxBioFaceStreamer::wxBioFaceStreamer(wxWindow* parent, wxWindowID id) : wxWindow(parent, id)
		{			
			create();
			subscribe();
		}

		wxBioFaceStreamer::~wxBioFaceStreamer()
		{
		}
		
		/*void wxBioFaceStreamer::updateDetector(Poco::SharedPtr<Detector::FRsdkClient> frsdk_client, const std::string& detector_name)
		{
		  detector_name_ = detector_name;
			frsdk_client_  = frsdk_client;

			if (frsdk_client_.isNull())
				return;

			Poco::Observer<wxBioFaceStreamer, Detector::CaptureFrameNotification> observer(*this, &wxBioFaceStreamer::onFrameChanged);
		  if (frsdk_client_->hasTaskObserver(detector_name, observer))
		    frsdk_client_->removeTaskObserver(detector_name, observer);
		  
		  frsdk_client_->addTaskObserver(detector_name_, observer);
		}

		void wxBioFaceStreamer::onFrameChanged(Detector::CaptureFrameNotification* pNf)
		{
			if (pNf != NULL )
			{
				//Detector::CaptureFrameArgs* args = pNf->args();
				//wxThreadEvent evt(wxEVT_CAPTURE_FACE_THREAD, ID_EVENT_CAPTURE_FRAME_CHANGED);
				///evt.SetRefData((wxObjectRefData*)args);
				//this->QueueEvent(evt.Clone());
				//wxMessageOutputDebug().Printf("here3");
		
				Detector::CaptureFrameArgs* args = pNf->args();
				wxImage* image = new wxImage(args->width(), args->height(), args->bytes());	
				bio_face_view_->setImage(*image);			
				delete image;
			}
			else Refresh();
		}*/

	/*	void wxBioFaceStreamer::onThreadEvent(wxThreadEvent& event)
		{
			Poco::Mutex::ScopedLock lock(mutex_);
			int id = event.GetId();
			try
			{
				switch (id)
				{
				case ID_EVENT_CAPTURE_FRAME_CHANGED:
				{					
					Detector::CaptureFrameArgs* args = (Detector::CaptureFrameArgs*)event.GetRefData();			
					wxImage* image = new wxImage(args->width(), args->height(), args->bytes());				
					bio_face_view_->setImage(*image);					
					delete image;			
					break;
				}
				};
			}
			catch (std::exception& error)
			{
				wxLogError(error.what());
			}
		}
*/

		void wxBioFaceStreamer::do_create()
		{
			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			bio_face_view_ = new wxBioFaceView(this);

			bio_face_view_->enableContextMenu(true);
			bio_face_view_->SetWindowStyle(wxSIMPLE_BORDER);
			bio_face_view_->SetBackgroundColour(wxNullColour);

			bio_face_zoom_slider_ = new wxBioViewZoomSlider(this);
			bio_face_zoom_slider_->setBioView(bio_face_view_);

			main_sizer->Add(bio_face_view_       , 2, wxEXPAND, 5);
			main_sizer->Add(bio_face_zoom_slider_, 0, wxEXPAND, 5);
		
			this->Layout();
		}

		void wxBioFaceStreamer::loadFromFile(wxString file_name)
		{
			wxImage image(file_name);
			if (image.IsOk())
				bio_face_view_->setImage(image);
			else
			{
				wxLogError("Cannot open file '%s'.", file_name);
				return;
			}
		}

		void wxBioFaceStreamer::do_subscribe()
		{
			//this->Bind(wxEVT_CAPTURE_FACE_THREAD, &wxBioFaceStreamer::onThreadEvent, this);
		}

		void wxBioFaceStreamer::do_unsubscribe()
		{
			//this->Unbind(wxEVT_CAPTURE_FACE_THREAD, &wxBioFaceStreamer::onThreadEvent, this);
		}
	}
}