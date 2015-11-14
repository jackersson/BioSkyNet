#ifndef Bio_Properties_Utils_INCLUDED
#define Bio_Properties_Utils_INCLUDED


#include "bio_control_resource.hpp"
#include "usettings_info_item.hpp"

#include "Poco/StringTokenizer.h"

namespace SmartBio
{
	namespace View
	{
		class BioPropertiesUtils
		{
		public:
			BioPropertiesUtils();
			~BioPropertiesUtils();

			

		
			wxEnumProperty*   createEnumPropertyWithChoises( int index
				                                             , wxPropertyGridInterface& page
				                                             , BioControlResource<USettingInfoItem>&  personal_resource);

			wxDataViewColumn* createTextColumn(int index, wxDataViewListCtrl& page
				                                , BioControlResource<UInfoItem>& resource);

			wxDataViewColumn* createDateColumn(int index, wxDataViewListCtrl& page
				                                , BioControlResource<UInfoItem>& resource);

			wxDataViewColumn* createBitmapColumn(int index, wxDataViewListCtrl& page
				                                  , BioControlResource<UInfoItem>& resource);

			void BioPropertiesUtils::createColumn(int index, wxDataViewCtrl& page
				, int mlist, BioControlResource<UInfoItem>& resource, wxDataViewRenderer* renderer);

			


			template<typename PropertyType, typename ItemType = UInfoItem>
			PropertyType* createProperty( int index, wxPropertyGridInterface& page
				, BioControlResource<ItemType>& resource
											            , const wxPGEditor* editor = wxPGEditor_TextCtrl )
			{
				bool flag(false);
				ItemType item = resource.get(index, flag);

				if (flag)
				{
					PropertyType* prop;				
					prop = new PropertyType(item.text(), wxPG_LABEL);

					prop->SetEditor(editor);
					prop->SetHelpString(item.hint());
					page.Append(prop);
					return prop;
				}
				return NULL;
			}

		private:
			wxPGChoices buildChoices( const std::string& choices)
			{
				Poco::StringTokenizer tokenizer(choices, ",", Poco::StringTokenizer::TOK_TRIM);
				wxPGChoices chs;
				int i = 0;
				for (Poco::StringTokenizer::Iterator it = tokenizer.begin(); it != tokenizer.end(); ++it)
				{
					chs.Add(*it, i);
					i++;
				}

				return chs;
			}



		

		};
	}
}

#endif


