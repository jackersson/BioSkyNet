#ifndef BioFaceInformationSettings_Resource_INCLUDED
#define BioFaceInformationSettings_Resource_INCLUDED

#include "usettings_info_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioFaceInformationSettingsResource : public BioControlResource < USettingInfoItem >
		{
		public:
			BioFaceInformationSettingsResource();
			virtual ~BioFaceInformationSettingsResource();

		private:
			void do_initialize();
		};
	}
}

#endif

