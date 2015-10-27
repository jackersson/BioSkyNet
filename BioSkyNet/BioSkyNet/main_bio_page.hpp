#pragma once

#ifndef Main_Bio_Page_INCLUDED
#define Main_Bio_Page_INCLUDED

#include "tab_page.hpp"

namespace SmartBio
{
	namespace View
	{
		class MainBioPage : public TabPage
		{

		public:
			MainBioPage( wxWindow* parent
				         , wxWindowID id = wxID_ANY );

			~MainBioPage();

		private:
			//void do_initialize();
			void do_subscribe();
			void do_unsubscribe();
			void do_create();

		private:
			wxListbook* listbook_;




		};
	}
}

#endif


