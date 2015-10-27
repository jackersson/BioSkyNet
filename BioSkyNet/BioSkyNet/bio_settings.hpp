#pragma once

#ifndef BioSettings_INCLUDED
#define BioSettings_INCLUDED

namespace SmartBio
{
	namespace View
	{
		class BioSettings : public wxPropertyGridManager
		{

		public:
			BioSettings( wxWindow* parent
				         , wxWindowID id = wxID_ANY
			           , const wxPoint& pos = wxDefaultPosition
				         , const wxSize& size = wxDefaultSize
				         , long style = wxPGMAN_DEFAULT_STYLE
				         , const wxString& name = wxPropertyGridManagerNameStr );

			~BioSettings();
			
		private: 
			void do_initialize();




		};
	}
}

#endif


