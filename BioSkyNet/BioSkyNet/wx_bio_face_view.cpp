#include "stdafx.h"
#include "wx_bio_face_view.hpp"

namespace SmartBio
{
	namespace View
	{
		wxBioFaceView::wxBioFaceView( wxWindow* parent
																, wxWindowID winid )			                          
			                          : wxBioView(parent, winid)

		{
			SetScrollRate(1, 1);
			SetBackgroundColour(wxColour(150, 150, 150));

			subscribe();
		}

		wxBioFaceView::~wxBioFaceView()
		{
			unsubscribe();
		}

		void wxBioFaceView::subscribe()
		{
		
		}

		void wxBioFaceView::unsubscribe()
		{			
		}
		
		void wxBioFaceView::setImage(const wxImage& image)
		{
			if (image.IsOk())
			{
				main_bitmap_ = wxBitmap(image);
				setViewSize(image.GetWidth(), image.GetHeight());
			}
			else
			{
				main_bitmap_ = wxBitmap();
				setViewSize(1, 1);
			}
			Refresh(false);
		}

		void wxBioFaceView::clear()
		{
			main_bitmap_ = wxBitmap();
			Refresh(false);
		}
	}
}