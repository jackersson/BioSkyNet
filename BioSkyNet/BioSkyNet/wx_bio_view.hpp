#ifndef wx_Bio_View_Included
#define wx_Bio_View_Included

#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/scrolwin.h>
#include <wx/artprov.h>
#include <wx/menu.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <stdlib.h>

#include "Poco/SharedPtr.h"

namespace SmartBio {
	namespace View
	{

		wxDECLARE_EVENT(wxEVT_N_VIEW_ZOOM_CHANGED       , wxCommandEvent);
		wxDECLARE_EVENT(wxEVT_N_VIEW_ZOOM_TO_FIT_CHANGED, wxCommandEvent);

		class wxBioView : public wxScrolledWindow
		{
		public:
			wxBioView( wxWindow *parent, wxWindowID winid = wxID_ANY)
				       : wxScrolledWindow(parent, winid, wxDefaultPosition, wxDefaultSize
							 , wxHSCROLL | wxVSCROLL | wxFULL_REPAINT_ON_RESIZE | wxBORDER_SIMPLE)
							 , hand_open_cursor_icon_()
							 , hand_closed_cursor_icon_()
			{
				zoom_factor_         = 1    ;
				zoom_to_fit_         = true ;
				enable_context_menu_ = true ;
				hand_tool_active_    = false;

				SetBackgroundStyle(wxBG_STYLE_CUSTOM);
				SetScrollRate(1, 1);

				context_menu_ = new wxMenu();
				context_menu_->AppendCheckItem(ID_ZOOM_FIT, wxT("Zoom to fit"));
				context_menu_->Check (ID_ZOOM_FIT, true);
				context_menu_->Append(ID_ZOOM_50 , wxT("Zoom 50%"));
				context_menu_->Append(ID_ZOOM_100, wxT("Zoom 100%"));
				context_menu_->Append(ID_ZOOM_200, wxT("Zoom 200%"));

				SetCursor(hand_open_cursor_icon_);				
			}

			virtual ~wxBioView()	{	}

			void zoomToFit()
			{
				wxSize clientSize = GetClientSize();

				if (  bio_view_size_.GetWidth() != 0
					 && clientSize.x != 0
					 && bio_view_size_.GetHeight() != 0
					 && clientSize.y != 0)
				{
					double newZoomFactor = wxMin((double)(clientSize.x - 10) / (bio_view_size_.GetWidth() + 10),
						                           (double)(clientSize.y - 10) / (bio_view_size_.GetHeight() + 10));
					if (newZoomFactor != zoom_factor_)
					{
						zoom(newZoomFactor);
					}
				}
			}

			void setZoom(double value)
			{
				if (zoom_factor_ != value)				
					zoom(value);				
			}

			double getZoom()
			{
				return getZoomFactor();
			}

			void setZoomToFit(bool value)
			{
				if (zoom_to_fit_ != value)
				{
					zoom_to_fit_ = value;
					if (value)
						zoomToFit();

					Refresh();

					context_menu_->Check(ID_ZOOM_FIT, value);

					wxCommandEvent evt(wxEVT_N_VIEW_ZOOM_TO_FIT_CHANGED, GetId());
					wxPostEvent(this, evt);
				}
			}

			bool getZoomToFit() 
			{ 				
				return zoom_to_fit_;
			}

			void enableContextMenu(bool value = true) 
			{ 
				enable_context_menu_ = value; 
			}

			bool isContextMenuEnabled()
			{ 
				return enable_context_menu_; 
			}

		protected:
			//wxWidgets function
			virtual void DoSetSize(int x, int y, int width, int height, int sizeFlags)
			{
				wxWindow::DoSetSize(x, y, width, height, sizeFlags);
				if (zoom_to_fit_) zoomToFit();
			}

			void setViewSize(int viewWidth, int viewHeight)
			{
				wxRect oldImageRect = getImageRect();

				bio_view_size_ = wxSize(viewWidth, viewHeight);
				if (zoom_to_fit_ && !(viewWidth == 1 && viewHeight == 1)) zoomToFit();

				wxSize zoomedSize((int)(viewWidth * zoom_factor_), (int)(viewHeight * zoom_factor_));
				wxSize virtualSize = GetVirtualSize();
				if (virtualSize.x != zoomedSize.GetWidth() + 10
					|| virtualSize.y != zoomedSize.GetHeight() + 10)
				{
					SetVirtualSize(zoomedSize.GetWidth() + 10, zoomedSize.GetHeight() + 10);
				}

				wxRect imageRect = getImageRect();
				imageRect = imageRect.Union(oldImageRect);

				Refresh(false, &imageRect);
			}

			wxRect getImageRect()
			{
				wxSize imageSize(bio_view_size_);
				imageSize.x = (int)((double)imageSize.x * zoom_factor_);
				imageSize.y = (int)((double)imageSize.y * zoom_factor_);

				wxSize clientSize = GetClientSize();
				wxRect imageRect(5, 5, imageSize.x, imageSize.y);
				if (imageSize.x + 10 < clientSize.x) imageRect.x = (clientSize.x - imageSize.x) / 2;
				if (imageSize.y + 10 < clientSize.y) imageRect.y = (clientSize.y - imageSize.y) / 2;

				int viewX, viewY;
				GetViewStart(&viewX, &viewY);
				imageRect.x -= viewX;
				imageRect.y -= viewY;

				return imageRect;
			}

			wxMenu* GetContextMenu()
			{
				return context_menu_;
			}

#if wxUSE_GRAPHICS_CONTEXT == 1
			virtual void OnDraw(wxGraphicsContext *gc) = 0;
#else
			virtual void OnDraw(wxDC&) = 0;
#endif

