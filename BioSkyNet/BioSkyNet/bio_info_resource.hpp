#ifndef BioInfo_Resource_INCLUDED
#define BioInfo_Resource_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioInfoResource : public BioControlResource < UInfoItem >
		{
		public:
			BioInfoResource();
			virtual ~BioInfoResource();

		private:
			void do_initialize();
		};
	}
}

#endif

