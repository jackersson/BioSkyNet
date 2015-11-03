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

		wxEnumProperty* BioPropertiesUtils::createEnumProperty( int index, wxPropertyGridPage& page
																								          , BioControlResource<USettingInfoItem>& resource)
		{
			bool flag(false);
			USettingInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxEnumProperty* prop = new wxEnumProperty(item.text(), wxPG_LABEL);
				prop->SetHelpString(item.hint());
				page.Append(prop);

				return prop;
			}

			return NULL;
		}

		wxBoolProperty* BioPropertiesUtils::createBoolProperty( int index, wxPropertyGridPage& page
																							            , BioControlResource<USettingInfoItem>& resource)
		{
			bool flag(false);
			USettingInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxBoolProperty* prop = new wxBoolProperty(item.text(), wxPG_LABEL);
				prop->SetEditor(wxPGEditor_CheckBox);
				prop->SetHelpString(item.hint());
				page.Append(prop);
				return prop;

			}

			return NULL;
		}
		wxPropertyCategory* BioPropertiesUtils::createPropertyCategory( int index, wxPropertyGridPage& page
			                                                            , BioControlResource<USettingInfoItem>& resource)
		{
			bool flag(false);
			USettingInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxPropertyCategory* prop = new wxPropertyCategory(item.text(), wxPG_LABEL);
				//prop->SetEditor(wxPGEditor_CheckBox);
				prop->SetHelpString(item.hint());
				page.Append(prop);
				return prop;

			}

			return NULL;
		}

		/*wxEnumProperty* BioPropertiesUtils::createEnumPropertyC(int index, wxPropertyGridPage& page
			                    , BioControlResource<USettingInfoItem>& resource)
		{
			bool flag(false);
			USettingInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxEnumProperty* prop = new wxEnumProperty(item.text(), wxPG_LABEL);
				prop->SetHelpString(item.hint());
				page.Append(prop);

				return prop;
			}
		}*/




	}
}