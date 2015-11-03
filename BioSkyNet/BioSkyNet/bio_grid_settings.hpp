#pragma once
#include "bio_grid_settings_resource.hpp"

#ifndef BioGrid_Settings_INCLUDED
#define BioGrid_Settings_INCLUDED

namespace SmartBio
{
	namespace View
	{
		class BioGridSettings : public wxPropertyGridManager
		{

		public:
			BioGridSettings( wxWindow* parent
				             , wxWindowID id = wxID_ANY
				             , const wxPoint& pos = wxDefaultPosition
				             , const wxSize& size = wxDefaultSize
				             , long style = wxPGMAN_DEFAULT_STYLE
				             , const wxString& name = wxPropertyGridManagerNameStr);

			~BioGridSettings();

		private:
			

		private:
			void do_initialize();

			void BioGridSettings::addPage(int index, BioControlResource<UInfoItem>& resource, wxPropertyGridPage* page);




		};
	}
}

#endif


