#ifndef BioLocation_Resource_INCLUDED
#define BioLocation_Resource_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{

		class BioLocationResource : public BioControlResource <UInfoItem>
		{
		public:
			BioLocationResource();

			virtual ~BioLocationResource();

		private:
			void do_initialize();

		};

	}
}


#endif