			virtual void onLeftDown(wxMouseEvent& event)
			{
				GetViewStart(&view_X_position_, &view_Y_position_);
				start_position_ = event.GetPosition();
				SetCursor(hand_closed_cursor_icon_);
				hand_tool_active_ = true;
			}

			virtual void onLeftUp(wxMouseEvent& /*event*/)
			{
				SetCursor(hand_open_cursor_icon_);
				hand_tool_active_ = false;
			}

			virtual void onMouseMove(wxMouseEvent& event)
			{
				if (event.Dragging() && hand_tool_active_)
				{
					wxPoint currentPos = event.GetPosition();
					Scroll(view_X_position_ - currentPos.x + start_position_.x, view_Y_position_ - currentPos.y + start_position_.y);
				}
			}

			virtual void OnRightDown(wxMouseEvent& event)
			{
				if (enable_context_menu_) PopupMenu(context_menu_, event.GetPosition());
			}

			void zoom(double zoomFactor)
			{
				if (zoomFactor < 0.05)
				{
					zoomFactor = 0.05;
				}
				if (zoomFactor > 5)
				{
					zoomFactor = 5;
				}
				zoom_factor_ = zoomFactor;

				wxRect currentImageRect = getImageRect();

				wxSize clientSize = GetClientSize();
				int scrollX = currentImageRect.width + 10 > clientSize.x ?
					(currentImageRect.width - clientSize.x) : 0;
				int scrollY = currentImageRect.height + 10 > clientSize.y ?
					(currentImageRect.height - clientSize.y) : 0;

				SetVirtualSize(currentImageRect.width + 10, currentImageRect.height + 10);
				Scroll(scrollX / 2, scrollY / 2);

				Refresh();

				wxCommandEvent evt(wxEVT_N_VIEW_ZOOM_CHANGED, GetId());
				wxPostEvent(this, evt);
			}

			double getZoomFactor()
			{
				return zoom_factor_;
			}

			enum BioZoom
			{
				ID_ZOOM_FIT = wxID_HIGHEST + 1,
				ID_ZOOM_50,
				ID_ZOOM_100,
				ID_ZOOM_200,
				ID_WX_NVIEW_HIGHEST,
			};

		private:

#if wxUSE_GRAPHICS_CONTEXT == 1
			void OnPaint(wxPaintEvent&)
			{
				wxAutoBufferedPaintDC dc(this);
				dc.SetBackground(wxBrush(this->GetBackgroundColour()));
				dc.Clear();
				dc.SetBackground(wxNullBrush);

				::std::auto_ptr<wxGraphicsContext> gc(wxGraphicsContext::Create(dc));

				wxRect imageRect = getImageRect();

				wxGraphicsMatrix oldTransform = gc->GetTransform();

				gc->Translate(imageRect.x, imageRect.y);
				gc->Scale(zoom_factor_, zoom_factor_);

				wxFont font(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
				gc->SetFont(font, wxColour(0, 0, 0));

				OnDraw(gc.get());

				gc->SetTransform(oldTransform);
			}
#else
			void OnPaint(wxPaintEvent&)
			{
				wxAutoBufferedPaintDC dc(this);
				dc.SetBackground(wxBrush(this->GetBackgroundColour()));
				dc.Clear();
				dc.SetBackground(wxNullBrush);
				wxRect imageRect = getImageRect();

				wxPoint origin = dc.GetDeviceOrigin();
				dc.SetDeviceOrigin(imageRect.x, imageRect.y);

				double oldScaleX, oldScaleY;
				dc.GetUserScale(&oldScaleX, &oldScaleY);
				dc.SetUserScale(zoom_factor_, zoom_factor_);

				OnDraw(dc);

				dc.SetUserScale(oldScaleX, oldScaleY);
				dc.SetDeviceOrigin(origin.x, origin.y);
			}
#endif

			void onEraseBackGround(wxEraseEvent& /*event*/)
			{
			}

			void onZoom(wxCommandEvent& event)
			{
				switch (event.GetId())
				{
				case ID_ZOOM_FIT:
					setZoomToFit(context_menu_->IsChecked(ID_ZOOM_FIT));
					break;
				case ID_ZOOM_50:
					setZoomToFit(false);
					setZoom(0.5);
					break;
				case ID_ZOOM_100:
					setZoomToFit(false);
					setZoom(1);
					break;
				case ID_ZOOM_200:
					setZoomToFit(false);
					setZoom(2);
					break;
				}
				Refresh(false);
			}

			void onMouseWheel(wxMouseEvent& event)
			{
				if (event.ControlDown() && !zoom_to_fit_)
				{
					int wheelDelta = event.GetWheelDelta();
					if (event.GetWheelRotation() <= -wheelDelta)
					{
						zoom(zoom_factor_ * (1 - 0.1));
					}
					else if (event.GetWheelRotation() >= wheelDelta)
					{
						zoom(zoom_factor_ * (1 + 0.1));
					}
				}
				else
				{
					event.Skip();
				}
			}

			double zoom_factor_  ;
			wxSize bio_view_size_;

			int view_X_position_;
			int view_Y_position_;

			wxPoint  start_position_         ;
			wxCursor hand_open_cursor_icon_  ;
			wxCursor hand_closed_cursor_icon_;

			Poco::SharedPtr<wxMenu> context_menu_;

			bool hand_tool_active_   ;
			bool zoom_to_fit_        ;
			bool enable_context_menu_;

			DECLARE_EVENT_TABLE();
		};

	}
}

#endif 
