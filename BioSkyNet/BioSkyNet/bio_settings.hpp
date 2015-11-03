#pragma once

#ifndef BioSettings_INCLUDED
#define BioSettings_INCLUDED

#include "iui_subscrible.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioSettings : public wxPanel, public IUiSubscrible
		{

		public:
			BioSettings( wxWindow* parent
				         , wxWindowID id = wxID_ANY );

			~BioSettings();
			
		private:
			wxBitmapButton* btn_apply_           ;
			wxBitmapButton* btn_ok_              ;
			wxBitmapButton* btn_reset_to_default_;

		private:
			void BioSettings::onBtnApplyClick         (wxCommandEvent& e);
			void BioSettings::onBtnOkClick            (wxCommandEvent& e);
			void BioSettings::onBtnResetToDefaultClick(wxCommandEvent& e);

		private: 
			void do_create();
			void do_subscribe();
			void do_unsubscribe();	
		};
	}
}

#endif


