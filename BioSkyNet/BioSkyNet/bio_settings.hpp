#pragma once
#include "bio_settings_resource.hpp"
#include "bio_resources.hpp"


#include "iui_subscrible.hpp"

#ifndef BioSettings_INCLUDED
#define BioSettings_INCLUDED

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
			wxBitmapButton* btn_apply_;
			wxBitmapButton* btn_ok_;
			wxBitmapButton* btn_reset_to_default_;

		private:
			void BioSettings::btApply(wxCommandEvent& e);
			void BioSettings::btOk(wxCommandEvent& e);
			void BioSettings::btResetToDefault(wxCommandEvent& e);

		private: 
			void do_create();
			void do_subscribe();
			void do_unsubscribe();

			
			wxBitmapButton* BioSettings::addButton(UIBioSettings index, wxWindow* parent, BioSettingsResource& resource, wxBoxSizer* sizer);

			wxStaticBitmap* BioSettings::addImage(int index, wxWindow* parent
				, BioControlResource<UInfoItem>& resource, wxSizer* sizer, int style);
		};
	}
}

#endif


