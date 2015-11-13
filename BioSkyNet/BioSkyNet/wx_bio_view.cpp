#include "stdafx.h"
#include "wx_bio_view.hpp"
#include "wx_bio_view_zoom_slider.hpp"

namespace SmartBio
{
	namespace View
	{
		wxDEFINE_EVENT(wxEVT_N_VIEW_ZOOM_CHANGED       , wxCommandEvent);
		wxDEFINE_EVENT(wxEVT_N_VIEW_ZOOM_TO_FIT_CHANGED, wxCommandEvent);

		BEGIN_EVENT_TABLE(wxBioViewZoomSlider, wxWindow)
			EVT_SLIDER  (wxID_ANY, wxBioViewZoomSlider::onSliderValueChanged )
			EVT_SPINCTRL(wxID_ANY, wxBioViewZoomSlider::onSpinValueChanged   )
			EVT_CHECKBOX(wxID_ANY, wxBioViewZoomSlider::onChbZoomToFitChanged)
		END_EVENT_TABLE()

		BEGIN_EVENT_TABLE(wxBioView, wxScrolledWindow)
			EVT_ERASE_BACKGROUND(wxBioView::onEraseBackGround)
			EVT_PAINT           (wxBioView::OnPaint          )
			EVT_LEFT_DOWN       (wxBioView::onLeftDown       )
			EVT_MOTION          (wxBioView::onMouseMove      )
			EVT_LEFT_UP         (wxBioView::onLeftUp         )
			EVT_MOUSEWHEEL      (wxBioView::onMouseWheel     )
			EVT_RIGHT_DOWN      (wxBioView::OnRightDown      )
			EVT_MENU_RANGE      (ID_ZOOM_FIT, ID_ZOOM_200, wxBioView::onZoom)
		END_EVENT_TABLE()
	}
}