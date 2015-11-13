#pragma once

#ifndef Bio_Surveillance_Page_INCLUDED
#define Bio_Surveillance_Page_INCLUDED

#include "tab_page.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioSurveillancePage : public TabPage
		{

		public:
			BioSurveillancePage(wxWindow* parent
				                 , wxWindowID id = wxID_ANY);

			~BioSurveillancePage();

		private:		
			void do_subscribe();
			void do_unsubscribe();
			void do_create();

		private:

		};
	}
}

#endif


