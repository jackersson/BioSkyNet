#ifndef Bio_Personal_Page_INCLUDED
#define Bio_Personal_Page_INCLUDED

#include "iui_subscrible.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioPersonalPage : public wxPanel, public IUiSubscrible
		{
		public:
			BioPersonalPage(wxWindow* parent, wxWindowID id);

			virtual ~BioPersonalPage();

		private:
			void do_create     ();
			void do_unsubscribe();
			void do_subscribe  ();

		private:
			void onBtnEditClick    (wxCommandEvent& e);
			void onBtnFileOpenClick(wxCommandEvent& e);
			void onBtnSaveClick    (wxCommandEvent& e);
			void onBtnDeleteClick  (wxCommandEvent& e);		

		private:
			wxStaticBitmap* person_photo_      ;
			wxPropertyGrid* person_information_;
			wxBitmapButton* btn_edit_          ;
			wxBitmapButton* btn_open_          ;
			wxBitmapButton* btn_save_          ;
			wxBitmapButton* btn_delete_        ;

		};
	}
}

#endif

