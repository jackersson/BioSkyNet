#ifndef Bio_Face_Page_INCLUDED
#define Bio_Face_Page_INCLUDED

#include "iui_subscrible.hpp"

#include "../BioSkyNetData/bio_photo_item_binder.hpp"

#include "wx_bio_face_streamer.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioFacePage : public wxPanel, public IUiSubscrible
		{
		public:
			BioFacePage(wxWindow* parent, wxWindowID id);
			virtual ~BioFacePage();

			void update(const Data::BioPhotoItem& photo_item);
							
		private:
			void do_create     ();
			void do_unsubscribe();
			void do_subscribe  ();

		private:
			
			void onEnrollFromCamera  (wxCommandEvent& e);
			void onEnrollFromImage   (wxCommandEvent& e);
			void onSelectedFaceDelete(wxCommandEvent& e);
			void onItemSelection     (wxDataViewEvent& e);

		private:
			wxBioFaceStreamer*  person_photo_          ;
			wxDataViewCtrl*     enrolled_photos_holder_;
			wxStaticBitmap*     enroll_status_image_   ;


			
			
			wxBoolProperty*	          natural_skin_color_ ; 
			wxEnumProperty*       	  gender_             ;
			wxIntProperty*	          age_                ; 
			wxBoolProperty*	          glasses_            ;
			wxStringProperty*	        resolution_					; 
			wxEnumProperty*          	ethnicity_          ;
			wxFloatProperty*          sample_quality_     ;
			

			wxBitmapButton* btn_enroll_from_camera_;
			wxBitmapButton* btn_enroll_from_image_ ;
			wxBitmapButton* btn_face_delete_       ;

			wxDataViewColumn* first_name_;
			wxDataViewColumn* photo_path_;

			std::map<int, Data::BioPhotoItem> photo_items_;

		};
	}
}

#endif

