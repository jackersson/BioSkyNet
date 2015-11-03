#ifndef Bio_Face_Page_INCLUDED
#define Bio_Face_Page_INCLUDED

#include "iui_subscrible.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioFacePage : public wxPanel, public IUiSubscrible
		{
		public:
			BioFacePage(wxWindow* parent, wxWindowID id);
			virtual ~BioFacePage();
				
		private:
			void do_create     ();
			void do_unsubscribe();
			void do_subscribe  ();

		private:
			
			void onEnrollFromCamera  (wxCommandEvent& e);
			void onEnrollFromImage   (wxCommandEvent& e);
			void onSelectedFaceDelete(wxCommandEvent& e);

		private:
			wxStaticBitmap*     person_photo_          ;
			wxDataViewListCtrl* enrolled_photos_holder_;
			wxStaticBitmap*     enroll_status_image_   ;

			wxBitmapButton* btn_enroll_from_camera_;
			wxBitmapButton* btn_enroll_from_image_ ;
			wxBitmapButton* btn_face_delete_       ;
		};
	}
}

#endif

