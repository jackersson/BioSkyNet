#ifndef wx_Bio_Face_View_INCLUDED
#define wx_Bio_Face_View_INCLUDED

#include "wx_bio_view.hpp"

namespace SmartBio 
{
	namespace View 
	{		
		
		class wxBioFaceView : public wxBioView
		{
		public:
			wxBioFaceView( wxWindow* parent
				           , wxWindowID winid = wxID_ANY);	
			
			~wxBioFaceView();	

			void clear   ();					
			void setImage(const wxImage& image);					
						
		protected:
			void subscribe  ();
			void unsubscribe();

#if wxUSE_GRAPHICS_CONTEXT == 1
			virtual void OnDraw(wxGraphicsContext *gc)
			{
				if (!main_bitmap_.IsOk()) return;
				if (main_bitmap_.GetRefData())
				{
					gc->DrawBitmap(main_bitmap_, 0, 0, main_bitmap_.GetWidth(), main_bitmap_.GetHeight());
				}

				gc->Clip(0, 0, main_bitmap_.GetWidth(), main_bitmap_.GetHeight());

			
				gc->ResetClip();				

				do_additional_draw(gc);
			}

		private:
			virtual void do_additional_draw(wxGraphicsContext* /*gc*/) {};
		
#else
		protected:
			virtual void OnDraw(wxDC& dc)
			{
				if (main_bitmap_.GetRefData())
				{
					dc.DrawBitmap(main_bitmap_, 0, 0, false);
				}				

				do_additional_draw(dc);
			}

		private:
			virtual void do_additional_draw(wxDC& dc) {};

			/*static inline void RotatePointAt(double x, double y, double centerX, double centerY, double angle, double *ox, double *oy)
			{
				*ox = centerX + cos(angle) * (x - centerX) - sin(angle) * (y - centerY);
				*oy = centerY + sin(angle) * (x - centerX) + cos(angle) * (y - centerY);
			}
*/

#endif

		protected:
#if wxUSE_GRAPHICS_CONTEXT == 1
			virtual void DrawAttributes(wxGraphicsContext* /*gc*/)
			{
				
			}
#else
			virtual void DrawAttributes(wxDC & dc)
			{
			
			}
#endif			
		protected:
			wxBitmap main_bitmap_;	

		/*private:
			virtual void do_additional_draw(wxGraphicsContext *gc) {};
*/

	
	
		};


	}
}

#endif 
