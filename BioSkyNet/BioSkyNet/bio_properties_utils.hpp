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

			void createEnumProperty(wxPropertyGridPage& page, UIBioSettings index, BioGeneralSettingsResource& resource);			
			void createBoolProperty(wxPropertyGridPage& page, UIBioSettings index, BioGeneralSettingsResource& resource);		

		};
	}
}

#endif


