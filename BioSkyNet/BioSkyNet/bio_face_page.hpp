#ifndef Bio_Face_Page_INCLUDED
#define Bio_Face_Page_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

#include "bio_resources.hpp"

#include "bio_face_resource.hpp"
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
			void do_create();
			void do_unsubscribe();
			void do_subscribe();

		private:
			
			void enrollFromCamera(wxCommandEvent& e);
			void enrollFromImage(wxCommandEvent& e);
			void faceDelete(wxCommandEvent& e);

		private:
			wxStaticBitmap* person_photo_;
			wxDataViewListCtrl* photo_holder_;
			wxStaticBitmap* status_image_;

			wxBitmapButton* btn_enroll_from_camera_;
			wxBitmapButton* btn_enroll_from_image_;
			wxBitmapButton* btn_face_delete_;

			wxBitmapButton* addButton(UIBioFacePage index, wxWindow* parent, BioFaceResource& resource, wxBoxSizer* sizer);
			wxStaticBitmap* BioFacePage::addImage(int index, wxWindow* parent
				, BioControlResource<UInfoItem>& resource, wxSizer* sizer, int style);
		};
	}
}

#endif

