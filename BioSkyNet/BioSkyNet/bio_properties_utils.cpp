#include "stdafx.h"
#include "bio_properties_utils.hpp"

#include "usettings_info_item.hpp"

#include "Poco/StringTokenizer.h"


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


		wxEnumProperty* BioPropertiesUtils::createEnumPropertyWithChoises( int index, wxPropertyGridInterface& page
			                                                               , BioControlResource<USettingInfoItem>& personal_resource)
		{
			bool flag(false);
			USettingInfoItem item = personal_resource.get(index, flag);

			if (flag)
			{
				/*Poco::StringTokenizer tokenizer(item.choices(), ",", Poco::StringTokenizer::TOK_TRIM);
				wxPGChoices chs;
				int i = 0;
				for (Poco::StringTokenizer::Iterator it = tokenizer.begin(); it != tokenizer.end(); ++it)
				{
					chs.Add(*it, i);
					i++;
				}*/
				wxPGChoices chs = buildChoices(item.choices());
				wxEnumProperty* enum_pr = new wxEnumProperty(item.text(), wxPG_LABEL, chs);

				page.Append(enum_pr);

				return enum_pr;
			}
			return NULL;
		}


		wxDataViewColumn* BioPropertiesUtils::createTextColumn(int index, wxDataViewListCtrl& page
			                                                    , BioControlResource<UInfoItem>& resource)
		{
			bool flag(false);
			UInfoItem item = resource.get(index, flag);

			if (flag)
			{				
				wxDataViewColumn* prop = page.AppendTextColumn(item.text(), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
				return prop;
			}

			return NULL;
		}


		wxDataViewColumn* BioPropertiesUtils::createDateColumn(int index, wxDataViewListCtrl& page
			                                                    , BioControlResource<UInfoItem>& resource)
		{
			bool flag(false);
			UInfoItem item = resource.get(index, flag);

			if (flag)
			{				
				wxDataViewColumn* prop = page.AppendDateColumn(item.text(), 1);
				return prop;
			}

			return NULL;
		}

		wxDataViewColumn* BioPropertiesUtils::createBitmapColumn(int index, wxDataViewListCtrl& page
			                                                      , BioControlResource<UInfoItem>& resource)
		{
			bool flag(false);
			UInfoItem item = resource.get(index, flag);

			if (flag)
			{		
				wxDataViewColumn* prop = page.AppendBitmapColumn(item.text(), 1);			
				return prop;
			}

			return NULL;
		}



		void BioPropertiesUtils::createColumn(int index, wxDataViewCtrl& page
			, int mlist, BioControlResource<UInfoItem>& resource, wxDataViewRenderer* renderer)
		{
			bool flag(false);
			UInfoItem item = resource.get(index, flag);

			if (flag)			
				page.AppendColumn(new wxDataViewColumn(item.text(), renderer
					, mlist, wxCOL_WIDTH_AUTOSIZE));
			
			

		}

	}
}