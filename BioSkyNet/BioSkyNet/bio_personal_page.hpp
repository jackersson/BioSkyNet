#ifndef Bio_Personal_Page_INCLUDED
#define Bio_Personal_Page_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioPersonalPage : public wxPanel
		{
		public:
			BioPersonalPage(wxWindow* parent, wxWindowID id);
			virtual ~BioPersonalPage();

		protected:
			void create()
			{
				do_create();
			}

		private:
			virtual void do_create();

		private:
			wxStaticBitmap* person_photo_;
			wxPropertyGrid* person_information_;
		};
	}
}

#endif

