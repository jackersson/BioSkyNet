#include "stdafx.h"
#include "bio_settings.hpp"

#include "bio_general_settings.hpp"

#include "bio_face_settings.hpp"

namespace SmartBio
{
	namespace View
	{
		BioSettings::BioSettings( wxWindow* parent, wxWindowID id, const wxPoint& pos
			                      , const wxSize& size, long style, const wxString& name  )
														: wxPropertyGridManager(parent, id, pos, size, style, name)
		{
			do_initialize();
		}

		BioSettings::~BioSettings()
		{
		
		}

		void BioSettings::do_initialize()
		{					
			//texts = new Texts::BioSettingsTexts();
			//wxInfoBar* infobar = new wxInfoBar()

			AddPage("General settings", wxArtProvider::GetBitmap(wxART_QUESTION), new BioGeneralSettings(  ));
			AddPage("Face settings", wxArtProvider::GetBitmap(wxART_FILE_OPEN), new BioFaceSettings());
		};
	}
}