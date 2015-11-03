#ifndef Bio_Personal_Page_INCLUDED
#define Bio_Personal_Page_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

#include "bio_resources.hpp"

#include "bio_profile_resource.hpp"
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



			void do_create();
			void do_unsubscribe();
			void do_subscribe();

		private:
			void edit(wxCommandEvent& e);
			void open(wxCommandEvent& e);
			void save(wxCommandEvent& e);
			void btn_delete(wxCommandEvent& e);

		

		private:
			wxStaticBitmap* person_photo_;
			wxPropertyGrid* person_information_;
			wxBitmapButton* btn_edit_;
			wxBitmapButton* btn_open_;
			wxBitmapButton* btn_save_;
			wxBitmapButton* btn_delete_;

			wxBitmapButton* addButton(UIBioProfilePage index, wxWindow* parent, BioProfileResource& resource, wxBoxSizer* sizer);
		};
	}
}

#endif

