#include "stdafx.h"
#include "bio_properties_utils.hpp"

#include "usettings_info_item.hpp"

namespace SmartBio
{
	namespace View
	{
		BioPropertiesUtils::BioPropertiesUtils()
		{

		}
		BioPropertiesUtils::~BioPropertiesUtils()
		{

		}

		

		void BioPropertiesUtils::createEnumProperty(  wxPropertyGridPage& page
			                                          , UIBioSettings index
			                                          , BioGeneralSettingsResource& resource)
		{
			bool flag(false);
			USettingInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxEnumProperty* prop = new wxEnumProperty(item.text(), wxPG_LABEL);
				prop->SetHelpString(item.hint());
				page.Append(prop);
			}
		}

		void BioPropertiesUtils::createBoolProperty( wxPropertyGridPage& page
			                                         , UIBioSettings index
			                                         , BioGeneralSettingsResource& resource)
		{
			bool flag(false);
			USettingInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxBoolProperty* prop = new wxBoolProperty(item.text(), wxPG_LABEL);
				prop->SetEditor(wxPGEditor_CheckBox);
				prop->SetHelpString(item.hint());
				page.Append(prop);
			}
		}


	}
}