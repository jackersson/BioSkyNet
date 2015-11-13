#pragma once

#ifndef Main_Bio_Page_INCLUDED
#define Main_Bio_Page_INCLUDED

#include "tab_page.hpp"

#include "bio_personal_page.hpp"
#include "bio_face_page.hpp"

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

			void updatePerson(bool default_update = true);
			void updatePerson(const Data::BioPerson& data);			

			//TODO Data::Bio Person should contain all information about Photo items
			//create new field in DataBioPerson
			void updateFace(const Data::BioPhotoItem& data);	

		private:

			//TODO for Taras (try to tranfer below variables to .cpp only
			BioPersonalPage* personal_page_;
			BioFacePage*     face_page_    ;

		private:		
			void do_subscribe  ();
			void do_unsubscribe();
			void do_create     ();

		private:
			wxListbook* listbook_;			
		};
	}
}

#endif


