#ifndef BioFaceSettings_Resource_INCLUDED
#define BioFaceSettings_Resource_INCLUDED

#include "usettings_info_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioFaceSettingsResource : public BioControlResource < USettingInfoItem >
		{
		public:
			BioFaceSettingsResource();
			virtual ~BioFaceSettingsResource();

		private:
			void do_initialize();
		};
	}
}

#endif

