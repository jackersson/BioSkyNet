#pragma once

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

		public:
			virtual void Init();
			//void Init();

		};
	}
}

#endif


