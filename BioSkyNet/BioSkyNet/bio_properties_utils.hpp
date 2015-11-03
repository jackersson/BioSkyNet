#ifndef Bio_Properties_Utils_INCLUDED
#define Bio_Properties_Utils_INCLUDED

//#include "bio_main_menu_resource.hpp"


#include "bio_resources.hpp"
#include "bio_general_settings_resource.hpp"


namespace SmartBio
{
	namespace View
	{
		class BioPropertiesUtils
		{
		public:
			BioPropertiesUtils();
			~BioPropertiesUtils();

			wxEnumProperty* createEnumProperty(int index, wxPropertyGridPage& page
														, BioControlResource<USettingInfoItem>& resource);
			wxBoolProperty* createBoolProperty(int index, wxPropertyGridPage& page
														, BioControlResource<USettingInfoItem>& resource);
			wxPropertyCategory* createPropertyCategory(int index, wxPropertyGridPage& page
														, BioControlResource<USettingInfoItem>& resource);

			wxEnumProperty* BioPropertiesUtils::createEnumPropertyC(int index, wxPropertyGridPage& page
				, BioControlResource<USettingInfoItem>& resource);

		};
	}
}

#endif


